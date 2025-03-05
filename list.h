#ifndef LIST_H
#define LIST_H
#include "def.h"
#include <vector>
#include <list>
using namespace std;
void Vectot_To_list() {
	List_Student.clear();
	List_Student.insert(List_Student.end(), DB_Student.begin(), DB_Student.end());
	for (auto it = List_Student.begin(); it != List_Student.end(); ++it) {
		it->print();
	}
}
void Delete_From_List() {
	auto it = List_Student.begin();
	while (it != List_Student.end()) {
		if (it->name == " ") {
			it = List_Student.erase(it);
		}
		else {
			++it;
		}
	}
	DB_Student.clear();
	for (auto it = List_Student.begin(); it != List_Student.end(); ++it) {
		DB_Student.push_back(*it);
	}
}
void AddToList() {
	int position = 0;
	EnterNumber(position, "Enter position to insert: ");
	auto it = List_Student.begin();
	advance(it, position - 1);
	Student newStudent = addStudent();
	List_Student.insert(it, newStudent);
	cout << "Student added norm!\n";
	DB_Student.clear();
	for (auto it = List_Student.begin(); it != List_Student.end(); ++it) {
		DB_Student.push_back(*it);
	}
}
#endif