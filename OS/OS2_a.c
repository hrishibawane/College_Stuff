#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[],char *env[])
{


int i,n,search,first,last,middle;
int b[5];
printf("\n No of Arguments in a are : %d",argc);   
n=atoi(argv[1]);

printf("\n%d",n);


 for(i=0;i<n;i++)
{
	b[i]=atoi(argv[i+2]);


}

printf("Enter element to be searched");
scanf("%d",&search);

first=0;
last=n-1;

middle = (first+last)/2;
 
   while (first <= last) 
{
      if (b[middle] < search)
         first = middle + 1;    
      else if (b[middle] == search) 
	{
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
  }
   if (first > last)
      printf("Not found! %d isn't present in the list.\n", search);


/*

for(i=0;i<n;i++)
{
	printf("b=%d",b[i]);


}*/

return 0;
}

