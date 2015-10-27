#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstring>
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

using namespace std;

typedef pair <int, int> PII;
typedef pair <int, double> PID;
typedef pair <double, double> PDD;
typedef vector <int> VI;
typedef vector < pair<int,int> > VP;
typedef vector <double> VD;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define inf 0x7fffffff

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define F first
#define S second

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

string bigInt(int n){
	if(n==0)
		return "1";
	string cur = "1";

	for (int i = 0; i < n; ++i)
	{
		
		reverse(cur.begin(),cur.end());
		string next="";
		int car=0;
		for(char c : cur){
			int t = c - '0';
			t = t*2;
			t+=car;
			next  =next +  to_string(t%10);
			car = t/10;
		}
		if(car>0) next  =next + "1";
		reverse(next.begin(),next.end());
		cur = next;
	}

	string p = cur.substr(cur.length()-1);
	cur = cur.substr(0,cur.length()-1) + to_string(stoi(p)-2);
	CO<<cur;




	return cur;
}

int main()
{	
	// CO<<'8'-'2';
	bigInt(2);
	
	return 0;
}
