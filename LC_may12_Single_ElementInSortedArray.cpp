#include<iostream>
using namespace std;

//This is a very common problem and there are a lot of ways to solve this problem
//1. Create a map of numbers and their count, only one number will have count 1, return that number. Time and Space Complexity - O(n)
//2. Iterate through the array and take xor of all the elements, because each number except one number appears twice, the xor will give you that number
//Time Complexity -- O(n) Space Complexity -- O(1)
//3. Because the array is sorted, we should think about binary search. Time complexity -- O(logn) Space Complexity -- O(1) --> Most optimal
//--If you observe the sort array [1,1,2,3,3,4,4,8,8]
//--For all elements before 2, first occurence - even index, second occurence - odd index
//--For all elements after 2, first occurence - odd index, second occurence - even index
//--Thus, if mid is even, and arr[mid] == arr[mid+1] means that we are on the left of 2. Thus, we should move right else left.
//--If mid is odd and arr[mid]==arr[mid-1] means that we are on left. We should move right, else left.


int findNum(int* nums,int size)
{
	int start = 0;
	int mid,end = size-1,res;
	while(start <= end)
	{
		if(start == end)
		{
			res = nums[start];
			break;
		}
		mid = (end + start)/2;
		if(mid%2==0)
		{
			if(nums[mid]==nums[mid+1])
			{
				start = mid + 2;
			}
			else
			{
				end = mid;
			}
		}
		else
		{
			if(nums[mid]==nums[mid-1])
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
	}
	return res;
}

int main()
{
	int nums[] = {1,1,2,3,3,4,4,8,8};
	int size = sizeof(nums)/sizeof(nums[0]);
	cout<<"The number which occurs once is "<<findNum(nums,size)<<endl;
}
