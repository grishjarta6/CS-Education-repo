#include <iostream>
#include <iostream>
#include <string>
using namespace std;

class vector{
    private:
        int size;
        int* data;

    public:
        vector(int n){
            size = n;
            data = new int[size];
            write();
        }
        ~vector(){DelVec();}
        //void initVec(int n){
        //    size = n;
        //    data = new int[size];
        //}

        void DelVec(){ delete [] data;}

        void write(){
            cout << "enter num: " << endl;
            for (int i = 0; i < size; i += 1){
                cin >> data[i];
            }
        }

        void print(){
            for(int i = 0; i < size; i += 1){
                cout << data[i] << " ";
                //cout << i << " ";
            }
            cout << endl;
        }

        int getByIndex(int i){
            return data[i];
        }

        void setByIndex(int i, int n){
            data[i] = n;
        }

        void popBack(){
            if (size > 0) {
                size -= 1;
            }
            else {
                DelVec();
            }
        }

        void pushBack(int x){
            int* newData = new int[size + 1];
            for(int i = 0; i < size; i += 1){
                newData[i] = data[i];
            }
            newData[size] = x;
            DelVec();
            data = newData;
            delete [] newData;
            size += 1;
        }

        void popBack2(){
            if (size > 0) {
                int size2 = size - 1;
                int* newData = new int[size2];
                for(int i = 0; i < size2; i += 1){
                    //cout << data[i] << " " << i << " " << size2 << " " << size << endl;
                    newData[i] = data[i];
                }
                DelVec();
                data = newData;
                delete [] newData;
                size = size2;
            }
            else {
                DelVec();
            }
        }

};

void ts1(){
    int n;
    vector v;
    cin >> n;
    v.initVec(n);
    v.write();
    v.print();
    v.DelVec();
}

void ts2(){
    int n, i, x;
    vector v;
    cin >> n;
    v.initVec(n);
    v.write();
    cout <<"cin i x" << endl;
    cin >> i >> x;
    cout << v.getByIndex(i) << endl;
    v.setByIndex(i, x);
    v.print();
    v.DelVec();
}

void ts3() {
    int n;
    vector v;
    cin >> n;
    v.initVec(n);
    v.write();
    
    v.popBack();
    v.print(); 
    
    v.DelVec();
}

void ts4() {
    int n;
    vector v;
    cin >> n;
    v.initVec(n);
    v.write();
    
    int val;
    cin >> val;
    
    v.pushBack(val); 
    v.print();       
    
    v.DelVec();
}

void ts21(){
    ts1();
}

void ts22() {
    int n;
    vector v;
    cin >> n;
    v.initVec(n);
    v.write();
    
    v.popBack2();
    v.print(); 
    
    v.DelVec();
}

int main(){
    //ts1();
    //ts2();
    //ts3();
    //ts4();
    //ts21();
    ts22();
    return 0;
}