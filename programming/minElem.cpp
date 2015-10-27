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

int minE(int k){
	int l = 0,h = k;
	int res= 1;
	while(h>=l){
		int m = (h+l)>>1;
		if(m*m>k)
			h = m-1;
		else
			{
				res = m;
				l=m+1;
			}	
	} 
	return res;
}

int maxE(VI &v){
	int l=0,h=v.size()-1;
	if(l==h) return v[l];
	while(l<=h){
		// printf("l=%d h=%d\n",l,h );
		int m = l + (h-l)/2;
		if(l+1==h){
			// printf("here1\n");
			return max(v[l],v[h]);
		}
		else if(v[m+1]>v[m] && v[m]>v[m-1])
		{
			l=m;
		}
		else if(v[m+1]<v[m] && v[m]>v[m-1]){
			// printf("here2\n");

			return v[m];
		}
		else{
			h=m;
		}
	}
	return -1;
}


int main()
{
	VI v = {1,4,13,15,55,52,1,-1};
	int t = maxE(v);
	printf("%d \n",t);
	
	return 0;
}
