#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#define LL long long int
using namespace std;


unordered_set<pair <int,int> > visited;
vector< vector<int> > grid;

bool isValid(pair<int,int> p)
{
  int row=grid.size();
  int col=grid[0].size();
  if(p.first>=row || p.second>=col || p.first<0 || p.second<0 || visited[p.first][p.second]!=-1)
    return false;
  return true;
}

void visit(pair<int,int> cur, pair<int,int> end, stack<pair <int,int> curStack)
{
    curStack.push(cur);
    pair<int,int> next = {cur.first+1,cur.second};
    if(isValid(next)) visit(next,end)
}

int main()
{

  return 0;
}
