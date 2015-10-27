#include<iostream>
#include<set>
#include<vector>
using namespace std;
int getMax(int f,int l)
{
	return f>l?f:l;
}
void swap(int &r,int &l)
{
	int t=l;
	l=r;
	r=t;
}
 void rotate(vector<int>& nums, int k) {
 	cout<<(int)nums.size()-k;
 //        for(int i=0;i<nums.size()-k;i++)
	// {
	// 	int r=(i+k)%(nums.size());
	// 	swap(nums[i],nums[r]);
	// }
}


int main()
{	
	vector<int> v;
	v.push_back(-1);
	rotate(v,2);

	return 0;
}
