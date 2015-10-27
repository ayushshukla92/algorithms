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

bool isT(int a,int b, int c){
	return (a+b>c) && (a+c>b) && (c+b>a);
}

int main()
{
	int a,b,c,l;
	int res = 0;
	cin>>a>>b>>c>>l;
	for(int i = 0;i <= l; i++){

		for(int j = 0;j+i<=l;j++){
			if(i+j>l) break;

			if(b+j+c<a+i || a+i+c<b+j)
				continue;

			res+=min(l-i-j, a+b+i+j-c)>0?min(l-i-j, a+b+i+j-c):0;
			CO<<a+i<<' '<<b+j<<' '<<min(l-i-j, a+b+i+j-c)<<'*'<<EL;
			// for(int k = 0;k+i+j<=l;k++){
				
			// 	if(isT(a+i,b+j,c+k))
			// 		res++;
			// }
		}
	}
	CO<<res<<EL;
	
	return 0;
}
