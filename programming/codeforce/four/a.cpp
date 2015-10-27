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
	int n,m;
	cin>>n>>m;
	// VP maxc;

	int minOI = 0, maxON = -1;
	for(int i = 0;i < m;i++)
	{
		int minI=0,maxN=-1; 
		for (int j = 0; j < n; j++)
		{
			int t;
			cin>>t;
			// CO<<j<<'*';
			if(t > maxN){
				maxN = t;
				minI = j;
			}
		}
		if(maxON < maxN){
			maxON = maxN;
			minOI = minI;
		}
		else if(maxN == maxON){
			minOI = min(minOI,minI);
		}
	}
	CO<<minOI+1<<EL;

	return 0;
}
