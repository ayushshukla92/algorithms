#include <iostream> 
#include <string>
#include <vector>
using namespace std;

struct trieNode{
	bool isLeaf = false;
	trieNode *children[26];
};
trieNode *root;

void initTrie(vector<string> &dict)
{
	root = new trieNode;
	for(string s : dict)
	{
		trieNode * cur = root;
		for(char c : s)
		{
			int num = c-'a';

			if(cur->children[num]==NULL)
			{
				trieNode *tn = new trieNode;
				cur->children[num] = tn;
			}
			cur = cur->children[num];

		}
		cur->isLeaf = true;
	}

}

bool isThere(string s)
{
	trieNode *cur = root;
	for(char c: s)
	{
		int num = c-'a';
		if(cur->children[num]==NULL)
			return false;
		cur = cur->children[num];

	}
	return cur->isLeaf;
}
int main()
{
	vector<string> dict = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	initTrie(dict);
	if(isThere("ther"))
		cout<<"exists!!";
	
	return 0;
}