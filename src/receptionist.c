#include <stdio.h>
#include "receptionist.h"

/*
This receptionist file contains the list of 
employee functions and pointer array for the functions
*/
void emp_func_1(){
    printf("\nEmployee Id: 1 is called");
}

void emp_func_2() {
    printf("\nEmployee Id: 2 is called");
}

void emp_func_3(){
    printf("\nEmployee Id: 3 is called");
}

void emp_func_4(){
    printf("\nEmployee Id: 4 is called");
}

void emp_func_5(){
    printf("\nEmployee Id: 5 is called");
}

eventptr eventptr_arr[5] = {
    emp_func_1,
    emp_func_2,
    emp_func_3,
    emp_func_4,
    emp_func_5
};
