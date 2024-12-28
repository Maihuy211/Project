#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
    int choice, choice2, choice3;
    int studentCount = 0;
    struct Student students[50]={
    	{21, "ENG24C", "Mai Van Huy", {25, 11, 2006}, 1, "maihuylc@gmail.com", "0971235256", "pass123"},
        {20, "ENG24D", "Nguyen Van A", {1, 11, 2006}, 1, "abce123@gmail.com", "0987654321", "pass124"},
        {23, "ENG24E", "Nguyen Van B", {6, 5, 2006}, 1, "abcd123@gmail.com", "0987654322", "pass125"}
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
                printf("\tExiting program...\n");
                saveStudentToFile(studentCount, students);
                break;
            default:
                printf("\n");
				printf("\tERROR: Please try again.\n");
        }
    }while(choice!=0);  
    return 0;
}
