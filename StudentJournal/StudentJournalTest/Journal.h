#pragma once

// ������ ������, ���������� ������
#define GROUP_SIZE 6
// ������ ������, ���������� �������
#define SURNAME_SIZE 25
// ���������� ������
#define GRADE_COUNT 4
// ������������ ������ �������
#define ARRAY_MAX_SIZE 50

typedef struct {
	int course; // ����
	char group[GROUP_SIZE]; // ������
	char surname[SURNAME_SIZE]; // �������
	unsigned int gradeCount[GRADE_COUNT]; // ���������� ������
} Student;

// �������� ��������
void addStudent(Student array[], int index, int course,
	const char* group, const char* surname,
	unsigned int grade1, unsigned int grade2,
	unsigned int grade3, unsigned int grade4);

// ������� ���� ���������
void printStudents(Student array[], int count);

// �������� �������� ���� ���������� �������
void swap(Student *a, Student *b);

// ���������� � ���� �� �����
void heapifyByCourse(Student array[], int n, int i);

// ���������� � ���� �� ������
void heapifyByGroup(Student array[], int n, int i);

// ���������� � ���� �� �������
void heapifyBySurname(Student array[], int n, int i);

// ���������� ����� (������������� ����������) �� �����
void sortByCourse(Student array[], int n);

// ���������� ����� (������������� ����������) �� ������
void sortByGroup(Student array[], int n);

// ���������� ����� (������������� ����������) �� �������
void sortBySurname(Student array[], int n);

// ������ ������
int importStudents(Student array[], const char* file);

// ������� ������
void exportStudents(Student array[], const char* file, int count);