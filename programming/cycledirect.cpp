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

void hasCycle(unordered_map<int,VI> &g,VI &vis,int s)
{
	vis[s] = 1;
	for(int ch : g[s]){
		if(vis[ch]==1){
			printf("cycle found\n");
			// return true;
		}
		else if(vis[ch]==-1){
			vis[ch] = 1;
			hasCycle(g,vis,ch);
			// return 
		}
	}
	vis[s] = 2;
}


int main()
{
	unordered_map<int,std::vector<int> > g;
	g[0].PB(1);
	g[0].PB(0);
	g[1].PB(2);
	g[0].PB(2);
	g[3].PB(0);
	int n = 4;
	VI vis(n,-1);
	for (int i = 0; i < n; ++i)
	{
		if(vis[i]==-1)
		{
			vis[i]==1;
			hasCycle(g,vis,i);
			// printf("cycle exist\n");
		}

	}
	
	return 0;
}
