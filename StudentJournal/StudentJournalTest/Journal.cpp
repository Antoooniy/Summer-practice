#include "Journal.h"

#include <stdio.h>
#include <string.h>

// Добавить студента
void addStudent(Student array[], int index, int course,
	const char* group, const char* surname,
	unsigned int grade1, unsigned int grade2,
	unsigned int grade3, unsigned int grade4) {
	Student s;

	s.course = course;
	strcpy(s.group, group);
	strcpy(s.surname, surname);
	s.gradeCount[0] = grade1;
	s.gradeCount[1] = grade2;
	s.gradeCount[2] = grade3;
	s.gradeCount[3] = grade4;

	array[index] = s;
}

// Вывести всех студентов
void printStudents(Student array[], int count) {
	for(int i = 0; i < count; i++) {
		printf("ID студента: %d\n", i);
		printf("Студент %d курса группы %s\n", array[i].course, array[i].group);
		printf("%s\n", array[i].surname);
		printf("Количество оценок: %u %u %u %u\n\n", array[i].gradeCount[0],
			array[i].gradeCount[1], array[i].gradeCount[2], array[i].gradeCount[3]);
	}
}

// Поменять значения двух переменных местами
void swap(Student *a, Student *b) {
	Student temp = *a;
	*a = *b;
	*b = temp;
}

// Объединить в кучу
void heapifyByCourse(Student array[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && array[left].course > array[largest].course) {
		largest = left;
	}

	if(right < n && array[right].course > array[largest].course) {
		largest = right;
	}

	if(largest != i) {
		swap(&array[i], &array[largest]);
		heapifyByCourse(array, n, largest);
	}
}

// Объединить в кучу по группе
void heapifyByGroup(Student array[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && strcmp(array[left].group, array[largest].group) > 0) {
		largest = left;
	}

	if(right < n && strcmp(array[right].group, array[largest].group) > 0) {
		largest = right;
	}

	if(largest != i) {
		swap(&array[i], &array[largest]);
		heapifyByGroup(array, n, largest);
	}
}

// Объединить в кучу по фамилии
void heapifyBySurname(Student array[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && strcmp(array[left].surname, array[largest].surname) > 0) {
		largest = left;
	}

	if(right < n && strcmp(array[right].surname, array[largest].surname) > 0) {
		largest = right;
	}

	if(largest != i) {
		swap(&array[i], &array[largest]);
		heapifyBySurname(array, n, largest);
	}
}

// Сортировка кучей (пирамидальная сортировка) по курсу
void sortByCourse(Student array[], int n) {
	for(int i = n / 2 - 1; i >= 0; i--) {
		heapifyByCourse(array, n, i);
	}

	for(int i = n - 1; i >= 0; i--) {
		swap(&array[0], &array[i]);
		heapifyByCourse(array, i, 0);
	}
}

// Сортировка кучей (пирамидальная сортировка) по группе
void sortByGroup(Student array[], int n) {
	for(int i = n / 2 - 1; i >= 0; i--) {
		heapifyByGroup(array, n, i);
	}

	for(int i = n - 1; i >= 0; i--) {
		swap(&array[0], &array[i]);
		heapifyByGroup(array, i, 0);
	}
}

// Сортировка кучей (пирамидальная сортировка) по фамилии
void sortBySurname(Student array[], int n) {
	for(int i = n / 2 - 1; i >= 0; i--) {
		heapifyBySurname(array, n, i);
	}

	for(int i = n - 1; i >= 0; i--) {
		swap(&array[0], &array[i]);
		heapifyBySurname(array, i, 0);
	}
}

// Импорт списка
int importStudents(Student array[], const char* file) {
	FILE* fp;
	char line[256] = {0};
	char* tok;
	int i, count;

	if(!(fp = fopen(file, "r"))) {
		return -1;
	}

	count = 0;
	while(fgets(line, 256, fp)) {
		i = 0;

		for(tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n")) {
			if(i == 0) {
				if(sscanf(tok, "%d", &array[count].course) != 1) {
					return -1;
				}
			}
			else if(i == 1) {
				strncpy(array[count].group, tok, 6);
			}
			else if(i == 2) {
				strncpy(array[count].surname, tok, 25);
			}
			else if(i == 3) {
				if(sscanf(tok, "%u", &array[count].gradeCount[0]) != 1) {
					return -1;
				}
			}
			else if(i == 4) {
				if(sscanf(tok, "%u", &array[count].gradeCount[1]) != 1) {
					return -1;
				}
			}
			else if(i == 5) {
				if(sscanf(tok, "%u", &array[count].gradeCount[2]) != 1) {
					return -1;
				}
			}
			else if(i == 6) {
				if(sscanf(tok, "%u", &array[count].gradeCount[3]) != 1) {
					return -1;
				}
			}
			else {
				return -1;
			}

			i++;
		}

		count++;
	}

	fclose(fp);
	return count;
}

// Экспорт списка
void exportStudents(Student array[], const char* file, int count) {
	FILE* fp;

	if(!(fp = fopen(file, "w"))) {
		return;
	}

	for(int i = 0; i < count; i++) {
		fprintf(fp, "%d;%s;%s;%u;%u;%u;%u\n", array[i].course, array[i].group,
			array[i].surname, array[i].gradeCount[0], array[i].gradeCount[1],
			array[i].gradeCount[2], array[i].gradeCount[3]);
	}

	fclose(fp);
}