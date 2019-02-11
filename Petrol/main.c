#include <stdio.h>
#include <stdlib.h>
struct petrol{
    float d;
    float p;
};
void main()
{
    struct petrol obj[100];
    int num=0,i,j,index=0;
    float tank=0;
    float total=0;
    float extra;
    float cd=0;


    printf("Enter the no. of petrol pumps\n");
    scanf("%d",&num);
    printf("the no is %d\n",num);
    for(i=0;i<num;i++)
        {
            printf("Enter the capacity in petrol pump no. %d\n",i+1);
            scanf("%f",&obj[i].p);
            printf("Enter the distance to the next petrol pump\n");
            scanf("%f",&obj[i].d);
        }
        printf("Capacity\t\tDistance\n");
     for(i=0;i<num;i++)
     {
         printf("%f\t\t%f\n\n",obj[i].p,obj[i].d);
     }
     for(i=0;i<num;i++)
     {
         total+=obj[i].d;

     }

     for(i=0;i<num;i++)
     {
         extra=0;
         tank=obj[i].p;
         for(j=0;(tank>=0||cd==total);j++)
         {
             if(tank>=obj[j].d)
             {
                 cd+=obj[j].d;
                 extra=tank-obj[j].d;
                 tank+=extra+obj[j+1].p;

             }
             else
                break;
         }
         if(cd>=total)
         {
             printf("You can start from petrol pump no %d\n",i+1);
             index++;
         }
     }

     if(index==0)
        printf("Sorry no petrol pump");


}
