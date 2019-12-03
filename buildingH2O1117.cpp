class H2O {
public:
    mutex m1, m2;
    int h, o;
    H2O() {
		m1.lock();
		m2.lock();
		m1.unlock();
        o = h = 0;
    }
    void hydrogen(function<void()> releaseHydrogen) {
        m1.lock();
        releaseHydrogen();
        h++;
        if (h < 2) m1.unlock();
        else m2.unlock();
    }

    void oxygen(function<void()> releaseOxygen) {
        m2.lock();
        releaseOxygen();
        h = 0;
        m1.unlock();
    }
};
//the fatest solution
class H2O {
public:
    mutex mtx;
    condition_variable cv;
    int h_count = 2;
    int o_count = 1;
    
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this]{return h_count > 0;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h_count--;
        if(h_count == 0 && o_count == 0){
            o_count = 1;
            h_count = 2;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this]{return o_count == 1;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        o_count = 0;
        if(h_count == 0 && o_count == 0){
            o_count = 1;
            h_count = 2;
        }
        cv.notify_all();
    }
};
