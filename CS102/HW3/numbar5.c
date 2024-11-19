#include <stdio.h>

// Question 5 of Homework 3 (CS102 HW3 1/2567)
// Your program will not successfully be compiled and run properly until readSquare and findMagicNumber functions are defined correctly.
// Let's define readSquare and findMagicNumber functions here !

void readSquare (int arr[8][8], int N) {
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

int findMagicNumber (int arr[8][8], int N) {
    // create checker
    int i,j;
    int checker[N*N + 1];
    for (i = 1; i < (N*N); i++) {
        checker[i] = 0;
    }

    for (i = 1; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (arr[i][j] > (N*N) || arr[i][j] < 1) {
                return -1;
            }
            checker[arr[i][j]]++;
        }
    }

    // using checker
    for (i = 1; i <= N; i++) {
        if (checker[i] > 1) {
            return -1;
        }
    }

    //checking condition for checking diagnal
    int sumdiagnal1 = 0;
    int sumdiagnal2 = 0;
    for (i = 0; i < N; i++) {
        sumdiagnal1 += arr[i][i];
        sumdiagnal2 += arr[i][N-1-i];
    }

    //checking diagnal
    if (sumdiagnal1 != sumdiagnal2) {
        return -1;
    }

    return sumdiagnal1;
}

int main(){

    int arr[8][8];
    int N;

    scanf("%d", &N);
    readSquare(arr, N);

    int magicNumber = findMagicNumber(arr, N);

    if (magicNumber == -1) {
        printf("Your square is NOT a magic square.");
    } else {
        printf("Your square is a magic square!! with the magic constant = %d.", magicNumber);
    }

    return 0;
}