/*EXPERIMENT -2 Non Preemptive SJF*/
/*Name:Jinay Parekh
Batch:C RollNo:46*/
#include <stdio.h>
#include <stdlib.h>
/*Creating a structure "process" having id, waiting time,turnaround time,arrival time and burst time as its attributes*/

struct process{
int wt,tt,at,id,bt;
};
void main()
{
    int n,i,j;
    int sum=0;float avgwt=0;float avgtt=0;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    struct process obj[n];//Creating an array of structure objects to store multiple processes
    struct process temp;
    for(i=0;i<n;i++){
        printf("Enter the process ID of %d process\n",i+1);
        scanf("%d",&obj[i].id);
        printf("Enter the arrival time of %d process\n",i+1);
        scanf("%d",&obj[i].at);
        printf("Enter the burst time of %d process\n",i+1);
        scanf("%d",&obj[i].bt);
    }
    printf("PROCESS\tBURST TIME\tARRIVAL TIME\n");
    for(i=0;i<n;i++){
        printf("P%d     \t%d        \t%d          \n",obj[i].id,obj[i].bt,obj[i].at);
    }
/*Sorting on the basis of the burst time if the arrival time is the same else sorting on the basis of the arrival time*/
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if((obj[j].at==obj[j+1].at)){
                if(obj[j].bt>obj[j+1].bt){
                    temp=obj[j];
                    obj[j]=obj[j+1];
                    obj[j+1]=temp;
                }
            }
            else{
                if(obj[j].at>obj[j+1].at){
                temp=obj[j];
                obj[j]=obj[j+1];
                obj[j+1]=temp;
                }
            }
        }
    }
    /*Calculation of the waiting time and the turnaround time of each process*/
    obj[0].wt=0;
    obj[0].tt=obj[0].bt;
    for(i=1;i<n;i++){
        sum+=obj[i-1].bt;
        obj[i].wt=sum-obj[i].at;
        if(obj[i].wt<0){
            obj[i].wt=0;
        }
        obj[i].tt=obj[i].wt+obj[i].bt;
    }
    /*Printing the information of all the processes in a tabular format*/
    printf("THE PROCESSES ARE EXECUTED IN THE FOLLOWING ORDER\n");
    printf("PROCESS\tBURST TIME\tARRIVAL TIME\t\WAITING TIME\tTURN AROUND TIME\n");
    for(i=0;i<n;i++){
        avgwt+=obj[i].wt;
        avgtt+=obj[i].tt;
        printf("P%d     \t%d        \t%d          \t%d          \t%d\n",obj[i].id,obj[i].bt,obj[i].at,obj[i].wt,obj[i].tt);
    }
    printf("AVERAGE WAITING TIME IS %f\n",avgwt/n);
    printf("AVERAGE TURNAROUND TIME IS %f\n",avgtt/n);
}
/*Output:
1.
Enter the number of processes
4
Enter the process ID of 1 process
1
Enter the arrival time of 1 process
0
Enter the burst time of 1 process
6
Enter the process ID of 2 process
2
Enter the arrival time of 2 process
0
Enter the burst time of 2 process
8
Enter the process ID of 3 process
3
Enter the arrival time of 3 process
0
Enter the burst time of 3 process
7
Enter the process ID of 4 process
4
Enter the arrival time of 4 process
0
Enter the burst time of 4 process
3
PROCESS BURST TIME      ARRIVAL TIME
P1      6               0
P2      8               0
P3      7               0
P4      3               0
THE PROCESSES ARE EXECUTED IN THE FOLLOWING ORDER
PROCESS BURST TIME      ARRIVAL TIME    WAITING TIME    TURN AROUND TIME
P4      3               0               0               3
P1      6               0               3               9
P3      7               0               9               16
P2      8               0               16              24
AVERAGE WAITING TIME IS 7.000000
AVERAGE TURNAROUND TIME IS 13.000000

2.Enter the number of processes
3
Enter the process ID of 1 process
1
Enter the arrival time of 1 process
5
Enter the burst time of 1 process
10
Enter the process ID of 2 process
2
Enter the arrival time of 2 process
20
Enter the burst time of 2 process
30
Enter the process ID of 3 process
3
Enter the arrival time of 3 process
20
Enter the burst time of 3 process
15
PROCESS BURST TIME      ARRIVAL TIME
P1      10              5
P2      30              20
P3      15              20
THE PROCESSES ARE EXECUTED IN THE FOLLOWING ORDER
PROCESS BURST TIME      ARRIVAL TIME    WAITING TIME    TURN AROUND TIME
P1      10              5               0               10
P3      15              20              0               15
P2      30              20              15              45
AVERAGE WAITING TIME IS 5.000000
AVERAGE TURNAROUND TIME IS 23.333333
*/
