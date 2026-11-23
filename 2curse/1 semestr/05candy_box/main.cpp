#include <iostream>
#include <iostream>
#include <string>
using namespace std;

class candy_box{
    private:
        int cnt;
        int* box;        
    public:
        void initBox(int n){
            cnt = n;
            box = new int[cnt];
        }

        void DelBox(){delete [] box;}
        
        void write(){
            cout << "enter num" << endl;
            for (int i = 0; i < cnt; i += 1){
                cin >> box[i];
            }
        }

        void print(){
            for(int i = 0; i < cnt; i += 1){
                cout << box[i] << " ";
            }
        }

        int CntDif() {
        int t = 0;

        for (int i = 0; i < cnt; i += 1) {
            bool is_unique = true;

            for (int j = 0; j < i; j += 1) {
                if (box[i] == box[j]) {
                    is_unique = false;
                    break;
                }
            }

            if (is_unique) {
                t += 1;
            }
        }

        return t;
        }



};

void ts1(){
    candy_box b;
    int n;
    cin >> n;
    b.initBox(n);
    b.write();
    cout << b.CntDif() << endl;
}

int main(){
    ts1();
    return 0;
}