#include <iostream>

using namespace std;

bool isPalin(string s)
{
	for(int i=0;i<s.length()/2;i++)
	{
		if(s[i]!=s[s.length()-1-i])
			return false;
	}
	return true;
}
string add(string s)
{
	while()
}
string getN(string n)
{
	if(n[0]=='-')
		return "0";
	
	return n;
}
int main()
{	
	int t;
	cin>>t;
	string n;
	while(t--)
	{
		cin>>n;
		cout<<getN(n)<<endl;
	}
	return 0;
}
//6182-6886       51245  6943400006