//
//  main.c
//  P7 Pointer Arithmetic
//
//  Created by Benjamin Valdez on 2/21/20.
//

#include <stdio.h>

void changeString(int address) {
    printf("%d", &address);
    int i = 0;
    /*
    while (*(string + i) != '\0') {
        switch (*(string + i)) {
            case 'a':
                *(string + i) = '4';
                break;
            case 'o':
                *(string + i) = '0';
            default:
                break;
        }
    }
    printf("%s", string);
    */
    printf("\n");
}

int main(int argc, const char * argv[]) {
    char input[60];
    char *first;
    char **pointer;
    
    printf("Give me a string: ");
    fgets(input, sizeof(input), stdin);
    printf("\nAddress of variable num is: %p\n", &input[0]);
    
    first = &input[0];
    printf("%s", first);
   // int add = &first;
    
    //changeString(add);
    return 0;
}
