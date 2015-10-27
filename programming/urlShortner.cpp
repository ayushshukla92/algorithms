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

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

string shortern(int id){
	string map = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ023456789";
	string code = "";
	while(id){
		code = code + map[id%62];
		id = id/62;
	}
	reverse(code.begin(),code.end());
	return code;
}
int decode(string code){

	int id = 0;
	for(char c : code){
		int ans=0;
		if(c>='A' && c<='Z'){
			ans+=26;
			ans+=c-'A';
		}
		else if(c>='a' && c<='z'){
			ans+=c-'a';
		}
		else{
			ans+=52;
			ans=c-'0';
		}
		id = id*62+ans;
	}
	return id;

}
int main()
{
	cout<<decode(shortern(124324324));
	return 0;
}
