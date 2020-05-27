#include<iostream>
#define A 3
#define B 3
using namespace std;

void floodFillUtil(int image[A][B],int size,int oldColor,int sr,int sc,int newColor)
{
	if(sr < 0 || sc < 0 || sr >= size || sc >= size)
	{
		return;
	}
	if(image[sr][sc]==newColor)
	{
		return;
	}
	if(image[sr][sc]!=oldColor)
	{
		return;
	}
	image[sr][sc] = newColor;
	floodFillUtil(image,size,oldColor,sr,sc-1,newColor);
	floodFillUtil(image,size,oldColor,sr-1,sc,newColor);
	floodFillUtil(image,size,oldColor,sr,sc+1,newColor);
	floodFillUtil(image,size,oldColor,sr+1,sc,newColor);
}

void floodFill(int image[A][B],int size,int sr,int sc,int newColor)
{
	int oldColor = image[sr][sc];
	floodFillUtil(image,size,oldColor,sr,sc,newColor);
}

int main()
{
	int image[A][B] = {{1, 1, 1}, 
                      {1, 1, 0}, 
                      {1, 0, 1}
                     };
	int sr = 1, sc = 1,newColor = 2;
	int size = 3;
    floodFill(image,size,sr,sc,newColor);
    for(int i = 0;i<size;i++)
    {
    	for(int j = 0;j<size;j++)
    	{
    		cout<<image[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
