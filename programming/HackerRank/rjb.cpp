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

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------
std::vector<int> genP(int n){
	VI res;
	VB isP(n+1,true);
	for (int i = 2; i < n; ++i)
	{
		if(isP[i]){
			for (int j = 2; j*i <= n; ++j)
			{
				
				isP[j*i] = false;
			}
		}
	}
	for (int i = 2; i < n+1; ++i)
	{
		if(isP[i])
			res.PB(i);
	}
	return res;
}

int main()
{
	int n;
	SD(n);
	while(n--){
		int m;
		SD(m);
		VI scores = {1,4};
		std::vector<int> perm(m+1,0);
		perm[0] = 1;
		for (int i = 1; i <= m; ++i)
		{
			for(int score : scores)
			{
				if(i >= score)
					perm[i] += perm[i-score];
			}
		}
		int res = perm[m];
		// CO<<"res="<<res;
		int ans = genP(res).size();
		printf("%d\n",ans );

	}
	return 0;
}
