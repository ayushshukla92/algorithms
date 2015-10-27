#include <iostream>
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
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstring>


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

// Input macros
#define SD(n)    scanf("%d",&n)
#define SF(n)    scanf("%f",&n)
#define SLF(n)    scanf("%lf",&n)
#define SS(n)    scanf("%s",&n)

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define IN(a,b)                      (b).find(a) != (b).end()

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

std::vector<int> genP(int n){
	VI res;
	VB isP(n+1,true);
	for (int i = 2; i < n; ++i)
	{
		if(isP[i]){
			for (int j = 2; j*i <= n; ++j)
			{
				
				isP[j*i] = false;
			}
		}
	}
	for (int i = 2; i < n+1; ++i)
	{
		if(isP[i])
			res.PB(i);
	}
	return res;
}

int main()
{
	int n;
	SD(n);
	std::vector<int> v = genP(n);

	unordered_set<int> ms;
	for(int i : v){
		ms.insert(i);
	}

	if(IN(n,ms)){
		// CO<<"1";
		printf("1\n%d",n );

	}
	else{
		int m = v.size();
		bool found = false;
		for (int i = 0; i < m; ++i)
		{
			int n1 = v[i];
			if(IN(n-n1,ms))
			{
				printf("%d\n%d %d",2,n1,n-n1);
				found = true;	
				break;
			}
			for (int j = i; j < m; ++j)
			{
				int n2 = v[j];
				if(IN(n-n1-n2,ms)){
					printf("%d\n%d %d %d ",3,n1,n2,n-n1-n2 );
					found = true;
					break;
				}
				// if(found)
				// 	break;
			}
			if(found)
					break;
		}
		if(!found)
			CO<<"-1";


	}

	// print(v);
	return 0;
}
