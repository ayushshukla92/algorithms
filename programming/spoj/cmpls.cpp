#include <iostream>
#include <vector>

using namespace std;

float getNext(vector<int> v,int x)
{
	float r=0;
	int pro=1;
	for(int i=1;i<=v.size();i++)
	{
		pro=pro*(x-i);
	}
	for(int i=1;i<=v.size();i++)
	{
		float temp=1;
		for(int j=1;j<=v.size();j++)
		{
			if(i!=j)
				temp=temp*(i-j);
		}
		r+=v[i-1]*(pro/(x-i))/temp;

	}
	return r;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			v.push_back(t);
		}
		for(int i=0;i<m;i++)
		{
			cout<<getNext(v,n+i+1)<<endl;
		}
	}
	return 0;
}