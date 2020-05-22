#include<iostream>
#include<math.h>
using namespace std;

int findComplement(int num)
{
	int n = 1;
	while(n < num)
	{
		n = (n<<1) + 1;
	}
	return n^num;
}

int main()
{
	int num = 5;
	cout<<findComplement(num)<<endl;
	num = 1;
	cout<<findComplement(num)<<endl;
}
