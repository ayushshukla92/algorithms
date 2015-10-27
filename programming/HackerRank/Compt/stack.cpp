#include <bits/stdc++.h>
using namespace std;

#define inf 0x7fffffff

void makeC(unordered_map<string,int> &m, string r, stack<char> is, stack<char> ms)
{
	if(is.empty() && ms.empty()){
		m[r]++;
		return;
	}
	if(is.empty())
	{
		r+=ms.top();
		ms.pop();
		makeC(m,r,is,ms);
		return;
	}
	if(ms.empty()){
		ms.push(is.top());
		is.pop();
		makeC(m,r,is,ms);
		return;
	}
	string t = r;
	char t1 = ms.top();
	r =r + ms.top();
	ms.pop();
	makeC(m,r,is,ms);


	char c = is.top();
	is.pop();

	ms.push(t1);
	ms.push(c);
	makeC(m,t,is,ms);


}

int main()
{
	unordered_map<string,int> m;
	stack<char> ms,is;
	string s,r="";
	cin>>s;
	for(char c : s)
	{
		is.push(c);
	}

	makeC(m,r,is,ms);

	unordered_map<string,int>::iterator it;
	// for(it=m.begin(); it!=m.end();it++)
	// 	cout<<it->first<<' '<<it->second<<endl;
	reverse(s.begin(),s.end());
	cout<<m[s]<<' '<<m.size();
	return 0;
}