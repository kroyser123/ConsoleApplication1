#ifndef VECTOR_H
#define VECTOR_H
#include "def.h"

using namespace std;
#include <cstring>
function<void()> createStudentsFromFile(const string& filename) {
    return [filename]() {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "�� ������� ������� ����: " << filename << endl;
            return;
        }

        DB_Student.clear(); // ������� ���� ������ ����� ���������
        string line;
        while (getline(file, line)) {
            cout << "������ ������: " << line << endl; // ����� ��� �������

            stringstream ss(line); // ���������� stringstream ��� ��������� ������
            string name;
            int id, age;
            vector<int> grades;

            // ������ �����, ID � ��������, � ����� ������
            getline(ss, name, ','); // ������ ��� �� ������ �������
            ss >> id; // ������ ID
            ss.ignore(); // ���������� �������
            ss >> age; // ������ �������
            ss.ignore(); // ���������� �������

            // ������ ������
            int grade;
            while (ss >> grade) {
                grades.push_back(grade);
                if (ss.peek() == ',') {
                    ss.ignore(); // ���������� �������, ���� ��� ����
                }
            }

            // ������� ������ Student � ��������� ��� � ���� ������
            DB_Student.emplace_back(name, id, age, grades);
        }

        cout << "���� ������ ��������� ���������." << endl;
        file.close();
        };
}

void ShowStudents() {
	for (const auto& student : DB_Student) {
		student.print();
	}
}
void sortStudents() {
	sort(DB_Student.begin(), DB_Student.end(), comp_Student(1));
	ShowStudents();
}
Student addStudent() {
	string name;
	int id, age;
	vector<int> grades; 


	EnterString(name, "Enter name: ");


	EnterNumber(id, "Enter id: ");

	EnterNumber(age, "Enter age: ");

	for (int i = 0; i < 5; ++i) { 
		int grade; 
		EnterNumber(grade, "Enter grade: "); 
		grades.push_back(grade); 
	}


	return Student(name, id, age, grades);
}
void addStudentToDB() {
	DB_Student.emplace_back(addStudent());
	cout << "Student added normalno!\n";
}
#endif 

