#include <bits/stdc++.h>

using namespace std;
 
 int main()
 {

 	int t,n,m;
 	cin>>t;
 	while(t--)
 	{

 		cin>>n>>m;
 		int index,deg;
 		deg = (m-1)/n;
 			
 		bool isEven = m%2==0?true:false;
 		m = m%n;

 		if(m==0)
 		{
 			index = isEven? (n/2+1):n/2;
 		}
 		else{
 			int diff=0;
 			
 			int p=m/2;
 			index = m%2==0?n-p+1:p+1;
 			if(n%2==1 && deg%2!=0)
 				index = m%2!=0?n-p:p+1;
 		}


	 		cout<<index<<' '<<deg<<endl;	

 	}

 	return 0;
 }