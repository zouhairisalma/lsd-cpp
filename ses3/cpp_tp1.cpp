#include <iostream>
using namespace std;

//Exercise 1: stack with linked lists
//Node, elementary componenent of the linked list
struct Node
{
    int value;
    struct Node * next;
};

struct Node *  push(int valuex,struct Node* list)
{
    //THE NEW NODE 
    struct Node* NewNode = (struct Node*) malloc(sizeof(struct Node));
    NewNode->value =valuex ;
    if(list==NULL)
        NewNode->next = NULL;
    else
        NewNode->next=list;
    return list;
}


struct Node * pop(struct Node * list )
{
    if(list==NULL)
    {
        cout<<"stack underflow"<<endl;
        return list;
    }    
    else
    {
        list=list->next;
    }
    return list;
}
//\\//*_*\\//  !\_:D:_/!   -<^=_=^>-  ~((^~_:_~^))~   "^._.^"   *[.¬¬.]*    (^\.|./^)    

int main()
{
    struct Node m;
    m.value=1;
    m.next=NULL;
    //Case 1: list NOT NULL
    struct Node * list =&m;
    list=pop(list);
    cout<<"I can run Cpp code  on vs code now yaay"<<endl;

}




