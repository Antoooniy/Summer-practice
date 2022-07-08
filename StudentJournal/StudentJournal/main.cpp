/*
* File: main.cpp
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "Journal.h"

// ����� ����
void showMenu();

int main() {
	int userChoice = 0;
	int arrayCount = 0;
	Student studentArray[ARRAY_MAX_SIZE];

	// ����� �����
	setlocale(LC_ALL, "");

	while(true) {
		// �������� �����
		system("cls");

		// ����� ����
		showMenu();

		// ����� ������ ����
		printf("������� ����� ������: ");
		scanf_s("%d", &userChoice);

		// ����������
		if(userChoice == 1) {
			// �������� ��������

			int course;
			char group[GROUP_SIZE];
			char surname[SURNAME_SIZE];
			unsigned int grade1, grade2, grade3, grade4;

			system("cls");
			printf("������� ����� �����: ");
			scanf("%d", &course);
			printf("������� ������: ");
			scanf("%s", group);
			printf("������� �������: ");
			scanf("%s", surname);
			printf("������� ���������� ������: ");
			scanf("%u %u %u %u", &grade1, &grade2, &grade3, &grade4);

			addStudent(studentArray, arrayCount,
				course, group, surname, grade1, grade2, grade3, grade4);

			arrayCount++;
		}
		else if(userChoice == 2) {
			// ������� ���� ��������� �� �����

			system("cls");
			printStudents(studentArray, arrayCount);
			while(getchar() != '\n');
			getchar();
		}
		else if(userChoice == 3) {
			sortByCourse(studentArray, arrayCount);
		}
		else if(userChoice == 4) {
			sortByGroup(studentArray, arrayCount);
		}
		else if(userChoice == 5) {
			sortBySurname(studentArray, arrayCount);
		}
		else if(userChoice == 6) {
			// ������������� ������ ��������� �� �����
			char file[80];

			system("cls");
			printf("������� ��� �����: ");
			scanf("%s", file);
			arrayCount = importStudents(studentArray, file);
		}
		else if(userChoice == 7) {
			// �������������� ������ ��������� � ����
			char file[80];

			system("cls");
			printf("������� ��� �����: ");
			scanf("%s", file);
			exportStudents(studentArray, file, arrayCount);
		}
		else if(userChoice == 8) {
			system("cls");
			break;
		}
	}
}

// ����� ����
void showMenu() {
	printf("����\n");
	printf("1.�������� ��������\n");
	printf("2.������� ���� ��������� �� �����\n");
	printf("3.������������� ��������� �� �����\n");
	printf("4.������������� ��������� �� ������\n");
	printf("5.������������� ��������� �� �������\n");
	printf("6.������������� ������ ��������� �� �����\n");
	printf("7.�������������� ������ ��������� � ����\n");
	printf("8.����� �� ���������\n");
}