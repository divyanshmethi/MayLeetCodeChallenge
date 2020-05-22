#include<iostream>
#include<unordered_map>
using namespace std;

int majorityElement(int* A,int size)
{
	unordered_map<int,int> m;
	for(int i = 0;i<size;i++)
	{
		m[A[i]]++;
		if(m[A[i]] > size/2)
		{
			return A[i];
		}
	}
	return -1;
}

int main()
{
	int arr1[] = {3,2,3};
	int arr2[] = {2,2,1,1,1,2,2};
	int size1 = sizeof(arr1)/sizeof(int);
	int size2 = sizeof(arr2)/sizeof(int);
	cout<<majorityElement(arr1,size1)<<endl;
	cout<<majorityElement(arr2,size2)<<endl;
}
