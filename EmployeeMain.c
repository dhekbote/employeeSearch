//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 

//gcc employeeMain.c employeeTable.c employeeTwo.c 

#include <string.h> 
#include <stdlib.h>
#include "Employee.h" 

int main(void)
{ 

    // defined in employeeSearchOne.c 
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);


    //defined in employeeTable.c 
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //Declaration 
    
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 
    //Example not found 
    if (matchPtr != NULL) 
        printf("Employee ID 1045 is in record %ld\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee ID is NOT found in the record\n"); 

    //Example found 
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 
    if (matchPtr != NULL) 
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Tony Bobcat is NOT found in the record\n"); 

    // Phone found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-1235"); 
    if (matchPtr != NULL) 
        printf("Employee with number 909-555-1235 is in record %ld\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee with number 909-555-1235 is NOT found in the record\n"); 

    // Phone NOT found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-505-1235"); 
    if (matchPtr != NULL) 
        printf("Employee with number 909-505-1235 is in record %ld\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee with number 909-505-1235 is NOT found in the record\n");

    //Example Salary found 
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78); 
    if (matchPtr != NULL) 
        printf("Employee salary 8.78 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee salary 8.78 is NOT found in the record\n");

    //Example Salary NOT found 
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.20); 
    if (matchPtr != NULL) 
        printf("Employee salary 4.20 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee salary 4.20 is NOT found in the record\n");

    return EXIT_SUCCESS; 
}