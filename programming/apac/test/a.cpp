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
typedef long long LL;
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
using namespace std;

LL d[1000000];//Distance function

list<pair<int,int> > *graph;

void dijkstra(int root) {

set<pair<int,int> > pq;
/* A set helps insertion and extraction operations in logarithmic time. This set maintains (distance,vertex number) pair sorted on basis of distance*/

set<pair<int,int> > ::iterator it;

int u,v,wt;

list<pair<int,int> > :: iterator i;




d[root]=0;

pq.insert(pair<int,int>(0,root));

while(pq.size()!=0)
{
    it=pq.begin();

    u=it->second;

    pq.erase(it);

    for(i=graph[u].begin(); i!=graph[u].end(); i++)
    {
        v=i->first;
        wt=i->second;
        //Relax u-v edge with weight wt below:
        if(d[v]>d[u]+wt)
        {
            if(d[v]!=1e8)
            {
                pq.erase(pq.find(pair<int,int>(d[v],v)));
            }
            d[v]=d[u]+wt;
            pq.insert(pair<int,int>(d[v],v));
        }
//Relax ends

}

}
}

void addedge(int src,int des,int wt) { pair<int,int> x;

x.first=des;
x.second=wt;

graph[src].push_front(x);
//here we are consering directed graph so. /* include in case of undirected graph

x.first=src;

x.second=wt;

graph[des].push_front(x);
}

int main() {

int i;

int t;

cin>>t;

while(t--){

int v,e,src,des,wt;

cin>>v>>e;

//Initialise all d[v] to a large number
for(i=0; i<=v; i++)
{
    d[i]=1e8;
/*Do not use INF because mathematical operations performed on it will cause overflow
in some cases you may need higher values like 1e18 etc. as per constraints
*/

}

graph=new list<pair<int,int> >[v+1];

for(i=0; i<e; i++)
{
    cin>>src>>des>>wt;
    addedge(src,des,wt);
}
int x,y;

cin>>x>>y;

dijkstra(x);

if(d[y]!=1e8)
cout<<d[y]<<endl;
else
    cout<<"NO"<<endl;
}
return 0;
}