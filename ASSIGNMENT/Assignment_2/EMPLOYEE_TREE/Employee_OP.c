#include "Employee.h"
int main(){
    Employee *root=NULL;
    Employee *emp;
    int n,id,search_id,i;
    char name[50];
    float salary;
    printf("Enter number of Employees: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter Employee ID: ");
        scanf("%d",&id);
        printf("Enter Employee Name: ");
        scanf(" %49[^\n]",name);
        printf("Enter Employee Salary: ");
        scanf("%f",&salary);
        root=insert_employee(root,id,name,salary);
    }
    printf("\nEnter Employee ID to search: ");
    scanf("%d",&search_id);
    emp=search_employee(root,search_id);
    if(emp!=NULL){
        printf("\nEmployee Found:\n");
        display_employee(emp);
    }
    else{
        printf("\nEmployee Not Found\n");
    }
    printf("\nEmployees with Salary between 50K and 70K:\n");
    display_salary_range(root);
    printf("\nEmployees in Ascending Order of Employee ID:\n");
    display_ascending(root);
    return 0;
}