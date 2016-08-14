#include<stdio.h>
#include<string.h>

void run_test();
void run_main();
void minmax(int values[], int array_size, int *a, int *b);

int main(int argc, char *argv[]){
    if(argc > 0 && argv[1] != NULL && strcmp("test", argv[1]) == 0){
        run_test();
    } else {
        run_main();
    }
}

void run_test(){
    int array_size = 6;
    int expected_smallest_value = -5;
    int expected_largest_value = 38062;

    int values[array_size];
    values[0] = 10;
    values[1] = 17;
    values[2] = -5;
    values[3] = 38062;
    values[4] = 2;
    values[5] = 0;

    int a;
    int b;

    minmax(values, array_size, &a, &b);

    if(a != expected_smallest_value){
        printf("Test Failed: Expected value for smallest number is %d, but actual is %d.\n", expected_smallest_value, a);
    }else if(b != expected_largest_value){
        printf("Test Failed: Expected value for largest number is %d, but actual is %d.\n", expected_largest_value, b);
    }else{
        printf("Test Passed!\n");
    }
}

void run_main(){
    int array_size = 0;
    int i = 0;

    while(array_size == 0){
        printf("Enter the size of array: ");
        scanf("%d", &array_size);

        if(array_size > 0){
            int values[array_size];

            for(; i < array_size; i++){
                printf("Enter the value on index %d: ", i);
                scanf("%d", &values[i]);
            }

            int smallest_value; 
            int largest_value; 
            minmax(values, array_size, &smallest_value, &largest_value);

            printf("The smallest value is %d and the largest value is %d.\n", smallest_value, largest_value);
            getchar();
        }else{
            printf("The array cannot be empty.\n");
        }
    }
}

void minmax(int values[], int array_size, int *a, int *b){
    int i = 0;
    
    *a = 2147483647;
    *b = -2147483647;

    for(; i < array_size; i++){
        if(values[i] < *a){
            *a = values[i];
        }

        if(values[i] > *b){
            *b = values[i];
        }
    }
}