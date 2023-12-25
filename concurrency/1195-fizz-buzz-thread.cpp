class FizzBuzz {
private:
    int n;
    int i = 1;
    mutable mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true) {            
            std:unique_lock<mutex> lock(m);
            cv.wait(lock, [this] {return (i%3==0 && i%5!=0)||shutDown;});
            if(shutDown)
                break;            
            printFizz();            
            if(i==n)
                shutDown = true;
            i++;
            cv.notify_all();                                       
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
          while(true) {
            std:unique_lock<mutex> lock(m);
            cv.wait(lock,[this] {return (i%5==0 && i%3!=0)||shutDown;});
            if(shutDown) 
                break;
            printBuzz();
            if(i==n)
                shutDown = true;
            i++;
            cv.notify_all();                    
        }
        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
          while(true) {
            std:unique_lock<mutex> lock(m);
            cv.wait(lock,[this] {return (i%3==0 && i%5==0)||shutDown;});
            if(shutDown)
                break;            
            printFizzBuzz();
            if(i==n)
                shutDown = true;
            i++;
            cv.notify_all();                              
        }        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
          while(true) {
            std:unique_lock<mutex> lock(m);
            cv.wait(lock,[this] {return (i%3!=0 && i%5!=0)||shutDown;});
            if(shutDown)
                break;                        
            printNumber(i);
            if(i==n)
                shutDown = true;
            i++;
            cv.notify_all();                                           
        }
        
    }
};
