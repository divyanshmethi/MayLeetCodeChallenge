#include<iostream>
using namespace std;

class TrieNode
{
	public:
		bool endsHere;
		TrieNode* children[26];
		TrieNode()
		{
			endsHere = false;
			for(int i = 0;i<26;i++)
			{
				children[i] = NULL;
			}
		}
};

class Trie
{
	public:
		TrieNode* root;
		Trie()
		{
			root = new TrieNode();
		}
		void insert(string word)
		{
			TrieNode* temp = root;
			for(int i = 0;i<word.length();i++)
			{
				int j = word[i] - 'a';
				if(!temp->children[j])
				{
					temp->children[j] = new TrieNode();
				}
				temp = temp->children[j];
			}
			temp->endsHere = true;
		}
		bool search(string word)
		{
			TrieNode* temp = root;
			for(int i = 0;i<word.length();i++)
			{
				int j = word[i] - 'a';
				if(temp->children[j])
				{
					temp = temp->children[j];
				}
				else
				{
					return false;
				}
			}
			return temp->endsHere;
		}
		bool startsWith(string prefix)
		{
			TrieNode* temp = root;
			for(int i = 0;i<prefix.length();i++)
			{
            	int j = prefix[i] - 'a';
				if(temp->children[i])
				{
					temp = temp->children[i];
				}
				else
				{
					return false;
				}
			}
			return true;
		}
};

int main()
{
	Trie* trie = new Trie();
	trie->insert("apple");
	cout<<trie->search("apple")<<endl;
	cout<<trie->search("app")<<endl;
	cout<<trie->startsWith("app")<<endl;
	trie->insert("app");   
	cout<<trie->search("app")<<endl;
}
