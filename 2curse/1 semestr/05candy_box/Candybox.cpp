#include <iostream>
using namespace std;

class CandyBox {
    int cnt;
    int* candies;

public:
    CandyBox() { cnt = 0; candies = nullptr; };
    ~CandyBox() { delete[] candies; };
    CandyBox(const CandyBox& other) {
        cnt = other.cnt;
        if (other.candies != nullptr && cnt > 0) {
            candies = new int[cnt];
            for (int i = 0; i < cnt; i++) {
                candies[i] = other.candies[i];
            }
        }
        else { candies = nullptr; }
    }

    void read();
    void print();
    int varieties();
    int size();
    int& at(int index);
};

void CandyBox::read() {
    cin >> cnt;
    delete[] candies;
    candies = new int[cnt];
    for (int i = 0; i < cnt; i++) {
        cin >> candies[i];
    }
}

void CandyBox::print() {
    for (int i = 0; i < cnt; i++) {
        cout << candies[i] << (i == cnt - 1 ? "" : " ");
    }
    cout << "\n";
}

int CandyBox::varieties() {
    int t = 0;
    for (int i = 0; i < cnt; i++) {
        bool is_unique = true;
        for (int j = 0; j < i; j++) {
            if (candies[i] == candies[j]) {
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

int CandyBox::size() {
    return cnt;
}

int& CandyBox::at(int index) {
    return candies[index];
}
CandyBox Arcady_process(CandyBox b) {
    int even_count = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (b.at(i) % 2 == 0) even_count++;
    }

    if (even_count == 0) return b;
    int* evens = new int[even_count];
    int k = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (b.at(i) % 2 == 0) {
            evens[k++] = b.at(i);
        }
    }
    int kept_count = (even_count + 1) / 2;
    int* kept = new int[kept_count];
    for (int i = 0, j = 0; i < even_count; i += 2, ++j) {
        kept[j] = evens[i];
    }
    int kc = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (b.at(i) % 2 == 0) {
            if (kc < kept_count) {
                b.at(i) = kept[kc++]; 
            }
            else {
                b.at(i) = 0;          
            }
        }
    }

    delete[] evens;
    delete[] kept;
    return b;
}
CandyBox Alice_process(CandyBox b) {
    int half = b.size() / 2;
    int size = b.size();
    int* second_half = new int[size - half];
    for (int i = 0; i < size - half; ++i) {
        second_half[i] = b.at(half + i);
    }
    for (int i = 0; i < size; ++i) {
        b.at(i) = 0;
    }
    int target = 0;
    for (int i = 0; i < size - half; ++i) {
        b.at(target) = second_half[i];
        target += 2;
    }

    delete[] second_half;
    return b;
}

int main() {
    CandyBox b;
    b.read();
    CandyBox arkady_box = Arcady_process(b);
    CandyBox alice_box = Alice_process(b);
    arkady_box.print();
    alice_box.print();

    return 0;
}