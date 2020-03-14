//
//  main.c
//  P8 Data Union
//
//  Created by Benjamín Valdez on 3/12/20.
//

#include <stdio.h>
#include <float.h>
#include <string.h>

union Data {
   int unionInt;
   float unionDouble;
   char unionString[101];
};

int main(int argc, const char * argv[]) {
    union Data inputs;
    
    int input1 = 0;
    char input2 = ' ';
    double input3 = 0;
    
    printf("Give me a integer: ");
    scanf("%d", &input1);
    inputs.unionInt = input1;
    printf("Your integer <%d> storage size is <<%lu>> bytes\n", input1, sizeof(input1));
    
    printf("Give me a double: ");
    scanf("%lf", &input3);
    inputs.unionDouble = input3;
    printf("Your double <%f> storage size is <<%lu>> bytes, I can read any number from <<%f>> to <<%f>> in this data type.\n", input3, sizeof(input3), DBL_MIN, DBL_MAX);
    
    printf("Give me a char: ");
    scanf("%s", &input2);
    strcpy(inputs.unionString, &input2);
    printf("Your char <%c> storage size is <<%lu>> bytes. And I can read it as <<%c>> or as <<%d>>\n", input2,sizeof(input2), input2, input2);
    
    return 0;
}
