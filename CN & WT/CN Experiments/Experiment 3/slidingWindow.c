#include<stdio.h>

int main()  {
    int window, nFrame;
    printf("Enter the size of frame: ");
    scanf("%d", &window);
    printf("Enter no of frames: ");
    scanf("%d", &nFrame);
    int frame[nFrame];
    for (int i = 1; i <= nFrame; i++)  {
        printf("Enter %d frame: ", i);
        scanf("%d", &frame[i]);
    }
    for(int i = 1; i <= nFrame; i++)  {
        if(i % window != 0)  {
            printf("%d ", frame[i]);
        }
        else {
            printf("%d",frame[i]);
            printf("\nAcknowledgement of above frames sent is received by sender\n");
        }
    }
    if(nFrame % window != 0)
            printf("\nAcknowledgement of above frames sent is received by sender\n");
}
