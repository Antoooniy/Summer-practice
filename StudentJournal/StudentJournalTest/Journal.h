#pragma once

// Размер строки, содержащую группу
#define GROUP_SIZE 6
// Размер строки, содержащую фамилию
#define SURNAME_SIZE 25
// Количество оценок
#define GRADE_COUNT 4
// Максимальный размер массива
#define ARRAY_MAX_SIZE 50

typedef struct {
	int course; // Курс
	char group[GROUP_SIZE]; // Группа
	char surname[SURNAME_SIZE]; // Фамилия
	unsigned int gradeCount[GRADE_COUNT]; // Количество оценок
} Student;

// Добавить студента
void addStudent(Student array[], int index, int course,
	const char* group, const char* surname,
	unsigned int grade1, unsigned int grade2,
	unsigned int grade3, unsigned int grade4);

// Вывести всех студентов
void printStudents(Student array[], int count);

// Поменять значения двух переменных местами
void swap(Student *a, Student *b);

// Объединить в кучу по курсу
void heapifyByCourse(Student array[], int n, int i);

// Объединить в кучу по группе
void heapifyByGroup(Student array[], int n, int i);

// Объединить в кучу по фамилии
void heapifyBySurname(Student array[], int n, int i);

// Сортировка кучей (пирамидальная сортировка) по курсу
void sortByCourse(Student array[], int n);

// Сортировка кучей (пирамидальная сортировка) по группе
void sortByGroup(Student array[], int n);

// Сортировка кучей (пирамидальная сортировка) по фамилии
void sortBySurname(Student array[], int n);

// Импорт списка
int importStudents(Student array[], const char* file);

// Экспорт списка
void exportStudents(Student array[], const char* file, int count);