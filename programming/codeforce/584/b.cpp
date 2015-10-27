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
#define in(a,b)                     ( (b).find(a) != (b).end())

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
char get(char a, char b){
	if(a!='x' && b!='x')
		return 'x';
	if(a!='y' && b!='y')
		return 'y';
	if(a!='z' && b!='z')
		return 'z';
}

int main()
{
	int n,t;
	SD(n);	
	SD(t);
	string s1,s2,s3;
	cin>>s1>>s2;
	s3 = s2;
	int c = 0;
	int same = n-t;
	bool flag = false;
	int chng = 0;
	for (int i = 0; i < n; ++i)
	{
		//change t chars in s3 st matches n-t chars in s1
		// if(same<0)
		// {
		// 	flag = true;
		// 	break;
		// }
		// if(chng==t && same==0)
		// 	break;
		if(s1[i]==s2[i]){
			c++;
			// same--;
		}
		// else if(same==0)
		// {
		// 	s3[i] = get(s1[i],s2[i]);
		// 	chng++;
		// }
		// else{
		// 	s3[i] = s1[i];
		// 	chng++;
		// 	same--;
		// }

	}
	if(c==0){
		for (int i = 0; i < n; ++i)
		{
			if(same>0){
				s3[i] = s1[i];
				t--;
				same--;
			}
			else if(t>0){
				s3[i] = get(s1[i],s2[i]); 
			}
		}
		if(t<0)
			CO<<"-1";
		else
			CO<<s3;
		
	}
	else if(same > c)
	{
		same = same-c;
		for (int i = 0; i < n; ++i)
		{
			if(s1[i]==s2[i])
				continue;
			if(same>0){
				s3[i] = s2[i];
				t--;
				same--;
			}
			else if(t>0){
				s3[i] = get(s1[i],s2[i]); 
			}
		}
		if(t<0)
			CO<<"-1";
		else
			CO<<s3;
	}
	else{  //c>same
		if(t>c)
			CO<<"-1";
		else{
			for (int i = 0; i < n; ++i)
				{
				if(s1[i]==s2[i] && t!=c){
					s3[i] = get(s1[i],s2[i]); 
					t--;
				}
				}
			}
			CO<<s3;

	}


	

	return 0;
}
