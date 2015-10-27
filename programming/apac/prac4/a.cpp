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
#define inf 10000009

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

		VP bus;
		for (int i = 0; i < n; ++i)
		{
			int l,r;
			cin>>l>>r;
			bus.PB({l,r});
		}
		int q;
		cin>>q;
		while(q--){

			int c;
			cin>>c;
			int res = 0;
			for(auto p : bus){
				if(p.F <= c && p.S >= c)
					res++;
			}
			CO<<res<<' ';

		}
		CO<<EL;

		
	}

	return 0;
}
