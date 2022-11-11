#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node
{
	int ptt;
	Node* next;
};

struct Node* reverse(Node* head , int k)
{
	if(!head)
		return NULL;
	Node* cur = head;
	Node* next = NULL;
	Node* prev = NULL;
	int n =0;
	while(cur!= NULL && n < k)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		n++;
	}
	if(next!= NULL)
		head->next = reverse(next , k);
	return prev;
}


                     

                      
                     

                      
                     


int main()
{
	struct Node m;
	m.ptt = 3;
	m.next = NULL;
	
}
