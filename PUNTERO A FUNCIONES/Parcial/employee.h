
#ifndef __EMPLOYEE
#define __EMPLOYEE
struct
{
    char name[51];
    char email[30];
    int isEmpty;
    int index;

}typedef Employee;
#endif // __EMPLOYEE

int compareEmployee(void* pEmployeeA,void* pEmployeeB);
void printEmployee(Employee* p);
Employee* newEmployee(char name[],char email[]);


