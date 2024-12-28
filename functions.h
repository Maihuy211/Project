# include"datatypes.h"
void menuStart();
void menuAdmin();
void menuStudents();
void inputStudent(int *length, struct Student sv[]);
void printHeader();
void printStudent(int length, struct Student sv[]);
void addStudent(int *length, struct Student sv[]);
void saveStudentToFile(int length, struct Student sv[]);
void loadClassesFromFile(int *length, struct Student sv[]);
void deleteStudent(int *length, struct Student sv[]);
void editStudent(int length, struct Student sv[]);
void searchStudent(int length, struct Student sv[]);
void sortStudentsByName(int length, struct Student sv[]);

