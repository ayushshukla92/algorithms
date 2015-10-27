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

bool check(ll p1,ll q1, ll p2, ll q2){
	return p1*q2==p2*q1;
}

int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ":\n";
		int np,nt,ne;
		cin>>np>>ne>>nt;
		VI v1(np);
		VI v2(ne);
		VI v3(nt);
		for (int i = 0; i < np; ++i)
		{
			cin>>v1[i];
		}
		
		for (int i = 0; i < ne; ++i)
		{
			cin>>v2[i];
		}
		for (int i = 0; i < nt; ++i)
		{
			cin>>v3[i];
		}
		int q;
		cin>>q;
		// VP next1;
		std::vector< pair<ll,ll> > res;
		for (int i = 0; i < np; ++i)
		{
			/* code */
			for (int j = 0; j < ne; ++j)
			{
				// next1.PB({v1[i],v2[j]});
				pair<ll,ll> cur1 = {(ll)v1[i], (ll)v2[j]};
				for (int k = 0; k < ne; ++k)
				{
					if(k!=j){
						for (int w = 0; w < nt; ++w)
						{
							pair<ll,ll> cur2= { (ll)v2[k],(ll)v3[w] };
							pair<ll,ll> ans = {cur2.F*cur1.F , cur1.S*cur2.S}; 
							 res.PB(ans);
						}
					}
				}
			}
		}
		// CO<<res.size()<<"******"
		// for (int i = 0; i < res.size(); ++i)
		// {
		// 	 code 
		// 	CO<<res[i].F<<" "<<res[i].S<<EL;
		// }
		// VP next2;
		// for (int i = 0; i < ne; ++i)
		// {
		// 	/* code */
		// 	for (int j = 0; j < nt; ++j)
		// 	{
		// 		next2.PB({v2[i],v3[j]});
		// 	}
		// }
		
		// for (int i = 0; i < next1.size(); ++i)
		// {
		// 	for (int j = 0; j < next2.size(); ++j)
		// 	{
		// 		pair<ll,ll> p;
		// 		p = {next1[i].first*next2[j].first , next1[i].second * next2[j].second};
		// 	 	res.PB(p);
				
		// 	}
		// }

		while(q--){
			ll l,r;
			cin>>l>>r;
			bool flag = false;
			for (int i = 0; i < res.size(); ++i)
			{
				if(check(l,r, res[i].F, res[i].S)){
					flag = true;
					CO<<"Yes"<<EL;
					break;
				}
				/* code */
			}
			if(!flag){
				CO<<"NO"<<EL;
			}

		}


	}

	return 0;
}
