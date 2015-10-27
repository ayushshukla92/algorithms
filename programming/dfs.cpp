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
	int tCases;
	SD(tCases);
	while(tCases--){
		int n;
		SD(n);
		if(n==1)
			printf("1\n");
		else{
			queue<PII> mq;
			mq.push({1,1});
			int res = 0;
			unordered_set<int> ms;
			ms.insert(1);

			while(!mq.empty()){

				PII cur = mq.front();
				mq.pop();
				int num = cur.F;
				int occ = cur.S;
				string s = to_string(num);
				reverse(ALL(s));
				int next2 = stoi(s);
				if(num+1==n || next2==n ){
					printf("found : %d\n", occ+1);
					break;
				}
				if(!IN(num+1,ms)){
					ms.insert(num+1);
					mq.push({num+1,occ+1});
				}
				if(!IN(next2,ms)){
					ms.insert(next2);
					mq.push({next2,occ+1});
				}

				

			}

			// printf("%d\n", );

		}	

	}
	
	return 0;
}
