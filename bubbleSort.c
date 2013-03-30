#include <stdio.h>

/*
    Bubble Sort
    Author: Steven Hood
    Version: 30/03/2013
*/

void bubbleSort(int *array, int size);
void printArray(int *array, int size);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: bubbleSort <file>\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file for reading\n");
        return 1;
    }

    int size;
    fscanf(fp, "%d\n", &size);
    printf("%d\n", size);

    int array[size];
    int i;
    for (i = 0; i < size; i++) {
        fscanf(fp, "%d ", &array[i]);
    }

    bubbleSort(array, size);
    printArray(array, size);
    
    fclose(fp);
    return 0;
}

void bubbleSort(int *array, int size) {
    int n, i, temp;
    for (n = 0; n < size; n++) {
        for (i = 1; i < (size - n); i++) {

            if (*((array+i)-1) > *(array+i)) {
            
                temp = *((array+i)-1);
                *((array+i)-1) = *(array+i);
                *(array+i) = temp;
            }
        }
    }
}

void printArray(int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", *(array+i));
    }
    printf("\n");
}
