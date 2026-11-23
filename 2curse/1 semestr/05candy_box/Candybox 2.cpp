#include <iostream>
#include <cstring>
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
    int count(int x);
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

int count_afterwards(CandyBox b, int x) {
    CandyBox c = Arcady_process(b);
    CandyBox d = Alice_process(b);
    return c.count(x) + d.count(x);
}

int CandyBox::count(int x) {
    int count_x = 0;
    for (int i = 0; i < cnt; i++) {
        if (candies[i] == x) {
            count_x += 1;
        }
    }
    return count_x;
}

class Barrel {
private:
    int cnt;
    char* balls;

public:
    Barrel(const char* str = NULL) {
        if (str == NULL) {
            cnt = 0;
            balls = NULL;
            return;
        }
        cnt = strlen(str);         
        balls = new char[cnt];
        for (int i = 0; i < cnt; ++i) {
            balls[i] = str[i];
        }
    }

    ~Barrel() {
        delete[] balls;
    }

    int count() {
        return cnt;
    }

    void clockwise(int x) {
        if (cnt == 0) return;
        x %= cnt;
        if (x < 0) x += cnt;
        if (x == 0) return;

        char* tmp = new char[x];
        for (int i = 0; i < x; ++i) {
            tmp[i] = balls[cnt - x + i];
        }
        for (int i = cnt - 1; i >= x; --i) {
            balls[i] = balls[i - x];
        }
        for (int i = 0; i < x; ++i) {
            balls[i] = tmp[i];
        }
        delete[] tmp;
    }

    void countercw(int x) {
        if (cnt == 0) return;
        x %= cnt;
        if (x < 0) x += cnt;
        if (x == 0) return;

        char* tmp = new char[x];
        for (int i = 0; i < x; ++i) {
            tmp[i] = balls[i];
        }
        for (int i = 0; i < cnt - x; ++i) {
            balls[i] = balls[i + x];
        }
        for (int i = 0; i < x; ++i) {
            balls[cnt - x + i] = tmp[i];
        }
        delete[] tmp;
    }

    char extract() {
        if (cnt == 0) return '\0';
        char res = balls[0];
        for (int i = 0; i < cnt - 1; ++i) {
            balls[i] = balls[i + 1];
        }
        --cnt;
        return res;
    }
};
class Job {
private:
    string surname;
    string name;
    int let;
    string phone_number;
public:
    Job(string surname = "Иванове", string name = "Иване", int let = 123, string phone_number = "+79051234567") {
        surname = this->surname;
        name = this->name;
        let = this->let;
        phone_number = this->phone_number;
    }
    void read();
    void print();
    void proverka(int x);
};
void Job::read() {
    cin >> surname >> name >> let >> phone_number;
}
void Job::print() {
    cout << surname << " " << name << "\n";
}
void Job::proverka(int x) {
    if (let > x) {
        print();
    }
}
int main() {
    int n;
    cin >> n;
    Job* temp = new Job[n];
    for (int i = 0; i < n; i++) {
        Job b;
        b.read();
        temp[i] = b;
    }
    int r;
    cin >> r;
    for (int i = 0; i < n; i++) {
        temp[i].proverka(r);
    }
    delete[] temp;
}