#include<stdio.h>

bool check(int pages[],int p,int k)
{
	for(int i=0;i<p;i++)
	{
		if(pages[i]==k)
		{
			return true;
		}
	}
	return false;
}


//3 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1 -1
int lru(int p)
{
	int pages[p],time[p]={0},hits=0,timevariable=1;
	for(int i=0;i<p;i++)
	{
		pages[i]=-1;
	}
	printf("enter negative number to exit");
	int request,count=0;
	while(true)
	{   for(int j=0;j<p;j++)
	    {
	    	printf("%d ",pages[j]);
		}
		printf("\t");
		printf("enter the request page \t");
		scanf("%d",&request);
		if(request<0)
		{
			break;
		}
		count++;
		if(check(pages,p,request))
		{   printf("hit");
			hits++;
			for(int k=0;k<p;k++)
			{
				if(pages[k]==request)
				{
					time[k]=timevariable;
					break;
				}
			}
			printf("\t");
		}
		
		else
		{   printf("miss");
			int mintime=10000,minindex=10000;
			for(int j=0;j<p;j++)
			{if(mintime>time[j])
			 {
			 	mintime=time[j];
			 	minindex=j;
			 }
			 
			}
			
			pages[minindex]=request;
			time[minindex]=timevariable;
			
		}
		printf("\n");
		timevariable++;
	}
	
	printf("the no of page requests %d\n",count);
	printf("the no of page hits %d\n",hits);
	printf("the no of page faults %d\n",count-hits);
	return hits;
}


int main()
{   printf("enter no of frames");
	int p;
	scanf("%d",&p);
	lru(p);
	
	
	
}


