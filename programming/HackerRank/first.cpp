#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	unordered_set<int> ms;
	int ans = k;
	while(k--)
	{
		int t;
		cin>>t;
		ms.insert(t);
	}
	for(int i=1;i<=n;i++)
	{
		if(ms.find(i)==ms.end() && ms.find(i+1)==ms.end() && ms.find(i-1)==ms.end())
			ans++;
	}
	cout<<ans;

	return 0;
}