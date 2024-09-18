#include <stdio.h>

int main() {
    int num1, num2, num3;
    printf("Please enter length of each side of your traingle: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 <= 0 || num2 <= 0 || num3 <= 0) {
        printf("This is NOT a possible triangle.");
    } else if (num1 + num2 <= num3 || num1 + num3 <= num2 || num2 + num3 <= num1) {
        printf("This is NOT a possible triangle.");
    } else if (num1 == num2 == num3) {
        printf("This is an equilateral triangle.");
    } else if (num1 != num2 && num1 != num3 && num2 != num3) {
        printf("This is a sclanene triangle.");
    } else if (num1 == num2 || num1 == num3 || num2 == num3) {
        printf("This is an isosceles triangle");
    }
    
    return 0;
}