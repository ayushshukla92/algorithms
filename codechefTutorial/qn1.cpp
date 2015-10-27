#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
 int arr[100001];
int c,n;
bool fun(int x)
{
	int cowPlaced = 1;
	int lastPos = arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]-lastPos>=x)
		{
			cowPlaced++;
			lastPos = arr[i];
			if(cowPlaced==c)
				return true;
		}
	}
	return false;
}
int binSearch()
{
	int l=0,h=arr[n-1],res=-1;
	while(h>=l)
	{
		int m = l+(h-l)/2;
		if(fun(m))
			{
				res = m; l=m+1;
			}
			else
				h=m-1;
	}
	return res;
}
     
int main(){
    int t;
    scanf("%d",&t);
    
    while(t--){
        scanf("%d %d",&n,&c);
        
        for(int i=0;i<n;i++)
          scanf("%d",&arr[i]);
          sort(arr,arr+n);
        printf("%d\n",binSearch());
     }
 }