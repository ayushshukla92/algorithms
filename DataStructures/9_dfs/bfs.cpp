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
LL n;
string ans;

void bfs()
{   
  string str,first,second;
  str+='1'; // number will start with '1' always
  if(n==1)
  {
    ans=str;
    return;
  }
  queue<pair<string,LL> >q; // pair of STRING(number) and long long int
                            // (to hold remainder till now)
  pair<string,LL>p;
  p=make_pair(str,1);
  q.push(p);
  LL rem,val,temp;
  while(q.empty()==0)
  {
    p=q.front();
    q.pop();
    str=p.first;
    cout<<"string: "<<p.first<<endl;
    val=p.second;   
    cout<<"value - "<<val<<endl;
    if(val==0)  // remainder is zero means this is number 
    {
      ans=str;
      return ;
    }
    // adding 1 to present number       
    temp=val*10+1; 
    rem=(temp)%n;
    string firstone=str+'1';
    p=make_pair(firstone,rem);
    q.push(p);
    // adding 0 to present number       
    temp=val*10+0;
    rem=(temp)%n;
    string secondone=str+'0';
    p=make_pair(secondone,rem); 
    q.push(p);  
  }
}

int main()
{
  int t,i;
  scanf("%d",&t);
  while(t--)
  {   
    scanf("%lld",&n);       
    bfs();
    for(i=0;i<ans.size();i++)
    {
      printf("%c",ans[i]);        
    }
    printf("\n");
  }
  return 0;
}