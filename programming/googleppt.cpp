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

void solve(string s,int ind,string cur,std::vector<string> &res){

	if(ind==s.length()){
		res.push_back(cur);
		return;
	}

	char c = s[ind]-'1'+'a';
	solve(s,ind+1,cur+c,res);
	if(ind+1<s.length() && s[ind]!='0'){
		string num = s.substr(ind,2);
		if(stoi(num)<=26){
			char t = 'a'-1+stoi(num);
			solve(s,ind+2,cur+t,res);
		}
	}


}
string conv(char c){
	string res = "";
	// char n = s[ind]-'1'+'a';
	res += c-'1'+'a';
	return res;

}

void sol(string s){
	std::vector<string> prev;
	std::vector<string> cur;
	prev.push_back("");
	// string 
	cur.push_back(conv(s[0]));
	for (int i = 1; i < s.length(); ++i)
	{
		std::vector<string> cv;
		for (int j = 0; j < cur.size(); ++j)
		{
			cv.push_back(cur[j]+conv(s[i]));
		}
		string pnum = s.substr(i-1,2);
		if(stoi(pnum)<=26){
			char t = 'a'-1+stoi(pnum);
			for(string p : prev){
				cv.push_back(p+t);
			}
		}
		prev.clear();
		for(string p : cur){
			prev.push_back(p);
		} 
		cur.clear();
		for(string p: cv){
			cur.push_back(p);
		}

	}
	print(cur);
}

int main()
{
	string s;
	cin>>s;
	// std::vector<string> v = solve(s);
	// print(v);
	// print(res);
	sol(s);
	
	return 0;
}
