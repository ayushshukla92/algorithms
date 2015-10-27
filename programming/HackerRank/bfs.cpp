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
	int tc;
	SD(tc);
	while(tc--){

		int n,m;
		SD(n);
		SD(m);
		unordered_map<int,std::vector<PII> > g;
		while(m--){
			int l,r;
			SD(l);SD(r);
			g[l].PB({r,6});
			g[r].PB({l,6});
		}
		int s;
		SD(s);

		unordered_map<int,int> dist;
		VB visited(n+1,false);
		queue<PII> mq;
		mq.push({s,0});
		dist[s] = -1;
		visited[s] = true;
		while(!mq.empty()){
			PII p = mq.front();
			mq.pop();
			int curD = p.S;
			int curN = p.F;
			for(PII child : g[curN]){
				int childN = child.F;
				int childD = child.S;
				if(!visited[childN]){
					visited[childN] = true;
					dist[childN] = curD + childD;
					mq.push({childN,dist[childN]});
				}
			}

		}
		for (int i = 1; i <= n; ++i)
		{
			if(i!=s){
				if(IN(i,dist)){
					printf("%d ", dist[i]);
				}
				else{
					CO<<"-1 ";
				}
			}
		}
		CO<<EL;


	}
	return 0;
}
