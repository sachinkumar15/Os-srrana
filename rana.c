#include<stdio.h> 
int main() 
{ 
	int Pr=5,Re=3;
 	// Number of processes 
    // Number of resources 
	printf("Enter number of process and resources:	");
	scanf("%d%d",&Pr,&Re);
	const int P=Pr,R=Re;
    // Available resources 
    int avail[15];
    printf("Enter number of available resources:	");
	for(int i=0;i<R;i++)
	{
		scanf("%d",&avail[i]);
	} 
    // Maximum Resources that can be allocated
    int maxm[10][10];
    for(int i=0;i<P;i++)
	{
		printf("Enter maximum required resources for P%d:	",i+1);
		for(int j=0;j<R;j++)
		{
			scanf("%d",&maxm[i][j]);
		}
	}
    // Allocated Resources to processes 
    int allot[10][10];   
    for(int i=0;i<P;i++)
	{
		printf("Enter resources allocated by P%d:	",i+1);
		for(int j=0;j<R;j++)
		{
			scanf("%d",&allot[i][j]);
		}
	}
	// Required Resources 
   int need[P][R]; 
  
    // Calculating Need(Required Resources by Process) 
    for (int i = 0 ; i < P ; i++) 
        for (int j = 0 ; j < R ; j++) 
  
            // Need of instance = maxm instance - 
            //                    allocated instance 
            need[i][j] = maxm[i][j] - allot[i][j]; 
  
    // Mark all processes as not finished
    bool finish[P] = {0}; 
    // Safe sequence 
    int safeSeq[P]; 
  
    // Copy of available resources 
    int work[R]; 
    for (int i = 0; i < R ; i++) 
        work[i] = avail[i]; 
  
    // while all processes are not finished 
    int count = 0; 
	while (count < P) 
    { 
        // Find a process which is not finish 
        bool found = false; 
        for (int p = 0; p < P; p++) 
        { 
            // checking process is finished or not
            if (finish[p] == 0) 
            { 
                // checking that current process less than work
                int j; 
                for (j = 0; j < R; j++) 
                    if (need[p][j] > work[j]) 
                        break; 
  
                // If all needs of p were satisfied. 
                if (j == R) 
                { 
                    // Add resources of current process to available resources 
                    for (int k = 0 ; k < R ; k++) 
                        work[k] += allot[p][k]; 
  
                    // Add this process to safe sequence. 
                    safeSeq[count++] = p; 
  
                    // Mark this p as finished 
                    finish[p] = 1; 
  
                    found = true; 
                } 
            } 
        } 
		  // If we could not find a next process in safe sequence
        if (found == false) 
        { 
            printf("System is not in safe state");  
        } 
    } 
  

    // safe sequence will be as below 
    printf("System is in safe state\n");
    printf("Sequence is: "); 
    for (int i = 0; i < P ; i++) 
        printf("P%d_____",safeSeq[i]+1);

} 
