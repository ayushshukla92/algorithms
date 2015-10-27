#include <iostream>
#include <string>
#define p 101
#define base  256
using namespace std;
int highP;

int hasLcs(string text, string pat, int l)
{	
	int patHash=0,textHash=0;
	int textL = text.length();
	int patL = pat.length();
	highP=1;
	for(int i=0;i<l;i++)
	{
		highP=(highP*base)%p;
	}
	
	for(int i=0;i<l;i++)
	{
		patHash =  (patHash*base  + pat[i])%p;
		textHash =  (textHash*base  + text[i])%p;
	}
	for(int i=0 ; i<textL-l+1;i++)
	{
		for(int j=0;j<patL-l+1;j++){
			if(patHash==textHash)
			{
				if(text.substr(i,l)==pat.substr(j,l))
					return j;
			}
			if(j<patL){
				patHash = (base*(patHash-highP*pat[j])+pat[j+l])%p;
				if(patHash<0)
					patHash = patHash+p;
				}
		}

		if(i<textL){
				textHash = (base*(textHash-highP*text[i])+text[i+l])%p;
				if(textHash<0)
					textHash = textHash+p ;
			}
	}
	return -1;
}

string binSearch(string text,string pat)
{
	int l=0,r=pat.length();
	int res=-1,ind=-1;
	while(l<=r)
	{
		int m = l+(r-l)/2;
		int temp;
		if((temp = hasLcs(text,pat,m))!=-1)
		{
			res=m;
			ind =temp;                //change here
			l=m+1;
		}
		else
			r=m-1;
	}
	if(res!=-1)
		return pat.substr(ind,res);
	else
		return "not found";



}

int main(int argc, char const *argv[])
{
	string text="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string pat="aaaaaaaaaaaaaaaaaaaaaa";
	cout<<binSearch(text,pat);
	return 0;
}
