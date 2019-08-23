/*
Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}

The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

 

Example 1:

Input: [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.

Example 2:

Input: [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.

 

Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seems to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.
*/
#include <unistd.h>
class Foo {
public:
    Foo() {
        count = 0;
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        while (count%3) usleep(1);
        printFirst();
        count++;
    }

    void second(function<void()> printSecond) {
        // printSecond() outputs "second". Do not change or remove this line.
        while (count%3!=1) usleep(1);
        printSecond();
        count++;
    }

    void third(function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        while (count%3!=2) usleep(1);
        printThird();
        count++;
    }
private:
    int count = 0;
};

//64 ms solution
//http://www.cplusplus.com/reference/future/promise/get_future/
/*std::future is an asynchronous return object ("an object that reads results from a shared state") and a std::promise is an asynchronous provider ("an object that provides a result to a shared state") i.e. a promise is the thing that you set a result on, so that you can get it from the associated future.

The asynchronous provider is what initially creates the shared state that a future refers to. std::promise is one type of asynchronous provider, std::packaged_task is another, and the internal detail of std::async is another. Each of those can create a shared state and give you a std::future that shares that state, and can make the state ready.

std::async is a higher-level convenience utility that gives you an asynchronous result object and internally takes care of creating the asynchronous provider and making the shared state ready when the task completes. You could emulate it with a std::packaged_task (or std::bind and a std::promise) and a std::thread but it's safer and easier to use std::async.

std::promise is a bit lower-level, for when you want to pass an asynchronous result to the future, but the code that makes the result ready cannot be wrapped up in a single function suitable for passing to std::async. For example, you might have an array of several promises and associated futures and have a single thread which does several calculations and sets a result on each promise. async would only allow you to return a single result, to return several you would need to call async several times, which might waste resources.*/ 
//https://stackoverflow.com/questions/11004273/what-is-stdpromise
class Foo {
private:
  std::promise<void> p1;
  std::promise<void> p2;

public:
  void first(function<void()> printFirst) {
    printFirst();
    p1.set_value();
  }

  void second(function<void()> printSecond) {
    p1.get_future().wait();
    printSecond();
    p2.set_value();
  }

  void third(function<void()> printThird) {
    p2.get_future().wait();
    printThird();
  }
};
