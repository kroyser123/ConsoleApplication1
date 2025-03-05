#pragma once
#include "def.h"
void dequeform() {
	DQ_Student.clear();
	for (auto it = DB_Student.begin(); it != DB_Student.end(); ++it) {
		if (it->age >= 22) {
			DQ_Student.push_back(*it);
		}
		else DQ_Student.push_front(*it);
	}
	for (auto it1 = DQ_Student.begin(); it1 != DQ_Student.end(); ++it1) {
		it1->print();
	}
}