#include <stdio.h>

int main () {
    int i;
    char str[1000];
    scanf("%s", str);

    int count = 1, special = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '_') {
            count++;
        }
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '_'){
            if(str[i+1] == 'a' || str[i+1] == 'e' || str[i+1] == 'i' || str[i+1] == 'o' || str[i+1] == 'u' || str[i+1] == 'A' || str[i+1] == 'E' || str[i+1] == 'I' || str[i+1] == 'O' || str[i+1] == 'U') {
                special++;
            }
        }
    }

    if (str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u' || str[0] == 'A' || str[0] == 'E' || str[0] == 'I' || str[0] == 'O' || str[0] == 'U') {
        special++;
    }

    printf("%d %d", count, special);
    return 0;
}