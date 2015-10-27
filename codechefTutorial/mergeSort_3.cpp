#include <iostream>
#include <vector>
using namespace std;

void printV(vector<int> v)
{
	for(int e:v)
		cout<<e<<' ';
	cout<<endl;
}
void merge(vector<int> &v,int l,int m,int h)
{ 
	// m is the last index of 1st
	int i=l,j=m+1;
	vector<int> t;
	while(i<=m && j<=h)
	{
		if(v[i]<=v[j])
		{
			t.push_back(v[i++]);
		}
		else
			t.push_back(v[j--]);	
	}
	while(i<=m)
		t.push_back(v[i++]);
	while(j<=h)
		t.push_back(v[j--]);
	for(int i=l;i<=h;i++)
		v[i] = t[i-l];

}
void mergeSort(std::vector<int> &v,int l,int h)
{
	if(h>l)
	{
		int m = l+(h-l)/2;
		mergeSort(v,l,m);
		mergeSort(v,m+1,h);
		merge(v,l,m,h);
	}
	
}

int main()
{
	vector<int> v = {4,2,6,8,9,1};
	mergeSort(v,0,v.size()-1);
	printV(v);
	return 0;
}