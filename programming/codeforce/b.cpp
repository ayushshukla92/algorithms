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
//---



int main()
{
	unordered_map<int,std::vector<int> > graph;
	VP edges;
	int n,m;
	cin>>n>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		graph[l].PB(r);
		graph[r].PB(l);
		edges.PB({l,r});
	}
	int res=inf;
	for(auto edge : edges){
		int v1 = edge.F;
		int v2 = edge.S;
		unordered_set<int> nbr1;
		for(int p : graph[v1]){
			nbr1.insert(p);
		}
		// cout<<"v1="<<v1<<" v2="<<v2<<EL;
		for(int p : graph[v2]){

			if(nbr1.find(p)!=nbr1.end()){
				int v3 = p;
				int prev = graph[v1].size()+graph[v2].size()+graph[v3].size()-6;
				// cout<<"prev="<<prev<<EL;
				res = min(res,prev);

			}

		}



	}
	if(res!=inf)
		cout<<res<<EL;
	else
		cout<<"-1"<<EL;
	
	return 0;
}
