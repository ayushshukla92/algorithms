#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool hasRedun(string s)
{
	stack<int> ms;
	int secondLastB=-1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(')
			ms.push(i);
		if(s[i]==')')
		{
			if(secondLastB!=-1)
			{
				
			}
			secondLastB=i;
		}


	}
}

int main()
{
	string s;
	cin>>s;
	if(hasRedun(s))
		cout<<"has redundant brackets";
	return 0;
}