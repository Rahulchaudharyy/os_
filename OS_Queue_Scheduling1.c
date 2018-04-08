#include<stdio.h>
#include<stdlib.h>
struct Queue
{
	int burst;
	int prior;
};
int main()
{
	int process;
	scanf("%d",&process);
	struct Queue *Firs_Com_serv=(struct Queue*)malloc(process*sizeof(struct Queue));
	struct Queue *Round___Robin=(struct Queue*)malloc(process*sizeof(struct Queue));
	struct Queue *Priority_Queu=(struct Queue*)malloc(process*sizeof(struct Queue));
	printf("Enter Priority and Burst Time \n");
	int Count_RR=0,Count_FF=0,Count_PR=0;
	for(int i=0;i<process;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a>=1 && a<=5)
		{
			(Round___Robin+Count_RR)->burst=b;
			(Round___Robin+Count_RR)->prior=a;
			Count_RR++;
		}
		else if(a>=6 && a<=10)
		{
			(Firs_Com_serv+Count_FF)->burst=b;
			(Firs_Com_serv+Count_FF)->prior=a;
			Count_FF++;
		}
		else
		{
			(Priority_Queu+Count_PR)->burst=b;
			(Priority_Queu+Count_PR)->prior=a;
			Count_PR++;
		}
	}
	for(int i=0;i<Count_PR-1;i++)
	{
		for(int j=0;j<Count_PR-i-1;j++)
		{
			if((Priority_Queu+j)->prior>(Priority_Queu+j+1)->prior)
			{
				int temp_prio=(Priority_Queu+j)->prior;
				int temp_burst=(Priority_Queu+j)->burst;
				(Priority_Queu+j)->prior=(Priority_Queu+j+1)->prior;
				(Priority_Queu+j)->burst=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j+1)->prior=temp_prio;
				(Priority_Queu+j+1)->burst=temp_burst;
			}
		}
	}
	int temp_RR=0,temp_FF=0,temp_PQ=0;
	while(Count_FF!=temp_FF)
	{
		int a=1,b=1,c=1,set=1;
		while(Count_FF!=temp_FF)
		{
            if(set==1)
			if(a==11)
			{
			   break;
			}
			if((Firs_Com_serv+temp_FF)->burst>0)
			{
				(Firs_Com_serv+temp_FF)->burst-=1;
			}
			if((Firs_Com_serv+temp_FF)->burst==0)
			{
				printf("Process P%d Completed\n",temp_FF+1);
				temp_FF++;
			}
			a++;
		}
		if((Firs_Com_serv+temp_FF)->burst!=0)
		{
			printf("Process P%d Remaining Burst Time %d \n",temp_FF+1,(Firs_Com_serv+temp_FF)->burst);
		}
	}
	return 0;
}
