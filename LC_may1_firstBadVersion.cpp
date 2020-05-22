#include<iostream>
using namespace std;

bool isBadVersion(int version)
{
	if(version >= 3)
	{
		return true;
	}
	return false;
}

int findFirstBad(int n)
{
	if(n==0)
	{
		return -1;
	}
	int start = 0;
	int mid,end = n;
	while(start <= end)
	{
		mid = (start + end)/2;
		if(mid >= 1 && isBadVersion(mid) && !isBadVersion(mid-1))
		{
			return mid;
		}
		else if(mid >= 1 && isBadVersion(mid) && isBadVersion(mid-1))
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;
}

int main()
{
	cout<<findFirstBad(14)<<endl;
}
