#include <iostream>
#include <vector>
using namespace std;
//121
std::string Reverse(std::string& str, int start, int end)
{
    while(start < end)
    {
        char temp = str[end];
        str[end] = str[start];
        str[start] = temp;
        start++;
        end--;
    }
    return str;
}

std::string ReverseWord(std::string& str)
{
    int len = str.size();
    int i = 0;
    int start = 0;
    int end;
    while(i < len)
    {
        while(str[i] != ' ' && str[i] != '\0')
        {
            i++;
        }
        end = i-1;
        Reverse(str, start, end);
        start = ++i;
    }
    return str;
}


int main()
{
    std::string str("Rudra Kiran Nagesh Tirth");
    cout << "String Before reverse =>: " << str << endl << endl;
    str = Reverse(str,0, str.size()-1);
    cout << "String after reverse =>: " << str << endl << endl;
    str = ReverseWord(str);
    cout << "String after word reverse =>: " << str << endl << endl;
    return 0;
}