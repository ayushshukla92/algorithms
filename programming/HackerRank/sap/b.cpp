#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define MAXN 100009
#define MAX MAXN*6
#define inf 10000000
#define sd(n) scanf("%d",&n)
typedef long long ll;

double arr[MAXN];  //original array
double tree[MAX];    //nodes of the segment tree
//tree[0] stores the maximum value
//tree[1] stores how many times maximum values occurs

void build_tree(int node, int a, int b)
{
    if(a > b) return;
    if(a == b) {
        tree[node] = arr[a];
        return;
    }
    build_tree(node*2, a, (a+b)/2);     //build left
    build_tree(node*2+1, 1+(a+b)/2, b); //build right

    tree[node] = tree[node*2] + tree[node*2+1] ;

}

double query_tree(int node, int a, int b, int i, int j)
{
    if(a > b || a > j || b < i)
        return 0.0;
    if(a==b)
        return tree[node];

    if(a >= i && b <= j)
        return tree[node];

    double q1 = query_tree(node*2, a, (a+b)/2,i,j);
    double q2 = query_tree(node*2+1, 1 + (a+b)/2 , b,i,j);
    // double q2 = tree[node*2+1];
    return q1+q2;
}
int main()
{
    int n,fl,l,r,x,m;
    sd(n);
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];	
    build_tree(1, 0, n-1);
    sd(m);
    while(m--)
    {
        sd(l),sd(r);
        l--,r--;
        double my=query_tree(1,0,n-1,l,r);
        printf("%.6lf\n",my/(r-l+1) );
    }
    return 0;
}