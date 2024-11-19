#include <stdio.h>
#include <string.h>

void swap_elements(int *arr, int pos1, int pos2) {
    int swap;
    swap = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = swap;
}

int main () {
    int N,i,pos1,pos2;

    printf("Enter the number of elements (max100): ");

    do  {
       scanf("%d", &N); 
    } while (N < 0 || N > 100);

    int nums[N];
    printf("Enter %d numbers: ", N);

    for (i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Enter first position to swap (0-%d): ", N-1);
    scanf("%d", &pos1);
    printf("\n");
    printf("Enter second position to swap (0-%d): ", N-1);
    scanf("%d", &pos2);
    printf("\n");
    printf("After swapping elements at positions %d and %d:\n", pos1, pos2);
    swap_elements(nums, pos1, pos2);

    for (i = 0; i < N; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}