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
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v) //foreach(it,map)
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

int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";
		unordered_map<int,std::vector<int> > g;
		int q;
		SD(q);
		while(q--){
			int s1,s2;
			cin>>s1>>s2;
			g[s1].PB(s2);
			g[s2].PB(s1);
		}
		int n = g.size();
		std::vector<int> color(n,-1);

		for (int i = 0; i < n; ++i)
		{
			bool found = false;
			if(color[i] == -1){
				queue<int> mq;
				mq.push(i);
				color[i] = 0;
				while(!mq.empty())
				{
					// int 
					int cur = mq.front();
					mq.pop();
					for(int j : g[cur])
					{
						if(color[j]==-1)
						{
							color[j] = 1 - color[cur];
							mq.push(j);
						}	
						if(color[j] == color[cur]){
							CO<<"FOUND";
							found = true;
							break;
						}

					}
					if(found)
						break;
				}

			}
			if(found)
				break;
		}
		print(color);





		
	}

	return 0;
}
