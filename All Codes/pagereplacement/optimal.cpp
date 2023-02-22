#include<stdio.h>

bool hit(int pages[],int frames,int f)
{
	for(int i=0;i<frames;i++)
	{
		if(pages[i]==f)
		{
			return true;
		}
	}
	return false;
}
//findindex(refstr,i,frames,pages)
int findindex(int refstr[],int i,int n,int frames,int pages[]  )
{ int neg=0;
  int index[frames];
  for(int j=0;j<frames;j++)
  {
  	if (pages[j]==-1)
  	{
  		return j;
	  }
  }
  for(int j=0;j<frames;j++)
  { int flag=0;
  	index[j]=-1;
   
  for(int k=i+1;k<n;k++)
  {  if(refstr[k]==pages[j])
     {
     	index[j]=k;
     	flag=1;
     	break;
	 }
  	
	  }
	if(flag==0)
	{
		neg++;
		}	
	}
	
	if(neg<2)
	{
		int max=0;
		int returnindex;
		for(int k=0;k<frames;k++)
		{ if(index[k]==-1)
		      return k;
			
		  else
		  {
		  	if(max<index[k])
		  	{
		  		max=index[k];
		  		returnindex=k;
			  }
		  }
		}
		return returnindex;
		
	}
	
	else
	{
		for(int j=0;j<i;j++)
		{
			for(int k=0;j<frames;k++)
			{
				if(refstr[j]==pages[k])
				{
					return k;
				}
			}
		}
	}
}

int optimal(int n,int refstr[],int frames)
{
	int pages[frames];
	int hitcount=0;
	for(int i=0;i<frames;i++)
	{
		pages[i]=-1;
	}
	for(int i=0;i<n;i++)
	{   printf("\n");
		for(int j=0;j<frames;j++)
		{
			printf("%d ",pages[j]);
		}
		printf("\t");
		if(hit(pages,frames,refstr[i]))
		{  printf(" hit  %d \t",refstr[i]);
			hitcount++;
		}
		else
		{   printf(" miss  %d \t",refstr[i]);
			int index=findindex(refstr,i,n,frames,pages);
			pages[index]=refstr[i];
		}
		
	}
	printf("the no of page requests %d\n",n);
	printf("the no of page hits %d\n",hitcount);
	printf("the no of page faults %d\n",n-hitcount);
	return hitcount;
	
}


int main()
{
	int n;
	printf("enter no of page requests");
	scanf("%d",&n);
	int refstr[n];
	printf("enter page requests");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&refstr[i]);
	}
	
	printf("enter no of frames");
	int frames;
	scanf("%d",&frames);
	optimal(n,refstr,frames);
	
}

