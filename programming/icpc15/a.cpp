#include <bits/stdc++.h>


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


//-----------------------------------------utilities end---------------------------

int main()
{
	int tCases;
	SD(tCases);
	while(tCases--){
		int n,k;
		SD(n);
		SD(k);

		if (k >= n){
			printf("-1\n");
		}
		else {
			int c = 0;
			for (int i = 1; i <= n; ++i)
			{
				if(i-k<1){
					// CO<<"here1";
					printf("%d ", i+k);
				}
				// else if(i-k >= 1 && i <2*k+1){
				// 	printf("%d ",i-k );
				// // }

				// else if(i <  2*k+1 && i <= n){
				// 	printf("%d ", i-k);
				// } 
				else if ( i >= k + 1 && i <= n-2*k){
					// CO<<"here2";
					printf("%d ", i-k);
				}
				else if (i > n - 2*k && i <= n-k){
					// CO<<"here3";
					printf("%d ", i+k);
				}
				else if (i <3*k + 1){
					// CO<<"here3";
					printf("%d ", i-2*k);
				}
				else if (i >= 3*k + 1 ){
					// CO<<"here4";
					printf("%d ",i-k );
					c++;
				}
			}
			printf("\n");
		}

	}
	
	return 0;
}
