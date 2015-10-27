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
int n;
int get(VI &v,VI &csum, int p, int s){
	if(p>=n || p<0)
		return -1;
	if(p==0){
		int sigma = s/n;

		if(sigma < v[0])
			return sigma;
		else
			return -2;
	}
	int left = v[p-1];
	int right = v[p];

	int sigma = (s-csum[p-1])/(n-p);

	if(sigma>left && sigma < right)
		return sigma;
	if(sigma<left)
		return -1;
	else
		return -2;
	// return -1;

}

int main()
{
	VI v = {90,30,100,40,20};
	n = v.size();
	sort(ALL(v));
	VI csum(n,0);
	csum[0] = v[0];

	for (int i = 1; i < n; ++i)
	{
		csum[i] += v[i] + csum[i-1];
	}

	// int l = 0,r = n-1;
	// while(l<r){
	// 	int m = (l+r)/2;
	// 	if(get(v,csum,m,s)!=-1)
	// 	{
	// 		printf("found %d\n", get(v,csum,m,s));
	// 	}
	// 	else if()
	// }
	for (int i = 0; i < n; ++i)
	{
		printf("i=%d  ans=%d\n",i,get(v,csum,i,150) );
	}


	return 0;
}
