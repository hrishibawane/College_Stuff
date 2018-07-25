/*
Rucha Kolekar TE-IT-A-3
Roll no:3164062
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
 
int a[3][3], b[3][3], c[3][3];

struct init
{
	int i,j;
};

void *mult(void *arg);
int sum;
int main()
{
	pthread_t id;
	int i,j,res;
	void *status=NULL;
	struct init *data=(struct init*)malloc(sizeof(struct init));
	printf("Enter 1st matrix row wise\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	printf("Enter 2nd matrix row wise\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			data->i=i;
			data->j=j;
			
			pthread_create(&id, NULL, mult, data);
			pthread_join(id, &status);
			res=*((int*)status);
			printf("Sum is %d\n", res);
			c[data->i][data->j]=res;
		}
		printf("\n");
	}
	printf("The product matrix is:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d \t", c[i][j]);
		printf("\n");
	}
}

void *mult(void *arg)
{
	struct init *data1=arg;
	int k;
	sum=0;
	for(k=0;k<3;k++)
		sum+=a[data1->i][k]*b[k][data1->j];
	pthread_exit(&sum);
}
/*
Output
itexam@c05l0326-HP-EliteDesk-800-G1-TWR:~$ cd Desktop/
itexam@c05l0326-HP-EliteDesk-800-G1-TWR:~/Desktop$ gcc thread.c -lpthread
itexam@c05l0326-HP-EliteDesk-800-G1-TWR:~/Desktop$ ./a.out
Enter 1st matrix row wise
1
2
3
1
2
3
1
2
3
Enter 2nd matrix row wise
1
2
3
1
2
3
1
2
3
Sum is 6
Sum is 12
Sum is 18

Sum is 6
Sum is 12
Sum is 18

Sum is 6
Sum is 12
Sum is 18

The product matrix is:
6 	12 	18 	
6 	12 	18 	
6 	12 	18 	
itexam@c05l0326-HP-EliteDesk-800-G1-TWR:~/Desktop$ ^C
itexam@c05l0326-HP-EliteDesk-800-G1-TWR:~/Desktop$ ^C
itexam@c05l0326-HP-EliteDesk-800-G1-TWR:~/Desktop$ 

*/
