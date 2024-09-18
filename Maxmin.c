#include <stdio.h>

int main() {
    int num1, num2, num3;
    int largest, smallest;
    char size;
    printf("Do you want to find smallest or largest number? <S/L>: ");
    scanf("%c", &size);
    printf("Enter 3 integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    //ไม่มีเลขซ้ำ
    if (num1 > num2 && num1 > num3) {
        largest = num1;
        if (num2 > num3) {
            smallest = num3;
        } else {
            smallest = num2;
        }
    } else if (num2 > num1 && num2 > num3) {
        largest = num2;
        if (num1 > num3) {
            smallest = num3;
        } else {
            smallest = num1;
        }
    } else if (num3 > num1 && num3 > num2) {
        largest = num3;
        if (num1 > num2) {
            smallest = num2;
        } else {
            smallest = num1;
        }
    //มีเลขซ้ำ
    } else if ((num1 == num2) > num3) {
        largest = num1 = num2;
        smallest = num3;
    } else if ((num1 == num3) > num2) {
        largest = num1 = num3;
        smallest = num2;
    } else if ((num2 == num3) > num1) {
        largest = num2 = num3;
        smallest = num1;
    }

    //รับไซซ์
    switch (size) {
        case 'L' : printf("Largest number: %d", largest); break;
        case 'S' : printf("Smallest number: %d", smallest); break;
        

        default:
            printf("Please check your identifier."); break;
    }


    return 0;
}