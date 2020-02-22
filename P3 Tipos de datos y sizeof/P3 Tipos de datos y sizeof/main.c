//
//  main.c
//  P3 Tipos de datos y sizeof
//
//  Created by Benjamin Valdez on 2/21/20.
//

#include <stdio.h>
#include <float.h>

int main(int argc, const char * argv[]) {
    int input1 = 0;
    char input2 = ' ';
    double input3 = 0;
    
    printf("Give me a integer: ");
    scanf("%d", &input1);
    printf("Give me a char: ");
    scanf("%s", &input2);
    printf("Give me a double: ");
    scanf("%lf", &input3);
    
    printf("\nYour integer <%d> storage size is <<%lu>> bytes\n", input1, sizeof(input1));
    printf("Your char <%c> storage size is <<%lu>> bytes. And I can read it as <<%c>> or as <<%d>>\n", input2,sizeof(input2), input2, input2);
    printf("Your double <%f> storage size is <<%lu>> bytes, I can read any number from <<%f>> to <<%f>> in this data type.\n", input3, sizeof(input3), DBL_MIN, DBL_MAX);
    
    
    return 0;
}
