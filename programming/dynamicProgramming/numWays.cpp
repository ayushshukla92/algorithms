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
	int n;
	cin>>n;

	VI v(n);
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin>>t;
		sum  = sum + t;
		v[i] = t;
	}

	if(sum%3!=0) CO<<"not possible"<<EL;
	else{

			VI first;
			int res=0;
			// VP pairs;

			VI curS(n,0);
		for (int i = 0; i < n; ++i)
			{
				curS[i] = ((i-1)>=0?curS[i-1]:0) + v[i];
				CO<<curS[i]<<"        "<<sum/3<<EL;
				if(curS[i] == sum/3){
					CO<<i<<'*'<<EL;
					first.PB(i);
				}
				if(curS[i]==2*sum/3){
					CO<<"****";
					for(int last : first){
						VI pv = {curS[i],curS[last+1],sum/3};
						print(pv);
						if((curS[i] - curS[last])==sum/3)
							res++;
					}
				}
				/* code */
			}

			CO<<res<<EL;
	}

	return 0;
}
