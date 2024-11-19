#include <stdio.h>

/* Function zone*/

float Maxval(float realnum[], int inputnum) {
    int i;
    float maxval = realnum[0];
    for (i = 0; i < inputnum; i++) {
        if (realnum[i] > maxval) {
            maxval = realnum[i];
        }
    }
    
    return maxval;
}

float Minval (float realnum[], int inputnum) {
    int i;
    float minval = realnum[0];
    for (i = 0; i < inputnum; i++) {
        if (realnum[i] < minval) {
            minval = realnum[i];
        }
    }
    
    return minval;
}

int Maxindex (float realnum[], int inputnum) {
    int i;
    int maxin = 0;
    for (i = 0; i < inputnum; i++) {
        if (realnum[i] > realnum[maxin]) {
            maxin = i;
        }
    }

    return maxin;
}

int Minindex (float realnum[], int inputnum) {
    int i;
    int minin = 0;
    for (i = 0; i < inputnum; i++) {
        if (realnum[i] < realnum[minin]) {
            minin = i;
        }
    }

    return minin;
}

float Average (float realnum[], int inputnum) {
    int i;
    float average, sum = 0;
    for (i = 0; i < inputnum; i++) {
        sum += realnum[i];
    }
    average = sum/inputnum;

    return average; 
}

void Reverse (float realnum[], int inputnum) {
    int i;
    for (i = inputnum - 1; i >= 0; i--) {
        printf("%.2f ", realnum[i]);
    }
}

void Aboveavg (float realnum[], int inputnum) {
    int i;
    float avg = Average(realnum, inputnum);
    for (i = inputnum - 1; i >= 0; i--) {
        if (realnum[i] > avg) {
            printf("%.2f ", realnum[i]);
        }
    }
}

void Negativeco (float realnum[], int inputnum) {
    int i,j;
    for (i = 0; i < inputnum; i++) {
        if (realnum[i] < 0) {
            for (j = i + 1; j < inputnum; j++) {
                if (realnum[j] < 0) {
                    printf("(%.2f, %.2f), ", realnum[i], realnum[j]);
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