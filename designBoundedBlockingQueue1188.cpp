class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        c = capacity;
        m1.lock();
        m2.lock();
        m1.unlock();
    }

    void enqueue(int element) {
        m1.lock();
        q.push(element);
        if (q.size() < c) m1.unlock();
        m2.unlock();
    }

    int dequeue() {
        m2.lock();
        //if (q.size())
        int ans = q.front();
        q.pop();
        if (q.size()) m2.unlock();
        m1.unlock();
        return ans;
    }

    int size() {
        return q.size();
    }
private:
    queue<int>q;
    int c;
    mutex m1, m2;
};
//the 16 ms solution
/*
ToDo:
* Try algorithm 1.
* Use a real queue, not my modulo addressing in a vector.
  ! no I tried a solution from the discussion using queue
  and it had similar and similarly widely swinging times.

Algorithm 1:
Vector substrate.
One 64 bit number for insert point, another for read. Actual locations are mod capacity.
A mutex covers all state.
A condition variable is waited on from read side.
Write side spins on a yield when blocked.

Algorithm 2:
Spin waiting for work and then grab a lock over all state in another spin.

Algorithm 3:
Vector substrate.
One 64 bit number for insert point, another for read. Actual locations are mod capacity.
A mutex covers all state.
A condition variable is waited on from read side.
Write side waits on a different condition variable when blocked.

Algorithm 4:
1 condition var & mutex shared by all.
Vector substrate.
One 64 bit number for insert point, another for read. Actual locations are mod capacity.
notify all.

Algorithm 5:
Algorithm 3/4 except we have 2 cond vars but only 1 mutex.

# Log

Algorithm 2 first submit worked, but ooch on the timing:
Runtime: 620 ms, faster than 5.13% of C++ online submissions for Design Bounded Blocking Queue.
Memory Usage: 11.4 MB, less than 100.00% of C++ online submissions for Design Bounded Blocking Queue.
Yielding on read and write, padded between members:
188, 128, 148, 148, 148, 188
No yield on read (dequeue):
292, 276, 308
No yield on write (enqueue):
324, 280, 316 

Algorithm 1 (yield on write side, wait on read) got as good as 104ms:
Runtime: 104 ms, faster than 57.46% of C++ online submissions for Design Bounded Blocking Queue.
Memory Usage: 11.5 MB, less than 100.00% of C++ online submissions for Design Bounded Blocking Queue.
Without padding:
156, 140, 112, 120, 

Algorithm 3 (2 condition var waits):
Runtime: 100 ms, faster than 65.04% of C++ online submissions for Design Bounded Blocking Queue.
Memory Usage: 11.5 MB, less than 100.00% of C++ online submissions for Design Bounded Blocking Queue.
112,120, 64, 88, 104, 92  <----- 64ms
With padding after mutexes and cvars:
96, 120, 96, 132, 104, 
With padding between all:
112, 100, 88, 
Aligned 64 all members, no padding:
88, 132, 72, 128, 96
Ofast+ 2 pragmas:
80, 120, 120, 
Os + 2 pragmas:
140, 72, 128, 
Padding back:
132, 96, 72, 
No pragmas:
100, 92, 96, 108, 96, 120, 24,    <------------------------ 24ms
  Runtime: 24 ms, faster than 99.76% of C++ online submissions for Design Bounded Blocking Queue.
  Memory Usage: 11.6 MB, less than 100.00% of C++ online submissions for Design Bounded Blocking
No padding but whole class set to alignment 64:
92, 120, 136, 120, 76, 124, 120, 104, 
Algorithm 4:
Runtime: 32 ms, faster than 99.76% of C++ online submissions for Design Bounded Blocking Queue.
Memory Usage: 11.5 MB, less than 100.00% of C++ online submissions for Design Bounded Blocking Queue.
88,72,124,104,116, 112,
Ofast+ 2 pragmas:
128, 104, 112, 96
notify_all():
112, 96, 84, 84, 100, 116, 100, 96, 116, 104, 120
// No pragmas:
96, 80, 72
Move cv & mutex after vector: 
128, 64, 
Explicit unlocks:
92, 88, 80
Only read and write vars are 64 byte aligned:
116, 100, 88, 120, 116, 96
vector aligned, mutex and cv aligned together, then the read and write separate:
116, 92, 100, 84, 128, 104, 72
Explicit capacity member variable:
84, 100, 100
capacity_ aligned 64:
84, 52, 72, 100, 120, 96, 104
Example from the discussion 1, using queue:
80, 108, 116, 96, 100, 108
Ofast, 2 pragmas:
152, 60, 104, 72, 88
The 16ms solution from the submissions graph:
152, 92, 88, 136, 88
Back to algorithm 4 Ofast, cannonlake:
112, 76, 140, 124, 120, 100, 100, 
*/
#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("no-exceptions")
#pragma GCC optimize ("no-rtti")
#pragma GCC optimize ("no-threadsafe-statics")
#pragma GCC target ("arch=cannonlake") 
#pragma GCC target ("tune=cannonlake")

//#include <immintrin.h>

#define ALGORITHM 4
namespace
{
   
// Algorithm 4 Implementation: 
#if ALGORITHM == 4

    class BoundedBlockingQueue {
    public:
        BoundedBlockingQueue(int capacity) : capacity_(capacity)
        {
            buf_.resize(capacity);
        }

        void enqueue(int element)
        {
            unique_lock<mutex> lock(m_);
            cv_.wait(lock, [this](){return write_ - read_ < capacity_;});
            buf_[write_ % capacity_] = element;
            ++write_;
            //cv_.notify_one();
            cv_.notify_all();
            lock.unlock();
        }

        int dequeue() {
            unique_lock<mutex> lock(m_);
            cv_.wait(lock, [this](){return read_ < write_;});
            
            const int res = buf_[read_ % capacity_];
            ++read_;
            //cv_.notify_one();
            cv_.notify_all();
            lock.unlock();
            return res;
        }

        int size() {
            return write_ - read_;
        }
        
    private:
        // Variables are placed on different cachelines:
        // ! Except there is no false sharing: the paths for reading and writing hit them
        //   all so its probably better for them to be as compact as possible so the fewest 
        //   cachelines pingpong
        vector<int>        buf_;// __attribute__ ((aligned (64)));
        const unsigned     capacity_;// __attribute__ ((aligned (64)));
        mutex              m_;// __attribute__ ((aligned (64)));
        condition_variable cv_;// __attribute__ ((aligned (64)));// ..
        uint64_t           write_ = 0;// __attribute__ ((aligned (64))) = 0;
        uint64_t           read_  = 0;// __attribute__ ((aligned (64))) = 0;
    } __attribute__ ((aligned (64))); // Good to start on a cacheline
    

    // Algorithm 3 Implementation: 
#elif ALGORITHM == 3
    
    class BoundedBlockingQueue {
    public:
        BoundedBlockingQueue(int capacity) {//capacity_(capacity) {
            buf_.resize(capacity);
        }

        void enqueue(int element)
        {
            bool done = false;
            unique_lock<mutex> lock(m_write_);
            while(true){
                {
                    if(write_ - read_ < buf_.size())
                    {
                        buf_[write_ % buf_.size()] = element;
                        ++write_;
                        done = true;
                    } else {
                        cv_write_.wait(lock);
                    }
                }
                if(done){
                    cv_.notify_one();
                    // one seems faster cv_.notify_all();
                    return;
                }
            }
        }

        int dequeue() {
            unique_lock<mutex> lock(m_);
            while(true){
                {
                    //lock_guard<mutex> lock(m_);
                    if(read_ < write_){
                        const int res = buf_[read_ % buf_.size()];
                        ++read_;
                        cv_write_.notify_one();
                        return res;
                    } else {
                        cv_.wait(lock);
                    }
                }
            }
        }

        int size() {
            int sz = 0;
            {
                //scoped_lock<mutex> lock(m_);
                sz = write_ - read_;
            
            }
            //cerr << "Thread(" << this_thread::get_id() << ") size() -> " << sz << endl;
            return sz;
        }
        
    private:
        mutex              m_ __attribute__ ((aligned (64)));
        //char padding4[64];
        condition_variable cv_ __attribute__ ((aligned (64)));
        //char padding5[64];
        mutex              m_write_ __attribute__ ((aligned (64)));
        //char padding6[64];
        condition_variable cv_write_ __attribute__ ((aligned (64))); // Signalled when clear to send.
        //char padding1[64];
        vector<int> buf_ __attribute__ ((aligned (64)));
        //char padding2[64];
        uint64_t write_ __attribute__ ((aligned (64))) = 0;
        //char padding3[64];
        uint64_t read_ __attribute__ ((aligned (64))) = 0;
        //const uint64_t capacity_;
    } __attribute__ ((aligned (64)));
    
    // Algorithm 1 Implementation (vanilla)
#elif ALGORITHM == 1
    
    class BoundedBlockingQueue {
    public:
        BoundedBlockingQueue(int capacity) {//capacity_(capacity) {
            buf_.resize(capacity);
        }

        void enqueue(int element)
        {
            bool done = false;
            while(true){
                {
                    //scoped_lock<mutex> lock(m_);
                    lock_guard<mutex> lock(m_);
                    if(write_ - read_ < buf_.size())
                    {
                        buf_[write_ % buf_.size()] = element;
                        ++write_;
                        done = true;
                    }
                }
                if(done){
                    cv_.notify_one();
                    // one seems faster cv_.notify_all();
                    //this_thread::yield(); // Not much difference
                    return;
                }
                this_thread::yield();
            }
        }

        int dequeue() {
            unique_lock<mutex> lock(m_);
            while(true){
                {
                    //lock_guard<mutex> lock(m_);
                    if(read_ < write_){
                        const int res = buf_[read_ % buf_.size()];
                        ++read_;
                        return res;
                    } else {
                        cv_.wait(lock);
                    }
                }
            }
        }

        int size() {
            int sz = 0;
            {
                //scoped_lock<mutex> lock(m_);
                sz = write_ - read_;
            
            }
            //cerr << "Thread(" << this_thread::get_id() << ") size() -> " << sz << endl;
            return sz;
        }
        
    private:
        mutex              m_;
        condition_variable cv_;
        //char padding1[64];
        vector<int> buf_;
        //char padding2[64];
        uint64_t write_ = 0;
        //char padding3[64];
        uint64_t read_  = 0;
        //const uint64_t capacity_;
    };

    // Algorithm 2 implementation:
#elif ALGORITHM == 2   
    class BoundedBlockingQueue {
    public:
        BoundedBlockingQueue(int capacity) {//capacity_(capacity) {
            buf_.resize(capacity);
            // cerr << "Thread(" << this_thread::get_id() << ") Creating BoundedBlockingQueue(" << capacity << ")" << endl;
            // cerr << "Hardware concurrency: " << thread::hardware_concurrency() << endl;
        }

        void enqueue(int element)
        {
            // cerr << "Thread(" << this_thread::get_id() << ") enqueue(" << element << ")" << endl;
            
            //while(write_ - read_ >= buf_.size()) { _mm_pause(); }
            while(true){
                {
                    scoped_lock<mutex> lock(m_);
                    if(write_ - read_ < buf_.size())
                    {
                        buf_[write_ % buf_.size()] = element;
                        ++write_;
                        return;
                    }
                }
                //_mm_pause();
                this_thread::yield();
                
            }
        }

        int dequeue() {
            // cerr << "Thread(" << this_thread::get_id() << ") dequeue()" << endl;
            //while(write_ <= read_) { _mm_pause(); }
            while(true){
                {
                    scoped_lock<mutex> lock(m_);
                    if(read_ < write_){
                        const int res = buf_[read_ % buf_.size()];
                        ++read_;
                        return res;
                    }
                }
                this_thread::yield();
                //_mm_pause();
                //_mm_pause();
            }
        }

        int size() {
            int sz = 0;
            {
                //scoped_lock<mutex> lock(m_);
                sz = write_ - read_;
            
            }
            //cerr << "Thread(" << this_thread::get_id() << ") size() -> " << sz << endl;
            return sz;
        }
        
    private:
        std::mutex  m_;
        char padding1[64];
        vector<int> buf_;
        char padding2[64];
        uint64_t write_ = 0;
        char padding3[64];
        uint64_t read_  = 0;
        //const uint64_t capacity_;
    };
    
#endif // Algorithm 2

    static const auto fast=[](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();
    //struct Exiter { ~Exiter() { exit(1);}};
    //Exiter exit;
}
