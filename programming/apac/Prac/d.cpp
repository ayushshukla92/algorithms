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

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define inf 0x7fffffff
#define MAX 1000000007

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 

void gen(int lc, int rc,string prev,vector<string> &vs){
	if(rc<lc || rc<0 || lc<0)
		return;
	if(lc==0 && rc==0)
		vs.PB(prev);
	gen(lc-1,rc,prev+"(",vs);
	gen(lc,rc-1,prev+")",vs);


}

// void get(int n){
// 	string a="";
// 	gen(3,3,a);
// }

int main() {


	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";
		int n,m;
		cin>>n>>m;
		vector<string> vs;
		string temp = "";
		gen(n,n,temp,vs);

		if(vs.size()<m)
			CO<<"Doesn't Exist!"<<EL;
		else{
			m--;
			CO<<vs[m]<<EL;
		}


		
	}

	return 0;
}
