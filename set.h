#pragma once
#include "def.h"
void sets() {
	for (const auto& da : DB_Student) {
		Set_Id_Student.insert(da.age);
	}
	cout << "unique id";
	for (int age : Set_Id_Student) {
		cout << age << " ";
	}
	cout << " size set ";

	cout << Set_Id_Student.size();
	cout << " size bd ";

	cout << DB_Student.size() << endl;
	int searchId;
	std::cout << "������� �������: ";
	std::cin >> searchId;

	if (Set_Id_Student.find(searchId) != Set_Id_Student.end()) {
		std::cout << "������� " << searchId << " ������." << std::endl;
	}
	else {
		std::cout << "������� " << searchId << " �� ������." << std::endl;
	}
}