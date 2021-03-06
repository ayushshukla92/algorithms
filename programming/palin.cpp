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

string longP(string s){
	if(s.length()==0)
		return "";
	int n = s.length();
	string res = "";
	int mx=0;
	for (int i = 1; i < n-1; ++i)
	{
		int k=1;
		while(i-k>=0 && i+k<n && s[i-k]==s[i+k]){
			k++;
		}
		k--;
		int len = 2*k+1;
		if(len>mx){
			res = s.substr(i-k,len);
			// cout<<res<<endl;
			mx = len;
		}

	}

	for (int i = 0; i < n-1; ++i)
	{
		int k=1;
		while(i-k+1>=0 && i+k<n && s[i-k+1]==s[i+k]){
			k++;
		}
		k--;
		int len = 2*k;
		if(len>mx){
			res = s.substr(i-k+1,len);
			// cout<<res<<endl;
			mx = len;
		}

	}	


	return res;

}

int main()
{
	string s = "asdnasdnaaaaaaamanasmsadfn";
	cout<<longP(s);
	return 0;
}
