#include<stdio.h>

struct petrolpump {
	int petrol;
	int dist;
};

void main()
{
	int n,i,k,j,m=0,d=0;
	printf("Enter number of petrol pumps\n");
	scanf("%d",&n);
	struct petrolpump pp[n];

	for(i=0;i<n;i++)
	{
		printf("Enter petrol available at petrol pump %d and distance to petrol pump %d\n",i+1,(i==n-1)?1:i+2);
		scanf("%d%d",&pp[i].petrol,&pp[i].dist);
	}
	for(i=0;i<n;i++)
	{
		m=0,d=0;

		for(j=i,k=0;k<2;j++)
		{
			if(j>n)
			{
				j=j-n;
				k++;
			}

			m = m + pp[j].petrol;
			d = d + pp[j].dist;

			if(m<d)
			{
				break;
			}
		}

		if(m>=d)
		{
			printf("Petrolpump %d could be used as a starting point\n",i+1);
		}
}
}
