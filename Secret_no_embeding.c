#include<stdio.h>
#include<stdlib.h>

#define m 3

//Bit extraction function of a number from a given bit place
int bitExtract(long int num, int p)				              											
{
	int x=1;
	return (((1 << x)-1) & (num >> (p-1)));
}


//main function to embed a secret no. to a given matrix by 2-bit LSB 
int main()
{
	int Arr[m][m] = {{145,189,176}, {224,240,199}, {205,143,236}};
	long int scrt_if;
	int a,bt=18,shift=0,flag=0;
	
	//inputting a no. which is to be embeded
	printf("Enter the secret number you want to embed(0-262143): ");
	scanf("%ld",&scrt_if);	
	
	//printing the matrix in which embeding will process
	printf("\nPrinting the matrix in which the embeding will process:\n");
	for(int i=0 ;i<3; i++)
	{
		 for(int j=0; j<3; j++)
		 {
		 	printf("%d ",Arr[i][j]);
		 }
		 printf("\n");
	}
	
	//time delay
	printf("\nEmbeding is in process...\n");
	for(long long int i=0; i<1000000000; i++);
	
	//changing the matrix elements by 1-bit lsb
	for(int i=0 ;i<3; i++)
	{
		 for(int j=0; j<3; j++)
		 {
		 	shift = 1;
		 	flag = 0;
		 	while(flag<2)
		 	{ 
		 		a = bitExtract(scrt_if,bt);
			 	if(a==1)
			 		Arr[i][j] |= (1<<shift);
			 		
			 	else if(a==0)
			 		Arr[i][j] &= ~(1<<shift);
			 	
			 	flag++;	
			 	bt--;	
			 	shift=0;
			 		
		 	}
		 }
	}
	

	//printing the matrix
	printf("\nPrinting the matrix in which your secret number has been embeded:\n");
	for(int i=0 ;i<3; i++)
	{
		 for(int j=0; j<3; j++)
		 {
		 	printf("%d ",Arr[i][j]);
		 }
		 printf("\n");
	}
	
	printf("\n\n");
	
	return 0;
}
	
	
	
	
