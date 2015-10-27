#include <iostream>
#include <string>
#include <stack>
using namespace std;

short getPref(char c)
{
	switch(c)
	{
	case '+': return 0;
	case '-': return 1;
	case '*': return 2;
	case '/': return 3;
	case '^': return 4;
	}
	return -1;
}
string getPost(string s)
{
	stack<char> ms;
	string r="";
	for(int i=0;i<s.length();i++)
	{
		if(s[i]<='z' && s[i]>='a')
			r+=s[i];
		else
		{
			if(!ms.empty())
			{
				if(s[i]=='(')
				{
					ms.push('(');
				
				}
				else if(s[i]==')')
				{
					while(ms.top()!='(')
					{
						r+=ms.top();
						ms.pop();
					}	
					ms.pop();		
						
				}
				else if(getPref(s[i])<getPref(ms.top()))
				{
					r+=ms.top();
					ms.pop();
					ms.push(s[i]);
				}
				else
					ms.push(s[i]);
				
			}
			else
				ms.push(s[i]);

		}
	}
	while(!ms.empty())
	{
		r+=ms.top();
		ms.pop();
	}
return r;
}

int main()
{
	string s;
	int t;
	cin>>t;
	while(t--){
	cin>>s;
	cout<<getPost(s)<<endl;
}
	return 0;
}