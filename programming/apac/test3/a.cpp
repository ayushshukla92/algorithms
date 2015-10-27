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

bool comparePairs(const std::pair<ll,string>& lhs, const std::pair<ll,string>& rhs)
{
  return lhs.first > rhs.first || (lhs.F==rhs.F && lhs.S<rhs.S);
}


int main() {
	int Tcases;
	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": "<<EL;
		int p;
		SD(p);
		std::vector<ll>  pos(p,0);
		for (int i = 0; i < p; ++i)
		{
			cin>>pos[i];
		}
		int n;
		SD(n);
		unordered_map<string,set<ll,std::greater<ll> > > mp;
		for (int i = 0; i < n; ++i)
		{
			ll w;
			cin>>w;
			for (int j = 0; j < p; ++j)
			{
				string s;
				cin>>s;
				ll mrk = w*pos[j];
				mp[s].insert(mrk);
			}

		}
		int m;
		cin>>m;
		std::vector<pair<ll,string> > v;

		for(auto it : mp){
			//set - it.S
			ll tot = 0;
			int k = m;
			for(auto tt  : it.S){
				if(k==0)
					break;
				tot += tt;	
				k--;
			}
			pair<ll,string> pr = {tot,it.F};
			v.PB(pr);
		}

		sort(v.begin(),v.end(),comparePairs);
		int k = 1;
		int prev = 1;
		for (int i = 0; i < v.size(); ++i)
		{
			if(i==0){
				cout<<k<<": "<<v[i].S<<EL;
				prev = k;
			}
			else{
				if(v[i].F==v[i-1].F){
					cout<<prev<<": "<<v[i].S<<EL;
				}
				else{
					// k++;
					cout<<i+1<<": "<<v[i].S<<EL;
					prev = i+1;


				}
			}
		}
		
	}

	return 0;
}
