#include<iostream>
#include<map>
using namespace std;

int findStonesWhichAreJewels(string j,string s)
{
	map<char,int> j_map;
	for(int i = 0;i<j.length();i++)
	{
		j_map[j[i]]++;
	}
	int count = 0;
	for(int i = 0;i<s.length();i++)
	{
		if(j_map[s[i]])
		{
			count++;
		}
	}
	return count;
}

int main()
{
	string jewels = "aA",stones = "aAAbbbb";
	cout<<findStonesWhichAreJewels(jewels,stones)<<endl;
	jewels = "z",stones = "ZZ";
	cout<<findStonesWhichAreJewels(jewels,stones)<<endl;
}
