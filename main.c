#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
    int choice, choice2, choice3, choice5, choice7;
    int studentCount= 3;
    int teacherCount= 3;
    int classCount=3;
    struct Student students[50]={
    	{"1","403","Mai Van Huy", {25, 11, 2006}, 1, "maihuylc@gmail.com", "0971*****", "pass123"},
        {"2","403","Nguyen Van A", {21,10, 2006}, 1, "abce123@gmail.com", "0987654321", "pass124"},
        {"3","403","Nguyen Van B", {6, 5, 2006}, 1, "abcd123@gmail.com", "0987654322", "pass125"}
    };
    struct Teacher teachers[50]={
        {"4","403","Nguyen Van A", {2,30,1998}, 1, "abct123@gmail.com", "098765444", "pass124"},
        {"5","405","Nguyen Van B", {6,5,2000}, 1, "abcf123@gmail.com", "0987654345", "pass156"},
        {"6","404","Nguyen Van C", {6,5,2000}, 1, "aocf123@gmail.com", "0986745464", "pass116"},
    };
    struct Classroom classrooms[50]={
    	{"403", "IT101", "4", "Nguyen Van A"},
        {"405", "IT102", "5", "Nguyen Van B"},
        {"404", "ENG105", "6", "Nguyen Van C"}
    };
    do {
        menuStart();
        printf("\tEnter the Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                do{
                    menuAdmin();
                    printf("\tEnter the Choice: ");
                    scanf("%d", &choice2);
                    switch(choice2){
                        case 1:
                            do {
                                menuStudents();
                                printf("\tEnter your choice: ");
                                scanf("%d", &choice3);
                                switch(choice3){
                                    case 1:
                                        addStudent(&studentCount, students);
                                        break;
                                    case 2:
                                        printHeader();
                                        printStudent(studentCount, students);
                                        break;
                                    case 3:
                                    	deleteStudent(&studentCount, students);
                                    	break;
                                    case 4:
                                    	editStudent(studentCount, students);
                                    	break;
                                    case 5:
                                    	searchStudent(studentCount, students);
                                    	break;
                                    case 6:
                                    	sortStudentsByName(studentCount, students);
                                    	break;
                                    case 0:
                                        break;
                                    default:
                                        printf("\tERROR: Please try again.\n");
                                }
                            }while(choice3!=0);
                            break;
                        case 2:
                        	do{
                        		menuClass();
                        		printf("\tEnter your choice: ");
                                scanf("%d", &choice7);
                                switch(choice7){
                                	case 1:
                                		break;
                                	case 2:
                                		printHeader3();
                                		printClass(classCount,classrooms);
                                		break;
                                	case 3:
                                		break;
                                	case 4:
                                		break;
                                	case 5:
                                	    break;
                                	case 6:
                                	    break;
                                	case 7:
                                		break;
                                	case 8:
                                		break;
                                	case 0:
                                		break;
                                	default:
                                		printf("\tERROR: Please try again.\n");
                                }
							}while(choice7!=0);
                        	break;
                        case 3:
                        	do{
                        		menuTeacher();
                        		printf("\tEnter your choice: ");
                                scanf("%d", &choice5);
                                switch(choice5){
                                	case 1:
                                		addTeacher(&teacherCount, teachers);
                                		break;
                                	case 2:
                                		printHeader2();
                                        printTeacher(teacherCount, teachers);
                                		break;
                                	case 3:
                                    	deleteTeacher(&teacherCount, teachers);
                                    	break;
                                    case 4:
                                    	editTeacher(teacherCount, teachers);
                                    	break;
                                    case 5:
                                    	searchTeacher(teacherCount, teachers);
                                    	break;
                                    case 6:
                                    	addTeacherClass(classCount, teachers, classrooms);
                                    	break;
                                	case 0:
                                		break;
                                	default:
                                		printf("\tERROR: Please try again.\n");	
                                }
							}while(choice5!=0);
                        	break;
                        case 0:
                            break;
                        default:
                            printf("\tERROR: Please try again.\n");
                    }
                }while(choice2!=0);
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                endProgram();
                saveStudentToFile(studentCount, students);
                break;
            default:
                printf("\n");
				printf("\tERROR: Please try again.\n");
        }
    }while(choice!=0);  
    return 0;
}
