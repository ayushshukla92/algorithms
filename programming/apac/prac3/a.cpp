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
// #define inf 0x7fffffff

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 

void print2d(vector< vector<int> > &m){
	int n = m.size();
	for (int i = 0; i < n; ++i)
	{
		/* code */
		for (int j = 0; j < n; ++j)
		{
			/* code */CO<<m[i][j]<<' ';
		}
		CO<<EL;
	}
}

int travel(vector< vector<int> > &m, int i, int j){
	if( (i-1>=0 && m[i][j]+1==m[i-1][j]) )
		return 1+travel(m,i-1,j);
	if( (j-1>=0 && m[i][j]+1==m[i][j-1]) )
		return 1+travel(m,i,j-1);
	if( (i+1<m.size() && m[i][j]+1==m[i+1][j]) )
		return 1+travel(m,i+1,j);
	if( (j+1<m.size() && m[i][j]+1==m[i][j+1]) )
		return 1+travel(m,i,j+1);
	return 0;
}

PII visit(vector< vector<int> > &m){
	int n = m.size();
	unordered_map<int,vector<int> > mapr;
	int maxN=-1;
	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			if( (i == 0 || m[i][j]!=m[i-1][j]+1) && (j == 0 || m[i][j]!=m[i][j-1]+1) &&
				(i==n-1 || m[i][j]!=m[i+1][j]+1) && (j == n-1 || m[i][j]!=m[i][j+1]+1) )
			{
				// CO<<m[i][j]<<EL;
				int cur = travel(m,i,j);
				maxN = max(maxN,cur);
				mapr[cur].PB(m[i][j]);
				// CO<<"***"<<i<<"**"<<j<<EL;
			}
		}
	}
	PII res;
	int minp=10000000;
	for(int i : mapr[maxN]){
		minp = min(minp,i);
	}
	res = {maxN,minp};

	return res;


}

int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";

		int n;
		cin>>n;
		std::vector< vector<int> > m(n,vector<int>(n,0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>m[i][j];

			}
		}
		// print2d(m);
		 PII res = visit(m);
		CO<<res.second<<' '<<res.first+1<<EL;
	}

	return 0;
}
