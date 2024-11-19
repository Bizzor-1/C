#include <stdio.h>

/* Function zone*/

float Maxval(float *realnumPtr, int inputnum) {
    int i;
    float maxval = realnumPtr[0];
    for (i = 0; i < inputnum; i++) {
        if (realnumPtr[i] > maxval) {
            maxval = realnumPtr[i];
        }
    }
    
    return maxval;
}

float Minval (float *realnumPtr, int inputnum) {
    int i;
    float minval = realnumPtr[0];
    for (i = 0; i < inputnum; i++) {
        if (realnumPtr[i] < minval) {
            minval = realnumPtr[i];
        }
    }
    
    return minval;
}

int Maxindex (float *realnumPtr, int inputnum) {
    int i;
    int maxin = 0;
    for (i = 0; i < inputnum; i++) {
        if (realnumPtr[i] > realnumPtr[maxin]) {
            maxin = i;
        }
    }

    return maxin;
}

int Minindex (float *realnumPtr, int inputnum) {
    int i;
    int minin = 0;
    for (i = 0; i < inputnum; i++) {
        if (realnumPtr[i] < realnumPtr[minin]) {
            minin = i;
        }
    }

    return minin;
}

float Average (float *realnumPtr, int inputnum) {
    int i;
    float average, sum = 0;
    for (i = 0; i < inputnum; i++) {
        sum += realnumPtr[i];
    }
    average = sum/inputnum;

    return average; 
}

void Reverse (float *realnumPtr, int inputnum) {
    int i;
    for (i = inputnum - 1; i >= 0; i--) {
        printf("%.2f ", realnumPtr[i]);
    }
}

void Aboveavg (float *realnumPtr, int inputnum) {
    int i;
    float avg = Average(realnumPtr, inputnum);
    for (i = inputnum - 1; i >= 0; i--) {
        if (realnumPtr[i] > avg) {
            printf("%.2f ", realnumPtr[i]);
        }
    }
}

void Negativeco (float *realnumPtr, int inputnum) {
    int i,j;
    for (i = 0; i < inputnum; i++) {
        if (realnumPtr[i] < 0) {
            for (j = i + 1; j < inputnum; j++) {
                if (realnumPtr[j] < 0) {
                    printf("(%.2f, %.2f), ", realnumPtr[i], realnumPtr[j]);
                }
            }
        }
    }
}

/* Function zone*/

int main () {
    /* input N */
    int inputnum, i;
    do {
       scanf("%d", &inputnum); 
    } while (inputnum < 1 || inputnum > 50);
    
    /* input Realnum */
    float realnum[inputnum];
    for (i = 0; i < inputnum; i++) {
        scanf("%f", &realnum[i]);
    }

    printf("Maximun value:\t\t%5.2f\n", Maxval(realnum, inputnum));
    printf("Minimun value:\t\t%5.2f\n", Minval(realnum, inputnum));
    printf("Maximun index:\t\t%5d\n", Maxindex(realnum, inputnum));
    printf("Minimun index:\t\t%5d\n", Minindex(realnum, inputnum));
    printf("Average:\t%8.2f\n", Average(realnum, inputnum));
    printf("Reverse order: "); Reverse (realnum, inputnum); printf("\n");
    printf("Above average list: "); Aboveavg(realnum, inputnum); printf("\n");
    printf("Negative coordinates: "); Negativeco(realnum, inputnum);

    return 0;
}