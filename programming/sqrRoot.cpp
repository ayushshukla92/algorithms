#include <iostream>

using namespace std;

double sqrt(double num)
{
	double l,r;
	if(num>1.0)
	{
		l=1.0;
		r=num;
	}
	else
	{
		l=num;
		r=1.0;
	}
	while(r-l>0.01)
	{
		double m=l+(r-l)/2;
		double sq=m*m;
		if(sq>num)
			r=m;
		else
			l=m;
	}
	return l;

}

int main()
{
	cout<<sqrt(15);
}