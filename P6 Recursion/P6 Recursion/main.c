//
//  main.c
//  P6 Recursion
//
//  Created by Benjamín Valdez on 2/21/20.
//

#include <stdio.h>

int factorial(int number) {
    if (number == 0 || number == 1)
        return 1;
    else
        return (number * factorial(number - 1));
}

int fibbonacci(int number) {
   if(number == 0 || number == 1)
      return number;
    else
      return (fibbonacci(number-1) + fibbonacci(number-2));
}

int main(int argc, const char * argv[]) {
    int factorialNumber = 0;
    int fibonacciNumber = 0;
    
    printf("Enter the number for which you want to find it's factorial: ");
    scanf("%d", &factorialNumber);
    printf("%d!= %d", factorialNumber, factorial(factorialNumber));
    
    printf("\nFind the fibonacci sequence until n= ");
    scanf("%d", &fibonacciNumber);
    
    for (int i = 0; i < fibonacciNumber; i++) {
        printf("%d ", fibbonacci(i));
    }
    printf("\n");
    
    return 0;
}
