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

void getD(string s,unordered_set<string> &ms){
	string res = "";
	int start = -1;

	int loc = 0;
	// unordered_set<string> ms;

	while((loc = s.find("http://",start+1))!=string::npos)
	{

		res = "";
		string temp = s.substr(loc+7); 
		for(char c : temp)
		{
			if(c=='.' || (c>='a' && c<='z'))
				res += c;
			else
				break;
		}
		error(res);
		if(res.find("www.")!=string::npos){
			int dif = res.find("www.");
			ms.insert(res.substr(dif+4));
		}
		else
			ms.insert(res);
		// cout<<res;
		start = loc+1;
	}
	// return res;


}

int main()
{
	int tCases;
	scanf("%d",&tCases);
	unordered_set<string> ms;
	while(tCases--){
		cin.ignore();
		string s;
		getline(cin,s);
			getD(s,ms);

	}
	for(auto it : ms)
		cout<<it<<endl;
	
	return 0;
}
