#include<iostream>
using namespace std;

//The idea here is to remove that number from the string whose immediate next number is smaller than itself.

string removekDigits(string nums,int k)
{
	if(nums.length()==0 || k==0)
	{
		return nums;
	}
	if(k==nums.length())
	{
		return "0";
	}
	int j;
	//We will remove the element 1 by 1
	for(int i = 0;i<k;i++)
	{
		j = 0;
		//j -- > for iteration and will store the index of number that should be removed from the string
		//We can iterate maximum to nums.size() - 1 because we are comparing j and j+1 indices
		while(j < nums.size() - 1)
		{
			if(nums[j] > nums[j+1])
			{
				break;
			}
			j++;
		}
		//There are two cases here
		//1. If we actually come out of the while loop with a break in that case we have found a nums[j] such that nums[j] > nums[j+1], so we need to remove nums[j]
		//2. We come out of the loop because j = nums.size() - 1, in that case there is no element nums[j] such that nums[j] > nums[j+1]
		//In that case the last element is the biggest element and the element that should be removed
		//The below code handles both of these cases
		//To remove character at index=j, we can use the substr method
		nums = nums.substr(0,j) + nums.substr(j+1);
		//Now there is one more edge case where there can be trailing zeroes after removing a number. For example, 1031 --> 1 > 0 so remove 1 --> 031
		//In this case 0 in the front should be discarded --> 31 and there can be more than 1 zeroes for example if number is 100000031 all 0's need to go
		int p = 0;
		while(nums[p]=='0')
		{
			p++;
		}
		//p will store the first index where a non-zero character occurs
		//Now p can be equal to nums.length() in case like 1000000000, so when you remove 1, you are left with all zeroes so in that case we should return "0"
		//In all the other cases, we can return subtring starting at p
		if(p==nums.length())
		{
			nums = "0";
		}
		else
		{
			nums = nums.substr(p);
		}
	}
	return nums;
}

int main()
{
	string num = "1432219";
	int k = 3;
	cout<<removekDigits(num,k)<<endl;
}
