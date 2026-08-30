#include "student.h"

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>


void test(){

    List *list = list_new();
    int flag = 1;
    while(flag){
        printf("\n1. Add student\n2. Modify\n3. Remove Student\n4. Display\n5. Exit\n");
        int n;
        scanf("%d" ,&n);
        switch(n){
            case 1:{
                student_add(list); 
                student_length(list);
                break;
            }
            case 2:{
                // printf("Enter the Roll Number of the Student : ");
                // long long key;
                // scanf("%lld" ,&key);
                student_modify(list);
                break;
            }
            case 3:{
                // printf("Enter the Roll Number of the Student to be Removed: ");
                // long long key;
                // scanf("%lld" ,&key);
                student_remove(list);
                student_length(list);
                break;
            }
            case 4:{
                display_student(list);
                break;
            }
            case 5:{
                printf("THANK YOU\n");
                flag = 0;
                break;
            }
            default :{
                printf("Invalid Choice");
            }
        }
    }

}
int main(){

    test();
    return 0;
}