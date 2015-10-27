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

int main()
{
	vector<int> v = {2,2,2,2,4,4};
	
	std::vector<int> mod;
	int s = 1;
	while(s<v.size()){
		if(v[s]==v[s-1]){
			mod.push_back(v[s]*2);
			s = s+2;
		}
		else{
			mod.push_back(v[s-1]);
			mod.push_back(v[s]);
			s++;
		}
	}
	for(int j = 0;j<v.size();j++){
		if(j<mod.size())
			v[j] = mod[j];
		else
			v[j] = 0;
	}

	print(v);
	return 0;
}
