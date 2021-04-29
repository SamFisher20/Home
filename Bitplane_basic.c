#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define m 3

//Bit extraction function of a number from a given bit place
int bitExtract(int num, int p)
{
	int x=1;
	return (((1 << x)-1) & (num >> (p-1)));
}

//function to create a binary form bit extractor
int** bitplanecreate(int A[m][m], int pos)
{
	int** res = malloc(m*m* sizeof(int *));;
	
	for(int i=0; i<3; i++)	
	{
		res[i] = malloc(m* sizeof(int *));
		for(int j=0; j<3; j++)
		{
			res[i][j] = bitExtract(A[i][j],pos);
		}

	}
	
	return res;
}

//main function to create bitplane from a following matrix
int main()
{
	int Arr[m][m] = {{185, 171, 131},{224, 24, 199},{235, 43, 230}};
	int ***Ans;
	
	
	//bit plane matrix(3-d)
	for(int i=0; i<8; i++)
	{
		Ans[i] = bitplanecreate(Arr,i+1);
	}
	
	//printing the binary form of the bitplane
	for(int i=0; i<8; i++)	
	{
		printf("Binary matrix %d:\n",i);
		for(int j=0; j<3; j++)
		{
			for(int k=0; k<3; k++)
			{
				printf("%d   ",Ans[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	printf("\n\n\n");
        
        //printing the decimal form of the bitplane
	for(int i=0; i<8; i++)	
	{
		printf("Decimal matrix %d:\n",i);
		for(int j=0; j<3; j++)
		{
			for(int k=0; k<3; k++)
			{
				if(Ans[i][j][k] == 1)
				{
					int x = pow(2,i);
					printf("%d   ",x);
				}
					
				else if(Ans[i][j][k] == 0)
					printf("0   ");
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n\n");
	return 0;
}
	
	
	
	
