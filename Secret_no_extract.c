#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define m 3

//Bit extraction function of a number from a given bit place
int bitExtract(long int num, int p)				              											
{
	int x=1;
	return (((1 << x)-1) & (num >> (p-1)));
}

//creating and inputting the embeded matrix
int** createmat()
{
	int **A = malloc(m*m* sizeof(int *));
	
	for(int i=0; i<3; i++)
	{
		A[i] = malloc(3* sizeof(int *));
		for(int j=0; j<3;j++)
		{
			printf("A[%d][%d]:",i,j);
			scanf("%d",&A[i][j]);
		}
	}
	return A;
}


//main function to extracting the secret number from embeded matrix 
int main()
{
	int **Arr = createmat();
	
	long int secrtno=0;
	int a,bt=17,shift=0,flag=0;
	
	
	
	
	//extracting and putting to a data variable and also showing the secret number in binary form
	printf("\nBinary form of the secret number:\n");
	for(int i=0 ;i<3; i++)
	{
		 for(int j=0; j<3; j++)
		 {
		 	shift = 2;
		 	flag = 0;
		 	while(flag<2)
		 	{ 
		 		a = bitExtract(Arr[i][j],shift); 
		 		printf("%d",a);
			 	secrtno += a * pow(2,bt);
			 	flag++;
			 	bt--;	
			 	shift=1;
			 		
		 	}
		 }
	}
	
	//printing the secret number in decimal form
	printf("\nThe secret number is :%ld",secrtno);

	
	printf("\n\n");
	
	return 0;
}
	
	
	
	
