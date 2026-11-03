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


class cat2{public: int age; int buildyear; string name; };

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

class cat3{
    public: 
        int age; 
        int year; 
        string name;
    void write(string n, int a, int y) {
        name = n;
        if (a < 1) a = 1;
        else if (a > 100) a = 100;
        age = a;
        if (y < 2018) y = 2018;
        else if (y > 2034) y = 2034;
        year = y;
    }
        
    void print() {
        cout << "C.A.T. " << name << " need recharging at "
             << year + age << endl;
    }
};


void ts21(){
    cat3 c1, c2, c3;
    int a, b;
    string n;
    cin >> n >> a >> b;
    c1.write(n, a, b);
    cin >> n >> a >> b;
    c2.write(n, a, b);
    cin >> n >> a >> b;
    c3.write(n, a, b);

    c1.print();
    c2.print();
    c3.print();

}

int main(){
    //ts11();
    //ts12();
    //ts13();
    //ts14();
    ts21();
    return 0;
}