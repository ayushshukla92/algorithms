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
	int tCases;
	SD(tCases);
	while(tCases--){
		int n,m;
		SD(n);
		SD(m);
		vector<unordered_set<int> > train(3);	
		PII start;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				char c;
				cin>>c;
				if(c!='.'){
					if(c=='s')
						start = {0,i};
					else
						train[i].insert(j);
				}
			}
		}
		std::vector<std::vector<bool> > visited(3,std::vector<bool>(n+3,false) );;
		queue<PII> mq;
		mq.push(start);
		visited[start.F][start.S]=  true;

		bool flag = false;
		while(!mq.empty())
		{
			PII cur  = mq.front();
			printf(" at {%d,%d}\n",cur.F,cur.S );
			mq.pop();
			int l = cur.S;
			int col = cur.F;
			if(!IN(col+1,train[l])){
				printf("here1\n" );




				if(!visited[l][col+3] && !IN(col+2,train[l]) && !IN(col+3,train[l]) ){
					// printf("here2\n" );

					if(col+3 >= n){
						printf("YES\n");
						flag = true;
						break;
					}
					// if(!visited[l][col+3])
						mq.push({col+3,l});
					// else
						visited[l][col+3] = true;
				}

				if(l+1<=2 &&!visited[l][col+3]&& !IN(col+1,train[l+1]) && !IN(col+2,train[l+1]) && !IN(col+3,train[l+1]) ){
					// printf("here3\n" );

					if(col+3 >= n){
						printf("YES\n");
						flag = true;
						break;
					}
					// if(!visited[l+1][col+3])
						mq.push({col+3,l+1});
					// else
						visited[l][col+3] = true;
				}

				if(l-1>=0 && !visited[l][col+3]&& !IN(col+1,train[l-1]) && !IN(col+2,train[l-1]) && !IN(col+3,train[l-1]) ){
					// printf("here4\n" );

					if(col+3 >= n){
						printf("YES\n");
						flag = true;
						break;
					}
					// if(!visited[l-1][col+3])
						mq.push({col+3,l-1});
					// else
						visited[l-1][col+3] = true;
				}
			}
		}
			if(!flag)
				printf("NO\n");

	}
	
	return 0;
}
