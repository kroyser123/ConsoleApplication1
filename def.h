#ifndef DEF_H
#define DEF_H
#include <string> 
#include <fstream> 
#include <iostream> 
#include <sstream> 
#include <vector>
#include <list> 
#include <deque> 
#include <map> 
#include <set> 
#include <stack> 
#include <functional> 
#include <numeric> 
#include <algorithm> 
using namespace std;
bool isValidNumber(const string& input) {
	if (input.empty()) {
		return false;
	}

	for (char c : input) {
		if (!isdigit(c)) {
			return false; // Если есть хотя бы один нечисловой символ
		}
	}

	return true; // Ввод полностью числовой
}

// Функция для ввода числа с проверкой
void EnterNumber(int& varLink, const string& label) {
	string raw_input;
	cout << label << " = ";
	while (true) {
		getline(cin, raw_input);

		if (isValidNumber(raw_input) && !raw_input.empty()) {
			varLink = stoi(raw_input);
			break; // Выход из цикла если ввод корректен
		}
		else {
			cout << "Ошибка! Пожалуйста, введите положительное целое число. " << label << " = ";
		}
	}
}

// Функция для ввода строки
void EnterString(string& varLink, const string& label) {
	cout << label << " = ";
	getline(cin, varLink);
}
struct Student {
	string name;
	int id;
	int age;
	vector<int> grades;

	
	Student() = default;  

	
	Student(string name, int id, int age, vector<int> grades)
		: name(name), id(id), age(age), grades(grades) {
	}

	void print() const {
		cout << "Name: " << name
			<< ", Record book: " << id
			<< ", Age: " << age
			<< ", Grades: ";
		for (int grade : grades) {
			cout << grade << " ";
		}
		cout << endl;
	}

	
	double get_sr_bal() const {
		if (grades.empty()) {
			return 0; // Возвращаем 0, если нет оценок, чтобы избежать деления на ноль
		}
		double sum = accumulate(grades.begin(), grades.end(), 0);
		return sum / grades.size();
	}
};
struct comp_Student {
	int what;

	bool compare(const struct Student& f, const struct Student& s) {
		switch (abs(what)) {
		case 1: return f.name > s.name; 
		case 2: return f.id > s.id;      
		case 3: return f.age > s.age;    
		case 4: return f.get_sr_bal() > s.get_sr_bal(); 
		default: return false;            
		}
	}

public:
	comp_Student(int what) : what(what) {}

	bool operator()(const struct Student& f, const struct Student& s) {
		bool ret = compare(f, s);
		return what >= 0 ? ret : !ret; 
	}
};
list<Student> List_Student;
deque<Student> DQ_Student;
map<int, Student> Map_Student;
set<int> Set_Id_Student;
stack<Student> Stack_Student;
vector<Student> DB_Student;





#endif
