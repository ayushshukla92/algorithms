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

int main()
{
	int n,m;
	SD(n);
	SD(m);
	string s;
	cin>>s;
	unordered_map<char,int> mp;
	std::vector<char> v(26);
	for (int i = 0; i < 26; ++i)
	{
		char c= 'a'+i;
		mp[c] = i;
		v[i] = c;
	}
	while(m--){
		char x,y;
		cin>>x>>y;
		int ix = mp[x];
		int iy = mp[y];
		swap(v[ix],v[iy]);
		mp[ x ] = iy;
		mp[y] = ix;
	}

	for (int i = 0; i < s.length(); ++i)
	{
		s[i] = v[ s[i]-'a' ];
	}
	cout<<s;
	
	return 0;
}
