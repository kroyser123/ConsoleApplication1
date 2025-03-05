
#include <iostream>
#include "def.h"
#include "vector.h"
#include "list.h"
#include "deque.h"
#include "map.h"
#include "set.h"
#include "stack.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    int choice = 0;

    while (true) {
        cout << "Меню" << endl;
        cout << "1. Create vector Student" << endl;
        cout << "2. Show vector Student" << endl;
        cout << "3. Add vector Student" << endl;
        cout << "4. Sort Students" << endl;
        cout << "5. Create and show list Student" << endl;
        cout << "6. Delete student from list" << endl;
        cout << "7. Add list Student" << endl;
        cout << "8. deque > 22" << endl;
        cout << "9. getsummap" << endl;
        cout << "10. sumgrades" << endl;
        cout << "11 set one" << endl;
        cout << "12 stack one" << endl;
        cout << "0. Exit" << endl;

        EnterNumber(choice, "Введите номер пункта: ");

        switch (choice) {
        case 1:
            createStudentsFromFile("BD1.txt")();
            break;
        case 2:
            ShowStudents();
            break;
        case 3:
            addStudentToDB();
            break;
        case 4:
            sortStudents();
            break;
        case 5:
            Vectot_To_list();
            break;
        case 6:
            Delete_From_List();
            break;
        case 7:
            AddToList();
            break;
        case 8:
            dequeform();
            break;
        case 9:
            getsummap();
            break;
        case 10:
            sumgrades();
            break;
        case 11:
            sets();
            break;
        case 12:
            stacks();
            break;

        case 0:
            cout << "2025 andrey" << endl;
            return 0; // Завершить программу
        default:
            cout << "Неправильный ввод! Пожалуйста, попробуйте снова." << endl;
            break;
        }
        cout << endl; // Пустая строка для отделения выводов
    }

    return 0;
}
