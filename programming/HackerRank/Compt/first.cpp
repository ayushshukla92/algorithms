#include <bits/stdc++.h>
using namespace std;

#define inf 0x7fffffff

struct node{
	int l,r,max,val;
	node *left, *right;
};


node* makeTree(vector<int> &v,int l,int r){
	if(r<l)
		return NULL;
	node* root=  new node();
	root->l = l;
	root->r = r;
	if(l==r)
	{
		root->max = v[l-1];
		root->val = 1;
		return root;
	}
	int m = (l+r)/2;
	root->left = makeTree(v,l,m);
	root->right = makeTree(v,m+1,r);

	if(root->left->max == root->right->max ){
		root->val = root->left->val + root->right->val;
		root->max = root->left->max;
	}
	else if(root->left->max > root->right->max)
	{
		root->val = root->left->val;
		root->max = root->left->max;
	}
	else{
		root->val = root->right->val;
		root->max = root->right->max;
	}

	return root;
}



int search(node *n, int i,int j,stack<int> &ms)
{
	if(!n) return 0;
	if(n->l > j || n->r < i) return 0; // Out of range

	if(n->l >= i && n->r <= j) {
		cout<<n->l<<' '<<n->r<<' '<<endl;
		if(ms.empty()){
		 	ms.push(n->max);
		 	cout<<n->max<<'*'<<endl;
		}
		else{
			if(n->max == ms.top()){
				ms.push(n->max);
				cout<<n->max<<'#'<<endl;
			}
			else if(n->max > ms.top()){
				ms.pop();
				ms.push(n->max);
				cout<<n->max<<'@'<<endl;
			}
		}

	}

	search(n->left, i, j,ms);
	search(n->right, i, j,ms);
	return ms.size();

}

node* root;
int main(){
	
	vector<int> v;

	int n,q;
	cin>>n>>q;

	for(int i=0;i<n;i++){


		int t;
		cin>>t;
		v.push_back(t);
	}
	root = makeTree(v,1,n);

	while(q--){
		int l,r;
		stack<int> ms;
		cin>>l>>r;
		cout<<search(root,l,r,ms)<<endl;


	}






	return 0;
}	