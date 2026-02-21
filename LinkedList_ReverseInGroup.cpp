#include <iostream>
using namespace std;
struct List{
  int data;
  List* next;
  List(int value) {
      data = value;
      next = nullptr;
  }
};
void Print(List* head) {
    List* temp = head;
    cout << "List is: ";
    while(temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
List* ReverseList(List* head)
{
    List* curr = head;
    List* prev = nullptr;
    List* next = nullptr;
    
    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

List* GetNthNode(List* head, int offset) 
{
    List* temp = head;
    int count = 1;
    while(count < offset && temp)
    {
        temp = temp->next;
        count++;
    }
    if(temp) {
        return temp;
    } else {
        return nullptr;
    }
}
void ReverseInGroup(List* head, int offset) 
{
    List* temp = head;
    List* NthNode = nullptr;
    List* NthNext = nullptr;
    List* NthPrev = nullptr;
    if(temp == nullptr) {
        return ;
    }
    
    while(temp != nullptr) 
    {
        NthNode = GetNthNode(temp, offset);
        if(NthNode == nullptr)
        {
            // This means that we have less number of nodes.
            NthPrev->next = temp;
            break;
        }
        NthNext = NthNode->next;
        NthNode->next = nullptr;
        List* tHead = ReverseList(temp);
        
        if(temp == head) {
            //this is first Group
            head = tHead;
        } 
        else 
        {
            NthPrev->next = tHead;
        }
        
        temp->next = NthNext;
        NthPrev = temp;
        temp = NthNext;
    }
    Print(head);
}
int main()
{
    List* head = new List(10);
    head->next = new List(20);
    head->next->next = new List(30);
    head->next->next->next = new List(40);
    head->next->next->next->next = new List(50);
    head->next->next->next->next->next = new List(60);
    head->next->next->next->next->next->next = new List(70);
    head->next->next->next->next->next->next->next = new List(80);
    head->next->next->next->next->next->next->next->next = new List(90);
    head->next->next->next->next->next->next->next->next->next = new List(100);
    Print(head);
  
    ReverseInGroup(head, 4);
    return 0;
}