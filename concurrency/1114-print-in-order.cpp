class Foo {
public:
std::mutex m;
bool firstComplete = false;
bool secondComplete = false;

condition_variable cv1;
condition_variable cv2;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        std::lock_guard<mutex> lock(m);
        firstComplete = true;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<mutex> lock(m);
        cv1.wait(lock,[this] {return firstComplete;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondComplete = true;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<mutex> lock(m);
        cv2.wait(lock,[this] {return secondComplete;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
