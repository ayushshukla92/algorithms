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

typedef vector<PII> VP;

#define F first
#define S second

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define inf 0x7fffffff

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 


int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";
		int n;
		cin>>n;

		unordered_map<string, string> tk;
		unordered_map<string,int> first;
		for (int i = 0; i < n; ++i)
		{
			string l,r;
			cin>>l>>r;
			tk[l] = r;
			first[l]++;
			first[r]++;
		}
		string start = "";
		for(auto p : first){
			if(p.S == 1  && tk.find(p.F)!=tk.end()){
				start = p.F;
				break;
			}
		}
		// CO<<start;

		while(tk.find(start)!=tk.end()){
			CO<<start<<"-"<<tk[start]<<' ';
			start = tk[start];
		}
		CO<<EL;



		
	}

	return 0;
}
