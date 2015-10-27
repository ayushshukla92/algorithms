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
typedef vector <bool> VB;
typedef vector < pair<int,int> > VP;
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

int main()
{
	int t;
	cin>>t;
	
	while(t--){
		unordered_map<int,int> b;
		int n;
		cin>>n;

		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin>>temp;
			b[i+1] = temp;
		}

		int res = -1;
		std::vector<bool> visited(n+1,false);
		visited[0] = true;

		for (int i = 1; i <= n; ++i)
		{
			if(!visited[i]){
				res++;
				
				int start = i;
				visited[i]  = true;
				int next = start;

				while(b[next] != start){
					visited[b[next]] = true;
					next = b[next];
				}

			}
			// CO<<"*";
		}
		CO<<res<<EL;

	}


	return 0;
}
