#include <stdio.h>
#include <string.h>
int main() {
    int n;
    printf("Enter the no. of frames: ");
    scanf("%d",&n);
    char str[20];
    char frame[n][20];
    int header[n];
    for(int i = 0; i < n; i++ )  {
        printf("Frame%d: ",i+1);
        scanf("%s", frame[i]);
        header[i] = strlen(frame[i]);
    }
    printf("AT THE SENDER\n");
    printf("Data as frames: \n");
    for(int i = 0; i < n; i++)  {
        printf("Frame%d: %d%s\n",i+1,header[i],frame[i]);
    }
    printf("Data Transmitted: ");
    for(int i = 0; i < n; i++)  {
        printf("%d%s",header[i],frame[i]);
    }
    printf("\nAT THE RECEIVER\n");
    printf("The data received\n");
    printf("The data after removing count char: ");
    for(int i = 0; i < n; i++)  {
        printf("%s ",frame[i]);
    }
    printf("\nThe data in frame form: \n");
    for(int i = 0; i < n; i++)  {
        printf("Frame%d: %s\n",i+1,frame[i]);
    }
    return 0;
}