#include <iostream>
using namespace std;
struct Node{
    int coe;
    int expo;
    Node* next;
    Node(int c, int e) 
    {
        coe = c;
        expo = e;
        next = nullptr;
    }
};
void PrintPoly(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout << temp->coe << "^" << temp->expo ;
        if(temp->next != nullptr)
            cout << " + ";
        temp = temp->next;  
    }
    cout << endl;
}
void create_result(Node* &result, int coe, int expo)
{
    if(result == nullptr)
    {
        result = new Node(coe, expo);// first node case
        return;
    }
    Node* temp = result;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next =  new Node(coe, expo);
}
Node* AddPoly(Node* head1, Node* head2)
{
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* result = nullptr;
    
    while(ptr1 != nullptr && ptr2 != nullptr)
    {
        
        if(ptr1->expo == ptr2->expo)
        {
            create_result(result, ptr1->coe + ptr2->coe, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->expo > ptr2->expo) //here I am trying to create result list in decreasing order of exponents.
        {
            create_result(result, ptr1->coe, ptr1->expo);
            ptr1 = ptr1->next;
        } 
        else
        {
            create_result(result, ptr2->coe, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != nullptr)
    {
        create_result(result, ptr1->coe, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while(ptr2 != nullptr)
    {
        create_result(result, ptr2->coe, ptr2->expo);
        ptr2 = ptr2->next;
    }
    return result;
}
int main()
{
    Node* head1 = new Node(5,4);
    head1->next = new Node(10,3);
    head1->next->next = new Node(15,2);
    head1->next->next->next = new Node(2,1);
    
    Node* head2 = new Node(5,6);
    head2->next = new Node(10,3);
    head2->next->next = new Node(9,2);
    PrintPoly(head1);
    PrintPoly(head2);
    
    PrintPoly( AddPoly(head1, head2) );
	
    return 0;
}