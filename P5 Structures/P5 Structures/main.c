//
//  main.c
//  P5 Structures
//
//  Created by Benjamin Valdez on 2/21/20.
//

#include <stdio.h>
#include <string.h>

struct Agent {
    char name[256];
    char lastName[256];
    int age;
    char gender;
    char mission[14];
};

int main(int argc, const char * argv[]) {
    struct Agent userAgent;
    char stringInputs[256];
    int numberInputs = 0;
    char charInputs = ' ';
    
    printf("Greetings Agent, I require some information about you!\n");
    printf("First of all, what's your first name? ");
    fgets(stringInputs, sizeof(stringInputs), stdin);
    strcpy(userAgent.name, stringInputs);
    
    printf("What's your last name? ");
    fgets(stringInputs, sizeof(stringInputs), stdin);
    strcpy(userAgent.lastName, stringInputs);
    
    printf("What's your current age? ");
    scanf("%d", &numberInputs);
    userAgent.age = numberInputs;
    
    printf("What's your gender? (M/F) ");
    scanf("%s", &charInputs);
    userAgent.gender = charInputs;
    
    //To avoid reading the enter as a string
    fflush(stdin);
    fgets(stringInputs, sizeof(stringInputs), stdin);
    
    printf("What's your current mission? ");
    fgets(stringInputs, sizeof(stringInputs), stdin);
    strcpy(userAgent.mission, stringInputs);
    
    return 0;
}
