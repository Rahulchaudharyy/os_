#include<stdio.h>
#include<stdlib.h>
struct Queue
{
	int burst;
	int prior;
    int arrival;
    int p_id;
    int burstt;
};
int main()
{
	int process;
	scanf("%d",&process);
	struct Queue *Firs_Com_serv=(struct Queue*)malloc(process*sizeof(struct Queue));
	struct Queue *Round___Robin=(struct Queue*)malloc(process*sizeof(struct Queue));
	//struct Queue Round___Robin[100];
	struct Queue *Priority_Queu=(struct Queue*)malloc(process*sizeof(struct Queue));
	printf("Enter Priority,Burst Time and Arrival time o the Process: \n");
	int Count_RR=0,Count_FF=0,Count_PR=0;
	for(int i=0;i<process;i++)
	{
		int a,b,arr;
		scanf("%d %d %d",&a,&b,&arr);
		if(a>=1 && a<=5)
		{
			(Round___Robin+Count_RR)->burst=b;
			(Round___Robin+Count_RR)->burstt=b;
			(Round___Robin+Count_RR)->prior=a;
			(Round___Robin+Count_RR)->arrival=arr;
			Count_RR++;
		}
		else if(a>=6 && a<=10)
		{
			(Priority_Queu+Count_PR)->burst=b;
			(Priority_Queu+Count_PR)->burstt=b;
			(Priority_Queu+Count_PR)->prior=a;
			(Priority_Queu+Count_PR)->arrival=arr;
			Count_PR++;
			
		}
		else
		{
			(Firs_Com_serv+Count_FF)->burst=b;
			(Firs_Com_serv+Count_FF)->burstt=b;
			(Firs_Com_serv+Count_FF)->prior=a;
			(Firs_Com_serv+Count_FF)->arrival=arr;
			Count_FF++;
		}
	}
	for(int i=0;i<Count_FF-1;i++)
	{
		for(int j=0;j<Count_FF-i-1;j++)
		{
			if((Firs_Com_serv+j)->arrival>(Firs_Com_serv+j+1)->arrival)
			{
				int temp_prio=(Firs_Com_serv+j)->arrival;
				int temp_burst=(Firs_Com_serv+j)->burst;
				(Firs_Com_serv+j)->arrival=(Firs_Com_serv+j+1)->arrival;
				(Firs_Com_serv+j)->burst=(Firs_Com_serv+j+1)->burst;
				(Firs_Com_serv+j)->burstt=(Firs_Com_serv+j+1)->burst;
				(Firs_Com_serv+j+1)->arrival=temp_prio;
				(Firs_Com_serv+j+1)->burst=temp_burst;
				(Firs_Com_serv+j+1)->burstt=temp_burst;
			}
		}
	}
	for(int i=0;i<Count_RR-1;i++)
	{
		for(int j=0;j<Count_RR-i-1;j++)
		{
			if((Round___Robin+j)->arrival>(Round___Robin+j+1)->arrival)
			{
				int temp_prio=(Round___Robin+j)->arrival;
				int temp_burst=(Round___Robin+j)->burst;
				(Round___Robin+j)->arrival=(Round___Robin+j+1)->arrival;
				(Round___Robin+j)->burst=(Round___Robin+j+1)->burst;
				(Round___Robin+j)->burstt=(Round___Robin+j+1)->burst;
				(Round___Robin+j+1)->arrival=temp_prio;
				(Round___Robin+j+1)->burst=temp_burst;
				(Round___Robin+j+1)->burstt=temp_burst;
			}
		}
	}
	for(int i=0;i<Count_PR-1;i++)
	{
		for(int j=0;j<Count_PR-i-1;j++)
		{
			if((Priority_Queu+j)->arrival>(Priority_Queu+j+1)->arrival)
			{
				int temp_prio=(Priority_Queu+j)->arrival;
				int temp_burst=(Priority_Queu+j)->burst;
				int temp_arr=(Priority_Queu+j)->prior;
				(Priority_Queu+j)->arrival=(Priority_Queu+j+1)->arrival;
				(Priority_Queu+j)->burst=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->burstt=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->prior=(Priority_Queu+j+1)->prior;
				(Priority_Queu+j+1)->arrival=temp_prio;
				(Priority_Queu+j+1)->burst=temp_burst;
				(Priority_Queu+j+1)->burstt=temp_burst;
				(Priority_Queu+j+1)->prior=temp_arr;
			}
		}
	}
	for(int j=0;j<Count_PR;j++)
	{
			printf("Priority: %d   Arrival : %d\n",(Priority_Queu+j)->prior,(Priority_Queu+j)->arrival);
	}
	for(int j=0;j<Count_PR;j++)
	{
			if((Priority_Queu+j)->arrival==(Priority_Queu+j+1)->arrival)
			{
				if((Priority_Queu+j+1)->prior<(Priority_Queu+j)->prior)
				{
				int temp_arr=(Priority_Queu+j)->arrival;
				int temp_burst=(Priority_Queu+j)->burst;
				int temp_prio=(Priority_Queu+j)->prior;
				(Priority_Queu+j)->arrival=(Priority_Queu+j+1)->arrival;
				(Priority_Queu+j)->burst=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->burstt=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->prior=(Priority_Queu+j+1)->prior;
				(Priority_Queu+j+1)->arrival=temp_arr;
				(Priority_Queu+j+1)->burst=temp_burst;
				(Priority_Queu+j+1)->burstt=temp_burst;
				(Priority_Queu+j+1)->prior=temp_prio;
				}
			}
	}
	for(int j=0;j<Count_PR;j++)
	{
			printf("Priority: %d   Arrival : %d\n",(Priority_Queu+j)->prior,(Priority_Queu+j)->arrival);
	}
	int temp_RR=0,temp_FF=0,temp_PQ=0,t1=0,t=0,x1,x2,x3,temp_R=0,turn_RR[Count_RR],turn_PQ[Count_PR],turn_FF[Count_FF],wait_RR[Count_RR],wait_PQ[Count_PR],wait_FF[Count_FF];
	while(1)
    {
       if(temp_FF<Count_FF||(Firs_Com_serv+temp_FF)->burst!=0)
      {
    	printf("FCS Queue Start\n");
		for(int i=1;i<=10;i++)
		{
            if(temp_FF==Count_FF)
            {
            	break;
            }
			if((Firs_Com_serv+temp_FF)->burst>0)
			 {
			  (Firs_Com_serv+temp_FF)->burst-=1;
			  t1++;
			 }
			if((Firs_Com_serv+temp_FF)->burst==0)
			{
			  printf("Process P%d Completed  turn time %d\n",temp_FF+1,t1);
			  turn_FF[temp_FF]=t1-(Firs_Com_serv+temp_FF)->arrival;
			  wait_FF[temp_FF]=turn_FF[temp_FF]-(Firs_Com_serv+temp_FF)->burstt;
			  temp_FF++;
			}
		}
		if((Firs_Com_serv+temp_FF)->burst!=0 && temp_FF<=Count_FF-1)
		{
			printf("Process P%d Remaining Burst Time %d \n",temp_FF+1,(Firs_Com_serv+temp_FF)->burst);
		}
		printf("FCS Queue End\n");
	 }
     else
     {
    	x1=1;
     }  
	 if(temp_PQ<Count_PR||(Priority_Queu+temp_PQ)->burst!=0)
	  {
		printf("Priority_Queu Queue Start\n");
		for(int i=1;i<=10;i++)
		{
			if(temp_PQ==Count_PR)
            {
            	break;
            }
			if((Priority_Queu+temp_PQ)->burst>0)
			{
			 (Priority_Queu+temp_PQ)->burst-=1;
			 t1++;
			}
			if((Priority_Queu+temp_PQ)->burst==0)
			{
			  printf("Process P%d Completed  turn time %d\n",temp_PQ+1,t1);
			  turn_PQ[temp_PQ]=t1-(Priority_Queu+temp_PQ)->arrival;
			  wait_PQ[temp_PQ]=turn_PQ[temp_PQ]-(Priority_Queu+temp_PQ)->burstt;
			  temp_PQ++;
			}
		}
		if((Priority_Queu+temp_PQ)->burst!=0 && temp_PQ<=Count_PR-1)
		{
			printf("Process P%d Remaining Burst Time %d \n",temp_PQ+1,(Priority_Queu+temp_PQ)->burst);
		}
		printf("Priority_Queu End\n");
	  }
	  else
	  {
	  	x3=1;
	  }
	  if(temp_RR<Count_RR||(Round___Robin+temp_RR)->burst!=0)
	  {
		printf("Round___Robin Queue Start  %d\n",Count_RR);
		for(int i=1;i<=10;i++)
		{
			int quant=4;
			if(temp_RR==Count_RR)
            {
            	break;
            }
            int d=(Round___Robin+temp_R)->burst;
            while(1)
            {
            	if(d==0)
            	{
            		temp_R++;
            		d=(Round___Robin+temp_R)->burst;
            	}
            	else
            	{
            		break;
            	}
            }
			while(quant--)
			{
				   if((Round___Robin+temp_R)->burst>0)
			       {
				     (Round___Robin+temp_R)->burst-=1;
				     t1++;
				     t++;

			       }
			       if((Round___Robin+temp_R)->burst==0)
			       {
			         printf("Process P%d Completed  turn time %d\n",temp_R+1,t1);
			         turn_RR[temp_RR]=t1-(Round___Robin+temp_RR)->arrival;
			         wait_RR[temp_RR]=turn_RR[temp_RR]-(Round___Robin+temp_RR)->burstt;
			         temp_RR++;
			         break;
			       }
			       if(t==10)
                   {
                   	i=13;
                   	break;
                   }
   			}
			printf("%d\n", t1);
			if((Round___Robin+temp_R)->burst!=0 && temp_R<Count_RR)
		    {
			printf("Process P%d Remaining Burst Time %d \n",temp_R+1,(Round___Robin+temp_R)->burst);
		    }
		    temp_R++;
		    if(temp_R>=Count_RR)
		    {
		    	temp_R=0;
		    }
		}
		printf("Round___Robin End\n");
	  }
	  else
	  {
	  	x2=1;
	  }
	  if(x2==1 && x3==1 && x1==1)
	  {
	  	break;
	  }
    }
printf("\n\n\n\n\n\n\n");
for(int i=0;i<temp_FF;i++)
{
	printf("waiting time %d  TurnAround time %d\n",wait_FF[i],turn_FF[i]);
}
printf("\n\n\n\n\n\n\n");
for(int i=0;i<temp_PQ;i++)
{
	printf("waiting time %d  TurnAround time %d\n",wait_FF[i],turn_FF[i]);
}
printf("\n\n\n\n\n\n\n");
for(int i=0;i<temp_RR;i++)
{
	printf("waiting time %d  TurnAround time %d\n",wait_FF[i],turn_FF[i]);
}
exit(0);
}
