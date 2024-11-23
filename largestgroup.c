#include <stdio.h>

int main () {
    int i,N;
    do {
        scanf("%d", &N);
    } while (N < 1 || N > 100);

    int checker[21];
    for (i = 0; i <= 21; i++) {
        checker[i] = 0;
    }

    int arr[N];
    int max_count=0;
    int max_number=0;

    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        checker[arr[i]]++;
    }

    for (i = 1; i <= 20; i++) {
        if (checker[i] > max_count || (checker[i] == max_count && i > max_number)) {
                max_number = i;
                max_count = checker[i];
        }
    }

    printf("%d %d", max_number, max_count);

    return 0;
}