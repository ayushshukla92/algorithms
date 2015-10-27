#include <iostream>
#include <vector>
using namespace std;


struct node{
  int val;
  vector<node*> children;
};
vector<node*> nodes;
void makeTree(int n) {
  for(int i=0;i<n;i++)
  {
    node* p = new node;
    p->val=i+1;
    nodes.push_back(p);
  }
}

int main() {
  int n;
  cin>>n;
  makeTree(n);
  return 0;
}
