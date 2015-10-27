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

void functio(VI &v){
	int size = v.size();
    int i = 0;
    int j = size - 1;
    int f = 0;
    while (i < j){
        swap(v[i], v[j]);
        f = f + 1;
        if(f % 2 == 1)
            i++;
        else
            j--;
    }
   }

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		VI v;
		for(int i = 0;i<n;i++)
		{
			int temp;
			cin>>temp;
			v.PB(temp);
		}
		// print(v);
		// while(k--){
		// 	functio(v);
		// 	 v.erase(v.begin()+v.size()/2);
		// 	print(v);
		// }
		VI r;
		int size = n-k;
		if(k%2==0){
			int i = k/2;
			while(size--){
				r.PB(v[i]);
				i++;
			}
		}
		else{
			int j =  n-k/2-1;
			while(size--){
				r.PB(v[j]);
				j--;
			}
		}
		print(r);

	}
	return 0;
}
