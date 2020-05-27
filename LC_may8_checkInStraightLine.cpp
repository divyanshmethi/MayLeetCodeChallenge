#include<iostream>
#define SIZE 100
using namespace std;

bool checkStraightLine(int coordinates[SIZE][2],int size)
{
	if(size <= 2)
	{
		return true;
	}
	if(coordinates[1][0] - coordinates[0][0] != 0)
	{
		float slope = ((float)(coordinates[1][1] - coordinates[0][1])/((float)(coordinates[1][0] - coordinates[0][0])));
		float c = coordinates[1][1] - slope*coordinates[1][0];
		for(int i = 2;i<size;i++)
		{
			if(c != coordinates[i][1] - slope*coordinates[i][0])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		for(int i =  1;i<size;i++)
		{
			if(coordinates[i][0] != coordinates[0][0])
			{
				return false;
			}
		}
		return true;
	}
}

int main()
{
	int coordinates1[6][2] = {{0,0},{0,1},{0,-1}};
	int coordinates2[6][2] = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
	cout<<checkStraightLine(coordinates1,3)<<endl;
	cout<<checkStraightLine(coordinates2,6)<<endl;
}
