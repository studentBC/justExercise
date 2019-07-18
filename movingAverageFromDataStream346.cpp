/*
 * Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

-------------------    wrong test case     -------------------

["MovingAverage","next","next","next","next","next","next","next","next","next","next"]
[[5],[12009],[1965],[-940],[-8516],[-16446],[7870],[25545],[-21028],[18430],[-23464]]
Output
[null,12009.0,6987.0,4344.66667,1129.5,-2385.6,-3213.4,1895.6,-2703.0,983.0,-3521.8]
Expected
[null,12009.0,6987.0,4344.66667,1129.5,-2385.6,-3213.4,1502.6,-2515.0,2874.2,1470.6]
 */

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n = size;
        sum = 0;
    }

    double next(int val) {
        sum+=(double)val;
        num.push((double)val);
        if (num.size() <= n) {
            return sum/(double)num.size();
        } else {
            sum-=num.front();
            num.pop();
            return sum/n;
        }
    }
private:
    queue<double>num;
    double sum = 0;
    int n;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
//the fatest method
class MovingAverage {
private:
    queue<int> _que;
    int _size;
    double sum = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : _size(size){
    }
    
    double next(int val) {
        _que.emplace(val);
        sum += val;
        if (_que.size() > _size) {
            auto cur = _que.front();
            _que.pop();
            sum -= cur;
        }
        return sum / _que.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
