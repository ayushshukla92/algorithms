#include <bits/stdc++.h>

using namespace std;

int main()
{
	unordered_map<int, int> m;
	int t;
	cin>>t;
	while(t--)
	{
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		string s;
		int num;
		getline(cin,s);

		string q= s.substr(0,3);
		num  =stoi(s.substr(4));
		cout<<num<<' '<<q;	
		if(q=="add")
				m[num]++;
		else if(q=="del" && m.find(num)!=m.end())
					m[num]--;
	
		else if(q=="cnt"){
				int res=0;
				unordered_map<int,int>::iterator it;
				for(it=m.begin();it!=m.end();it++)
				{
					if(it->first & num == it->first)
						res+=it->second;
				}
				cout<<res<<endl;
			}
	
	}

	return 0;
}