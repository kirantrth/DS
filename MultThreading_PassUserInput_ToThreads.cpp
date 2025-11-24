#include <iostream>
#include <cstring>
#include <thread>
#include <mutex>
#include <string>
#include <condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;
bool isReversed = false;

void Reverse(std::string& mystring)// thread to Reverse string
{
    std::unique_lock<std::mutex>lock(mtx);
    int len = strlen(mystring.c_str());
    int start = 0;
    int end = len -1;
    while(start < end)
    {
        char temp = mystring[start];
        mystring[start] = mystring[end];
        mystring[end] = temp;
        start++;
        end--;
    }
    cout << "string after reverse is " << mystring.c_str() << endl;
    isReversed = true; // set to true.
    lock.unlock();
    cv.notify_one();
}
void Rev_word(int start, int end, std::string& mystring)
{
    while(start < end)
    {
        char temp = mystring[start];
        mystring[start] = mystring[end];
        mystring[end] = temp;
        start++;
        end--;
    }
}
void Reverse_words(std::string& mystring)// thread to Reverse words in string
{
    std::unique_lock<std::mutex>lock(mtx);
    cv.wait(lock, []() { return isReversed; } ); // wait till the string is reversed by other thread.
    cout << "Got notification that string is reversed " << mystring.c_str() << endl;
    int len = strlen(mystring.c_str());
    int i = 0;
    int start = 0;
    while(i < len)
    {
        while(mystring[i] != ' ' && mystring[i] != '\0')
        {
            i++;
        }
        Rev_word(start, i-1, mystring);
        start = ++i;
    }
    cout << "string after reverse words is " << mystring.c_str() << endl;
}
int main()
{
    std::string input;
    while(1)
    {
        cout << "Provide input string..." << endl;
        std::getline(cin, input); // See how the input is read from command line here.
        
        std::thread t1(Reverse, std::ref(input)); // see how the parameter to thread is passed here..
        std::thread t2(Reverse_words, std::ref(input)); // see how the parameter to thread is passed here..
        
        t1.join();
        t2.join();
    }
    return 0;
}