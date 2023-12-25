class ZeroEvenOdd {
private:
    int n;
    int i = 1;
    int state = 0;
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this] {return state==0|| i>n;});
            if(i>n)
                break;
            printNumber(0);
            if(i%2 == 0)
                state = 2;
            else
                state = 1;
            cv.notify_all();    
        }        
    }

    void even(function<void(int)> printNumber) {
        while(true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this] {return state==2|| i>n;});
            if(i>n)
                break;
            printNumber(i);
            i++;
            state=0;
            cv.notify_all();    
        }        
        
    }

    void odd(function<void(int)> printNumber) {
        while(true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this] {return state==1|| i>n;});
            if(i>n)
                break;
            printNumber(i);
            i++;
            state = 0;
            cv.notify_all();    
        }          
        
    }
};
