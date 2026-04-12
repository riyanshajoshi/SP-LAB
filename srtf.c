#include<stdio.h>
int main(){
	int n,i,time=0,smallest;
	int bt[20],at[20],rt[20];
	int wt[20],tat[20],ct[20];
	int complete=0;
	float avg_wt=0,avg_tat=0;

	printf("enter number of processes: ");
	scanf("%d",&n);
	printf("enter arrival time and burst time: ");
	for(i=0;i<n;i++){
		printf("P%d",i+1);
		scanf("%d %d",&at[i],&bt[i]);
		rt[i]=bt[i];
	}
	rt[19]=9999;
	while(complete!=n){
		smallest=19;
		for(i=0;i<n;i++){
			if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0){
				smallest=i;
			}}
		rt[smallest]--;
		if(rt[smallest]==0){
			complete++;
			ct[smallest]=time+1;
			tat[smallest]=ct[smallest]-at[smallest];
			wt[smallest]=tat[smallest]-bt[smallest];
			
			avg_wt+=wt[smallest];
			avg_tat+=tat[smallest];
		}
		time++;
	}
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++){
		printf("P%d\t%dms\t%dms\t%dms\t%dms\t%dms\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("\n average waiting time=%.2f",avg_wt/n);
	printf("\n average turnaround time=%.2f",avg_tat/n);
	return 0;
}

