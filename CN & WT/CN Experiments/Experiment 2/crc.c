#include <stdio.h>
#include <string.h>

int main()
{
    int keylength, msglength, i, j;
    char a[100], b[100], k[100], k1[100], temp[100], Quotient[100], Remainder[100];
    printf("Enter data:");
    scanf("%s", a);
    strcpy(b, a);
    printf("Enter the Polynomial:");
    scanf("%s", k);
    msglength = strlen(a);
    keylength = strlen(k);
    strcpy(k1, k);
    for (i = 1; i < keylength; i++)
    {
        strcat(a, "0");
    }
    printf("String after adding zeroes:%s\n", a);
    for (i = 0; i < keylength; i++)
    {
        temp[i] = a[i];
    }
    for (i = 0; i < msglength; i++)
    {
        Quotient[i] = temp[0];
        if (Quotient[i] == '0')
        {
            for (j = 0; j < keylength; j++)
                k[j] = '0';
        }
        else
        {
            for (j = 0; j < keylength; j++)
                k[j] = k1[j];
        }
        for (j = keylength - 1; j > 0; j--)
        {
            if (temp[j] == k[j])
            {
                Remainder[j - 1] = '0';
            }
            else
            {
                Remainder[j - 1] = '1';
            }
        }
        Remainder[keylength - 1] = a[i + keylength];
        strcpy(temp, Remainder);
    }
    strcpy(Remainder, temp);
    Quotient[msglength] = '\0';
    Remainder[keylength - 1] = '\0';

    printf("Quotient:%s\n", Quotient);
    printf("Remainder:%s\n", Remainder);
    printf("Data received at receiver side:");
    strcat(b, Remainder);
    printf("%s", b);
    printf("\n");

    return 0;
}
