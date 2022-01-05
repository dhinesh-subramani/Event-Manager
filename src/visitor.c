#include <stdio.h>
#include <string.h>
#include "employee.h"
#include "visitor.h"
#include "receptionist.h"

static struct visitor visitorarr[5];

void main()
{
    int emp_size = 0;

    //Initializing employee details
    initialize_employees();

    // List of registered employees
    registered_employee_list();

    printf("\nEnter employee size - Maximum allowed size is 5\n");
    scanf("%d", &emp_size);

    //Get the employees and event details from visitor to perform appropriate action
    printf("\nEnter employees details which you want to communicate");
    for (int i = 0; i < emp_size; i++)
    {
        int exit = 0;
        int count = 0;
        while(1){
            printf("\nEnter employee name: ");
            scanf("%s", visitorarr[i].emp_name);
            if(validate_employee(visitorarr[i].emp_name)){
                break;
            }
        }
        printf("\nSelect the event numbers separated by space\n1 - Visitor\n2 - Parcel\n3 - PhoneCall\n");
        do
        {
            scanf("%d", &visitorarr[i].events[count++]);

        } while (getchar() != '\n');

    }
    printf("\nEmployees & Events details collected successfully\n");

    // According to the events from visitor input, call the appropriate employee and its related functions
    printf("\nList of Employees & Events mappings\n");
    for (int j = 0; j < emp_size; j++)
    {
        struct visitor _visitor = visitorarr[j];
        int length = sizeof(_visitor.events) / sizeof(_visitor.events[0]);
        int event = 0;

        // Employee call back function getting invoked
        cb_func(_visitor.emp_name);
        
        printf("\nEmployee Name : %s", _visitor.emp_name);
        printf("\nEmployee assigned events: ");

        for (int k = 0; k < length; k++)
        {
            event = _visitor.events[k];
            switch (event)
            {
            case 1:
                printf("\nVisitor");
                break;
            case 2:
                printf("\nParcel");
                break;
            case 3:
                printf("\nPhoneCall");
                break;
            
            default:
                break;
            }
        }
        printf("\n");
    }
}