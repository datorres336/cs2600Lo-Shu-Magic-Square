#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    bool isNotMagical = true;
    int count = 1;

    int array[3][3];
    int numbers[9];
   
    srand(time(NULL));

    for (int i = 0; i < 9; i++) {
        numbers[i] = i + 1;
    } 
    while (isNotMagical) {    
        for (int i = 9 - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&numbers[i], &numbers[j]);
    }

    //populating 2D array with shuffled 1-9 numbers
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = numbers[k];
            k++;
        }
    }
    
    /*
   //Print randomly populated 3x3 array // debug code
    for (int i = 0; i < 3; i++) {
        printf("[");
        for (int j = 0; j < 3; j++) {
            printf("%d", array[i][j]);
            if (j < 2) printf(" ");
        }
        printf("]");
        printf("\n");
    }
    */

    //check to see if 2D array is a Lo Shu Magic Square
    int sum = 0;
    bool isEqualTo15 = true;
    bool passed = false;
    while (isEqualTo15) {
        for (int i = 0; i < 3; i++) { //checking horizontal values
            for (int j = 0; j < 3; j++) {
                 sum += array[i][j];
             }
             //printf("Horizontal Sum = %d \n", sum); //debug code
             if (sum != 15) {
                 isEqualTo15 = false;
                 passed = false;
                 //printf("This 2D array is not a Lo Shu Magic Square on the horizontal sum.\n"); // debug code
                 break;
             }
             else
                passed = true;
             sum = 0;
        }

        if(isEqualTo15 != false) {
            for (int i = 0; i < 3; i++) { //checking vertical values
            for (int j = 0; j < 3; j++) {
                 sum += array[j][i];
             }
             //printf("Vertical Sum = %d \n", sum); //debug code
             if (sum != 15) {
                 isEqualTo15 = false;
                 passed = false;
                 //printf("This 2D array is not a Lo Shu Magic Square on the vertical sum.\n"); // debug code
                 break;
             }
             else
                passed = true;
             sum = 0;
        }
        }
        
        if(isEqualTo15 != false) {
            for (int i = 0; i < 3; i++) { //checking diagonal values
            for (int j = 0; j < 3; j++) {
                 if (i == j) {
                    sum += array[i][j];
                 }                    
             }             
            }
            if (sum != 15) {
                 isEqualTo15 = false;
                 passed = false;
                 //printf("This 2D array is not a Lo Shu Magic Square on the diagonal sum.\n"); // debug code
                 break;
             }
             else 
                passed = true;
        }

        isEqualTo15 = false;
        //printf("Number of squares generated: %d\n", count);
        count++;
        if (passed) {
           // printf("This 2D array IS a Lo Shu Magic Square on the diagonal sum.\n"); // debug code
            printf("The total number of squares generated and tested before success: %d\n", count);

            for (int i = 0; i < 3; i++) {
                printf("[");
                for (int j = 0; j < 3; j++) {
                    printf("%d", array[i][j]);
                    if (j < 2) printf(" ");
                }
                printf("]");
                printf("\n");
            }
            
            isNotMagical = false; 
        }        
    }
    }
    return 0;
}