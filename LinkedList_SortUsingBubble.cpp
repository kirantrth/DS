#include <iostream>
using namespace std;

struct List{
  int data;
  List* next;
  List(int num)
  {
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
}
List* ReverseList(List* head)
{
    List* curr = head;
    List* next = nullptr;
    List* prev = nullptr;
    
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // now prev contains totally reversed list.
    return prev;
}
List* ReverseAfter(List* head, int num)
{
    List* curr = head;
    List* prev = nullptr;
    while(curr && curr->data != num)
    {
        prev = curr;
        curr = curr->next;
    }
    cout << "Now reversing list after data " << prev->data << endl;
    List* merge = prev; // This is the merge node whose next will point to the revesred list
    
    prev = nullptr;
    List* next = nullptr;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // now prev contains tatally reversed list.
    //So now add it to the merge node's next.
    merge->next= prev;
    return head;
}
void SortLinkedList(List* head)
{
    cout << "Started sorting the given List " << endl;
    PrintList(head);
    
    List* i = head;
    List*j = nullptr;
    for(i; i->next != nullptr; i = i->next)
    {
        for(j=i; j->next != nullptr ; j=j->next) // This loop is not efficient here. As this will continue to check last sorted nodes also.
        {
            if( j->data > j->next->data )
            {
                int temp = j->next->data;
                j->next->data = j->data;
                j->data = temp;
            }
        }
    }
    cout << "After sorting list " << endl;
    PrintList(head);
}
int main()
{
    List* head = new List(10);
    head->next = new List(20);
    head->next->next = new List(30);
    head->next->next->next = new List(40);
    head->next->next->next->next = new List(50);
    head->next->next->next->next->next = new List(60);
    cout << "original List is => ";
    PrintList(head);
    
    //PrintList( ReverseList(head));
    
    PrintList(ReverseAfter(head, 30));
    
    SortLinkedList(head);

    return 0;
}