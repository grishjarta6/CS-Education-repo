#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    char name[51];
    char surname[51];
    unsigned int age;
    unsigned int grade;
    unsigned int mark_count;
    int* marks;
};

Student write_Student(){
    Student s{}; // {} обнуляет все поля, предотвращая мусор!
    
    cout << "s name: ";
    cin >> s.name;
    cout << "s surname: ";
    cin >> s.surname;
    cout << "age: ";
    cin >> s.age;
    cout << "grade: ";
    cin >> s.grade;
    cout << "mark count: ";
    cin >> s.mark_count;
    
    // Если пользователь ввел ерунду, cin сломается, и mark_count может стать огромным. 
    // Проверяем это:
    if (!cin || s.mark_count > 1000) { 
        cout << "Ошибка ввода!" << endl;
        exit(1); 
    }

    s.marks = new int[s.mark_count];
    cout << "marks: ";
    for (int i = 0; i < s.mark_count; i++) {
        cin >> s.marks[i];
    }
    return s;
}
void read_StUdent(){
    Student s;
    cout << "s name " << s.name << endl << "s surname " << s.surname << endl << "age " << s.age << endl << "greade " << s.grade << endl << "mark count " << s.mark_count << endl;
    for (int i = 0; i < s.mark_count; i++) {
        cout << s.marks[i] << " ";
    }
    cout << endl;
}

double get_student_avg_mark(const Student& s) {
    if (s.mark_count == 0) return 0;

    double sum = 0;
    for (int i = 0; i < s.mark_count; i++) {
        sum += s.marks[i];
    }
    sum = sum / s.mark_count;
    return sum;
}

bool will_graduate(Student s, int n) {
    return s.grade + n > 11;
}

void ts1(){
    int i;
    for (i = 0; i < 5; i += 1){write_Student();}
    for (i = 0; i < 5; i += 1){read_StUdent();}
}

void ts2(){
    Student arr[5];
    for (int i = 0; i < 5; ++i) arr[i] = write_Student();   // сохраняем!
    cout << fixed << setprecision(6);
    for (int i = 0; i < 5; ++i)
        cout << get_student_avg_mark(arr[i]) << '\n';
}

void ts3(){
    Student arr[5];
    int n;
    cin >> n;
    for (int i = 0; i < 5; ++i) arr[i] = write_Student();
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (will_graduate(arr[i], n)) {
            count++;
        }
    }
    cout << count;
}

int main(){
    //ts1();
    //ts2();
    ts3();
    return 0;
}