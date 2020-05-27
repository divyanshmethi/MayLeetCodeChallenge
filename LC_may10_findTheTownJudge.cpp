#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//The code for this problem can be divided into two parts which are the two constraints of the problem
//1. Judge should trust no one
//2. Everyone else should trust the judge
//a.We will first find if there is any person who trusts no one
//b.If there is not such person or if there are more than 1 person who trust no one then we should return -1
//c.If there is only 1 such person who does not trust any one, then we should find if he is trusted by everyone
//d.If yes --> return the index, else return -1

int findJudge(int n,int size,int trust[][2])
{
	//Step 1. Find the person who trust no one, for this we will create a map, map will have entry for all persons which comes
	// at index 0 of the trust relation
	map<int,int> m;
	for(int i = 0;i<size;i++)
	{
		m[trust[i][0]]++;
	}
	int possibleJudge = -1,c = 0;
	//Step 2. Check if there are more than 1 such persons or there is no such person
	for(int i = 1;i<=n;i++)
	{
		if(m.find(i)==m.end())
		{
			possibleJudge = i;
			c++;
		}
	}
	//Step 3. If true return -1
	if(c > 1 || possibleJudge == -1)
	{
		return -1;
	}
	int count = 0;
	//Step 4. Check if the possibleJudge is trusted by everyone
	for(int i = 0;i<size;i++)
	{
		if(trust[i][1] == possibleJudge)
		{
			count++;
		}
	}
	if(count==n-1)
	{
		return possibleJudge;
	}
	return -1;
}

//Note We can also use a simple vector in place of map to store the count, the implementation will be changed to this in that case

int findJudge(int n,int size,int trust[][2])
{
	vector<int> v(n+1,0);
	for(int i = 0;i<size;i++)
	{
		v[trust[i][0]] = 1;
	}
	int possibleJudge = -1,c = 0;
	for(int i = 1;i<=n;i++)
	{
		if(v[i]==0)
		{
			possibleJudge = i;
			c++;
		}
	}
	if(c > 1 || possibleJudge == -1)
	{
		return -1;
	}
	int count = 0;
	for(int i = 0;i<size;i++)
	{
		if(trust[i][1] == possibleJudge)
		{
			count++;
		}
	}
	if(count==n-1)
	{
		return possibleJudge;
	}
	return -1;
}

int main()
{
	int trust[][2] = {
		{1,3},
		{1,4},
		{2,3},
		{2,4},
		{4,3}
	};
	int n = 4;
	cout<<"The judge is "<<findJudge(n,5,trust)<<endl;
}
