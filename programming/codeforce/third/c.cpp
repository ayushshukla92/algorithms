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
typedef vector <bool> VB;
typedef vector < pair<int,int> > VP;
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
#define MAX_NUM 2000
// array will be initialized to 0 being global
int primes[MAX_NUM];
 
void gen_sieve_primes(void)
{
    for (int p = 2; p < MAX_NUM; p++) // for all elements in array
    {
        if (primes[p] == 0) // it is not multiple of any other prime
            primes[p] = 1; // mark it as prime
 
        // mark all multiples of prime selected above as non primes
        int c = 2;
        int mul = p * c;
        for (; mul < MAX_NUM;)
        {
            primes[mul] = -1;
            c++;
            mul = p * c;
        }
    }
}
 
VI genP(){
	VI res;
	gen_sieve_primes();
	for (int i = 0; i < MAX_NUM; ++i)
	{
		if(primes[i] == 1)
			res.PB(i);
	}
	return res;
} 

int main()
{
	VI prime = genP();
	// if(2%2==0) CO<<"han";
	int n;
	cin>>n;

	int i = 1;    //check for i=0
	if(n==1){
		CO<<"0"<<EL;
	}
	else{
		int j = 0;
		VI res;
		int tot = 0;

		int curP = prime[j];
		// CO<<curP<<'*'<<EL;
		while(curP<=n){

	
			int c = curP;
			if(n%curP==0){
				while(true){
					if(curP<=n) res.PB(curP);
					// CO<<m;

					// m = m/curP;
					if( n%curP!=0 )
					{
						// res.pop_back();
						break;
					}
					curP = curP*c;
					// curP = prev;
					// CO<<"m="<<m<<"cp="<<curP<<EL;
				}
			}

			else{
				res.PB(curP);
			}


			j++;
			curP = prime[j];
		}
		cout<<res.size()<<EL;
		print(res);

	}
	return 0;
}
