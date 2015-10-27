#include<iostream>

using namespace std;

typedef struct ListNode {
      int val;
      ListNode *next;
   	  ListNode(int x) : val(x), next(NULL) {}
 }ListNode;

ListNode* removeElements(ListNode* head, int val)
{
if(head==NULL)
	return NULL;
while(head!=NULL && head->val==val)
	head=head->next;
if(head==NULL)
	return NULL;
ListNode *p=head,*q=head;
while(p!=NULL)
{
	if(p->val==val)
		q->next=p->next;
	else
		q=p;
	p=p->next;

}


return head;
}


 int main()
 {
 	cout<<"sa";
 	 return 1;
 }