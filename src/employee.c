#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "employee.h"
#include "receptionist.h"

static struct emp emparr[5];
struct emp *head = NULL;
struct emp *tail = NULL;

/*
    Initializing employee details.
*/
void initialize_employees()
{
    initialize_employee_service(emp1, "arnold", eventptr_arr[0]);
    initialize_employee_service(emp2, "tyson", eventptr_arr[1]);
    initialize_employee_service(emp3, "batista", eventptr_arr[2]);
    initialize_employee_service(emp4, "undertaker", eventptr_arr[3]);
    initialize_employee_service(emp5, "tripleh", eventptr_arr[4]);
}

/*  
    Parsing employee details and callback into a employee linked list structure.
*/
void initialize_employee_service(int id, char e_name[10], void (*cb_ptr)())
{
    struct emp *new_emp = (struct emp *)malloc(sizeof(struct emp));
    if (new_emp != NULL)
    {
        new_emp->emp_id = id;
        strcpy(new_emp->name, e_name);
        new_emp->cb_func_ptr = cb_ptr;
        new_emp->next = NULL;
    }
    if (head == NULL)
    {
        head = new_emp;
        tail = new_emp;
    }
    else
    {
        tail->next = new_emp;
        tail = new_emp;
    }
    printf("\nEmployee %d - %s registered successfully", id, new_emp->name);
}

/*
    Validate employee details using the employee name.
*/
bool validate_employee(char emp_name[20])
{
    struct emp *f;
    f = head;
    while (f != NULL)
    {
        if (strcmp(f->name, emp_name) == 0)
        {
            return true;
        }
        f = f->next;
    }
    printf("\nPlease select employees from the given list of registered employees");
    return false;
    
}

/*
    To show the list of employees which are getting registered by parsing linked list.
*/
void registered_employee_list()
{
    struct emp *p;
    p = head;
    printf("\n\nRegistered Employees List\n");
    while (p != NULL)
    {
        printf("\nEmp_Id : %d\t", p->emp_id);
        printf("Emp_Name : %s\t\t", p->name);
        p = p->next;
    }
    printf("\n");
}

/*
    Handling the callback according to the employee details
*/
void cb_func(char emp_name[20])
{
    struct emp *f;
    f = head;
    while (f != NULL)
    {
        if (strcmp(f->name, emp_name) == 0)
        {
            f->cb_func_ptr();
        }
        f = f->next;
    }
}