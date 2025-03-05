#pragma once
#include "def.h"
#include <vector>
using namespace std;
void getsummap() {
	Map_Student.clear();
	for (const auto &student : DB_Student) {
		Map_Student.insert(std::make_pair(student.id, student));
	}
	for (const auto &pair : Map_Student) {
		cout << pair.first << " ";
		pair.second.print();
	}
}
void sumgrades() {
	int searchId;
	std::cout << "Введите ID студента для поиска: ";
	std::cin >> searchId;
	auto it = Map_Student.find(searchId);
	if (it != Map_Student.end()) {
		int grade1 = 0;
		for (int grade : it->second.grades) {
			grade1 += grade;
		}
		cout << grade1;

	}
	else cout << "error";
}