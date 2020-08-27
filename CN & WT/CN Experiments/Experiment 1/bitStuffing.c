#include <stdio.h>

int main()  {
    int n;
    printf("Enter the size of bits: ");
    scanf("%d", &n);
    int bit[n];
    int res[40] = {0,1,1,1,1,1,1,0};
    int flagSequence[8] = {0,1,1,1,1,1,1,0};
    printf("Enter the bits: ");
    for(int i = 0; i < n ; i++) {
        scanf("%d", &bit[i]);
    }

    int count = 1;
    int j = 8, k, i = 0;
    while(i<n)  {
        if(bit[i]==1)  {
            res[j]=bit[i];
            for(k=i+1; bit[k]==1 && k<n && count<5; k++)  {
                j++;
                res[j]=bit[k];
                count++;
                if(count==5)  {
                    j++;
                    res[j]=0;
                }
                i=k;
            }
        }
        else  {
            res[j]=bit[i];
        }
        i++;
        j++;
    }
    for(int a = j; a < j+8; a++) {
        res[a] = flagSequence[a-j];
    }
    int size = j+8;
    printf("AT THE RECEIVER:\n");
    for(int i = 0; i < size ; i++)  
        printf("%d ", res[i]);
    
    
    count = 0;
    int result[n];
    j = 0;
    i = 8;
    while(i<(size-8))  {
        if(res[i]==1)  {
            result[j]=res[i];
            count++;
            if (count == 5) {
                i++;
                count = 0;
            }
        }
        else if(res[i] == 0 && count < 5)  {
            result[j]=res[i];
        }
        i++;
        j++;
    }
    printf("\nAT THE SENDER:\n");
    for(int i = 0; i < j ; i++)  {
        printf("%d ", result[i]);
    }
    printf("\n");
}