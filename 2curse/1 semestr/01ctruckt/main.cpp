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

Student read_student() {
    Student s;
    cin >> s.name >> s.surname >> s.age >> s.grade >> s.mark_count;
    s.marks = new int[s.mark_count];
    for (int i = 0; i < s.mark_count; i++) {
        cin >> s.marks[i];
    }
    return s;
}

void print_student(Student s) {
    cout << s.name << " " << s.surname << " " << s.age << " " << s.grade << " " << s.mark_count << endl;
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
    return sum / s.mark_count;
}

bool will_graduate(Student s, int after_years) {
    return s.grade + after_years > 11;
}

int age_enterance(Student s) {
    return s.age - s.grade + 1;
}

void add_mark(Student &s, int mark) {
    int* temp = new int[s.mark_count + 1];
    for (int i = 0; i < s.mark_count; i++) {
        temp[i] = s.marks[i];
    }
    temp[s.mark_count] = mark;
    delete[] s.marks;
    s.marks = temp;
    s.mark_count++;
}

// 1.1 Ученик 1
void ts1() {
    Student arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = read_student();
    }
    for (int i = 0; i < 5; i++) {
        print_student(arr[i]);
    }
}

// 1.2 Ученик 2
void ts2() {
    Student arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = read_student();
    }
    cout << fixed << setprecision(6);
    for (int i = 0; i < 5; i++) {
        cout << get_student_avg_mark(arr[i]) << endl;
    }
}

// 1.3 Ученик 3
void ts3() {
    int n;
    cin >> n;
    Student arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = read_student();
    }
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (will_graduate(arr[i], n)) {
            count++;
        }
    }
    cout << count;
}

// 2.1 Ученик 4
void ts4() {
    Student arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = read_student();
    }
    for (int i = 0; i < 5; i++) {
        cout << age_enterance(arr[i]) << endl;
    }
}

// 2.2 Ученик 5
void ts5() {
    Student arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = read_student();
    }
    for (int i = 0; i < 5; i++) {
        while (get_student_avg_mark(arr[i]) < 4.5) {
            add_mark(arr[i], 5);
        }
    }
    for (int i = 0; i < 5; i++) {
        print_student(arr[i]);
    }
}

// ===== Журнал =====

struct Journal {
    int count;
    Student* data;
};

Journal read_journal() {
    Journal j;
    cin >> j.count;
    j.data = new Student[j.count];
    for (int i = 0; i < j.count; i++) {
        j.data[i] = read_student();
    }
    return j;
}

void print_journal(Journal j) {
    cout << j.count << endl;
    for (int i = 0; i < j.count; i++) {
        print_student(j.data[i]);
    }
}

// 3.2 Журнал 2
void add_total_marks(Journal &j) {
    for (int i = 0; i < j.count; i++) {
        double avg = get_student_avg_mark(j.data[i]);
        int mark;
        if (avg >= 4.5) mark = 5;
        else if (avg >= 3.5) mark = 4;
        else if (avg >= 2.5) mark = 3;
        else mark = 2;
        add_mark(j.data[i], mark);
    }
}

void ts6() {
    Journal j = read_journal();
    add_total_marks(j);
    print_journal(j);
}

// 3.3 Журнал 3
void filter_avg_above(Journal &j, double x = 4.5) {
    for (int i = 0; i < j.count; i++) {
        if (get_student_avg_mark(j.data[i]) >= x) {
            print_student(j.data[i]);
        }
    }
}

void ts7() {
    Journal j = read_journal();
    double x;
    cin >> x;
    filter_avg_above(j, x);
}

// 3.4 Журнал 4
bool equal_students(Student s1, Student s2) {
    if (string(s1.name) != string(s2.name)) return false;
    if (string(s1.surname) != string(s2.surname)) return false;
    if (s1.age != s2.age) return false;
    if (s1.grade != s2.grade) return false;
    if (s1.mark_count != s2.mark_count) return false;
    for (int i = 0; i < s1.mark_count; i++) {
        if (s1.marks[i] != s2.marks[i]) return false;
    }
    return true;
}

void remove_duplicates(Journal &j) {
    for (int i = 0; i < j.count; i++) {
        for (int k = i + 1; k < j.count; ) {
            if (equal_students(j.data[i], j.data[k])) {
                for (int m = k; m < j.count - 1; m++) {
                    j.data[m] = j.data[m + 1];
                }
                j.count--;
            }
            else {
                k++;
            }
        }
    }
}

void ts8() {
    Journal j = read_journal();
    remove_duplicates(j);
    print_journal(j);
}

int main() {
    //ts1();
    //ts2();
    //ts3();
    //ts4();
    //ts5();
    //ts6();
    //ts7();
    ts8();
}