#include<stdio.h>

int main()  {
    int bucketSize, outputRate, inputLines;
    printf("Enter the Bucket Size and Output Rate: ");
    scanf("%d %d", &bucketSize, &outputRate);
    printf("Enter the Input lines: ");
    scanf("%d", &inputLines);
    int a[inputLines];
    for(int i = 0;i < inputLines; i++)  {
        printf("Enter the  input packet rates of %d line : ",i+1);
        scanf("%d", &a[i]);
    }
    int n, total= 0;
    printf("Enter number of iterations: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)  {
        total += a[i];
        if(total <= bucketSize)  {
            printf("Input from line %d with rate %d is added to the bucket\nCurrent bucket size is %d\n",i+1,a[i],total);
        }
        else {
            total -= a[i];
            printf("Input from line %d with rate %d is thrown out of the bucket\nCurrent bucket size is %d\n",i+1,a[i],total);
        }
    }
    if(total <= outputRate)  {
        printf("packet sent to output line at a rate %d",total);
        total = 0;
        printf("Current bucket size is %d",total);
    }
    else {
        total -= outputRate;
        printf("Packets sent to the output line at rate %d\nCurrent bucket size is %d\n",outputRate,total);
    }
}
