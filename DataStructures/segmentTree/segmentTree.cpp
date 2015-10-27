#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <cstdio>
#include <list>

using namespace std;

typedef pair <int, int> PII;
typedef pair <int, double> PID;
typedef pair <double, double> PDD;
typedef vector <int> VI;
typedef vector <double> VD;
typedef vector< pair<int,int> > VP;  
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define inf 0x7fffffff

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define F first
#define S second

#define MAXN 100009
#define MAX MAXN*6

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

void makeTree(VP &tree, VI v, int nodeNum, int l, int r){

	// CO<<"l="<<l<<"r="<<r<<EL;

	if(l>r) return ;

	// maxnum ,num of max
	if(l==r){
		tree[nodeNum] = {v[l],1};
		return;
	}
	int m = (l+r)/2;
	makeTree(tree,v,nodeNum*2,l,m);
	makeTree(tree,v,nodeNum*2+1,m+1,r);

	PII leftP = tree[nodeNum*2];
	PII rightP = tree[nodeNum*2+1];

	if(leftP.F>rightP.F){
		tree[nodeNum] = leftP;
	}
	else if(leftP.F<rightP.F){
		tree[nodeNum] = rightP;
	}
	else{
		PII np = {leftP.F, leftP.S + rightP.S};
		tree[nodeNum] = np;
	}

	return;


}

PII query(VP &tree, int nodeNum, int curL, int curR, int ql, int qr ){
	if(curL > qr || curR < ql || curR<curL)
		return {-inf,1};

	if(curL>=ql && curR<=qr){
		return tree[nodeNum];
	}
	int m = (curL+curR)/2;
	PII ln = query(tree,nodeNum*2,curL,m,ql,qr);
	PII rn = query(tree,nodeNum*2+1,m+1,curR,ql,qr);

	if(ln.F>rn.F){
		return ln;
	}
	else if(ln.F<rn.F){
		return rn;
	}
	else{
		return {ln.F,rn.S+ln.S};
	}


}

int main()
{
	int n,q;
	cin>>n>>q;
	VP tree(MAX);
	VI v;

	for(int i=0;i<n;i++){


		int t;
		cin>>t;
		v.push_back(t);
	}
	makeTree(tree,v,1,0,n-1);


		while(q--){
		int l,r;
		cin>>l>>r;
		l = l-1;
		r = r-1;
		cout<<query(tree,1,0,n-1,l,r).S<<endl;


	}

	return 0;
}
