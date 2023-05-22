#include<stdio.h>
void knapsack(int num,float weight[20],float profit[20],float capacity);
int main()
{
	int num,i,j;  //num= object
	float weight[20],profit[20],capacity;
	float ratio[20], temp;
	
	printf("Enter the number of objects: ");
	scanf("%d",&num);
	
	
	printf("\n Enter the weight and profit of each objects: ");
	for(i=0;i<num;i++)
	{
		scanf("%f %f",&weight[i],&profit[i]);
	}	
	 
	printf("Enter the capacity: ");
	scanf("%f",&capacity);
	
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(ratio[i]<ratio[j])
			{
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;
				
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;
				
				temp = profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
				
			}
		}
	}
	knapsack(num,weight,profit,capacity);
}

void knapsack(int n,float weight[20],float profit[20],float capacity)
{
	float x[20], tp =0;
	int i, j, u;
	u = capacity;
	
	for(i=0;i<=n;i++)
	{
		x[i]=0.0;
	}
	
	for(i=0;i<n;i++)
	{
		if(weight[i]>u)
		{
			break; 
		}
		else
		{
			x[i]=1.0;
			tp=tp+profit[i];
			u= u-weight[i];
		}
	}
	
	if(i<n)
	{
		x[i]=u/weight[i];
	}
	
	tp = tp + (x[i]*profit[i]);
	
	printf("The reasult vector is: ");
	for(i=0;i<n;i++)
	{
		printf("%f\t",x[i]);
	}
	printf("\nMaximum profit is %f: ",tp);
}