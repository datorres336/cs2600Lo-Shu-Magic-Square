#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//  CODE WORKS DON'T DELETE
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffleArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

int main() {
    int array[3][3];
    //int array[3][3] = {{4,9,2},{3,5,7},{8,1,6}}; //test code IS a magical square
    //int array[3][3] = {{4,9,2},{3,5,7},{8,1,2}}; //test code is NOT  magical square
    int numbers[9];

    
    for (int i = 0; i < 9; i++) { //don't delete
        numbers[i] = i + 1;
    }
    

    shuffleArray(numbers, 9);
    //populating 2D array with shuffled 1-9 numbers
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = numbers[k];
            k++;
        }
    }
    

   //Print randomly populated 3x3 array
    for (int i = 0; i < 3; i++) {
        printf("[");
        for (int j = 0; j < 3; j++) {
            printf("%d", array[i][j]);
            if (j < 2) printf(" ");
        }
        printf("]");
        printf("\n");
    }
    printf("\n");

    //check to see if 2D array is a Lo Shu Magic Square
    int sum = 0;
    bool isEqualTo15 = true;
    bool passed = false;
    while (isEqualTo15) {
        for (int i = 0; i < 3; i++) { //checking horizontal values
            for (int j = 0; j < 3; j++) {
                 sum += array[i][j];
             }
             printf("Horizontal Sum = %d \n", sum); //test code
             if (sum != 15) {
                 isEqualTo15 = false;
                 passed = false;
                 printf("This 2D array is not a Lo Shu Magic Square on the horizontal sum.\n");
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
             printf("Vertical Sum = %d \n", sum); //test code
             if (sum != 15) {
                 isEqualTo15 = false;
                 passed = false;
                 printf("This 2D array is not a Lo Shu Magic Square on the vertical sum.\n");
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
                    printf("i = %d\n", i); //test code
                    printf("j = %d\n", j); //test code
                    sum += array[i][j];
                    printf("Sum = %d \n", sum); //test code
                 }
                    
             }             
            }
            if (sum != 15) {
                 isEqualTo15 = false;
                 passed = false;
                 printf("This 2D array is not a Lo Shu Magic Square on the diagonal sum.\n");
                 break;
             }
             else 
                passed = true;
        }

        isEqualTo15 = false;
        if (passed)
            printf("This 2D array IS a Lo Shu Magic Square on the diagonal sum.\n"); //test code
        
    }
    
    return 0;
}