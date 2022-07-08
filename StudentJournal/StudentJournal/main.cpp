/*
* File: main.cpp
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "Journal.h"

// Вывод меню
void showMenu();

int main() {
	int userChoice = 0;
	int arrayCount = 0;
	Student studentArray[ARRAY_MAX_SIZE];

	// Смена языка
	setlocale(LC_ALL, "");

	while(true) {
		// Очистить экран
		system("cls");

		// Вывод меню
		showMenu();

		// Выбор пункта меню
		printf("Введите номер пункта: ");
		scanf_s("%d", &userChoice);

		// Выполнение
		if(userChoice == 1) {
			// Добавить студента

			int course;
			char group[GROUP_SIZE];
			char surname[SURNAME_SIZE];
			unsigned int grade1, grade2, grade3, grade4;

			system("cls");
			printf("Введите номер курса: ");
			scanf("%d", &course);
			printf("Введите группу: ");
			scanf("%s", group);
			printf("Введите фамилию: ");
			scanf("%s", surname);
			printf("Введите количество оценок: ");
			scanf("%u %u %u %u", &grade1, &grade2, &grade3, &grade4);

			addStudent(studentArray, arrayCount,
				course, group, surname, grade1, grade2, grade3, grade4);

			arrayCount++;
		}
		else if(userChoice == 2) {
			// Вывести всех студентов на экран

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
			// Импортировать список студентов из файла
			char file[80];

			system("cls");
			printf("Введите имя файла: ");
			scanf("%s", file);
			arrayCount = importStudents(studentArray, file);
		}
		else if(userChoice == 7) {
			// Экспортировать список студентов в файл
			char file[80];

			system("cls");
			printf("Введите имя файла: ");
			scanf("%s", file);
			exportStudents(studentArray, file, arrayCount);
		}
		else if(userChoice == 8) {
			system("cls");
			break;
		}
	}
}

// Вывод меню
void showMenu() {
	printf("Меню\n");
	printf("1.Добавить студента\n");
	printf("2.Вывести всех студентов на экран\n");
	printf("3.Отсортировать студентов по курсу\n");
	printf("4.Отсортировать студентов по группе\n");
	printf("5.Отсортировать студентов по фамилии\n");
	printf("6.Импортировать список студентов из файла\n");
	printf("7.Экспортировать список студентов в файл\n");
	printf("8.Выйти из программы\n");
}