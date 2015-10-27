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

int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";
		int n;
		SD(n);
		VI p(n);
		std::vector<ll>  k(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>p[i]>>k[i];
		}

		// handle the case of zero!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(p[n-1]==100)
		{
			int res = k[n-1];
			bool flag = false;
			for (int j = 0; j < n; ++j)
			{
				float dn = (float)res;
				float nm  = k[j];
				float ans = (100*nm)/dn;
				int ver = (int)ans;

				if(ver!=p[j])
					break;
				if(j==n-1){
					// count++;
					flag = true;
					printf("%d\n",res ); 

				}
			}
			if(!flag)
				printf("-1\n");
		}
		else{
			ll count = 0;
			ll res = 0;
			bool flag=  false;

			ll last = 100;
			for (int i = 0; i < n; ++i)
			{
				if(p[i]>1){
					last = k[i];
					break;
				}
			}
			ll start = last;
			last = last*100;
			for (ll i = start; i <= last; ++i)//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
			{
				for (int j = 0; j < n; ++j)
				{
					float dn = (float)i;
					float nm  = k[j];
					float ans = (100*nm)/dn;
					int ver = (int)ans;

					if(ver!=p[j])
						break;
					if(j==n-1){
						count++;
						if(count==2)
						{
							flag = true;
						}	
						res = i; 

					}
				}
				if(flag)
					break;
		
			}
			if(count==1){
				printf("%lld\n",res);
			}
			else{
				printf("-1\n");
			}
		}
		
	}

	return 0;
}
