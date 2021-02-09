#include<stdio.h>

struct node {
    unsigned dist[20];
    unsigned from[20];
}mat[10];


int main()  {
    int n;
    printf("Enter the size of matrix: ");
    scanf("%d", &n);
    int costMat[n][n];
    printf("Enter the cost mat matrix\n");
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)  {
            scanf("%d", &costMat[i][j]);
            costMat[i][i] = 0;
            mat[i].dist[j] = costMat[i][j];
            mat[i].from[j] = j;
        }
    }
    int count = 0;
    do
    {
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)  {
                for (int k = 0; k < n; k++)  {
                    if(mat[i].dist[j] > costMat[i][k] + mat[k].dist[j])  {
                        count++;
                        mat[i].from[j] = k;
                        mat[i].dist[j] = mat[k].dist[j] + mat[i].dist[k];
                    }
                }   
            }
        }
        
    } while (count != 0);
    for (int i = 0; i < n; i++)  {
        printf("For router %d: \n", i+1);  
        for (int j = 0; j < n; j++)  {
            printf("node %d  via %d Distance %d\n", j+1,mat[i].from[j], mat[i].dist[j]);
        }    
        printf("\n");
    }    
}
