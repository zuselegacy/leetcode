class H2O {
    int h = 0;
    int o = 0;
    mutex m;
    condition_variable cv;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std:unique_lock<mutex> lock(m);
        cv.wait(lock, [this] {return h < 2;});        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h++;
        if(h==2 && o==1) {
            h=0;
            o=0;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std:unique_lock<mutex> lock(m);
        cv.wait(lock,[this] {return o == 0 ;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        o++;
        if(h == 2) {
            o=0;
            h=0;
        }
        cv.notify_all();
    }
};
