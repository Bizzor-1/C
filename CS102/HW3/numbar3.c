#include <stdio.h>

void Matrix_creation (int N, int matrix[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int Matrix_checker1(int N, int matrix[N][N]) {

    /* create checker for everyinput */
    int i, j;
    int checker[N*N + 1];
    for (i = 1; i <= (N*N); i++) {
        checker[i] = 0;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (matrix[i][j] > (N*N) || matrix[i][j] < 1) /* เลขต้องอยู่ใน 1 - N^2 */{
                return 0;
            }
            checker[matrix[i][j]]++; /* ถ้าไม่เข้าเงื่อนไข checkerจะ +1 ตามเลขที่รับไปไว้ในตำแหน่งตามเลขนั้นไว้เช็คว่าเลขไหนเกิน 2 */
        }
    }

    /* using check to check every (x,x) */
    for (i = 1; i <= (N*N); i++) {
        if (checker[i] != 1) {
            return 0;
        }
    }

    return 1;
}

int Matrix_checker2 (int N, int matrix[N][N]) {
    int i, j;
    int sumrow = 0;
    int rows[N];

    /* check sum of row */
    for (i = 0; i < N; i++) {
        sumrow = 0;
        for (j = 0; j < N; j++) {
            sumrow += matrix[i][j];
        }
        rows[i] = sumrow;
    }
    for (i = 0; i < N; i++) {
        if (rows[i] != rows[0]) {
            return 0;
        }
    }
    /* check sum of row */

    /* check sum of column */
    int columns[N];
    int sumcolumns = 0;
    for (j = 0; j < N; j++) {
        sumcolumns = 0;
        for (i = 0; i < N; i++) {
            sumcolumns += matrix[j][i];
        }
        columns[j] = sumcolumns;
    }
    for (i = 1; i < N; i++) {
        if (columns[i] != columns[0]) {
            return 0;
        }
    }
    /* check sum of column */

    /* check sum of diagonal */
    int sumdiagnal1 = 0;
    int sumdiagnal2 = 0;
    for (i = 0; i < N; i++) {
        sumdiagnal1 += matrix[i][i];
        sumdiagnal2 += matrix[i][(N-i)-1];
    }

    if (sumdiagnal1 != sumdiagnal2) {
        return 0;
    }

    /* check diagnal*/

    return 1;
}

int main () {
    int N;
    do {
        scanf("%d", &N);
    } while (N < 3 || N > 8);

    int matrix[N][N];

    Matrix_creation(N, matrix);
    if (Matrix_checker1(N, matrix) && Matrix_checker2(N, matrix)) {
        printf("This is a magic square!");
    } else {
        printf("This is NOT a magic square!");
    }
    

    return 0;
}