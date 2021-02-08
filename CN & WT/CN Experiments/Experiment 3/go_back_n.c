#include<stdio.h>

int main()  {
    int windows,ack, send = 0;
    printf("Enter the window size: ");
    scanf("%d", &windows);
    while(1)  {
        for(int i = 0; i < windows; i++)  {
            printf("Frame %d has been transmitted\n", send++);
            if(send == windows)
				      break;
        }
        printf("\nPlease enter the last Acknowledgement received.\n");
		    scanf("%d",&ack);
		    if(ack == windows) {
			    break;
		    }
		    else {
			    send = ack;
		    }
    }
}
