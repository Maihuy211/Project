#include<stdbool.h>
struct Date{
	int day,month,year;
};
struct Student{
	char studentId[10];
	char classroomId[10];
	char fullName[30];
	struct Date dateOfBrith;
	bool gender;
	char email[30];
	char phone[20];
	char password[20];
};

