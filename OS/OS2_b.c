#include<unistd.h>
#include<stdio.h>
pid_t cpid;

char  *str[10];
int input[10],temp;
//={"a","4","10","20","30","40"};


int main(){
int n,i,j;
 
printf("Enter Nos to be sorted\n");
scanf("%d",&n);

str[0]="a";

asprintf(&str[1],"%d",n);

 printf("Enter Elements ");

for(i=0;i<n;i++){

     
      scanf("%d",&input[i]);
}

		
	
	for(i=1;i<n;i++)
	{
		temp=input[i];
		j=i-1;
      	while((temp<input[j])&&(j>=0))
      	{
         		input[j+1]=input[j];
         		j=j-1;
      	}
      	input[j+1]=temp;
   }

printf("Sorted lements in ascending order:\n"); 
	for(i=0;i<n;i++)
	{
		printf("%d\n",input[i]);
	}		



for(i=0;i<n;i++){

    asprintf(&str[i+2],"%d",input[i]);

}


cpid= fork();

 if(cpid == 0) 

	execve("a",str,NULL);

   
else 
{

wait();

}
return 0;
}
