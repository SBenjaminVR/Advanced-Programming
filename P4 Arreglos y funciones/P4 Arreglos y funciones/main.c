//
//  main.c
//  P4 Arreglos y funciones
//
//  Created by Benjamin Valdez on 2/21/20.
//

#include "stdio.h"

void printMatrix(int matrix[2][2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
 
void addMatrices(int firstMatrix[2][2], int secondMatrix[2][2]) {
    int additionMatrix[2][2];
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            additionMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
    
    printf("Addition\n");
    printMatrix(additionMatrix);
}
 
void substractMatrices(int firstMatrix[2][2], int secondMatrix[2][2]) {
    int subtractionMatrix[2][2];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            subtractionMatrix[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
        }
    }
    
    printf("Subtraction\n");
    printMatrix(subtractionMatrix);
}
 
void multiplyMatrices(int firstMatrix[2][2], int secondMatrix[2][2]) {
    int number = 0;
    int multiplicationMatrix[2][2];
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                number +=  firstMatrix[i][k] * secondMatrix[k][j];
            }
            multiplicationMatrix[i][j] = number;
            number = 0;
        }
    }
    
    printf("Multiplication\n");
    printMatrix(multiplicationMatrix);
}

void readMatrix(int Matrix[2][2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            scanf("%d", &Matrix[i][j]);
        }
    }
}
 
int main(int argc, const char * argv[]) {
    int firstMatrix[2][2];
    int secondMatrix[2][2];
 
   
    printf("Enter the first Matrix: \n");
    readMatrix(firstMatrix);
 
    printf("Enter the second matrix: \n");
    readMatrix(secondMatrix);
   
    printf("First Matrix: \n");
    printMatrix(firstMatrix);
    printf("Second Matrix: \n");
    printMatrix(secondMatrix);
    
    addMatrices(firstMatrix, secondMatrix);
    substractMatrices(firstMatrix, secondMatrix);
    multiplyMatrices(firstMatrix, secondMatrix);
    
    return 0;
}
