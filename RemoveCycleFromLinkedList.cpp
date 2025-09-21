#include <iostream>
#include <vector>
using namespace std;

struct List{
  int data;
  List* next;
  List(int num) {
      data = num;
      next = nullptr;
  }
};

void PrintList(List* head)
{
    List* temp = head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
void  RemoveCycle(List* head)
{
    List* slow = head;
    List* fast = head;
    bool loop = false;
    while(slow != nullptr && fast->next != nullptr)
    {
        slow = slow->next; // move slow by 1 steps.
        fast = fast->next->next;// move fast by 2 steps.
        if(slow == fast){
            loop = true;
            break;
        }
    }
    if(loop)
        cout << "loop found : slow data " << slow->data << " " << " & fast data " << fast->data << endl;
    else
        cout << "No loop found " << endl;
    
    cout << "Removing the loop present " << endl;
    slow = head;
    if(slow == fast) // IMP - case where loop is at first node.
    {
        while(fast->next != slow) // go to last node.
            fast = fast->next;
        fast->next = nullptr; 
    }
    else
    {
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = nullptr;
    }
    
}
int main()
{
    List* head = new List(10);
    head->next = new List(20);
    head->next->next = new List(30);
    head->next->next->next = new List(40);
    head->next->next->next->next = new List(50);
    
    head->next->next->next->next->next = head->next->next; // here 50's next is pointing to 30
    //PrintList(head);
    
    RemoveCycle(head);
    PrintList(head);

    return 0;
}