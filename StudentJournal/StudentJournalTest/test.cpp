#include "gtest/gtest.h"

#include "Journal.h"

Student array1[5];
Student array2[5];

TEST(StuentJournal, SortTest1) {
	addStudent(array1, 0, 5, "555", "Chern", 0, 0, 0, 0);
	addStudent(array1, 1, 1, "111", "Anna", 0, 0, 0, 0);
	addStudent(array1, 2, 2, "222", "Hugo", 0, 0, 0, 0);
	addStudent(array1, 3, 4, "444", "Egor", 0, 0, 0, 0);
	addStudent(array1, 4, 3, "333", "Max", 0, 0, 0, 0);

	addStudent(array2, 0, 1, "111", "Anna", 0, 0, 0, 0);
	addStudent(array2, 1, 2, "222", "Hugo", 0, 0, 0, 0);
	addStudent(array2, 2, 3, "333", "Max", 0, 0, 0, 0);
	addStudent(array2, 3, 4, "444", "Egor", 0, 0, 0, 0);
	addStudent(array2, 4, 5, "555", "Chern", 0, 0, 0, 0);
	
	sortByCourse(array1, 5);

	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(array1[i].course, array2[i].course);
		EXPECT_EQ(strcmp(array1[i].group, array2[i].group), 0);
		EXPECT_EQ(strcmp(array1[i].surname, array2[i].surname), 0);
		EXPECT_EQ(array1[i].gradeCount[0], array2[i].gradeCount[0]);
		EXPECT_EQ(array1[i].gradeCount[1], array2[i].gradeCount[1]);
		EXPECT_EQ(array1[i].gradeCount[2], array2[i].gradeCount[2]);
		EXPECT_EQ(array1[i].gradeCount[3], array2[i].gradeCount[3]);
	}
}

TEST(StuentJournal, SortTest2) {
	addStudent(array1, 0, 5, "555", "Chern", 0, 0, 0, 0);
	addStudent(array1, 1, 1, "111", "Anna", 0, 0, 0, 0);
	addStudent(array1, 2, 2, "222", "Hugo", 0, 0, 0, 0);
	addStudent(array1, 3, 4, "444", "Egor", 0, 0, 0, 0);
	addStudent(array1, 4, 3, "333", "Max", 0, 0, 0, 0);

	addStudent(array2, 0, 1, "111", "Anna", 0, 0, 0, 0);
	addStudent(array2, 1, 2, "222", "Hugo", 0, 0, 0, 0);
	addStudent(array2, 2, 3, "333", "Max", 0, 0, 0, 0);
	addStudent(array2, 3, 4, "444", "Egor", 0, 0, 0, 0);
	addStudent(array2, 4, 5, "555", "Chern", 0, 0, 0, 0);

	sortByGroup(array1, 5);

	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(array1[i].course, array2[i].course);
		EXPECT_EQ(strcmp(array1[i].group, array2[i].group), 0);
		EXPECT_EQ(strcmp(array1[i].surname, array2[i].surname), 0);
		EXPECT_EQ(array1[i].gradeCount[0], array2[i].gradeCount[0]);
		EXPECT_EQ(array1[i].gradeCount[1], array2[i].gradeCount[1]);
		EXPECT_EQ(array1[i].gradeCount[2], array2[i].gradeCount[2]);
		EXPECT_EQ(array1[i].gradeCount[3], array2[i].gradeCount[3]);
	}
}

TEST(StuentJournal, SortTest3) {
	addStudent(array1, 0, 5, "555", "Chern", 0, 0, 0, 0);
	addStudent(array1, 1, 1, "111", "Anna", 0, 0, 0, 0);
	addStudent(array1, 2, 2, "222", "Hugo", 0, 0, 0, 0);
	addStudent(array1, 3, 4, "444", "Egor", 0, 0, 0, 0);
	addStudent(array1, 4, 3, "333", "Max", 0, 0, 0, 0);

	addStudent(array2, 0, 1, "111", "Anna", 0, 0, 0, 0);
	addStudent(array2, 1, 5, "555", "Chern", 0, 0, 0, 0);
	addStudent(array2, 2, 4, "444", "Egor", 0, 0, 0, 0);
	addStudent(array2, 3, 2, "222", "Hugo", 0, 0, 0, 0);
	addStudent(array2, 4, 3, "333", "Max", 0, 0, 0, 0);

	sortBySurname(array1, 5);

	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(array1[i].course, array2[i].course);
		EXPECT_EQ(strcmp(array1[i].group, array2[i].group), 0);
		EXPECT_EQ(strcmp(array1[i].surname, array2[i].surname), 0);
		EXPECT_EQ(array1[i].gradeCount[0], array2[i].gradeCount[0]);
		EXPECT_EQ(array1[i].gradeCount[1], array2[i].gradeCount[1]);
		EXPECT_EQ(array1[i].gradeCount[2], array2[i].gradeCount[2]);
		EXPECT_EQ(array1[i].gradeCount[3], array2[i].gradeCount[3]);
	}
}