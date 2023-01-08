#include <iostream>
#include <algorithm>

using namespace std;

struct  node
{

    int data ;
    struct node* next;    
};
typedef struct node node ;
typedef struct node* stack ;


stack push (int x , stack* L)
{
 
    stack p = new node; 
    p->data = x;
    p->next =*L;
    *L=p;
    return *L;
 }

 
void remove_duplicates(stack p)
{   
    stack ptr1;
    stack ptr2;
    ptr1=p;
    while(ptr1!=NULL  && ptr1->next!=NULL)
    { 
        ptr2=ptr1->next;
         while(ptr2->next!=NULL)
        {
            if (ptr2->next->data=ptr1->data)
            {
                stack dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                free(dup);
            }
            else
                ptr2=ptr2->next;
         
        }
     
     ptr1=ptr1->next;
   }
}
 
 
void PRINT(stack P)
{
    stack temp=P;
    while(temp->next!=NULL)
    {
        cout << temp->data;
        temp=temp->next;
    }
    if(temp!=NULL)
        cout << temp->data;
}

int main()
{
    stack P;
    push(4,&P);
    push(6,&P);
    push(1,&P);
    push(2,&P);
    push(3,&P);
    push(2,&P);
    push(7,&P);
    PRINT(P);
    cout<< "\n\n";
    remove_duplicates(P);
    PRINT(P);
    return 0;
}