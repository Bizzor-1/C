#include <stdio.h>

int main () {
    int i,N,count = 0;
    scanf("%d", &N);
    int arr[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < N; i++) {
        if (arr[i] > arr[N-1]) {
            count++;
        }
    }

    if (count == 0) {
        count = 1;
    }

    printf("%d\n", arr[N-1]);
    printf("%d", count);
    return 0;
}