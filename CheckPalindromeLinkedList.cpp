#include <iostream>
#include <queue>
using namespace std;
struct List {
  int data;
  List* next;
  List(int num) {
      data = num;
      next = nullptr;
  }
};

void PrintList(List* head) {
    List* temp = head;
    cout << "List is: " << endl;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//1 2 3 2 1
// Logic is same as of reverse list recursively. But actually no need to reverse.
bool CheckPalindrome(List* head, std::queue<int>& q) 
{
    bool isPalindrome = true;
    
    if(head->next != nullptr) 
    {
        q.push(head->data);
        isPalindrome = CheckPalindrome(head->next, q);
    }
    else 
    {
        q.push(head->data);
    }
    if(head->data != q.front()) {
        isPalindrome = false;
    } else {
        q.pop();
    }
    return isPalindrome;   
}
int main()
{
    List* head = new List(1);
    head->next = new List(2);
    head->next->next = new List(3);
    head->next->next->next = new List(2);
    head->next->next->next->next = new List(1);
    cout << "Given List is : " << endl;
    PrintList(head);
    std::queue<int> q;
    bool palindrome = CheckPalindrome(head, q);
    if(!palindrome) {
        cout << "List is not palindrome " << endl;
    }else {
        cout << "List is Palindrome " << endl;
    }
    return 0;
}