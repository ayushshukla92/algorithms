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
#include <stack>
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
//--------------------------------------------------------------
bool remove(stack<int> ms,int k){
	if(ms.size()<3)
		return false;

	int c = ms.top();
	ms.pop();
	int b = ms.top();
	ms.pop();
	int a = ms.top();
	ms.pop();
	return (c-b) == (b-a) && (b-a)==k;

}

int main() {
	int Tcases;
		cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";
		int n,k;
		cin>>n>>k;
		stack<int> curs;
		for (int i = 0; i < n; ++i)
		{
			int t;
			cin>>t;
			curs.push(t);
			while(remove(curs,k)){
				curs.pop();
				curs.pop();
				curs.pop();
			}
		}
		CO<<curs.size()<<EL;


		
	}

	return 0;
}
