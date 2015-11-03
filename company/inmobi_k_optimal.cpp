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

VI merge(VI &a,VI &b,int r){
	r++;
	std::vector<int> res;
	int k=0;
	int i=0,j=0;
	while(i<a.size() && j<b.size() && k<r){
		k++;
		if(a[i]<b[j])
			res.PB(a[i++]);
		else
			res.PB(b[j++]);
		k++;
	}
	// print(res);
	if(k<r){
		if(j==b.size())
		{
			while(k<r && i<a.size())
			{
				k++;
				res.PB(a[i++]);
			}
		}
		else{
			while(k<r && j<b.size())
			{
				k++;

				res.PB(b[j++]);
			}
		}

	}

	return res;
}

int solve(VVI &v,int ex,int ey,int k)
{
	// k++;
	int res=0;
	int r = v.size();
	int c = v[0].size();
	std::vector<std::vector<int> > prev;
	std::vector<int> ini;
	ini.PB(v[0][0]);
	prev.PB(ini);
	int ps=  v[0][0];
	for (int i = 1; i < c; ++i)
	{
		int csum = ps+v[0][i];
		VI temp;
		temp.push_back(csum);
		prev.PB(temp);
	}

	int vs = v[0][0];
	for (int i = 1; i < r; ++i)
	{
		if(v[i-1][0]!=MAX && v[i][0]!=MAX)
			vs += v[i][0];
		else
			vs = MAX;
		VI left;
		for (int j = 0; j < c; ++j)
		{

			if(j==0)
			{
				left.clear();
				left.PB(vs);
			}
			else{
				VI nleft = merge(left,prev[j],k);
				for (int it = 0; it < nleft.size(); ++it)
				{
					if(v[i][j]!=MAX)
						nleft[it] += v[i][j];
					else
						nleft[it] = MAX;

				}
				prev[j] = nleft;
				left.clear();
				left = nleft;
			}
		}
	}
	if(k>prev[c-1].size() || prev[c-1][k-1] <0 || prev[c-1][k-1] >=MAX){
		printf("not so many paths");
		return -1;
	}
	else{
		cout<<prev[c-1][k-1]<<EL;
		return prev[c-1][k-1];
	}
	return res;
}

int main()
{

	int tCases;
	SD(tCases);
	while(tCases--){
		int n,m;
		SD(m);
		SD(n);
		VVI v(m,std::vector<int>(n,0) );
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				string s;
				cin>>s;
				if(s!="##")
					v[i][j] = stoi(s);
				else
					v[i][j] = MAX;
			}
		}
		int q;
		SD(q);
		while(q--){
			int tx,ty,k;
			SD(tx);SD(ty);SD(k);
			
			solve(v,tx,ty,k);
		}
	}	
	
	return 0;
}
