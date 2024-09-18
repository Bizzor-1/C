#include <stdio.h>

int main () {
    float num1, num2;
    float avg;
    float sumheightplus, sumheightminus;
    printf("Enter the height of the mother (centimeters): ");
    scanf("%f", &num1);
    printf("Enter the height of the father (centimeters): ");
    scanf("%f", &num2);

    avg = (num1 + num2)/2;
    sumheightplus = avg + 13.5;
    sumheightminus = avg - 13.5;

    printf("The possible height of the child is between %.2f to %.2f centimeters.", sumheightminus, sumheightplus);

    return 0;
}