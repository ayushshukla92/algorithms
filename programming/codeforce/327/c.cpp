#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>


using namespace std;

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector<vector<int> > VVI;
typedef vector<vector<char> > VVC;
typedef vector <bool> VB;
typedef vector < pair<int,int> > VP;
typedef vector <double> VD;
typedef long long ll;
typedef long double ld;

// Input macros	
#define SC(n)    scanf(" %c",&n)
#define SD(n)    scanf("%d",&n)
#define SF(n)    scanf("%f",&n)
#define SLF(n)    scanf("%lf",&n)

#define ALL(a)                      a.begin(), a.end()
#define IN(a,b)                     ( (b).find(a) != (b).end())

#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";

#define PB push_back
#define PF push_front
#define EL endl
#define CO cout
#define F first
#define S second
#define MAX 1000000007

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
	SD(n);
	VI v(n);
	for (int i = 0; i < n; ++i)
	{
		SD(v[i]);
	}

	int zc=0,oc=0;

	int lastdif=0x7fffffff;
	bool flag=false;
	int count = 0;
	while(true){
		// count++;
		int prev = v[0];
		int diff=0;
		for (int i = 1; i < n-1; ++i)
		{
			int cur = v[i];
			if(prev + v[i] + v[i+1]>=2)
				v[i] = 1;
			else
				v[i] = 0;
			if(cur!=v[i])
				diff++;
			prev = cur;
		}
		// print(v);
		if(diff>0)
			count++;
		if(diff >= lastdif){
			flag = true;
			printf("-1\n");
			break;
		}
		if(diff==0)
			break;
		lastdif = diff;
	}
	if(!flag){
		// count--;
		printf("%d\n",count);
		for (int i = 0; i < n; ++i)
		{
			printf("%d ",v[i]);
		}
	}
	
	return 0;
}
