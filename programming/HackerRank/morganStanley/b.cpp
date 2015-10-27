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
#define MAX 0x7fffffff
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
	int t;
	cin>>t;

	while(t--){
		string x,u;
		cin>>x>>u;
		int de,in,re;
		cin>>de>>in>>re;
		
		VI wrng(26,0);
		VI corr(26,0);

		for (int i = 0; i < x.size(); ++i)
		{
			wrng[x[i]-'a']++;
		}
		for (int i = 0; i < u.size(); ++i)
		{
			corr[u[i]-'a']++;
		}

		int wc=0,cc=0;
		for (int i = 0; i < 26; ++i)
		{
			int m = min(wrng[i],corr[i]);
			wrng[i] = wrng[i]-m;
			corr[i] = corr[i]-m;
			wc = wc + wrng[i];
			cc = cc + corr[i];
		}

		int res = MAX;
		if(wc>cc){
			int diff = wc-cc;
			res = min(res, diff*de+cc*re);
			res = min(res,wc*de+cc*in);
		}
		else{
			int diff = cc-wc;
			res = min(res,wc*re+diff*in);
			res = min(res,wc*de+cc*in);
		}
		CO<<res<<EL;



	}	


	return 0;
}
