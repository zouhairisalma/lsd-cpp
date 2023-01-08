#include <iostream>


using namespace std;

struct  node {

    int data ;
    struct node* next;
    
    
              };
              
typedef struct node node ;
typedef struct node* stack ;
     

stack push (int , stack*);
stack pop (stack*); 



stack push (int x , stack* L)
{
 
    stack p = new node; 
    p->data = x;
    p->next =*L;
    *L=p;
    return *L;
    
 }
 
stack pop (stack*L)
{
   if (*L != NULL) 
   {
     stack p=*L;
     *L=(*L)->next;
     
     delete(p);
    }
    return *L;

}
