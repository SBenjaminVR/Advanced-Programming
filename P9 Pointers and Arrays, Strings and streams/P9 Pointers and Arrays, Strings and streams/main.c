//
//  main.c
//  P9 Pointers and Arrays, Strings and streams
//
//  Created by Benjamín Valdez on 3/13/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

bool checkIfValidAscii(char *s) {
    char validchars[] = "ABCDEF0123456789\n";
    if (strspn(s, validchars) == strlen(s)) {
        return true;
    }
    return false;
}

int asciiBinaryToInt(char *s) {
    char *ptr = s;
    int strSize = strlen(s);
    int powVal = -1;

    if (strSize > 32) {
        return 0;
    }
    
    int strNumber = 0;
    for (int i = strSize - 1; i >= 0; i--) {
        if (*(ptr+i) == '0' || *(ptr+i) == '1') {
            strNumber += (int)(*(ptr+i) - '0') * pow(2, ++powVal);
        }
        else {
            return strNumber;
        }
    }

    return strNumber;
}

int asciiHEXToInt(char *s) {
    char *ptr = s;
    int strSize = strlen(s);
    int powVal = 0;

    if (strSize > 8) {
        return 0;
    }

    int strNumber = 0;
    
    for (int i = strSize - 2; i >= 0; i--) {
        if ((*(ptr+i) >= 'A' && *(ptr+i) <= 'F') || (*(ptr+i) >= '0' && *(ptr+i) <= '9')) {
            if (*(ptr+i) >= 'A') {
                strNumber += (*(ptr+i) - 'A' + 10) * pow(16, powVal);
            }
            else {
                strNumber += (*(ptr+i) - '0') * pow(16, powVal);
            }
            powVal++;
        }
        else {
            return strNumber;
        }
    }

    return strNumber;
}

double asciiToDouble(char *s) {
    char *ptr = s;
    int strSize = strlen(s);
    int decimalPosition = -1;
    int firstValidChar = 0;
    bool isNegative = false;
    
    if (*ptr == '-') {
        isNegative = !isNegative;
        firstValidChar = 1;
    }

    for (int i = 0; i < strSize; i++) {
        if (*(ptr+i) == '.') {
            decimalPosition = i;
        }
    }

    if (decimalPosition == -1) {
        decimalPosition = strSize;
    }

    double strNumber = 0;
    double powVal = 1;
    
    for (int i = decimalPosition - 1; i >= firstValidChar; i--) {
        if (*(ptr+i) >= '0' && *(ptr+i) <= '9') {
            strNumber += (*(ptr+i) - '0') * powVal;
        }
        else {
            if (isNegative) {
                return strNumber * -1;
            }
            return strNumber;
        }
        powVal *= 10;
    }

    powVal = 10;
    for (int i = decimalPosition + 1; i < strSize; i++) {
        if (*(ptr+i) >= '0' && *(ptr+i) <= '9') {
            strNumber += (*(ptr+i) - '0') / powVal;
        }
        else {
            if (isNegative) {
                return strNumber * -1;
            }
            return strNumber;
        }
        powVal *= 10;
    }

    if (isNegative) {
        return strNumber * -1;
    }
    return strNumber;
}

int main(int argc, const char * argv[]) {
    int a = asciiBinaryToInt("1110");
    int b = asciiHEXToInt("AF");
    double c = asciiToDouble("-96.3");
    
    char input[256];
    while (input[0] != '\n') {
        fgets(input, sizeof(input), stdin);
        if (input[0] == '\n') {
            break;
        }
        if (checkIfValidAscii(input)) {
            printf("%d \n", asciiHEXToInt(input));
        }
        else {
            printf("ERROR. That's not a valid HEX number\n");
        }
    }
    
    printf("%d \n", a);
    printf("%d \n", b);
    printf("%f \n", c);
    
    return 0;
}
