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
#define ALL(a)                      a.begin(), a.end()
#define IN(a,b)                     ( (b).find(a) != (b).end())

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define F first
#define S second
#define MAX 1000000007

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

int part(VI &v,int l,int r)
{
	int p = v[r];
	int i = l;
	for (int j = l; j <= r-1; ++j)
	{
		if(v[j] < p){
			swap(v[i],v[j]);
			i++;
		}
	}
	swap(v[r],v[i]);
	return i;
}


int klarge(int k,VI &v){
	int l = 0,r= v.size()-1;
	while(r>=l){
		int p  = part(v,l,r);
		if(p==k-1)
			return v[p];
		else if(p>k-1)
			r = p-1;
		else
			l = p+1;
	}
}

int main()
{
	int k;
	SD(k);
	VI v = {5,2,2,4,7,8,6};
	int n = v.size();
	printf("%d\n", klarge(k,v));
	sort(ALL(v));
	print(v);

	return 0;
}
