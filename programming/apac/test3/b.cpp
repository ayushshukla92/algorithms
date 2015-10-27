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

ll getM(std::vector<std::vector<ll> > &m, int r,int c, int k){
	ll mx = -MAX;
	for (int i = r; i < r+k; ++i)
	{
		for (int j = c; j < c+k; ++j)
		{
			mx = max(mx,m[i][j]);
		}
	}
	return mx;
} 

int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";
		int n,k;
		ll c,x;
		cin>>n>>k>>c>>x;
		std::vector<ll> a(n+1,0);
		std::vector<ll> b(n+1,0);

		for (int i = 1; i <= n; ++i)
		{
			cin>>a[i];
		}
		for (int i = 1; i <= n; ++i)
		{
			cin>>b[i];
		}


		std::vector< std::vector<ll>  > m(n+1, std::vector<ll>(n+1,0) );

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				m[i][j] = ((a[i] * i)%x  +  (b[j] * j)%x + c%x )%x;
			}
		}

		ll sum = 0;
		for (int i = 1; i+k-1 <= n; ++i)
		{
			for (int j = 1; j+k-1 <= n; ++j)
			{
				sum += getM(m,i,j,k);
			}
		}
		cout<<sum<<endl;







	}

	return 0;
}
