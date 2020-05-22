#include<iostream>
#include<vector>
using namespace std;

bool canConstruct(string ransom,string magazine)
{
	if(magazine.length()==0)
	{
		if(ransom.length()==0)
		{
			return true;
		}
		return false;
	}
	if(ransom.length() > magazine.size())
	{
		return false;
	}
	vector<int> magazine_map(26,0);
	for(int i = 0;i<magazine.length();i++)
	{
		magazine_map[magazine[i] - 'a']++;
	}
	for(int i = 0;i<ransom.length();i++)
	{
		if(!magazine_map[ransom[i] - 'a'])
		{
			return false;
		}
		else
		{
			magazine_map[ransom[i] - 'a']--;
		}
	}
	return true;
}

int main()
{
	string ransom = "aa";
	string magazine = "ab";
	cout<<canConstruct(ransom,magazine)<<endl;
	ransom = "a";
	magazine = "b";
	cout<<canConstruct(ransom,magazine)<<endl;
	ransom = "aa";
	magazine = "aab";
	cout<<canConstruct(ransom,magazine)<<endl;
}
