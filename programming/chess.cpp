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

int rook(VVC &m,int r,int c)
{
	int res = 0;
	for (int i = c+1; i < 8; ++i)
	{
		if( m[r][i]!='.' )
		{
			res++;
			break;
		}
	}
	for (int i = c-1; i >= 0; --i)
	{
		if(m[r][i]!='.')
		{
			res++;
			break;
		}
	}

	for (int i = r+1; i < 8; ++i)
	{
		if( m[i][c]!='.' )
		{
			res++;
			break;
		}
	}
	for (int i = r-1; i >= 0; --i)
	{
		if(m[i][c]!='.')
		{
			res++;
			break;
		}
	}
	return res;
}

int bishop(VVC &m, int r,int c){
	int res = 0;
	int i = r+1,j=c+1;
	while(i<8 && j<8){
		if(m[i][j]!='.'){
			res++;
			break;
		}
		i++;j++;
	}

	i = r-1,j=c+1;
	while(i>=0 && j<8){
		if(m[i][j]!='.'){
			res++;
			break;
		}
		i--;j++;
	}

	i = r+1,j=c-1;
	while(i<8 && j>=0){
		if(m[i][j]!='.'){
			res++;
			break;
		}
		i++;j--;
	}

	i = r-1,j=c-1;
	while(i>=0 && j>=0){
		if(m[i][j]!='.'){
			res++;
			break;
		}
		i--;j--;
	}
	return res;
}

int queen(VVC &m, int r,int c){
	return bishop(m,r,c) + rook(m,r,c); 
}

int pawn(VVC &m,int r,int c){
	int res = 0;
	if(r+1 <8 && c+1 < 8 && m[r+1][c+1]!='.')
	{
		res++;
	}

	if(r+1 <8 && c-1 >=0 && m[r+1][c-1]!='.')
	{
		res++;
	}

	if(r-1 >=0 && c+1 < 8 && m[r-1][c+1]!='.')
	{
		res++;
	}

	if(r-1 >=0 && c-1 >=0 && m[r-1][c-1]!='.')
	{
		res++;
	}

	return res;
}
int king(VVC &m,int r,int c){
	int res = 0;
	if(r+1 <8 && m[r+1][c]!='.')
	{
		res++;
	}

	if(r-1 >=0 && m[r-1][c]!='.')
	{
		res++;
	}

	if( c+1 < 8 && m[r][c+1]!='.')
	{
		res++;
	}

	if( c-1 >=0 && m[r][c-1]!='.')
	{
		res++;
	}
	return res + pawn(m,r,c);
}
int knight(VVC &m,int r,int c){
	int res = 0;
	VI a = {-1,-2,-2,-1,1,2,2,1};
	VI b = {-2,-1,1,2,2,1,-1,-2};

	for (int i = 0; i < 8; ++i)
	{
		int cr = r+a[i],cc=  c+b[i];
		if(cr>=0 && cr<8 &&cc>=0 && cc<8 && m[cr][cc]!='.')
			res++;
	}
	return res;

}

int main()
{
	int tCases;
	SD(tCases);
	while(tCases--){
		// printf("Case : %d\n", );
		int n;
		SD(n);
		VVC m(8,std::vector<char>(8,'.') );
		std::vector<string> v;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			v.PB(s);
			int r = s[1]-'1';
			int c = s[0]-'A';
			m[r][c] = s[3];

		}
		int res = 0;

		for(string s : v){
			int r = s[1]-'1';
			int c = s[0]-'A';
			switch(s[3])
			{
				case 'K':
					// printf("king %d\n",king(m,r,c) );
					res += king(m,r,c);
					break;
				case 'Q':
					// printf("quuen %d\n",queen(m,r,c) );

					res += queen(m,r,c);
					break;
				case 'R':
					res += rook(m,r,c);
					break;
				case 'B':
					res += bishop(m,r,c);
					break;
				case 'N':
					res += knight(m,r,c);
					break;
				case 'P':
					// printf("pawn %d\n",pawn(m,r,c) );

				res += pawn(m,r,c);
					break;
			}
		}

		printf("%d\n", res);

	}
	
	return 0;
}
