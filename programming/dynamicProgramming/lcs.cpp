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
	int n;
	cin>>n;
	string a;
	cin>>a;
	string b = a;
	reverse(b.begin(),b.end());

	std::vector<VI> dp(a.size()+1, vector<int>(b.size()+1,-1) );

	for (int i = 0; i <= a.size(); ++i)
	{
		for (int j = 0; j <= b.size(); ++j)
		{
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else{
				if(a[i-1]==b[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}

			/* code */
		}
	}

	CO<< a.size() - dp[a.size()][b.size()];
	return 0;
}
