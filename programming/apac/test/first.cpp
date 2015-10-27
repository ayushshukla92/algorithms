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
#define inf 0x7fffffff

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 

string fn(string s1)
{
	reverse(s1.begin(),s1.end());
	for(int i = 0;i<s1.length();i++)
	{
		if(s1[i]=='0')
			s1[i]='1';
		else
			s1[i]='0';
	}
	return s1;
}

int main() {
	int Tcases;
	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";

		string s;
		s = "0";
		for(int i=0;i<40;i++)
		{
			s = s+"0"+fn(s);
		}
		cout<<s.length();
		int q;
		cin>>q;
		q--;
		cout<<s[q]<<endl;

		
	}

	return 0;
}
