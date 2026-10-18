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

void write_Student(){
    Student s;
    cout << "s name " << endl << "s surname " << endl << "age " << endl << "greade " << endl << "mark count " << endl << "marks " << endl;
    cin >> s.name >> s.surname >> s.age >> s.grade >> s.mark_count;
    s.marks = new int[s.mark_count];
    for (int i = 0; i < s.mark_count; i++) {
        cin >> s.marks[i];
    }
}

void read_StUdent(){
    Student s;
    cout << "s name " << s.name << endl << "s surname " << s.surname << endl << "age " << s.age << endl << "greade " << s.grade << endl << "mark count " << s.mark_count << endl;
    for (int i = 0; i < s.mark_count; i++) {
        cout << s.marks[i] << " ";
    }
    cout << endl;
}

double get_student_avg_mark(Student s) {
    if (s.mark_count == 0) return 0;
    double sum = 0;
    for (int i = 0; i < s.mark_count; i++) {
        sum += s.marks[i];
    }
    sum = sum / s.mark_count;
    return sum;
}

void ts1(){
    int i;
    for (i = 0; i < 5; i += 1){write_Student();}
    for (i = 0; i < 5; i += 1){read_StUdent();}
}

void ts2(){
    int i;
    Student arr[5];
    for (i = 0; i < 5; i += 1){write_Student();}
    cout << fixed << setprecision(6);
    for (i = 0; i < 5; i += 1){cout << get_student_avg_mark(arr[i]);}
}

int main(){
    //ts1();
    ts2();
    return 0;
}