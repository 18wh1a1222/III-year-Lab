#include<stdio.h>
#include<string.h>
#define frame_max_size 3
#define max_frames 127

char str[max_frames*frame_max_size];

struct frame  {
    char text[frame_max_size];
    int seqNo;
}fr[max_frames], shuff[max_frames];

int assignNumbers()  {
    int k = 0;
    for(int i = 0; i < strlen(str); k++)  {
        fr[k].seqNo = k;
        for(int j = 0; j < frame_max_size && str[i]!='\0'; j++)  {
            fr[k].text[j] = str[i++];
        }
    }
    printf("After assigning:\n");
    for(int i = 0; i < k; i++)  {
        printf("%d: %s ", i, fr[i].text);
    }
    return k;
}

void genarate(int *randomArr, const int limit)  {
    int i = 0, r, j;
    while(i < limit)  {
        r = random() % limit;
        for(j = 0; j < i; j++)
            if(randomArr[j] == r)
                break;
        if(i == j) 
            randomArr[i++] = r;
    }
}

void shuffle(const int nFrames)  {
    int randonArray[nFrames];
    genarate(randonArray, nFrames);
    for(int i = 0; i < nFrames; i++)  {
        shuff[i] = fr[randonArray[i]];
    }
    printf("\nAfter Suffling:\n");
    for(int i = 0; i < nFrames; i++)  {
        printf("%d: %s ",shuff[i].seqNo, shuff[i].text);
    }
}

void sort(const int nFrame)  {
    struct frame hold;
    int flag = 1;
    for(int i = 0; i < nFrame-1 && flag == 1; i++)  {
        flag = 0;
        for(int j = 0; j < nFrame-1-i; j++)  {
            if(shuff[j].seqNo > shuff[j+1].seqNo)  {
                hold = shuff[j];
                shuff[j] = shuff[j+1];
                shuff[j+1] = hold;
                flag = 1;
            }
        }
    }
}

int main()  {
    printf("Enter the message: ");
    gets(str);
    int nFrame = assignNumbers();
    shuffle(nFrame);
    sort(nFrame);
    printf("\nAfter Sorting:");
    for (int i = 0; i < nFrame; i++)  {
        printf("%s", shuff[i].text); 
    }
    printf("\n");    
}
    
