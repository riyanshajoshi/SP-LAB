#include<stdio.h>
int main(){
	int n,i,time=0,remain;
	int at[20],bt[20],rt[20],wt[20],tat[20],ct[20];
	int tq;
	float avg_wt=0;
	float avg_tat=0;
	printf("enter number of processes: ");
	scanf("%d",&n);

	remain=n;

	printf("enter arrival time and burst time: \n");
	for(i=0;i<n;i++){
		printf("p%d",i+1);
		scanf("%d %d",&at[i],&bt[i]);
		rt[i]=bt[i];
	}
	printf("enter time quantum: ");
	scanf("%d",&tq);
	while(remain!=0){
		for(i=0;i<n;i++){
			if(rt[i]>0 && at[i]<=time){
				if(rt[i]<=tq){
					time+=rt[i];
					rt[i]=0;
					ct[i]=time;
					tat[i]=ct[i]-at[i];
					wt[i]=tat[i]-bt[i];

					avg_wt+=wt[i];
					avg_tat+=tat[i];

					remain--;
				}
				else{
					rt[i]-=tq;
					time+=tq;
				}}}
	if(i==n)
		time++;
	}
   printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%dms\t%dms\t%dms\t%dms\t%dms\n",i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2fms", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2fms\n", avg_tat/n);

    return 0;
}

