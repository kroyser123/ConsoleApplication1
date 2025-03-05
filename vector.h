#ifndef VECTOR_H
#define VECTOR_H
#include "def.h"

using namespace std;
#include <cstring>
function<void()> createStudentsFromFile(const string& filename) {
    return [filename]() {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Не удалось открыть файл: " << filename << endl;
            return;
        }

        DB_Student.clear(); // Очистка базы данных перед загрузкой
        string line;
        while (getline(file, line)) {
            cout << "Чтение строки: " << line << endl; // Вывод для отладки

            stringstream ss(line); // Используем stringstream для обработки строки
            string name;
            int id, age;
            vector<int> grades;

            // Чтение имени, ID и возраста, а затем оценок
            getline(ss, name, ','); // Читаем имя до первой запятой
            ss >> id; // Читаем ID
            ss.ignore(); // Игнорируем запятую
            ss >> age; // Читаем возраст
            ss.ignore(); // Игнорируем запятую

            // Чтение оценок
            int grade;
            while (ss >> grade) {
                grades.push_back(grade);
                if (ss.peek() == ',') {
                    ss.ignore(); // Игнорируем запятую, если она есть
                }
            }

            // Создаем объект Student и добавляем его в базу данных
            DB_Student.emplace_back(name, id, age, grades);
        }

        cout << "База данных студентов заполнена." << endl;
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

