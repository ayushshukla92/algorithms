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
	 unordered_set<string> dict = {"geek","geeks","for","each"};

	 string text = "geeksforgeeks";
	 int n = text.length()+1;
	 vector<bool> dp(n,false);

	 dp[0]=true;
	 VI words(n);
	 for(int i = 1;i<=n;i++)
	 {
	 	for(int j = 0;j<i;j++){
		 	// CO<<text.substr(j+1,i-j)<<EL;
	 		if(dp[j] && dict.find(text.substr(j,i-j))!=dict.end()){
	 			dp[i] = true;
	 			words[i] = i - j;
	 			break;
	 		}
	 	}
	 }
	 // for(word : words){

	 // }
	 print(words);
	 if(dp[n]==true) CO<<"yessss"<<EL;
	return 0;
}
