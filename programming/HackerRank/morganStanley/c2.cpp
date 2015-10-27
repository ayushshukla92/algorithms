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
#define MAX 0x7fffffff
#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define F first
#define S second

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

int root(VI &v,int i)
{
    while(v[ i ] != i)           //chase parent of current element until it reaches root.
    {
     i = v[ i ];
    }
    return i;
}

/*modified union function where we connect the elements by changing the root of one of the element */

void merge(VI &v ,VI &len, int A ,int B,unordered_map<int,int> &roots)
{


    int root_A = root(v,A);
    int root_B = root(v,B);
    if(len[root_A] < len[root_B ])
    {
		v[ root_A ] = v[root_B];
		len[root_B] += len[root_A];
	    roots[ root_B ] = roots[ root_B ] + roots[ root_A ];
		roots.erase(root_A); 
	}
	else
	{
		v[ root_B ] = v[root_A];
		len[root_A] += len[root_B];
		roots[ root_A ] = roots[ root_A ] + roots[ root_B ];
		roots.erase(root_B); 

	}


}

bool find(VI &v,int A,int B)
{
    if( root(v,A)==root(v,B) )       //if A and B have same root,means they are connected.
    return true;
    else
    return false;
}


int main()
{
	int n,q;
	SD(n);
	SD(q);
	std::vector<int> wt(n+1,0);
	unordered_map<int,int> roots;
	VI v(n);
	VI len(n);
	for (int i = 0; i < n; ++i)
	{
		int temp;
		SD(temp);
		// wt[i] = temp;
		v[i] = i;
		roots[i] = temp;
		len[i] = 1;
	}

	while(q--){

		int l,r;
		SD(l);
		SD(r);
		// cin>>l>>r;
		l--;r--;
		if(!find(v,l,r))
			merge(v,len,l,r,roots);

		int min_w = MAX;
		for(auto entry : roots){
			min_w = min(min_w,entry.S);
		}
		printf("%d\n",min_w);



	}

	return 0;
}
