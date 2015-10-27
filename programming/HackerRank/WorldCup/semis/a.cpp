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


#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())

#define MP make_pair
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
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


void visit(unordered_map<int,pair<int,float>> &graph, int s, VB &visited,float &res){
	if(visited[s])
		return;
	visited[s] = true;
	int next = graph[s].F;
	if(visited[next]){
		int start = next;
		int end = s;
		float ans = 1.00;
		// CO<<"start:"<<start<<"end"<<end;
		while(start!=end){
			// CO<<start<<'*';
			ans = ans*graph[start].S;
			start = graph[start].F;
		}
		ans = ans*graph[s].S;
		res  = res + ans;
	}
	else{
		visit(graph,next,visited,res);
	}


}

int main()
{
	int n;
	cin>>n;
	unordered_map<int,pair<int, float>> graph;
	// map<PII,float> prob;
	for (int i = 0; i < n; ++i)
	{
		int s;
		float p;
		cin>>s>>p;
		s--;
		graph[i] = {s,p/100};
		// prob[{i,s}] = p/100;

	}

	VB visited(n,false);
	float res = 0.00;
	for (int i = 0; i < n; ++i)
	{
		if(!visited[i])
			visit(graph,i,visited,res);
	}
	if(graph.size()==1)
		cout<<"0.00";
	else
		printf("%.2f\n",res);

	return 0;
}
