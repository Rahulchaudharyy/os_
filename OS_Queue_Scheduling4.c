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
	printf("Enter the number of Processes: \n");
	scanf("%d",&process);
	if(process<1)
	{
		printf("Number of Processes less than 1");
		exit(0);
	}
	struct Queue *Firs_Com_serv=(struct Queue*)malloc(process*sizeof(struct Queue));
	struct Queue *Round___Robin=(struct Queue*)malloc(process*sizeof(struct Queue));
	struct Queue *Priority_Queu=(struct Queue*)malloc(process*sizeof(struct Queue));
	printf("Enter ID, Priority, Burst Time and Arrival Time of each Process: \n\n");
	printf("P.ID  Priority  Burst_time  Arrival_time\n\n");
	int Count_RR=0,Count_FF=0,Count_PR=0;
	for(int i=0;i<process;i++)
	{
		int a,b,arr,id;
		scanf("%d %d %d %d",&id,&a,&b,&arr);
	  if(b>0 && arr>-1)
	  {
		if(a>=1 && a<=10)
		{
			(Round___Robin+Count_RR)->burst=b;
			(Round___Robin+Count_RR)->burstt=b;
			(Round___Robin+Count_RR)->prior=a;
			(Round___Robin+Count_RR)->arrival=arr;
			(Round___Robin+Count_RR)->p_id=id;

			Count_RR++;
		}
		else if(a>=11 && a<=20)
		{
			(Priority_Queu+Count_PR)->burst=b;
			(Priority_Queu+Count_PR)->burstt=b;
			(Priority_Queu+Count_PR)->prior=a;
			(Priority_Queu+Count_PR)->arrival=arr;
			(Priority_Queu+Count_PR)->p_id=id;
			Count_PR++;
			
		}
		else
		{
			(Firs_Com_serv+Count_FF)->burst=b;
			(Firs_Com_serv+Count_FF)->burstt=b;
			(Firs_Com_serv+Count_FF)->prior=a;
			(Firs_Com_serv+Count_FF)->arrival=arr;
			(Firs_Com_serv+Count_FF)->p_id=id;
			Count_FF++;
		}
	  }
	  else
	  {
	  	printf("Wrong Details Entered for Processes \n");
	  	exit(0);
	  }
	}
	//SORTING ACCORDING TO ARRIVAL TIME FOR FCFS
	for(int i=0;i<Count_FF-1;i++)
	{
		for(int j=0;j<Count_FF-i-1;j++)
		{
			if((Firs_Com_serv+j)->arrival>(Firs_Com_serv+j+1)->arrival)
			{
				int temp_prio=(Firs_Com_serv+j)->arrival;
				int temp_burst=(Firs_Com_serv+j)->burst;
				int temp_id=(Firs_Com_serv+j)->p_id;
				(Firs_Com_serv+j)->arrival=(Firs_Com_serv+j+1)->arrival;
				(Firs_Com_serv+j)->burst=(Firs_Com_serv+j+1)->burst;
				(Firs_Com_serv+j)->p_id=(Firs_Com_serv+j+1)->p_id;
				(Firs_Com_serv+j)->burstt=(Firs_Com_serv+j+1)->burst;
				(Firs_Com_serv+j+1)->arrival=temp_prio;
				(Firs_Com_serv+j+1)->p_id=temp_id;
				(Firs_Com_serv+j+1)->burst=temp_burst;
				(Firs_Com_serv+j+1)->burstt=temp_burst;
			}
		}
	}
	//SORTING COMPLETED FOR FCFS
	printf("PROCESSES IN FCFS QUEUE\n\n");
	printf("P.ID  Priority  Arrival_time  Burst_time\n\n");
	for (int i = 0; i <Count_FF; ++i)
	{
		printf("  %d      %d        %d            %d\n",(Firs_Com_serv+i)->p_id,(Firs_Com_serv+i)->prior,(Firs_Com_serv+i)->arrival,(Firs_Com_serv+i)->burst);
	}
	//SORTING STARTED FOR ROUND ROBIN
	for(int i=0;i<Count_RR-1;i++)
	{
		for(int j=0;j<Count_RR-i-1;j++)
		{
			if((Round___Robin+j)->arrival>(Round___Robin+j+1)->arrival)
			{
				int temp_prio=(Round___Robin+j)->arrival;
				int temp_burst=(Round___Robin+j)->burst;
				int temp_id=(Round___Robin+j)->p_id;
				(Round___Robin+j)->arrival=(Round___Robin+j+1)->arrival;
				(Round___Robin+j)->burst=(Round___Robin+j+1)->burst;
				(Round___Robin+j)->p_id=(Round___Robin+j+1)->p_id;
				(Round___Robin+j)->burstt=(Round___Robin+j+1)->burst;
				(Round___Robin+j+1)->arrival=temp_prio;
				(Round___Robin+j+1)->burst=temp_burst;
				(Round___Robin+j+1)->burstt=temp_burst;
				(Round___Robin+j+1)->p_id=temp_id;
			}
		}
	}
	for(int j=0;j<Count_RR;j++)
	{
			if((Round___Robin+j)->arrival==(Round___Robin+j+1)->arrival)
			{
				if((Round___Robin+j+1)->burst<(Round___Robin+j)->burst)
				{
				int temp_arr=(Round___Robin+j)->arrival;
				int temp_burst=(Round___Robin+j)->burst;
				int temp_prio=(Round___Robin+j)->prior;
				int temp_id=(Round___Robin+j)->p_id;
				(Round___Robin+j)->arrival=(Round___Robin+j+1)->arrival;
				(Round___Robin+j)->burst=(Round___Robin+j+1)->burst;
				(Round___Robin+j)->burstt=(Round___Robin+j+1)->burst;
				(Round___Robin+j)->p_id=(Round___Robin+j+1)->p_id;
				(Round___Robin+j)->prior=(Round___Robin+j+1)->prior;
				(Round___Robin+j+1)->arrival=temp_arr;
				(Round___Robin+j+1)->burst=temp_burst;
				(Round___Robin+j+1)->burstt=temp_burst;
				(Round___Robin+j+1)->prior=temp_prio;
				(Round___Robin+j+1)->p_id=temp_id;
				}
			}
	}
	//SORTING END FOR ROUND ROBIN
	printf("PROCESSES IN Round___Robin QUEUE\n\n");
	printf("P.ID  Priority  Arrival_time  Burst_time\n\n");
	for (int i = 0; i <Count_RR; ++i)
	{
		printf("  %d      %d        %d            %d\n",(Round___Robin+i)->p_id,(Round___Robin+i)->prior,(Round___Robin+i)->arrival,(Round___Robin+i)->burst);
	}
	//SORTING STARTED FOR PRIORITY QUEUE
	for(int i=0;i<Count_PR-1;i++)
	{
		for(int j=0;j<Count_PR-i-1;j++)
		{
			if((Priority_Queu+j)->arrival>(Priority_Queu+j+1)->arrival)
			{
				int temp_prio=(Priority_Queu+j)->arrival;
				int temp_burst=(Priority_Queu+j)->burst;
				int temp_arr=(Priority_Queu+j)->prior;
				int temp_id=(Priority_Queu+j)->p_id;
				(Priority_Queu+j)->arrival=(Priority_Queu+j+1)->arrival;
				(Priority_Queu+j)->burst=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->burstt=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->prior=(Priority_Queu+j+1)->prior;
				(Priority_Queu+j)->p_id=(Priority_Queu+j+1)->p_id;
				(Priority_Queu+j+1)->arrival=temp_prio;
				(Priority_Queu+j+1)->p_id=temp_id;
				(Priority_Queu+j+1)->burst=temp_burst;
				(Priority_Queu+j+1)->burstt=temp_burst;
				(Priority_Queu+j+1)->prior=temp_arr;
			}
		}
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
				int temp_id=(Priority_Queu+j)->p_id;
				(Priority_Queu+j)->arrival=(Priority_Queu+j+1)->arrival;
				(Priority_Queu+j)->burst=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->burstt=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->p_id=(Priority_Queu+j+1)->p_id;
				(Priority_Queu+j)->prior=(Priority_Queu+j+1)->prior;
				(Priority_Queu+j+1)->arrival=temp_arr;
				(Priority_Queu+j+1)->burst=temp_burst;
				(Priority_Queu+j+1)->burstt=temp_burst;
				(Priority_Queu+j+1)->prior=temp_prio;
				(Priority_Queu+j+1)->p_id=temp_id;
				}
			}
	}
	//SORTING END FOR PRIORITY QUEUE
	printf("PROCESSES IN Priority QUEUE\n\n");
	printf("P.ID  Priority  Arrival_time  Burst_time\n\n");
	for (int i = 0; i <Count_PR; ++i)
	{
		printf("  %d      %d        %d            %d\n",(Priority_Queu+i)->p_id,(Priority_Queu+i)->prior,(Priority_Queu+i)->arrival,(Priority_Queu+i)->burst);
	}
	printf("\n\n");
	int temp_RR=0,temp_FF=0,temp_PQ=0,t1=0,t=0,x1,x2,x3,temp_R=0,turn_RR[Count_RR],turn_PQ[Count_PR];
	int turn_FF[Count_FF],wait_RR[Count_RR],wait_PQ[Count_PR],wait_FF[Count_FF];
	int ideal=0;
	//THESE IF CONDITIONS ARE USED FOR SATISFYING SOME CONDITIONS
	while(1)
    { 
      //ROUND ROBIN CODE START 
      if(temp_RR<Count_RR||(Round___Robin+temp_RR-1)->burst!=0)
	  {
		printf("Round___Robin Queue Start  %d\n",Count_RR);
		for(int i=1;i<=10;i++)
		{
			int quant=4;
			if(ideal<(Round___Robin+temp_RR)->arrival)
			{
				printf("CPU IDLE\n");
				t1++;
				ideal++;
				break;
			}
			else
			{
				ideal++;
			}
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
			         printf("Process P.ID Completed%d\n",(Round___Robin+temp_R)->p_id);
			         turn_RR[temp_R]=t1-(Round___Robin+temp_R)->arrival;
			         wait_RR[temp_R]=turn_RR[temp_R]-(Round___Robin+temp_R)->burstt;
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
	//ROUND ROBIN CODE END
	 else
	  {
	  	x2=1;
	  }
	//PRIORITY QUEUE START
     if(temp_PQ<Count_PR||(Priority_Queu+temp_PQ-1)->burst!=0)
	  {
		printf("Priority_Queu Queue Start\n");
		for(int i=1;i<=10;i++)
		{
			if(ideal<(Priority_Queu+temp_PQ)->arrival)
			{
				printf("CPU IDLE\n");
				t1++;
				ideal++;
				break;
			}
			else
			{
				ideal++;
			}
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
			  printf("Process P.ID %d Completed\n",(Priority_Queu+temp_PQ)->p_id);
			  turn_PQ[temp_PQ]=t1-(Priority_Queu+temp_PQ)->arrival;
			  wait_PQ[temp_PQ]=turn_PQ[temp_PQ]-(Priority_Queu+temp_PQ)->burstt;
			  temp_PQ++;
			}
		}
		if((Priority_Queu+temp_PQ)->burst!=0 && temp_PQ<=Count_PR-1)
		{
			printf("Process P.ID %d Remaining Burst Time: %d \n",(Priority_Queu+temp_PQ)->p_id,(Priority_Queu+temp_PQ)->burst);
		}
		printf("Priority_Queu End\n");
	  }
	  //QUEUE CODE START
	  else
	  {
	  	x3=1;
	  }
	  //FCFSE CODE START
	  if(temp_FF<Count_FF||(Firs_Com_serv+temp_FF-1)->burst!=0)
      {
    	printf("FCS Queue Start\n\n");
		for(int i=1;i<=10;i++)
		{
			if(ideal<(Firs_Com_serv+temp_FF)->arrival)
			{
				printf("CPU IDLE\n");
				t1++;
				ideal++;
				break;
			}
			else
			{
				ideal++;
			}
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
			  printf("Process P.ID %d Completed.\n",(Firs_Com_serv+temp_FF)->p_id);
			  turn_FF[temp_FF]=t1-(Firs_Com_serv+temp_FF)->arrival;
			  wait_FF[temp_FF]=turn_FF[temp_FF]-(Firs_Com_serv+temp_FF)->burstt;
			  temp_FF++;
			}
		}
		if((Firs_Com_serv+temp_FF)->burst!=0 && temp_FF<=Count_FF-1)
		{
			printf("Process P.ID %d Remaining Burst Time: %d \n",(Firs_Com_serv+temp_FF)->p_id,(Firs_Com_serv+temp_FF)->burst);
		}
		printf("\nFCS Queue End\n\n");
	  }
	  //FCFS CODE END
      else
      {
    	x1=1;
      }
	  if(x1==1 && x3==1 && x2==1)
	  {
	  	break;
	  }
    }
    printf("%d\n", t1);
float sum1=0,sum2=0,sum4=0,sum5=0,sum6=0,sum3=0;
if(Count_FF>0)
{
   printf("\n\n");
   printf("FCFS QUEUE\n\n");
   printf("P.ID    PRIORITY    Burst_time    Arrival_time     Waiting_Time    TurnAround_Time\n\n");
   for(int i=0;i<temp_FF;i++)
   {
	printf(" %d         %d         %d            %d             %d             %d\n",(Firs_Com_serv+i)->p_id,(Firs_Com_serv+i)->prior,(Firs_Com_serv+i)->burstt,(Firs_Com_serv+i)->arrival,wait_FF[i],turn_FF[i]);
    sum1=sum1+wait_FF[i];
    sum2=sum2+turn_FF[i];
   }
   sum1=(sum1)/(Count_FF);
   sum2=(sum2)/(Count_FF);
   printf("Average WAITING TIME : %f\n",sum1);
   printf("Average ARRIVAL TIME : %f",sum2);
}
if(Count_PR>0)
{
  printf("\n\n");
  printf("PRIORITY QUEUE\n\n");
  printf("P.ID    PRIORITY    Burst_time    Arrival_time     Waiting_Time    TurnAround_Time\n\n");
  for(int i=0;i<temp_PQ;i++)
  {
	printf(" %d         %d         %d            %d             %d             %d\n",(Priority_Queu+i)->p_id,(Priority_Queu+i)->prior,(Priority_Queu+i)->burstt,(Priority_Queu+i)->arrival,wait_PQ[i],turn_PQ[i]);
    sum3=sum3+wait_PQ[i];
    sum4=sum4+turn_PQ[i];
  }
  sum3=(sum3)/(Count_PR);
  sum4=(sum4)/(Count_PR);
  printf("Average WAITING TIME : %f\n",sum1);
  printf("Average ARRIVAL TIME : %f",sum2);
}
return 0;
exit(0);
}