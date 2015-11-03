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

string substring(string s){
	string res = "";
	int n = s.length();
	int mx=0;
	for (int i = 1; i < n-1; ++i)
	{
		int k=1;
		while(i-k>=0 && i+k<n && s[i-k]==s[i+k])
			k++;
		k--;
		int len = 2*k+1;
		// Error(i,len);
		if(mx<len){
			// error(res);
			res = s.substr(i-k,len);
			mx=len;
		}
	}

	for (int i = 0; i < n-1; ++i)
	{
		int k=0;
		while(i-k>=0 && i+k+1<n && s[i-k]==s[i+k+1])
			k++;
		int len = 2*k;
		// k--;
		if(mx<len){
			res = s.substr(i-k+1,len);
			mx=len;
		}
	}

	return res;

}

int subseq(string s){
	string t=s;
	reverse(ALL(t));
	int n = s.length();
	VVI dp(n+1,std::vector<int>(n+1,0) );

	for (int i = 1; i <=n; ++i)
	{
		for (int j = 1; j <=n; ++j)
		{
			if(s[i-1]==t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}

	// res += s[n-1];
	string res = "";
	int i=n,j=n;
	while(i>0 && j>0){
		if(s[i-1]==t[j-1]){
			res += s[i-1];
			i--;j--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
			i--;
		else 
			j--;
	}
	cout<<res<<EL;
	return dp[n][n];

}

int main()
{
	string s = "aabaa";
	cout<<solve(s);
	return 0;
}
