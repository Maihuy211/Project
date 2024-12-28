#include <stdio.h>
#include "functions.h"
#include <string.h>
void menuStart(){
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t  CHOOSE YOUR ROLE\n");
    printf("\t=====================\n");
    printf("\t[1] Admin.\n");
    printf("\t[2] Student.\n");
    printf("\t[3] Teacher. \n");
    printf("\t[0] Exit the Program.\n");
    printf("\t=====================\n");
}
void menuAdmin(){
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t          MENU\n");
    printf("\t==========================\n");
    printf("\t[1] Students management.\n");
    printf("\t[2] Classrooms management.\n");
    printf("\t[3] Teacher management.\n");
    printf("\t[4] User Guideline.\n");
    printf("\t[5] About Us.\n");
    printf("\t[0] Back.\n");
    printf("\t==========================\n");
}
void menuStudents(){
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t    STUDENT MENU\n");
    printf("\t======================\n");
    printf("\t[1] Add A new student.\n");
    printf("\t[2] Show All students.\n");
    printf("\t[3] Delete A student.\n");
    printf("\t[4] Edit A student.\n");
    printf("\t[5] Search A student.\n");
    printf("\t[6] Soft A student.\n");
    printf("\t[0] Back.\n");
    printf("\t======================\n");
}
void addStudent(int *length, struct Student sv[]){
    printf("\n\t***Add A New Student***\n");
	int newStudents;
    printf("\nAdd number of students: ");
    scanf("%d", &newStudents);
    getchar(); 
    int i;
    for(i=*length;i<*length+newStudents;i++){
        printf("\n       Student %d\n", i + 1);
        printf("Enter the ID: ");
        fgets(sv[i].studentId, 10, stdin);
        sv[i].studentId[strcspn(sv[i].studentId, "\n")]= '\0'; 
        printf("Enter the Name: ");
        fgets(sv[i].fullName, 30, stdin);
        sv[i].fullName[strcspn(sv[i].fullName, "\n")]= '\0';
        printf("Enter the date of birth (dd / mm / yyyy): \n");
        printf("   Enter the day: ");
        scanf("%d", &sv[i].dateOfBrith.day);
        printf("   Enter the month: ");
        scanf("%d", &sv[i].dateOfBrith.month);
        printf("   Enter the year: ");
        scanf("%d", &sv[i].dateOfBrith.year);
        printf("Enter the Gender(1 for Male, 0 for Female): ");
        scanf("%d", &sv[i].gender);
        getchar(); 
        printf("Enter the Class: ");
        fgets(sv[i].classroomId, 10, stdin);
        sv[i].classroomId[strcspn(sv[i].classroomId, "\n")] = '\0';
        printf("Enter the Email: ");
        fgets(sv[i].email, 30, stdin);
        sv[i].email[strcspn(sv[i].email, "\n")]= '\0';
        printf("Enter the Phone: ");
        fgets(sv[i].phone, 20, stdin);
        sv[i].phone[strcspn(sv[i].phone, "\n")]= '\0';
        printf("Enter the Password: ");
        fgets(sv[i].password, 20, stdin);
        sv[i].password[strcspn(sv[i].password, "\n")]= '\0';
    }
    *length += newStudents;
    printf("\nStudent Added Successfully.\n");
}
void printHeader(){
	printf("\n\2t***All Student***\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|=====================|\n");
    printf("| ID         | ID Class    | FullName                   | Date Of Brith         | Gender     | Email                      | Phone               | Password            |\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|=====================|\n");
}
void printStudent(int length, struct Student sv[]){
    int i;
    for(i=0;i<length;i++){
    printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s| %-20s|\n",
            sv[i].studentId,
            sv[i].classroomId,
            sv[i].fullName,
            sv[i].dateOfBrith.day,
            sv[i].dateOfBrith.month,
            sv[i].dateOfBrith.year,
            sv[i].gender ? "Male" : "Female",
            sv[i].email,
            sv[i].phone,
            sv[i].password);
            printf("|------------|-------------|----------------------------|-----------------------|------------|----------------------------|---------------------|---------------------|\n");
    }
}
void saveStudentToFile(int length, struct Student sv[]){
    FILE *fptr = fopen("studentsData.dat", "wb");
    if (fptr == NULL) {
        printf("Cannot open file\n");
        return;
    }
    fwrite(sv, sizeof(struct Student), 50, fptr);
    printf("Student data saved successfully\n");
    fclose(fptr);
}
void loadClassesFromFile(int *length, struct Student sv[]){
    FILE *fptr = fopen("studentsData.dat", "rb");
    if (fptr == NULL) {
        printf("No data found.\n");
        return;
    }
    *length = fread(sv, sizeof(struct Student), 50, fptr);
    fclose(fptr);
}
void deleteStudent(int *length, struct Student sv[]) {
    printf("\n\t***Delete a Student***\n");
    char id[10];
    printf("\nEnter the student ID to delete: ");
    fgets(id, 10, stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex = -1;
    int i;
    for(i=0;i<*length; i++) {
        if(strcmp(sv[i].studentId, id) == 0) {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("\nStudent with ID %s not found.\n", id);
    } else {
        printf("\nOne Student Found for ID: %s\n", id);
        printf("  Student Information:\n");
        printf("----------------------\n");
        printHeader();
        printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s| %-20s|\n",
               sv[findIndex].studentId,
               sv[findIndex].classroomId,
               sv[findIndex].fullName,
               sv[findIndex].dateOfBrith.day,
               sv[findIndex].dateOfBrith.month,
               sv[findIndex].dateOfBrith.year,
               sv[findIndex].gender ? "Male" : "Female",
               sv[findIndex].email,
               sv[findIndex].phone,
               sv[findIndex].password);
        for(i=findIndex;i<*length-1; i++){
            sv[i]=sv[i+1];
        }
        (*length)--;
        printf("\n\t***Updated The New Student ***\n");
        printHeader();
        printStudent(*length, sv);
        printf("\nStudent Deleted Successfully.\n");
    }
}
void editStudent(int length, struct Student sv[]) {
    printf("\n\t***Edit a Student***\n");
    char id[10];
    printf("\nEnter the student ID to edit: ");
    fgets(id, 10, stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex = -1;
    int i;
    for(i=0;i<length;i++) {
        if(strcmp(sv[i].studentId, id)==0) {
            findIndex=i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("\nStudent with ID %s not found.\n", id);
    } else {
        printf("\nOne Student Found for ID: %s\n", id);
        printf("  Student Information:\n");
        printf("----------------------\n");
        printHeader();
        printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s| %-20s|\n",
               sv[findIndex].studentId,
               sv[findIndex].classroomId,
               sv[findIndex].fullName,
               sv[findIndex].dateOfBrith.day,
               sv[findIndex].dateOfBrith.month,
               sv[findIndex].dateOfBrith.year,
               sv[findIndex].gender ? "Male" : "Female",
               sv[findIndex].email,
               sv[findIndex].phone,
               sv[findIndex].password
		);
        printf("Enter new Name: ");
        fgets(sv[findIndex].fullName, 30, stdin);
        sv[findIndex].fullName[strcspn(sv[findIndex].fullName, "\n")]= '\0';
        printf("Enter new date of birth (dd / mm / yyyy):\n");
        printf("   Enter new day: ");
        scanf("%d", &sv[findIndex].dateOfBrith.day);
        printf("   Enter new month: ");
        scanf("%d", &sv[findIndex].dateOfBrith.month);
        printf("   Enter new year: ");
        scanf("%d", &sv[findIndex].dateOfBrith.year);
        printf("Enter new Gender (1 for Male, 0 for Female): ");
        scanf("%d", &sv[findIndex].gender);
        getchar();
        printf("Enter new Class: ");
        fgets(sv[findIndex].classroomId, 10, stdin);
        sv[findIndex].classroomId[strcspn(sv[findIndex].classroomId, "\n")]= '\0';
        printf("Enter new Email: ");
        fgets(sv[findIndex].email, 30, stdin);
        sv[findIndex].email[strcspn(sv[findIndex].email, "\n")]= '\0';
        printf("Enter new Phone: ");
        fgets(sv[findIndex].phone, 20, stdin);
        sv[findIndex].phone[strcspn(sv[findIndex].phone, "\n")]= '\0';
        printf("Enter new Password: ");
        fgets(sv[findIndex].password, 20, stdin);
        sv[findIndex].password[strcspn(sv[findIndex].password, "\n")]= '\0';
        printf("\n\t***Updated Student List***\n");
        printHeader();
        printStudent(length, sv);
        printf("\nStudent Edited Successfully.\n");
    }
}
void searchStudent(int length, struct Student sv[]){
    printf("\n\t***Search a Student***\n");
	char name[30];
    printf("\nEnter the name of the student to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    int i;
    int findIndex=-1;
	for(i=0;i<length; i++) {
        if (strcmp(sv[i].fullName,name)==0){
            findIndex=i;
            break;
        }
    }
    if (findIndex==-1){
        printf("\nNo student found with the name %s.\n",name);
    }else{
        printf("\nStudent found with the name %s.",name);
        printf("\nStudents Finded Successfully.\n");
	}
}
void sortStudentsByName(int length, struct Student sv[]){
    int choice4;
	do{
		printf("\n\t***Sort a Student***\n");
	    printf("\n");
	    printf("\t  SortStudents\n");
	    printf("\t=====================\n");
	    printf("\t[1] Increase.\n");
	    printf("\t[2] Reduce.\n");
	    printf("\t[0] Back.\n");
	    printf("\t=====================\n");
		printf("\tEnter the Choice: ");
	    scanf("%d", &choice4);
		switch(choice4){
			struct Student temp;
			int i,j;
			case 1:
			    printf("\n\t  Increase Sort\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(sv[i].fullName, sv[j].fullName)>0){
			                temp = sv[i];
			                sv[i] = sv[j];
			                sv[j] = temp;
			            }
			        }
			    }
			    printHeader();
		        printStudent(length,sv);
			    printf("\nStudents Are Placed Successfully.\n");
				break;
			case 2:
				printf("\n\t  Reduce Sort\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(sv[i].fullName, sv[j].fullName)<0){
			                temp=sv[i];
			                sv[i]=sv[j];
			                sv[j]=temp;
			            }
			        }
			    }
			    printHeader();
		        printStudent(length,sv);
			    printf("\nStudents Are Placed Successfully.\n");
				break;
			case 0:
				break;
			default:
				printf("\tERROR: Please try again.\n");
	    }
	}while(choice4!=0);
}
	
		


