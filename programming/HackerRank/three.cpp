#include <bits/stdc++.h>

using namespace std;

struct node{
	int val;
	node *next;
};

void printL(node* r)
{
	while(r)
	{
		cout<< r->val<<' ';
		r=r->next;
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	
	int t;
	cin>>t;
	node* root = new node;
	root->val = t;
	node* cur = root;
	

	for(int i=0;i<n-1;i++)
	{
		cin>>t;
		cur->next = new node;
		cur->next->val = t;
		cur = cur->next;
	}

	int days=0;

	if(n==1)	cout<<'0';
	else{
			while(true){
				bool flag = true;
				cur = root->next;
				node *prev = root;




				int prev_int = root->val;
				while(cur !=NULL){
					if(cur->val > prev_int)
					{
						prev ->next = cur->next;
						flag = false;	
					}
					else
					{
						prev ->next = cur;
						prev = cur;
					}
					prev_int = cur->val;
					cur = cur->next;

				}
				if(flag) break;
				else days++;

		}
			cout<<days;
	}
	return 0;
}