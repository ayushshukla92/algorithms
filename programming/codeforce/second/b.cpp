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
#include <stack>
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


template<typename T> void print_queue(T& q, unordered_map<int,int> m,char c) {
    stack<int> ms;
    while(!q.empty()) {
        ms.push(q.top());
        q.pop();
    }

    while(!ms.empty()){
    	cout<<c<<' ';
    	cout<<ms.top()<<' ';
    	cout<<m[ms.top()];

    	ms.pop();
    	CO<<EL;

    }
    CO<<EL;

}



int main()
{
	int n,s;
	cin>>n>>s;
	VI buy;
	VI sell;
	unordered_map<int,int> bq;
	unordered_map<int,int> sq;
	priority_queue<int> maxF;
	priority_queue<int, std::vector<int>, std::greater<int> > minF;

	int buyC=0,sellC=0;
	while(n--){
		char c;
		int p,q;
		cin>>c;
		if(c=='B'){
			cin>>p>>q;
			buyC++;

			if(buyC>s){
				int temp = minF.top();
				if(temp < p)
				{
					minF.pop();
					minF.push(p);
				}

			}
			else{
				minF.push(p);
			}

			bq[p] = bq[p] + q;
			buy.PB(p);

		}
		else{
			cin>>p>>q;
			sellC++;

			if(sellC>s){
				int temp = maxF.top();
				if(temp > p)
				{
					maxF.pop();
					maxF.push(p);
				}

			}
			else{
				maxF.push(p);
			}


			sq[p] = sq[p] + q;
			sell.PB(p);
		}
	}

	 
	while(!maxF.empty()){
		cout<<'S'<<' ';
		cout<<maxF.top()<<' ';
    	cout<<sq[maxF.top()];

		maxF.pop();
		CO<<EL;
	}
	 print_queue(minF,bq,'B');
	// print_queue(minF);



	return 0;
}
