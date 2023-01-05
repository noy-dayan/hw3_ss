#include <stdio.h>

#define SIZE 50

void shift_element(int* arr, int i);
void insertion_sort(int* arr, int len);

// Shifting the elements of an array to the right by one position, according to the pointer.
void shift_element(int* arr, int i) {
    for(int tmp = i; tmp < 0; tmp--)
        *(arr + tmp)= *(arr + tmp - 1); 
}

// Preform insertion sort on array.
void insertion_sort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int* current = arr + i; // 'current' points to the element being processed in the current iteration.
        int* j = current - 1; // 'j' points to the element preceding 'current'.
        while (j >= arr && *j > *current) {
            // Swap the elements pointed to by 'j' and 'current'.
            int tmp = *j;
            *j = *current;
            *current = tmp;
            // Move 'current' and 'j' one position to the left.
            current--;
            j--;
        }
    }
}

// Main function for isort.c
int main() {  
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        scanf(" %d",&(*(arr+i)));
    insertion_sort(arr,SIZE);
    for (int i = 0; i < SIZE; i++){
        if(i==SIZE-1){
          printf("%d\n",*(arr+i));
          break;
        }
        printf("%d,",*(arr+i));
    }
    return 0;
}