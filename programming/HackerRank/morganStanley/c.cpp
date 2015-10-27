#include <iostream>
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
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstring>


using namespace std;

typedef pair <int, int> PII;
typedef pair <int, double> PID;
typedef pair <double, double> PDD;
typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector < pair<int,int> > VP;
typedef vector <double> VD;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// Input macros
#define SD(n)    scanf("%d",&n)
#define SF(n)    scanf("%f",&n)
#define SLF(n)    scanf("%lf",&n)
#define SS(n)    scanf("%s",&n)

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define F first
#define S second
#define MAX 0x7fffffff
template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

struct dlist
{
	int val;
	dlist *h,*r;
};

void merge(int v1, int v2,unordered_map<int,dlist*> &m){
	dlist *d1 = m[v1];
	dlist *d2 = m[v2]->h;






	while(d1->r!=NULL){
		d1 = d1->r;
	}
	d1->r = d2;
	while(d2!=NULL){
		d2->h = d1->h; 
		d2 = d2->r;
	}
	// d1->r = d2;
	// d2->r = d1;
}

bool isSame(int v1, int v2,unordered_map<int,dlist*> &m){
	// bool f = false;
	
	dlist *d1 = m[v1];
	dlist *d2 = m[v2];
	return d1->h==d2->h;


}

int main()
{
	int n,q;
	cin>>n>>q;
	std::vector<int> wt(n+1,0);

	unordered_map<int,dlist*> m;

	for (int i = 1; i <= n; ++i)
	{
		dlist *d = new dlist();
		int temp;
		cin>>temp;
		d->val = i;
		d->h = d;
		wt[i] = temp;
		m[i] = d;
	}
	while(q--){

		int l,r;
		cin>>l>>r;
		if(!isSame(l,r,m)){
			merge(l,r,m);
		}

		VB visited(n+1,false);
		int min_w = MAX;
		for (int i = 1; i <= n; ++i)
		{
			int curW = 0;
			if(!visited[i]){
				dlist* d1 = m[i]->h;
				while(d1!=NULL){
					curW = curW + wt[ d1->val ];
					visited[d1->val] = true;
					d1= d1->r;
				}
				min_w = min(min_w,curW);

			}

		}
		CO<<min_w<<EL;


	}

	return 0;
}
