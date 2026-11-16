#include <iostream>
#include <string>
using namespace std;

class student{
private:
    char name[51];
    char surname[51];

    int hp;
    int energy;
    int iq;

    void change_field(int &field, int delta){
        field += delta;
        if(field > 100) field = 100;
        if(field < 0) field = 0;
    }

public:
    void start_game(){
        hp = 100;
        energy = 100;
        iq = 20;

        cout << "enter name: ";
        cin >> name;
        cout << endl << "enter surname: ";
        cin >> surname;
        cout << endl;
    }

    bool is_alive(){if(hp > 0) {return true;} else {return false;}}

    void eat(){
        if (is_alive() == true) {
            change_field(energy, 7);
            change_field(hp, 1);
            change_field(iq, -1);
        }
    }

    void wait(){
        if (is_alive() == true) {
            change_field(energy, -3);
            change_field(hp, 1);
        }
    }


    void study(){
        if (is_alive() == true) {
            change_field(hp, -2);
            change_field(energy, -4);
            change_field(iq, 5);
        }
    }

    void show(){
        if (is_alive() == true) {
            cout << "name: " << name << endl;
            cout << "surname: " << surname << endl;
            cout << "hp: " << hp << endl;
            cout << "energy: " << energy << endl;
            cout << "iq: " << iq << endl;
        }
        else {cout <<"its over" << endl;}       
    }
};

void ts1(){
    student a;
    a.start_game();
    a.show();
}


void ts2(){
    student a;
    a.start_game();
    a.show();

    a.eat();
    a.show();

    a.wait();
    a.show();
}

void ts3(){
    student a;
    int n, i;
    string command;
    a.start_game();

    cout << "enter n: ";
    cin >> n;
    cout << endl;

    for(i = 0; i < n; i += 1){
        cout << "enter command " << endl;
        cin >> command;
        if (command == "eat") {
            a.eat();
        }
        else if (command == "wait") {
            a.wait();
        }
        else if (command == "study") {
            a.study();
        }
        a.show();
    }
}

int main(){
    //ts1();
    //ts2();
    ts3();
    return 0;
}