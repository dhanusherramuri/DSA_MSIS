#ifndef _INCLUDED_EMPLOYEE_
#define _INCLUDED_EMPLOYEE_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _employee_ Employee;
struct _employee_{
    int emp_id;
    char name[50];
    float salary;
    Employee *left;
    Employee *right;
};
Employee* new_employee(int id,char name[],float salary);
Employee* insert_employee(Employee *root,int id,char name[],float salary);
Employee* search_employee(Employee *root,int id);
void display_employee(Employee *emp);
void display_salary_range(Employee *root);
void display_ascending(Employee *root);
#endif