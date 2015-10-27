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


#define inf 0x7fffffff
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
	ll n,m,sum=0;
	cin>>n>>m;

	std::vector<ll> v(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		sum = sum + v[i];
	}

	std::vector<vector <bool> > dp(sum, std::vector<bool>(sum,false) );
	dp[0][0] = true;

	if(m>sum)
		CO<<"NO"<<EL;
	else{

		for (int i = 0; i <n; ++i)
		{
			
			int flag = 0;
			for (ll j = 0; j <= sum; ++j){

					if(dp[i][j] == true){
						if(j%m==0){
							flag = 1;
							break;
						}
						dp[i+1][j] == true;
					}

					if(j >= v[i] && dp[i][j-v[i]]){
							dp[i+1][j] == true;
							if(j%m == 0)
							{
								flag = 1;
								break;
							}
					}
				
				
			}
			if(flag==1)
			{
				CO<<"YES"<<EL;
				break;
			}


		}	
	}

	return 0;
}
