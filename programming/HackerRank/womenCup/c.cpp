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
#define ALL(a)                      a.begin(), a.end()
#define IN(a,b)                     ( (b).find(a) != (b).end())

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define F first
#define S second
#define MOD 1000000007
#define MAX 0x7fffffff

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
	multiset<int> ms;
	// VI v(n);
	for (int i = 0; i < n; ++i)
	{
		int t;
		SD(t);
		ms.insert(t);
		// v[i] = t;
	}
	// multiset<int>::reverse_iterator rit=ms.rbegin();
	// CO<<*rit<<"*";
	// for (auto it=ms.begin(); it!=ms.end(); ++it)
	// {
	// 	CO<<*it<<"  ";
	// }
	int res = 0;

	//handle the case for one element
	if(ms.size()==1){
		printf("%d\n",*ms.begin() );
	}
	else{
		while(!ms.empty()){
			multiset<int>::iterator it=ms.begin();
			multiset<int>::iterator er;
			int f = *it;
			ms.erase(it);
			

			int min_n = MAX;
			it=ms.begin();

			while(it!=ms.end()){
				if(*it + f < min_n)
				{
					min_n = *it + f;
					er = it;
				}
				it++;
			}
			res = (res+min_n)%MOD;
			ms.erase(er);
			if(ms.empty())
				break;
			ms.insert(min_n);

		}
		printf("%d\n",res);
	}

	return 0;
}
