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
#define MAX 1000007
template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

int main()
{
	int n;
	SD(n);
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		SD(v[i]);
	}
	
	int c = 0;
	int i = 0;
	int res = 0;
	bool dir = true;
	// int l=0,r;
	std::vector<bool> vis(n,false);
	while(c!=n){

		if(i==n || i==-1){
			res++;
			dir = !dir;
			i =(i==n?n-1:0);
		}

		if(v[i]<=c && !vis[i]){
			c++;
			vis[i] = true;
		}
		if(dir){
			i++;
		}
		else{
			i--;
		}
	}
	CO<<res;

	return 0;
}