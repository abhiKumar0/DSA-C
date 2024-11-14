#include <stdio.h>

void bubbleSort(int *a, int n) 
{
    int i, temp;
    for (i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++) {

            if (a[j] > a[j+1])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() 
{
    int n = 6;
    int ar[6] = {5, 3, 8, 6, 9, 1};
    bubbleSort(&ar, n);
    for (int i=0; i<n; i++){
        printf("%d ", ar[i]);
    }
    printf("\n");
    return 0;
}