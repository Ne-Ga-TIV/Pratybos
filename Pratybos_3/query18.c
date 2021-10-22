#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student {
	char name[30];
	char surname[30];
	int course;					// year of study
	double average; 			// average grade
	
	int load; 					// number of courses
	char courses[10][30]; 		// course names
	int grades[10]; 			// course grades	
	
	char languages[100];		// spoken languages
	
} Student;

int uniname(Student *s, char *name, char *surname, int size)
{
	int count_n = 0, count_s = 0;
	for(int i = 0; i < size; i++)
	{
		if(!strcmp(name, s[i].name)){
			count_n++;
		}
		if(!strcmp(surname, s[i].surname)){
			count_s++;
		}
	}
	return (count_n >= count_s ? count_s : count_n);
}

int main(int argc, char *argv[]) {
	FILE *db = NULL;
	// open database file for reading, provide a parameter or use default "db.bin"
	if (argc > 1)
		db = fopen(argv[1], "rb");
	else
		db = fopen("db.bin", "rb");
		
	if (db){							
		Student students[1000];			// all the data goes here
		int size = 0;					// how many students in database
		
		// reading data from file
		fread(&size, sizeof(int), 1, db);
		
		for (int i = 0; i < size; i++){			
			fread(&students[i], sizeof(Student), 1, db);			
		}	
		printf("%d records loaded succesfully\n", size);
		
		
		// MODIFY CODE BELOW
		
		int counterDemo = 0; // for counting students
		
		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s
			
			if(uniname(students, s.name, s.surname, size) == 1){
				printf("NAME           SURNAME      COURSE   AVG.   CRS.COUTN\n");
				printf("%-15s%-15s%-5d%5.1f%10d\n", s.name, s.surname, s.course, s.average, s.load); // print student data
				int anotherDemo = 0; // for counting courses/grades
				for (int i = 0; i < s.load; ++i){ // process each course taken by the student
					if(1){ // *** second filter, conditions on the course/grade
						++anotherDemo; // counting courses
						printf("%-20s%5d\n", s.courses[i], s.grades[i]);
					}
				}
				printf("LANGUAGES: %s\n", s.languages);
				printf("%s", i == size - 1 ? "\n" : "\n\n\n");
				if (anotherDemo == s.load) // *** third filter, various other conditions			
					++counterDemo; // counting studfents
			}
		}
		printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);	
	} else {
		printf("File db.bin not found, check current folder\n");
	}
	
	return 0;
}