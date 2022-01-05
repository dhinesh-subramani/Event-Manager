#include <stdbool.h>

typedef void(*cbptr)();

struct emp {
    int emp_id;
    char name[20];
    cbptr cb_func_ptr;
    struct emp *next;
};

enum emp_id {
    ini_emp,
    emp1,
    emp2,
    emp3,
    emp4,
    emp5,
    max_emp
};

void initialize_employees();

void initialize_employee_service(int id, char e_name[10], void (*cb_ptr)());

void registered_employee_list();

bool validate_employee(char emp_name[20]);

void cb_func (char emp_name[20]);