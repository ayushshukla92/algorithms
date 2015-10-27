#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
string getStr(int n)
	{
		stringstream ss;
		ss<<n;
		return ss.str();
	}
void printV(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<"  ";
	}
	cout<<'\n';
}
int countPrime(int n)
{
	vector<int> v;
	for(int i=0;i<n ;i++)
	{
		v.push_back(1);
	}
	for(int i=2;i<n, v[i-1]!=-1;i++)
	{
		// cout<<i<<" ";
		for(int j=2;j*i<n;j++)
		{
			v[i*j]=-1;
			// cout<<i*j<<" ";
		}	
		
	}
	int count = 0;
	for(int i=0;i<n ;i++)
	{
		if(v[i]==1)
		{
			cout<<i<<"  ";
			count++;
		}
	}
	return count-2<0?0:count-2;
}

 int main()
{
	int n;
	cin>>n;
	cout<<countPrime(n+1);
}
