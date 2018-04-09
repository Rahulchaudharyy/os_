#include<stdio.h>
#include<stdlib.h>
struct Queue
{
	int burst;
	int prior;
    int arrival;
};
int main()
{
	int process;
	scanf("%d",&process);
	struct Queue *Firs_Com_serv=(struct Queue*)malloc(process*sizeof(struct Queue));
	struct Queue *Round___Robin=(struct Queue*)malloc(process*sizeof(struct Queue));
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
			(Round___Robin+Count_RR)->prior=a;
			(Round___Robin+Count_RR)->arrival=arr;
			Count_RR++;
		}
		else if(a>=6 && a<=10)
		{
			(Priority_Queu+Count_PR)->burst=b;
			(Priority_Queu+Count_PR)->prior=a;
			(Priority_Queu+Count_PR)->arrival=arr;
			Count_PR++;
			
		}
		else
		{
			(Firs_Com_serv+Count_FF)->burst=b;
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
				(Firs_Com_serv+j+1)->arrival=temp_prio;
				(Firs_Com_serv+j+1)->burst=temp_burst;
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
				(Round___Robin+j+1)->arrival=temp_prio;
				(Round___Robin+j+1)->burst=temp_burst;
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
				(Priority_Queu+j)->prior=(Priority_Queu+j+1)->prior;
				(Priority_Queu+j+1)->arrival=temp_prio;
				(Priority_Queu+j+1)->burst=temp_burst;
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
				(Priority_Queu+j)->prior=(Priority_Queu+j+1)->prior;
				(Priority_Queu+j+1)->arrival=temp_arr;
				(Priority_Queu+j+1)->burst=temp_burst;
				(Priority_Queu+j+1)->prior=temp_prio;
				}
			}
	}
	for(int j=0;j<Count_PR;j++)
	{
			printf("Priority: %d   Arrival : %d\n",(Priority_Queu+j)->prior,(Priority_Queu+j)->arrival);
	}
	/*int w[process],bust=0;
	w[0]=0;
	bust=w[0]+(Firs_Com_serv+0)->burst+(Firs_Com_serv+0)->arrival;
	for(int i=1;i<Count_FF;i++)
	{
          w[i]=bust-(Firs_Com_serv+i)->arrival;
          bust=bust+(Firs_Com_serv+i)->burst;
	}
	for(int i=0;i<Count_FF;i++)
	{
          printf(" waiting:= %d",w[i]);
	}*/
	int temp_RR=0,temp_FF=0,temp_PQ=0,set=0,t=0,t1=0,x1,x2,x3;
	while(1)
    {
     if(temp_FF<Count_FF||(Firs_Com_serv+temp_FF-1)->burst!=0)
     {
    	printf("FCS Queue Start\n");
		for(int i=1;i<=10;i++)
		{
           // t++;
            if(temp_FF==Count_FF)
            {
            	break;
            }
            if(set==0)
            {
            	printf("CPU idle %d\n",i);
            	if(i==(Firs_Com_serv+temp_FF)->arrival)
            	{
                    set=1;
            	}
            }
			else
			{
				if((Firs_Com_serv+temp_FF)->burst>0)
			    {
				 (Firs_Com_serv+temp_FF)->burst-=1;
			    }
			}
			if((Firs_Com_serv+temp_FF)->burst==0)
			{
			  printf("Process P%d Completed  turn time %d\n",temp_FF+1,t+t1);
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
	 if(temp_PQ<Count_PR||(Priority_Queu+temp_PQ-1)->burst!=0)
	  {
		printf("Priority_Queu Queue Start\n");
		for(int i=1;i<=10;i++)
		{
			//t1++;
			if(temp_PQ==Count_PR)
            {
            	break;
            }
            if(set==0)
            {
            	printf("CPU idle %d\n",i);
            	if(i==(Priority_Queu+temp_PQ)->arrival)
            	{
                    set=1;
            	}
            }
			else
			{
				if((Priority_Queu+temp_PQ)->burst>0)
			    {
				 (Priority_Queu+temp_PQ)->burst-=1;
			    }
			}
			if((Priority_Queu+temp_PQ)->burst==0)
			{
			  printf("Process P%d Completed  turn time %d\n",temp_PQ+1,t1);
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
	  	x2=1;
	  }
	  if(x1==1 && x2==1)
	  {
	  	break;
	  }
}
	return 0;
}
