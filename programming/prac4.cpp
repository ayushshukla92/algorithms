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



void visit(std::vector<std::vector<int> > &m,std::vector<std::vector<int> > &seq,int i,int j){
	int n = m[0].size();
	if(seq[i][j]!=-1)
		return;

	VI a = {1,-1,0,0};
	VI b = {0,0,1,-1};

	for (int k = 0; k < 4; ++k)
	{
		int nexti = i+a[k];
		int nextj = j+b[k];
		if(nexti >= 0 && nexti <=n-1 && nextj >=0 && nextj <= n-1 && m[nexti][nextj]== 1 + m[i][j])
		{
			if(seq[nexti][nextj]!=-1){
				seq[i][j] = 1 + seq[nexti][nextj];
			}
			else{
				visit(m,seq,nexti,nextj);
				seq[i][j] = 1 + seq[nexti][nextj];	
			}
		}

	}

}


int main()
{
	int tCases;
	SD(tCases);
	while(tCases--){
		int n;
		SD(n);
		VVI m(n,std::vector<int>(n,0) );
		VVI seq(n,std::vector<int>(n,-1) );
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				SD(m[i][j]);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(seq[i][j]==-1)
					visit(m,seq,i,j);
			}
		}

		printf("------------\n");
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				printf("%d ", 1+ seq[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
