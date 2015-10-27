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
	std::deque<int> dq;

	for(int i = 0;i<n;i++)
	{
		int t;
		cin>>t;
		dq.PB(t);
	}

	int res = 0;

	while(dq.size()>0){
		if(dq.size()<=2){
			res++;
			break;
		}

		unordered_map<int,int> finalh;
		for(int i = 1;i<dq.size()-1;i++){

			int t = min(dq[i-1],dq[i+1]);
			finalh[i] = dq[i]>t?t:dq[i]-1;
			if(finalh[i]<0) finalh[i] = 0;

		}
		for(int i = 1;i<dq.size()-1;i++){
			dq[i] = finalh[i];
		}

		dq.PPF();
		dq.PPB();

		res++;
		int flag = 1;
		for(int i = 0;i<dq.size();i++){
			if(dq[i]!=0)
				flag=0;
		}
		if(flag==1)
			break;

	}

	cout<<res;

	return 0;
}
