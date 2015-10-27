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
#define SC(n)    scanf("%c",&n)
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

int main()
{
	int n,m;
	SD(n);
	SD(m);
	std::vector<std::vector<char> > v(n,std::vector<char>(m,'.') );
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf(" %c",&v[i][j]);

		}
	}



	std::vector<std::vector<PII> > mat(n+1,std::vector<PII>(m+1,{0,0}) );



	int res = 0;
	for (int i = n-1; i >=0; i--)
	{
		for (int j = m-1; j >= 0; j--)
		{
			if(v[i][j]=='.'){
				// printf("{%d,%d}\n",mat[i+1][j].F,mat[i+1][j].S );
				mat[i][j] = {mat[i+1][j].F + 1,mat[i][j+1].S + 1};
				// res = max(res,mat[i][j].F*mat[i][j].S);
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("{%d,%d}  ", mat[i][j].F,mat[i][j].S);
			int h = mat[i][j].F;
			int w = mat[i][j].S;
			int minw = 9999;
			if(h*w > res){
				for (int k = 0; k < h; ++k)
				{
					minw = min(minw,mat[i+k][j].S);
					res = max(res,minw*(k+1));

				}
			}
		}
		CO<<EL;
	}
	printf("%d\n",res);
	return 0;
}
