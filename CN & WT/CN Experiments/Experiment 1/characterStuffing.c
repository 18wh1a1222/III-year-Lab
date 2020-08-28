#include <stdio.h>
#include <string.h>

int main()  {
    int n;
    printf("Enter the number of Characters: ");
    scanf("%d", &n);
    char data[n];
    printf("Enter the data: ");
    scanf("%s", data);
    char stuffing[3] = "dle";
    char res[30] = "dlestx";
    int  i = 0;
    while (i < n)  {
        if (i+2 < n)  {
            if (data[i] == stuffing[0] && data[i+1] == stuffing[1] && data[i+2] == stuffing[2]) {
                strncat(res, stuffing, 3);
                strncat(res,stuffing, 3);
                i = i+2;
            }
            else {
                char ch[1] = {data[i]};
                strncat(res, ch, 1);
            }
            
        }
        else {
        char ch[1] = {data[i]};
        strncat(res, ch, 1);
        }
        i++;
    }
    strncat(res, "dleetx", 6);
    printf("Original Data:\n");
    printf("%s\n", res);
    
    char result[30] = {};
    i = 6;
    int length = strlen(res);
    while (i < length-6) {
        if (i+2 < length-6)  {
            if (res[i] == stuffing[0] && res[i+1] == stuffing[1] && res[i+2] == stuffing[2]) {
                strncat(result, stuffing, 3);
                i = i+6;
            }
        }
        if(i < length-6) {
        char ch[1] = {res[i]};
        strncat(result, ch, 1);
        }
        i++;
    }
    printf("Recieved Data:\n");
    printf("%s\n", result);
    
}
    