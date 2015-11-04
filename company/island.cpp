#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>


using namespace std;

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector<vector<int> > VVI;
typedef vector<vector<char> > VVC;
typedef vector <bool> VB;
typedef vector < pair<int,int> > VP;
typedef vector <double> VD;
typedef long long ll;
typedef long double ld;

// Input macros	
#define SC(n)    scanf(" %c",&n)
#define SD(n)    scanf("%d",&n)
#define SF(n)    scanf("%f",&n)
#define SLF(n)    scanf("%lf",&n)

#define ALL(a)                      a.begin(), a.end()
#define IN(a,b)                     ( (b).find(a) != (b).end())

#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";

#define PB push_back
#define PF push_front
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

int dfs(VVI &m, int x,int y){
	VI a = {1,-1,0,0};
	VI b = {0,0,1,-1};
	int rs = m.size(),cs = m[0].size();
	int res = 1;
	m[x][y]=0;;
	for(int i=0;i<4;i++)
	{
		if(x+a[i]>=0 && x+a[i]<rs &&
			y+b[i]>=0 && y+b[i]<cs && m[x+a[i]][y+b[i]]==1){
			res += dfs(m,x+a[i],y+b[i]);
		}
	}
	return res;

}

int main()
{
	int n,m;
	SD(n);
	SD(m);

	VVI g(n,std::vector<int>(m,0) );
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{	
			SD(g[i][j]);
		}
	}

	int num = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{	
			if(g[i][j]==1)
			{
				num++;
				int sz = dfs(g,i,j);
				printf("%d\n",sz);
			}
		}
	}	

	return 0;
}
