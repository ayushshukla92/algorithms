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

vector<vector<int> > diagonal(vector<vector<int> > &v) {
	std::vector<std::vector<int> > res;
	int n = v.size();
	for (int j = 0; j < n; ++j)
	{
		int r = 0;
		int c = j;
		std::vector<int> t;
		while(r<n && c>=0){
			t.push_back(v[r][c]);
			r++;
			c--;
		}
		res.push_back(t);
	}
	for (int j = 1; j < n; ++j)
	{
		int r = j;
		int c = n-1;
		std::vector<int> t;
		while(r<n && c>=0){
			t.push_back(v[r][c]);
			r++;
			c--;
		}
		res.push_back(t);
	}
	return res;
}


int main()
{
	// int tCases;
	// SD(tCases);
	// while(tCases--){

	// }
	
	return 0;
}
