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

int main()
{
	VI v = {1,3,5};
	int n = v.size();
	int sum = 0;
	for(int i : v)
		sum += i;
	
	std::vector<std::vector<int> > dp(n+1, std::vector<int>(sum+1,0) );
	dp[0][0] = 1;

	for (int i = 0; i < n; ++i)
	{
		// int cur = v[i];
		for (int j = 0; j <= sum; ++j)
		{
			int t = j>=v[i]? dp[i][j-v[i]]:0;
			dp[i+1][j] = dp[i][j] + t;
		}
	}


	for (int i = 0; i < dp[n].size(); ++i)
	{
		printf("%d - %d\n", i,dp[n][i]);
	}
	
	
	return 0;
}