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

#define MAX 100009

int main()
{

	int n1,n2;
	cin>>n1>>n2;
	VI a(n1);
	VI b(n2);

	int k,m;
	cin>>k>>m;

	for(int i= 0;i<n1;i++){
		cin>>a[i];
	}

	for(int i= 0;i<n2;i++)
	{
		cin>>b[i];
	}


	if(b[n2-m] > a[k-1]){
		cout<<"YES"<<EL;
	}
	else{
		cout<<"NO"<<EL;
	}

	return 0;
}
