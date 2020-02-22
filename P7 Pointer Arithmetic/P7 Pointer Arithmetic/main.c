//
//  main.c
//  P7 Pointer Arithmetic
//
//  Created by Benjamin Valdez on 2/21/20.
//

#include <stdio.h>

void changeString(char *address) {
    int i = 0;
    while (*(address + i) != '\0') {
        switch (*(address + i)) {
            case 'a':
                *(address + i) = '4';
                break;
            case 'e':
                *(address + i) = '3';
                break;
            case 'i':
                *(address + i) = '1';
                break;
            case 'o':
                *(address + i) = '0';
                break;
            case 'u':
                *(address + i) = '2';
                break;
            default:
                break;
        }
        i++;
    }
    printf("%s", address);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    char input[60];
    char *ptr;
    
    printf("Give me a string: ");
    fgets(input, sizeof(input), stdin);
    
    ptr = &input[0];
    changeString(ptr);
    return 0;
}
