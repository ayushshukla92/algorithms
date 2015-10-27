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

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 

std::vector< pair<int,int> > nextMoves(pair<int,int> cur){
	vector< pair<int,int> > res;
	vector< pair<int,int> > temp = {  {-2,-1},{-2,1},{2,-1},{2,1},
									{-1,-2},{-1,2},{1,-2},{1,2}
										};
	for(auto t : temp){
		pair<int,int> r = {t.first+cur.first, t.second+cur.second};
		if(r.first >=1 && r.first<=8 && r.second >=1 && r.second<=8)
			res.push_back(r);
	}
	return res;
}
void printP(PII p){
	cout<<p.first<<' '<<p.second<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		pair<int,int> start = {s1[0]-'a'+1, s1[1]-'1'+1};
		pair<int,int> dest = {s2[0]-'a'+1, s2[1]-'1'+1};
		map< pair<int,int>, int > step;
		set<pair<int,int> > visited;
		queue< pair<int,int> > mq;
		mq.push(start);
		visited.insert(start);
		step[start] = 0;
		int moves = 0;
		int flag = 0;
		while(!mq.empty())
		{
			// int wq;
			// cin>>wq;
			PII cur = mq.front();
			mq.pop();
			for(PII child : nextMoves(cur) )
			{
				if(visited.find(child)!=visited.end())
					continue;
				step[child] = step[cur]+1;
				if(child == dest)
				{
					flag = 1;
					moves = step[cur] + 1;
					break;
				}
				mq.push(child);
			}
			if(flag==1) break;
		}		
		cout<<moves<<endl;
	}
	
	return 0;
}
