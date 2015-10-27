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

void print2d(vector< std::vector<char> > &board){
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			cout<<board[i][j]<<' ';
		}
		CO<<EL;
	}
}

void markD(vector< std::vector<char> > &board, int i, int j){
	int rows = board.size();
	int cols = board[0].size();
	int curI = i, curJ = j;
	while(i<rows && j>=0){
		if(board[i][j] == '*')
			break;
		board[i][j] = 'd';
		i++;
		j--;
	}

	i = curI;
	j = curJ;
	while(i<rows && j<cols){
		if(board[i][j] == '*')
			break;
		board[i][j] = 'd';
		i++;
		j++;
	}
}
void unMarkD(vector< std::vector<char> > &board, int i, int j){
	int rows = board.size();
	int cols = board[0].size();
	int curI = i, curJ = j;
	while(i<rows && j>=0 && board[i][j] == 'd'){

		board[i][j] = '.';
		i++;
		j--;
	}

	i = curI;
	j = curJ;
	i++; j++;
	while(i<rows && j<cols && board[i][j] == 'd'){

		board[i][j] = '.';
		i++;
		j++;
	}
}

void solve(vector< std::vector<char> > &board,int n,int &res){
	int rows = board.size();
	int cols = board[0].size();
	if(n==rows-1){
		for (int j = 0; j < cols; ++j)
		{
			if(board[n][j]!='*' && board[n][j]!='d'){
				res++;				
			}
		}
		return;
	}

	for (int j = 0; j < cols; ++j)
	{
		if(board[n][j]!='*' && board[n][j]!='d'){
			markD(board,n,j);

			solve(board,n+1,res);

			unMarkD(board,n,j);
		}
	}
}


int main()
{
	int n,m;
	cin>>n>>m;

	std::vector< std::vector<char> > board(n,vector<char>(m,'.'));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char c;
			cin>>c;
			if(c=='*')
				board[i][j] = '*';

		}
	}
	//print2d(board);
	int res = 0;
	solve(board,0,res);
	CO<<res;

	return 0;
}
