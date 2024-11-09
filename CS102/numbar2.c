#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 51

/* Function zone */

int size (char *strPtr) {
    int size = strlen(strPtr);
    return size;
}

int vowels_checker (char ch) {
    char lower = tolower(ch);
    if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
        return 1;
    }
    return 0;
}

int consonants (char *strPtr) {
    int count = 0;
    int i;
    for (i = 0; strPtr[i] != '\0'; i++) {
        if (isalpha(strPtr[i]) && !vowels_checker(strPtr[i])) {
            count++;
        }
    }
    return count;
}

int vowels(char *strPtr) {
    int count = 0;
    int i;
    for (i = 0; strPtr[i] != '\0'; i++) {
        if (isalpha(strPtr[i]) && vowels_checker(strPtr[i])) {
            count++;
        }
    }
    return count;
}

int uppercase (char *strPtr) {
    int i;
    int count = 0;
    for (i = 0; strPtr[i] != '\0'; i++) {
        if (isupper(strPtr[i])) {
            count++;
        }
    }
    return count;
}

int lowercase (char *strPtr) {
    int i;
    int count = 0;
    for (i = 0; strPtr[i] != '\0'; i++) {
        if (islower(strPtr[i])) {
            count++;
        }
    }
    return count;
}

int palindrome (char *strPtr) {
    int left = 0;
    int right = strlen(strPtr) - 1;
    while (left < right) {
        if (strPtr[left] != strPtr[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

/* Function zone */

int main () {
    char str[51];
    scanf("%s", str);

    printf("Size of input string is %d\n", size(str));
    printf("#Consonants: %d\n", consonants(str));
    printf("#Vowels: %d\n", vowels(str));
    printf("#Upper-case letters: %d\n", uppercase(str));
    printf("#Lower-case letters: %d\n", lowercase(str));
    
    if (palindrome(str) == 1) /* สามารถย่อได้เป็น if (palindrome(str))*/{
        printf("Is a palindrome string: Yes\n");
    } else {
        printf("Is a palindrome string: No\n");
    }

    return 0;
}