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
    printf("\t[1] Add A new Student.\n");
    printf("\t[2] Show All Students.\n");
    printf("\t[3] Delete A Student.\n");
    printf("\t[4] Edit A Student.\n");
    printf("\t[5] Search A Student.\n");
    printf("\t[6] Sort A Student.\n");
    printf("\t[0] Back.\n");
    printf("\t======================\n");
}
void addStudent(int *length, struct Student sv[]){
    printf("\n\t***Add A New Student***\n");
	int newStudents;
    printf("\nAdd number of Students: ");
    scanf("%d", &newStudents);
    getchar();
    int i, j, valid;
    for(i = *length;i<*length+newStudents;i++){
        printf("\n       Student %d\n",i+1);
	    do{
	    	valid=1;
	        printf("Enter the ID: ");
	        fgets(sv[i].studentId, 10, stdin);
	        sv[i].studentId[strcspn(sv[i].studentId, "\n")] = '\0';
	        if (strlen(sv[i].studentId)==0){
	            printf("Invalid ID. Please try again.\n");
	            valid = 0;
	        }
	        for(j=0;j<i;j++){
	            if (strcmp(sv[i].studentId,sv[j].studentId)==0){
	                printf("Invalid ID. Please enter a unique ID.\n");
	                valid = 0;
	                break;
	            }
	        }
	    }while(!valid);
	    do {
            valid = 1;
            printf("Enter the Name: ");
		    fgets(sv[i].fullName, 30, stdin); 
		    sv[i].fullName[strcspn(sv[i].fullName, "\n")] = '\0';  
		    if (strlen(sv[i].fullName) == 0) {
		        printf("Invalid Name. Please try again.\n");
		        valid = 0;
		    }
		}while(!valid);
	    do{
	    	valid=1;
	    	printf("Enter the date of birth (dd/mm/yyyy): \n");
		    printf("   Enter the day: ");
		    scanf("%d", &sv[i].dateOfBrith.day);
		    printf("   Enter the month: ");
		    scanf("%d", &sv[i].dateOfBrith.month);
		    printf("   Enter the year: ");
		    scanf("%d", &sv[i].dateOfBrith.year);
		    getchar();
		    switch(sv[i].dateOfBrith.month){
		    	case 2:
		    		if(sv[i].dateOfBrith.year%4==0&&sv[i].dateOfBrith.year%100!=0 ||sv[i].dateOfBrith.year%400==0){
			            if(sv[i].dateOfBrith.day>0&&sv[i].dateOfBrith.day<=29){
	           	            break;
	           	        }else{
	           		        printf("Invalid. Please try again.\n");
	           		        valid = 0;
				        }
			        }else{
				        if(sv[i].dateOfBrith.day>0&&sv[i].dateOfBrith.day<=28){
	           	            break;
	           	        }else{
	           		        printf("Invalid. Please try again.\n");
	           		        valid = 0;
				        }
			        }
			        break;
			    case 1:
			    case 3:
			    case 5:
			    case 7:
			    case 8:
			    case 10:
			    case 12:
			    	if(sv[i].dateOfBrith.day>0&&sv[i].dateOfBrith.day<=31){
	           	        break;
	           	    }else{
	           		    printf("Invalid. Please try again.\n");
	           		    valid = 0;
				    }
				    break;
				case 4:
				case 6:
				case 9:
				case 11:
					if(sv[i].dateOfBrith.day>0&&sv[i].dateOfBrith.day<=30){
	           	        break;
	           	    }else{
	           		    printf("Invalid. Please try again.\n");
	           		    valid = 0;
				    }
				    break;
				default:
					printf("Invalid. Please try again.\n");
	           		valid = 0;
	        }
		}while(!valid);
	    do{
		    valid = 1;
		    printf("Enter the Gender (1 for Male, 0 for Female): ");
            scanf("%d",&sv[i].gender);
            getchar();
		    if(sv[i].gender!= 1&&sv[i].gender!=0) {
		        printf("Invalid Gender. Please try again.\n");
		        valid = 0;
		    }
        }while(!valid);
		do{
		    valid = 1;
		    printf("Enter the IDclass: ");
		    fgets(sv[i].classroomId, 10, stdin);
	        sv[i].classroomId[strcspn(sv[i].classroomId, "\n")] = '\0';
		    if(strlen(sv[i].classroomId)==0){
		        printf("Invalid IDclass. Please try again.\n");
		        valid = 0;
		    }
		}while(!valid);
		do {
		    valid = 1;
		    printf("Enter the Email: ");
		    fgets(sv[i].email, 30, stdin);
		    sv[i].email[strcspn(sv[i].email, "\n")] = '\0';
		    if (strlen(sv[i].email) == 0) {
		        printf("Invalid Email. Please try again.\n");
		        valid = 0;
		        continue; 
		    }
		    for (j=0;j<i;j++){
		        if (strcmp(sv[i].email, sv[j].email) == 0){
		            printf("Invalid Email. Please enter a unique Email.\n");
		            valid = 0;
		            break;
		        }
		    }
		    char *check = strchr(sv[i].email, '@'); 
		    if (!check || check == sv[i].email || strchr(check + 1, '@') || strchr(check + 1, '.') == NULL) {
		        printf("Invalid Email. Please try again.\n");
		        valid = 0;
		        continue;
		    }
		    if (check - sv[i].email < 1) { 
		        printf("Invalid Email. Please try again.\n");
		        valid = 0;
		        continue;
		    }
		} while (!valid);
	    do{
	        valid = 1;
	        printf("Enter the Phone (exactly 10 characters): ");
	        scanf("%s",sv[i].phone);
	        getchar();
	        if(strlen(sv[i].phone)!=10){
	            printf("Invalid Phone. Please try again.\n");
	            valid = 0;
	            continue;
	        }
	        for(j=0;j<i;j++){
	            if(strcmp(sv[i].phone,sv[j].phone) == 0){
	                printf("Invalid Phone. Please enter a unique Phone.\n");
	                valid = 0;
	                break;
	            }
	        }
	    }while(!valid);
	    printf("Enter the Password: ");
	    fgets(sv[i].password, 20, stdin);
	    sv[i].password[strcspn(sv[i].password, "\n")] = '\0';
   }
    *length += newStudents;
    printf("\nStudent Added Successfully.\n");
}
void printHeader(){
	printf("\n\t  ***All Student***\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|\n");
    printf("| ID         | ID Class    | FullName                   | Date Of Brith         | Gender     | Email                      | Phone               |\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|\n");
}
void printStudent(int length, struct Student sv[]){
    
	int i;
    for(i=0;i<length;i++){
    printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s|\n",
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
            printf("|------------|-------------|----------------------------|-----------------------|------------|----------------------------|---------------------|\n");
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
void loadStudentFromFile(int *length, struct Student sv[]){
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
    getchar();
	char id[10];
    printf("\nEnter the student ID to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex= -1;
    int i;
    for(i=0;i<*length; i++) {
        if(strcmp(sv[i].studentId, id) == 0) {
            findIndex= i;
            break;
        }
    }
    if(findIndex==-1) {
        printf("\nStudent with ID %s not found.\n", id);
    }else{
		printf("\nOne Student Found for ID: %s\n", id);
        printf("  Student Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n",sv[findIndex].classroomId);
        printf("FullName: %s\n",sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n",sv[findIndex].dateOfBrith.day,sv[findIndex].dateOfBrith.month,sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n",sv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n",sv[findIndex].email);
        printf("Phone: %s\n",sv[findIndex].phone);
        printf("Password: %s\n",sv[findIndex].password);
		int choice6;
		printf("\n\t   Confirm Deletion ?\n");
		printf("\t======================\n");
		printf("\t[1] Yes.\n");
		printf("\t[0] No.\n");
		printf("\t======================\n");
		printf("\tEnter the Choice: ");
	    scanf("%d", &choice6);
		switch(choice6){
			case 1:
				for(i=findIndex;i<*length-1; i++){
		            sv[i]=sv[i+1];
		        }
		        (*length)--;
		        printf("\n\t***Updated The New Student ***\n");
		        printHeader();
		        printStudent(*length, sv);
		        printf("\nStudent Deleted Successfully.\n");
				break;
		    case 0:
				printf("\nDo Not Delete Student.\n");
				break;
		    default:
		        printf("\tERROR: Please try again.\n");		
       }
    }
}
void editStudent(int length, struct Student sv[]) {
    printf("\n\t***Edit a Student***\n");
    getchar();
    char id[10];
    int i, j, valid;
    printf("\nEnter the student ID to edit: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex=-1;
    for(i=0;i<length;i++) {
        if(strcmp(sv[i].studentId, id)==0) {
            findIndex=i;
            break;
        }
    }
    if (findIndex== -1) {
        printf("\nStudent with ID %s not found.\n", id);
    }else{
        printf("\nOne Student Found for ID: %s\n", id);
        printf("  Student Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n",sv[findIndex].classroomId);
        printf("FullName: %s\n",sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n",sv[findIndex].dateOfBrith.day,sv[findIndex].dateOfBrith.month,sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n",sv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n",sv[findIndex].email);
        printf("Phone: %s\n",sv[findIndex].phone);
        printf("Password: %s\n",sv[findIndex].password);
        printf("\n");
		do {
            valid = 1;
            printf("Enter new Name: ");
		    fgets(sv[findIndex].fullName, 30, stdin); 
		    sv[findIndex].fullName[strcspn(sv[findIndex].fullName, "\n")] = '\0';  
		    if (strlen(sv[findIndex].fullName) == 0) {
		        printf("Invalid Name. Please try again.\n");
		        valid = 0;
		    }
		}while(!valid);
	    do{
	    	valid=1;
	    	printf("Enter new date of birth (dd/mm/yyyy): \n");
		    printf("   Enter new day: ");
		    scanf("%d", &sv[findIndex].dateOfBrith.day);
		    printf("   Enter new month: ");
		    scanf("%d", &sv[findIndex].dateOfBrith.month);
		    printf("   Enter new year: ");
		    scanf("%d", &sv[findIndex].dateOfBrith.year);
		    getchar();
		    switch(sv[findIndex].dateOfBrith.month){
		    	case 2:
		    		if(sv[findIndex].dateOfBrith.year%4==0&&sv[findIndex].dateOfBrith.year%100!=0||sv[findIndex].dateOfBrith.year%400==0){
			            if(sv[findIndex].dateOfBrith.day>0&&sv[findIndex].dateOfBrith.day<=29){
	           	            break;
	           	        }else{
	           		        printf("Invalid. Please try again.\n");
	           		        valid = 0;
				        }
			        }else{
				        if(sv[findIndex].dateOfBrith.day>0&&sv[findIndex].dateOfBrith.day<=28){
	           	            break;
	           	        }else{
	           		        printf("Invalid. Please try again.\n");
	           		        valid = 0;
				        }
			        }
			        break;
			    case 1:
			    case 3:
			    case 5:
			    case 7:
			    case 8:
			    case 10:
			    case 12:
			    	if(sv[findIndex].dateOfBrith.day>0&&sv[findIndex].dateOfBrith.day<=31){
	           	        break;
	           	    }else{
	           		    printf("Invalid. Please try again.\n");
	           		    valid = 0;
				    }
				    break;
				case 4:
				case 6:
				case 9:
				case 11:
					if(sv[findIndex].dateOfBrith.day>0&&sv[findIndex].dateOfBrith.day<=30){
	           	        break;
	           	    }else{
	           		    printf("Invalid. Please try again.\n");
	           		    valid = 0;
				    }
				    break;
				default:
				    printf("Invalid. Please try again.\n");
	           		valid = 0;	
	        }
		}while(!valid);
	    do{
		    valid = 1;
		    printf("Enter new Gender (1 for Male, 0 for Female): ");
            scanf("%d",&sv[findIndex].gender);
            getchar();
		    if(sv[findIndex].gender!= 1&&sv[findIndex].gender!=0) {
		        printf("Invalid Gender. Please try again.\n");
		        valid = 0;
		    }
        }while(!valid);
		do{
		    valid = 1;
		    printf("Enter new IDclass: ");
		    fgets(sv[findIndex].classroomId, 10, stdin);
	        sv[findIndex].classroomId[strcspn(sv[findIndex].classroomId, "\n")] = '\0';
		    if(strlen(sv[findIndex].classroomId)==0){
		        printf("Invalid IDclass. Please try again.\n");
		        valid = 0;
		    }
		}while(!valid);
		do {
		    valid = 1;
		    printf("Enter new Email: ");
		    fgets(sv[findIndex].email, 30, stdin);
		    sv[findIndex].email[strcspn(sv[findIndex].email, "\n")] = '\0';
		    if (strlen(sv[findIndex].email) == 0) {
		        printf("Invalid Email. Please try again.\n");
		        valid = 0;
		        continue; 
		    }
		    for (j=0;j<findIndex;j++){
		        if (strcmp(sv[findIndex].email,sv[j].email) == 0){
		            printf("Invalid Email. Please enter a unique Email.\n");
		            valid = 0;
		            break;
		        }
		    }
		    char *check = strchr(sv[findIndex].email, '@'); 
		    if (!check || check == sv[findIndex].email || strchr(check + 1, '@') || strchr(check + 1, '.') == NULL) {
		        printf("Invalid Email. Please try again.\n");
		        valid = 0;
		        continue;
		    }
		    if (check - sv[findIndex].email < 1) { 
		        printf("Invalid Email. Please try again.\n");
		        valid = 0;
		        continue;
		    }
		} while (!valid);
	    do{
	        valid = 1;
	        printf("Enter new Phone (exactly 10 characters): ");
	        scanf("%s",sv[findIndex].phone);
	        getchar();
	        if(strlen(sv[findIndex].phone)!=10){
	            printf("Invalid Phone. Please try again.\n");
	            valid = 0;
	            continue;
	        }
	        for(j=0;j<findIndex;j++){
	            if(strcmp(sv[findIndex].phone,sv[j].phone) == 0){
	                printf("Invalid Phone. Please enter a unique Phone.\n");
	                valid = 0;
	                break;
	            }
	        }
	    }while(!valid);
	    printf("Enter new Password: ");
	    fgets(sv[findIndex].password, 20, stdin);
	    sv[findIndex].password[strcspn(sv[findIndex].password, "\n")] = '\0';
        printf("\n\t***Updated The New Student***\n");
        printHeader();
        printStudent(length, sv);
        printf("\nStudent Edited Successfully.\n");
    }
}
void searchStudent(int length, struct Student sv[]){
    printf("\n\t***Search a Student***\n");
    getchar();
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
        printf("\nStudent found with the name %s.\n",name);
        printf("Students Finded Successfully.\n\n");
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
				for(i=0;i<length-1;i++) {
			        for(j=i+1;j<length;j++) {
			            if(strcmp(sv[i].fullName,sv[j].fullName)>0){
			                temp = sv[i];
			                sv[i] = sv[j];
			                sv[j] = temp;
			            }
			        }
			    }
			    printHeader();
		        printStudent(length,sv);
			    printf("\nStudents Are Sorted Successfully.\n");
				break;
			case 2:
				printf("\n\t  Reduce Sort\n");
				for(i=0;i<length-1;i++) {
			        for(j=i+1;j<length;j++) {
			            if(strcmp(sv[i].fullName, sv[j].fullName)<0){
			                temp=sv[i];
			                sv[i]=sv[j];
			                sv[j]=temp;
			            }
			        }
			    }
			    printHeader();
		        printStudent(length,sv);
			    printf("\nStudents Are Sorted Successfully.\n");
				break;
			case 0:
				break;
			default:
				printf("\tERROR: Please try again.\n");
	    }
	}while(choice4!=0);
}
void menuTeacher(){
    printf("\n***Teacher Management System Using C***\n");
    printf("\n");
    printf("\t    TEACHER MENU\n");
    printf("\t======================\n");
    printf("\t[1] Add A new Teacher.\n");
    printf("\t[2] Show All Teacher.\n");
    printf("\t[3] Delete A Teacher.\n");
    printf("\t[4] Edit A Teacher.\n");
    printf("\t[5] Search A Teacher.\n");
    printf("\t[6] Sort A Teacher.\n");
    printf("\t[7] Add Teacher to a Class.\n");
    printf("\t[0] Back.\n");
    printf("\t======================\n");
}	
void addTeacher(int *length, struct Teacher tv[]){
    printf("\n\t***Add A New Teacher***\n");
	int newTeacher;
    printf("\nAdd number of Teacher: ");
    scanf("%d", &newTeacher);
    getchar();
	int i, j, valid;
	for (i = *length; i < *length + newTeacher; i++) {
	    printf("\n       Teacher %d\n", i + 1);
	    do{
	    	valid=1;
	        printf("Enter the ID: ");
	        fgets(tv[i].teacherId, 10, stdin);
	        tv[i].teacherId[strcspn(tv[i].teacherId, "\n")] = '\0';
	        if (strlen(tv[i].teacherId)==0){
	            printf("Invalid ID. Please try again.\n");
	            valid = 0;
	        }
	        for(j=0;j<i;j++){
	            if (strcmp(tv[i].teacherId,tv[j].teacherId)==0){
	                printf("Invalid ID. Please enter a unique ID.\n");
	                valid = 0;
	                break;
	            }
	        }
	    }while(!valid);
	    do {
            valid = 1;
            printf("Enter the Name: ");
		    fgets(tv[i].fullName, 30, stdin); 
		    tv[i].fullName[strcspn(tv[i].fullName, "\n")] = '\0';  
		    if (strlen(tv[i].fullName) == 0) {
		        printf("Invalid Name. Please try again.\n");
		        valid = 0;
		    }
		}while(!valid);
	    do{
	    	valid=1;
	    	printf("Enter the date of birth (dd/mm/yyyy): \n");
		    printf("   Enter the day: ");
		    scanf("%d", &tv[i].dateOfBrith.day);
		    printf("   Enter the month: ");
		    scanf("%d", &tv[i].dateOfBrith.month);
		    printf("   Enter the year: ");
		    scanf("%d", &tv[i].dateOfBrith.year);
		    getchar();
		    switch(tv[i].dateOfBrith.month){
		    	case 2:
		    		if(tv[i].dateOfBrith.year%4==0&&tv[i].dateOfBrith.year%100!=0 ||tv[i].dateOfBrith.year%400==0){
			            if(tv[i].dateOfBrith.day>0&&tv[i].dateOfBrith.day<=29){
	           	            break;
	           	        }else{
	           		        printf("Invalid. Please try again.\n");
	           		        valid = 0;
				        }
			        }else{
				        if(tv[i].dateOfBrith.day>0&&tv[i].dateOfBrith.day<=28){
	           	            break;
	           	        }else{
	           		        printf("Invalid. Please try again.\n");
	           		        valid = 0;
				        }
			        }
			        break;
			    case 1:
			    case 3:
			    case 5:
			    case 7:
			    case 8:
			    case 10:
			    case 12:
			    	if(tv[i].dateOfBrith.day>0&&tv[i].dateOfBrith.day<=31){
	           	        break;
	           	    }else{
	           		    printf("Invalid. Please try again.\n");
	           		    valid = 0;
				    }
				    break;
				case 4:
				case 6:
				case 9:
				case 11:
					if(tv[i].dateOfBrith.day>0&&tv[i].dateOfBrith.day<=30){
	           	        break;
	           	    }else{
	           		    printf("Invalid. Please try again.\n");
	           		    valid = 0;
				    }
				    break;
				default:
					printf("Invalid. Please try again.\n");
	           		    valid = 0;
	        }
		}while(!valid);
	    do{
			valid = 1;
			printf("Enter the Gender (1 for Male, 0 for Female): ");
		    scanf("%d", &tv[i].gender);
		    getchar();
		    if(tv[i].gender==1||tv[i].gender==0){
		    	break;	
		    }else{
		    	printf("Invalid Gender. Please try again.\n");
		    	valid = 0;
			}
		}while(!valid);
	    printf("Enter the Class: ");
	    fgets(tv[i].classroomId, 10, stdin);
	    tv[i].classroomId[strcspn(tv[i].classroomId, "\n")] = '\0';
	    do {
	        valid = 1;
	        printf("Enter the Email: ");
	        fgets(tv[i].email, 30, stdin);
	        tv[i].email[strcspn(tv[i].email, "\n")] = '\0';
	        if (strlen(tv[i].email) == 0) {
	            printf("Invalid Email. Please try again.\n");
	            valid = 0;
	        }
	        for (j = 0; j < i; j++){
	            if (strcmp(tv[i].email, tv[j].email) == 0) {
	                printf("Invalid Email. Please enter a unique Email.\n");
	                valid = 0;
	                break;
	            }
	        }
	        char *check = strchr(tv[i].email, '@'); 
		    if (!check || check == tv[i].email || strchr(check + 1, '@') || strchr(check + 1, '.') == NULL){
		        printf("Invalid Email. Please try again.\n");
		        valid = 0;
		    }
		    if (check - tv[i].email < 1){ 
		        printf("Invalid Email. Please try again.\n");
		        valid = 0;
		    }
	    }while(!valid);
	    do{
	        valid = 1;
	        printf("Enter the Phone (exactly 10 characters): ");
	        scanf("%s",tv[i].phone);
	        getchar();
	        if(strlen(tv[i].phone) == 0 || strlen(tv[i].phone)!=10){
	            printf("Invalid Phone. Please try again.\n");
	            valid = 0;
	        }
	        for(j=0;j<i;j++){
	            if(strcmp(tv[i].phone,tv[j].phone) == 0){
	                printf("Invalid Phone. Please enter a unique Phone.\n");
	                valid = 0;
	                break;
	            }
	        }
	    }while(!valid);
	    printf("Enter the Password: ");
	    fgets(tv[i].password, 20, stdin);
	    tv[i].password[strcspn(tv[i].password, "\n")] = '\0';
    }
    *length += newTeacher;
    printf("\nTeacher Added Successfully.\n");
}
void printHeader2(){
	printf("\n\t  ***All Teacher***\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|=====================|\n");
    printf("| ID         | ID Class    | FullName                   | Date Of Brith         | Gender     | Email                      | Phone               | Password            |\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|=====================|\n");
}		
void printTeacher(int length, struct Teacher tv[]){
    int i;
    for(i=0;i<length;i++){
    printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s| %-20s|\n",
            tv[i].teacherId,
            tv[i].classroomId,
            tv[i].fullName,
            tv[i].dateOfBrith.day,
            tv[i].dateOfBrith.month,
            tv[i].dateOfBrith.year,
            tv[i].gender ? "Male" : "Female",
            tv[i].email,
            tv[i].phone,
            tv[i].password);
            printf("|------------|-------------|----------------------------|-----------------------|------------|----------------------------|---------------------|---------------------|\n");
    }
}
void saveTeacherToFile(int length, struct Teacher tv[]){
    FILE *fptr = fopen("teachersData.dat", "wb");
    if (fptr == NULL) {
        printf("Cannot open file\n");
        return;
    }
    fwrite(tv, sizeof(struct Teacher), 50, fptr);
    printf("\nTeacher data saved successfully\n");
    fclose(fptr);
}
void loadTeacherFromFile(int *length, struct Teacher tv[]){
    FILE *fptr = fopen("teachersData.dat", "rb");
    if (fptr == NULL) {
        printf("No data found.\n");
        return;
    }
    *length = fread(tv, sizeof(struct Teacher), 50, fptr);
    fclose(fptr);
}
void deleteTeacher(int *length, struct Teacher tv[]) {
    printf("\n\t***Delete a Teacher***\n");
    getchar();
	char id[10];
    printf("\nEnter the teacher ID to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex= -1;
    int i;
    for(i=0;i<*length; i++) {
        if(strcmp(tv[i].teacherId, id) == 0) {
            findIndex= i;
            break;
        }
    }
    if(findIndex==-1) {
        printf("\nTeacher with ID %s not found.\n", id);
    }else{
        printf("\nOne Teacher Found for ID: %s\n", id);
        printf("  Teacher Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n",tv[findIndex].classroomId);
        printf("FullName: %s\n",tv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n",tv[findIndex].dateOfBrith.day,tv[findIndex].dateOfBrith.month,tv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n",tv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n",tv[findIndex].email);
        printf("Phone: %s\n",tv[findIndex].phone);
        printf("Password: %s\n",tv[findIndex].password);
        int choice8;
		printf("\n\t   Confirm Deletion ?\n");
		printf("\t======================\n");
		printf("\t[1] Yes.\n");
		printf("\t[0] No.\n");
		printf("\t======================\n");
		printf("\tEnter the Choice: ");
	    scanf("%d", &choice8);
	    switch(choice8){
			case 1:
		        for(i=findIndex;i<*length-1; i++){
		            tv[i]=tv[i+1];
		        }
		        (*length)--;
		        printf("\n\t***Updated The New Teacher ***\n");
		        printHeader2();
		        printTeacher(*length, tv);
		        printf("\nTeacher Deleted Successfully.\n");
		        break;
		    case 0:
				printf("\nDo Not Delete Teacher.\n");
				break;
		    default:
		        printf("\tERROR: Please try again.\n");	
	   }
    }
}
void editTeacher(int length, struct Teacher tv[]) {
    printf("\n\t***Edit a Teacher***\n");
    getchar();
    char id[10];
    printf("\nEnter the teacher ID to edit: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex=-1;
    int i,j,valid;
    for(i=0;i<length;i++) {
        if(strcmp(tv[i].teacherId, id)==0) {
            findIndex=i;
            break;
        }
    }
    if (findIndex== -1) {
        printf("\nTeacher with ID %s not found.\n", id);
    }else{
        printf("\nOne Teacher Found for ID: %s\n", id);
        printf("  Teacher Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n",tv[findIndex].classroomId);
        printf("FullName: %s\n",tv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n",tv[findIndex].dateOfBrith.day,tv[findIndex].dateOfBrith.month,tv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n",tv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n",tv[findIndex].email);
        printf("Phone: %s\n",tv[findIndex].phone);
        printf("Password: %s\n",tv[findIndex].password);
        do {
            valid = 1;
            printf("\nEnter New Name: ");
		    fgets(tv[i].fullName, 30, stdin); 
		    tv[i].fullName[strcspn(tv[i].fullName, "\n")] = '\0';  
		    if (strlen(tv[i].fullName) == 0) {
		        printf("Invalid Name. Please try again.\n");
		        valid = 0;
		    }
		}while(!valid);
	    do{
	    	valid=1;
	    	printf("Enter New date of birth (dd/mm/yyyy): \n");
		    printf("   Enter New day: ");
		    scanf("%d", &tv[i].dateOfBrith.day);
		    printf("   Enter New month: ");
		    scanf("%d", &tv[i].dateOfBrith.month);
		    printf("   Enter New year: ");
		    scanf("%d", &tv[i].dateOfBrith.year);
		    getchar();
		    switch(tv[i].dateOfBrith.month){
		    	case 2:
		    		if(tv[i].dateOfBrith.year%4==0&&tv[i].dateOfBrith.year%100!=0 ||tv[i].dateOfBrith.year%400==0){
			            if(tv[i].dateOfBrith.day>0&&tv[i].dateOfBrith.day<=29){
	           	            break;
	           	        }else{
	           		        printf("Invalid. Please try again.\n");
	           		        valid = 0;
				        }
			        }else{
				        if(tv[i].dateOfBrith.day>0&&tv[i].dateOfBrith.day<=28){
	           	            break;
	           	        }else{
	           		        printf("Invalid. Please try again.\n");
	           		        valid = 0;
				        }
			        }
			        break;
			    case 1:
			    case 3:
			    case 5:
			    case 7:
			    case 8:
			    case 10:
			    case 12:
			    	if(tv[i].dateOfBrith.day>0&&tv[i].dateOfBrith.day<=31){
	           	        break;
	           	    }else{
	           		    printf("Invalid. Please try again.\n");
	           		    valid = 0;
				    }
				    break;
				case 4:
				case 6:
				case 9:
				case 11:
					if(tv[i].dateOfBrith.day>0&&tv[i].dateOfBrith.day<=30){
	           	        break;
	           	    }else{
	           		    printf("Invalid. Please try again.\n");
	           		    valid = 0;
				    }
				    break;
	        }
		}while(!valid);
	    do{
			valid = 1;
			printf("Enter New Gender (1 for Male, 0 for Female): ");
		    scanf("%d", &tv[i].gender);
		    getchar();
		    if(tv[i].gender==1||tv[i].gender==0){
		    	break;	
		    }else{
		    	printf("Invalid Gender. Please try again.\n");
		    	valid = 0;
			}
		}while(!valid);
	    printf("Enter New Class: ");
	    fgets(tv[i].classroomId, 10, stdin);
	    tv[i].classroomId[strcspn(tv[i].classroomId, "\n")] = '\0';
	    do {
	        valid = 1;
	        printf("Enter New Email: ");
	        fgets(tv[i].email, 30, stdin);
	        tv[i].email[strcspn(tv[i].email, "\n")] = '\0';
	        if (strlen(tv[i].email) == 0) {
	            printf("Invalid Email. Please try again.\n");
	            valid = 0;
	        }
	        for (j = 0; j < i; j++){
	            if (strcmp(tv[i].email, tv[j].email) == 0) {
	                printf("Invalid Email. Please enter a unique Email.\n");
	                valid = 0;
	                break;
	            }
	        }
	        char *check = strchr(tv[i].email, '@'); 
		    if (!check || check == tv[i].email || strchr(check + 1, '@') || strchr(check + 1, '.') == NULL){
		        printf("Invalid Email. Please try again.\n");
		        valid = 0;
		    }
		    if (check - tv[i].email < 1){ 
		        printf("Invalid Email. Please try again.\n");
		        valid = 0;
		    }
	    }while(!valid);
	    do{
	        valid = 1;
	        printf("Enter New Phone (exactly 10 characters): ");
	        scanf("%s",tv[i].phone);
	        getchar();
	        if(strlen(tv[i].phone) == 0 || strlen(tv[i].phone)!=10){
	            printf("Invalid Phone. Please try again.\n");
	            valid = 0;
	        }
	        for(j=0;j<i;j++){
	            if(strcmp(tv[i].phone,tv[j].phone) == 0){
	                printf("Invalid Phone. Please enter a unique Phone.\n");
	                valid = 0;
	                break;
	            }
	        }
	    }while(!valid);
	    printf("Enter New Password: ");
	    fgets(tv[i].password, 20, stdin);
	    tv[i].password[strcspn(tv[i].password, "\n")] = '\0';
        printf("\n\t***Updated The New Teacher***\n");
        printHeader2();
        printTeacher(length, tv);
        printf("\nTeacher Edited Successfully.\n");
    }
}
void searchTeacher(int length, struct Teacher tv[]){
    printf("\n\t***Search a Teacher***\n");
    getchar();
	char name[30];
    printf("\nEnter the name of the teacher to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    int i;
    int findIndex=-1;
	for(i=0;i<length; i++) {
        if (strcmp(tv[i].fullName,name)==0){
            findIndex=i;
            break;
        }
    }
    if (findIndex==-1){
        printf("\nNo teacher found with the name %s.\n",name);
    }else{
        printf("\nTeacher found with the name %s.\n",name);
        printf("Teacher Finded Successfully.\n\n");
	}
}
void addTeacherClass(struct Classroom cr[], int length, struct Teacher tv[]){
	printf("\n\t***Add Teacher to Class***\n");
	char classId[10];
	printf("\nEnter Classroom ID to add a teacher: ");
    fgets(classId, sizeof(classId), stdin);
    classId[strcspn(classId, "\n")] = '\0';
    int i;
    int findIndex=-1;
	for(i=0;i<length; i++) {
        if (strcmp(cr[i].classroomId,classId)==0){
            findIndex=i;
            break;
        }
    }
    if (findIndex==-1){
        printf("\nClassroom ID not found%s.\n",classId);
    }else{
    	printf("Enter Teacher ID: ");;
        fgets(tv[i].teacherId, 10, stdin);
	    tv[i].teacherId[strcspn(tv[i].teacherId, "\n")] = '\0';   
		printf("Enter Teacher Name: ");
		fgets(tv[i].fullName, 30, stdin); 
		tv[i].fullName[strcspn(tv[i].fullName, "\n")] = '\0'; 
        strcpy(cr[i].teacherId,tv[i].teacherId);
        strcpy(cr[i].fullName,tv[i].fullName);
        printf("\nTeacher added to the classroom successfully!\n");
	}
}
void endProgram(){
	printf("\n");
	printf("\tExiting program...\n");
	printf("\n");
	printf("\n=========Thank You=========\n");
	printf("=========See You Soon======\n");
}
void menuClass(){
	printf("\n***Classroom Management System Using C***\n");
    printf("\n");
    printf("\t   Classroom MENU\n");
    printf("\t======================\n");
    printf("\t[1] Add A new Class.\n");
    printf("\t[2] Show All Class.\n");
    printf("\t[3] Delete A Class.\n");
    printf("\t[4] Detail A Class.\n");
    printf("\t[5] Edit A Class.\n");
    printf("\t[6] Add Student to a Class.\n");
    printf("\t[7] Delete Student to a Class.\n");
    printf("\t[8] Sort A Class.\n");
    printf("\t[0] Back.\n");
    printf("\t======================\n");
}
void printHeader3(){
	printf("\n\t  ***All CLASSROOMS***\n");
    printf("|===============|===================|===============|=========================|\n");
    printf("| ClassroomID   | Classroom Name    | Teacher ID    | Teacher Name            |\n");
    printf("|===============|===================|===============|=========================|\n");
}
void printClass(int length, struct Classroom cr[]){
	int i;
    for(i=0;i<length;i++){
    printf("| %-14s| %-18s| %-14s| %-24s|\n",
           cr[i].classroomId,
		   cr[i].classroomName,
		   cr[i].teacherId,
		   cr[i].fullName);
            printf("|---------------|-------------------|---------------|-------------------------|\n");
    }
}
void addClass(int *length, struct Classroom cr[]){
	printf("\n\t***Add A New TClassrooms***\n");
	int newClass;
    printf("\nAdd number of Teacher: ");
    scanf("%d", &newClass);
    getchar();
    int i,j,valid;
    for(i=*length;i<*length + newClass; i++){
	    printf("\n       Classrooms %d\n", i + 1);
	    do{
	    	valid=1;
	        printf("Enter the ID Class: ");
	        fgets(cr[i].classroomId, 10, stdin);
	        cr[i].classroomId[strcspn(cr[i].classroomId, "\n")] = '\0';
	        if (strlen(cr[i].classroomId)==0){
	            printf("Invalid ID. Please try again.\n");
	            valid = 0;
	        }
	        for(j=0;j<i;j++){
	            if (strcmp(cr[i].classroomId,cr[j].classroomId)==0){
	                printf("Invalid ID. Please enter a unique ID.\n");
	                valid = 0;
	                break;
	            }
	        }
	    }while(!valid);
	    do{
	    	valid=1;
	        printf("Enter the Class Name: ");
	        fgets(cr[i].classroomName, 10, stdin);
	        cr[i].classroomName[strcspn(cr[i].classroomName, "\n")] = '\0';
	        if (strlen(cr[i].classroomName)==0){
	            printf("Invalid ID. Please try again.\n");
	            valid = 0;
	        }
	        for(j=0;j<i;j++){
	            if (strcmp(cr[i].classroomName,cr[j].classroomName)==0){
	                printf("Invalid ID. Please enter a unique ID.\n");
	                valid = 0;
	                break;
	            }
		     }
		}while(!valid);
	    //addTeacherClass(cr,*length);
    }
}
void loginAdmin(){ 
    char username[30]; 
	char password[30]; 
	int valid; 
	do { 
	    printf("\n***Student Management System Using C***\n"); 
		printf("\t    LOGIN\n"); 
		printf("\t===================\n"); 
		printf("\tEMAIL: "); 
		fgets(username, 30, stdin); 
		username[strcspn(username, "\n")] = '\0'; 
		getchar();
		valid = 1; 
		if(strlen(username) == 0) { 
		    printf("Invalid Email. Please try again.\n"); 
			valid = 0; 
			continue; 
		} 
		char *check = strchr(username, '@'); 
		if (!check || check == username || strchr(check + 1, '@') || strchr(check + 1, '.') == NULL) { 
		    printf("Invalid Email. Please try again.\n"); 
			valid = 0; 
			continue; 
	    } 
		if (check - username < 1) { 
		    printf("Invalid Email. Please try again.\n"); 
			valid = 0; 
			continue; 
		} 
		printf("\tPassword: "); 
		int i = 0; 
		while (1){ 
		char ch = getch(); 
		if (ch == '\r'){  
			password[i] = '\0'; 
			break; 
		}else if(ch == '\b') { 
		    if (i > 0) { 
			    i--; 
			    printf("\b \b"); 
		    } 
	    }else{ 
		    password[i++] = ch; 
			printf("*");
	    } 
	} 
	if(strlen(password) == 0) { 
	    printf("\nInvalid Password. Please try again.\n"); 
	    valid = 0; 
	    continue; 
	} 
	}while (!valid); 
}

