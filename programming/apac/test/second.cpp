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
		cout << "Case #" << tc << ":\n";

		int n,q;
		cin>>n>>q;
		vector<double> v(n);
		for(int i= 0;i<n;i++)
		{
			double temp;
			cin>>temp;
			v[i]=temp;
		}
		while(q--)
		{

			int l,r;
			cin>>l>>r;
			double res,rhs=1.0000000;
			for(int i=l;i<=r;i++)
			{
				rhs=  rhs*v[i];
			}
			double d = r-l+1;
			res = pow(rhs,1.000000/d);
			printf("%.9lf\n",pow(rhs,1.00000000/d)) ;
			//value = std::pow(value, 1.0/root);

		}
		
	}

	return 0;
}
