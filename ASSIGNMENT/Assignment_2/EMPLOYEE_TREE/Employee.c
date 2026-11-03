#include "Employee.h"
Employee* new_employee(int id,char name[],float salary){
    Employee *emp=(Employee*)malloc(sizeof(Employee));
    if(emp==NULL)
        return NULL;
    emp->emp_id=id;
    strcpy(emp->name,name);
    emp->salary=salary;
    emp->left=NULL;
    emp->right=NULL;
    return emp;
}
Employee* insert_employee(Employee *root,int id,char name[],float salary){
    if(root==NULL)
        return new_employee(id,name,salary);
    if(id<root->emp_id)
        root->left=insert_employee(root->left,id,name,salary);
    else if(id>root->emp_id)
        root->right=insert_employee(root->right,id,name,salary);
    else
        printf("Employee ID already exists\n");
    return root;
}
Employee* search_employee(Employee *root,int id){
    if(root==NULL || root->emp_id==id)
        return root;
    if(id<root->emp_id)
        return search_employee(root->left,id);
    return search_employee(root->right,id);
}
void display_employee(Employee *emp){
    if(emp==NULL)
        return;
    printf("\nEmployee ID: %d",emp->emp_id);
    printf("\nName: %s",emp->name);
    printf("\nSalary: %.2f\n",emp->salary);
}
void display_salary_range(Employee *root){
    if(root==NULL)
        return;
    display_salary_range(root->left);
    if(root->salary>=50000 && root->salary<=70000)
        display_employee(root);
    display_salary_range(root->right);
}
void display_ascending(Employee *root){
    if(root==NULL)
        return;
    display_ascending(root->left);
    display_employee(root);
    display_ascending(root->right);
}