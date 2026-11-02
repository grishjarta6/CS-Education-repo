#include <iostream>
#include <string>
using namespace std;

class cat{public: int age;};

void ts11(){
    cat my_cat;
    cin >> my_cat.age;
    cout << "age: " << my_cat.age;
}

class cock{public: int hours; int minuts;};

void ts12(){
    cock clock;
    int n;
    cout << "enter hours" << endl;
    cin >> n;
    if ((0 <= n) and (n <= 23)){clock.hours = n;}
    else {cout << "wrong" << endl;}
    cout << "enter minutes" << endl;
    cin >> n;
    if ((0 <= n) and (n <= 59)){clock.minuts = n;}
    else {cout << "wrong" << endl;}
    cout << "hours: " << clock.hours << endl << "miutes: " << clock.minuts;
}

class cock2{public: int hours; int minuts; int seconds;};

void ts13(){
    cock2 clock;
    int n;
    cout << "enter hours" << endl;
    cin >> n;
    if ((0 <= n) and (n <= 23)){clock.hours = n;}
    else {cout << "wrong" << endl;}
    cout << "enter minutes" << endl;
    cin >> n;
    if ((0 <= n) and (n <= 59)){clock.minuts = n;}
    else {cout << "wrong" << endl;}
    cout << "enter seconds" << endl;
    cin >> n;
    if ((0 <= n) and (n <= 59)){clock.seconds = n;}
    else {cout << "wrong" << endl;}
    
    cout << "hours: " << clock.hours << endl << "miutes: " << clock.minuts << endl << "seconds: " << clock.seconds;
}


class cat2{public: int age; int buildyear;};

void ts14(){
    int n, i, a, e;
    cin >> n;
    for (i = 0; i < n; i += 1){
        cat2 cat;
        cin >> a;
        if ((1 <= a) and (a <= 100)){cat.age = a;}
        else {cout << "wrong"; break;}
        cin >> e;
        if ((2018 <= e) and (e <= 2034)){cat.buildyear = e;}
        else {cout << "wrong"; break;}
        cout << "C.A.T. " << i << " need recharging at "<< cat.buildyear + cat.age << endl;               
    }
}



int main(){
    //ts11();
    //ts12();
    //ts13();
    //ts14();
    return 0;
}