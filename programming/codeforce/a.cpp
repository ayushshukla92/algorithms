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

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

bool allGud(VI v,int d){
	for(int i=1;i<v.size();i++){
		if(v[i]>=d)
			return false;
	}
	return true;
}

int solve(VI &v,int d){
	int res=0,i=0;
	int sum=0,num=0;
	while(true){
		sum+=v[i];
		num+=1;
		int inc = (sum+d)/(num+1) + 1;
		if(i+1<v.size()){
			if((sum-(inc-d))/num >= v[i+1]){
				return inc-d;
			}
			else{
				i++;
			}
		}
		else{
			return inc-d;
		}

	}
}

int main()
{
	int n;
	cin>>n;
	VI v;
	int d;
	cin>>d;
	for(int i=1;i<n;i++){
		int temp;
		cin>>temp;
		v.PB(temp);
	}
	int res=0;
	if(d > *max_element(v.begin(),v.end()))
		cout<<0<<endl;
	else{
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		cout<<solve(v,d)<<EL;
	}


	return 0;
}
