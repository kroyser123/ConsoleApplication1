#pragma once
#include "def.h"
void stacks() {
	for (auto it = DB_Student.begin(); it != DB_Student.end(); ++it) {
		Stack_Student.push(*it);
	}
	stack<Student> tempstack = Stack_Student;
	cout << "students in stack" << endl;
	while (!tempstack.empty()) {
		tempstack.top().print();
		tempstack.pop();
	}
}