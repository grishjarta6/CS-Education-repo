#include <iostream>
#include <string>
using namespace std;

// 1.1 Классный котик – 1
class Cat1 {
public:
    int age;
};

void ts1() {
    Cat1 my_cat;
    cin >> my_cat.age;
    cout << "Age of my cat is " << my_cat.age;
}

// 1.2 Классные часы – 1
class Clock1 {
public:
    int hours;
    int minutes;
};

void ts2() {
    Clock1 my_clock;
    cin >> my_clock.hours >> my_clock.minutes;
    cout << "hours: " << my_clock.hours << " minutes: " << my_clock.minutes;
}

// 1.3 Классные часы – 2
class Clock2 {
public:
    int hours;
    int minutes;
    int seconds;
};

void ts3() {
    Clock2 my_clock;
    cin >> my_clock.hours >> my_clock.minutes >> my_clock.seconds;
    cout << "hours: " << my_clock.hours
         << " minutes: " << my_clock.minutes
         << " seconds: " << my_clock.seconds;
}

// 1.4 Классный котик – 2
class Cat2 {
public:
    int age;
    int buildYear;
};

void ts4() {
    int number = 1;
    while (1) {
        Cat2 my_cat;
        if (!(cin >> my_cat.age >> my_cat.buildYear)) break;
        cout << "C.A.T. " << number << " need recharging at "
             << my_cat.buildYear + my_cat.age << endl;
        number++;
    }
}

// 1.5 Классный котик – 3
class Cat3 {
public:
    string name;
    int age;
    int buildYear;

    void fix() {
        if (age < 1) age = 1;
        else if (age > 100) age = 100;
        if (buildYear < 2018) buildYear = 2018;
        else if (buildYear > 2034) buildYear = 2034;
    }
};

void ts5() {
    while (1) {
        Cat3 my_cat;
        if (!(cin >> my_cat.name >> my_cat.age >> my_cat.buildYear)) break;
        my_cat.fix();
        cout << "C.A.T. " << my_cat.name << " build in " << my_cat.buildYear
             << " and can work " << my_cat.age << " years" << endl;
    }
}

// 2.1 Классные часы – 3
class Clock {
public:
    int hours;
    int minutes;
    int seconds;
};

void changeTime(Clock &clock, int seconds) {
    int summary = clock.hours * 3600 + clock.minutes * 60 + clock.seconds + seconds;
    if (summary < 0)
        summary = 86400 + summary % 86400;
    summary = summary % 86400;
    int seconds_to = summary % 60;
    summary /= 60;
    int minutes_to = summary % 60;
    summary /= 60;
    int hours_to = summary;
    clock.hours = hours_to;
    clock.minutes = minutes_to;
    clock.seconds = seconds_to;
}

void ts6() {
    Clock clickClock;
    cin >> clickClock.hours >> clickClock.minutes >> clickClock.seconds;
    int seconds;
    cin >> seconds;
    changeTime(clickClock, seconds);
    cout << clickClock.hours << ":" << clickClock.minutes << ":" << clickClock.seconds;
}

// 2.2 Классный котик – 4
class Cat4 {
    int age;
    int buildYear;
    string name;
public:
    void set(string n, int a, int y) {
        name = n;
        if (a < 1) a = 1;
        else if (a > 100) a = 100;
        age = a;
        if (y < 2018) y = 2018;
        else if (y > 2034) y = 2034;
        buildYear = y;
    }

    void print() {
        cout << "C.A.T. " << name << " need recharging at "
             << buildYear + age << endl;
    }
};

void ts7() {
    Cat4 c1, c2, c3;
    string n;
    int a, y;

    cin >> n >> a >> y; c1.set(n, a, y);
    cin >> n >> a >> y; c2.set(n, a, y);
    cin >> n >> a >> y; c3.set(n, a, y);

    c1.print();
    c2.print();
    c3.print();
}

int main() {
    // ts1();
    // ts2();
    // ts3();
    // ts4();
    // ts5();
    // ts6();
    ts7();
    return 0;
}