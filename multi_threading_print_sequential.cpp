#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>
using namespace std;
int counter = 1;
std::mutex mtx;
std::condition_variable cv;

/*
If there are 4 threads, and you want to print threads seqeuntially like t1 -> 1, t2 -> 2, t3->3, t4->4, t1->5 ..

t1 1%4 = 1 5%4 = 1 9%4 = 1
t2 2%4 = 2 6%4 = 2 10%4 = 2
t3 3%4 = 3 7%4 = 3 11%4 = 3
t4 4%4 = 0 8%4 = 0 12%4 0

*/
void Thread1()
{
    while(1)
    {
        std::unique_lock<std::mutex>lock(mtx);
        cv.wait(lock, []() { return counter >= 50 || counter%4 == 1;} ); // look at predicate in lambda
        
        if (counter >= 50) {
            break;
        }

        cout << "Thread 1 => " << counter << endl;
        counter++;
        lock.unlock();
        cv.notify_all();
    }
}
void Thread2()
{
    while(1)
    {
        std::unique_lock<std::mutex>lock(mtx);
        cv.wait(lock, []() { return counter >= 50 || counter%4 == 2;} );// look at predicate in lambda
        if (counter > 50) {
            break;
        }
        cout << "Thread 2 => " << counter << endl;
        counter++;
        lock.unlock();
        cv.notify_all();
    }
}
void Thread3()
{
    while(1)
    {
        std::unique_lock<std::mutex>lock(mtx);
        cv.wait(lock, []() { return counter >= 50 || counter%4 == 3;} );// look at predicate in lambda
        if (counter > 50) {
            break;
        }
        cout << "Thread 3 => " << counter << endl;
        counter++;
        lock.unlock();
        cv.notify_all();
    }
}
void Thread4()
{
    while(1)
    {
        std::unique_lock<std::mutex>lock(mtx);
        cv.wait(lock, []() { return counter >= 50 || counter%4 == 0; } );// look at predicate in lambda
        if (counter > 50) {
            break;
        }
        cout << "Thread 4 => " << counter << endl;
        counter++;
        lock.unlock();
        cv.notify_all();
    }
}
int main()
{
    std::thread t1(Thread1);
    std::thread t2(Thread2);
    std::thread t3(Thread3);
    std::thread t4(Thread4);
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}