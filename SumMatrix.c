#include <stdio.h>

int main () {
    int arr[4][4];
    int i,j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int sumall,sumr = 0,sumc = 0,r,c;

    scanf("%d %d", &r, &c);

    for (i = 0; i < 4; i++) {
        sumr = sumr + arr[i][c];
        sumc = sumc + arr[r][i];
    }

    sumall = sumr + sumc;

    printf("%d", sumall);
    return 0;
}