#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

// 1.1 Принадлежит ли квадрату
bool is_in_square(double x, double y) {
    if (x >= -1 and x <= 1 and y >= -1 and y <= 1) {
        return true;
    }
    return false;
}

void ts1() {
    double x, y;
    cin >> x >> y;
    if (is_in_square(x, y)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}

// 1.2 Возведение в степень
long long pw(long long a, unsigned int p) {
    long long s = 1;
    for (int i = 0; i < p; i++) {
        s *= a;
    }
    return s;
}

void ts2() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << pw(x, 11) + pw(y, 5) + pw(z, 18);
}

// 1.3 Есть ли такая цифра
bool has_digit(int n, int d) {
    if (n == 0 and d == 0) {
        return true;
    }
    while (n > 0) {
        if (n % 10 == d) {
            return true;
        }
        n /= 10;
    }
    return false;
}

void ts3() {
    int n, d;
    cin >> n >> d;
    if (has_digit(n, d)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}

// 1.4 Принадлежит ли точка кругу
bool is_in_circle(double x, double y, double xc = 0, double yc = 0, double r = 1) {
    double dx = x - xc;
    double dy = y - yc;
    if (dx * dx + dy * dy < r * r) {
        return true;
    }
    return false;
}

void ts4() {
    double x, y, xc, yc, r;
    cin >> x >> y >> xc >> yc >> r;
    if (is_in_circle(x, y, xc, yc, r)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}

// 1.5 Периметр и площадь треугольника
void triangle_stats(double A, double B, double C, double *area, double *perimeter) {
    *perimeter = A + B + C;
    double p = *perimeter / 2;
    *area = sqrt(p * (p - A) * (p - B) * (p - C));
}

void ts5() {
    double A, B, C, area, perimeter;
    cin >> A >> B >> C;
    triangle_stats(A, B, C, &area, &perimeter);
    cout << fixed << setprecision(6);
    cout << area << endl << perimeter;
}

// 1.6 Площадь треугольника
double triangle_area(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    return triangle_area(a, b, c);
}

void ts6() {
    int p;
    cin >> p;
    cout << fixed << setprecision(4);
    if (p == 3) {
        double a, b, c;
        cin >> a >> b >> c;
        cout << triangle_area(a, b, c);
    }
    else {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        cout << triangle_area(x1, y1, x2, y2, x3, y3);
    }
}

// 1.7 Сократить дробь
int evk(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void reduce_fraction(int *n, int *m) {
    int d = evk(*n, *m);
    *n /= d;
    *m /= d;
}

void ts7() {
    int a, b;
    cin >> a >> b;
    reduce_fraction(&a, &b);
    cout << a << " " << b;
}

// 1.8 Вставить в массив
int* array_insert(int* a, int n, int x = 100, int k = 0) {
    int* temp = new int[n + 1];
    for (int i = 0; i < k; i++) {
        temp[i] = a[i];
    }
    temp[k] = x;
    for (int i = k + 1; i < n + 1; i++) {
        temp[i] = a[i - 1];
    }
    delete[] a;
    return temp;
}

void ts8() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x, k;
    cin >> x >> k;
    a = array_insert(a, n, x, k);
    for (int i = 0; i < n + 1; i++) {
        cout << a[i] << " ";
    }
}

// 1.9 Является ли перестановкой
bool is_permutation(int* A, int* B, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
            if (B[j] > B[j + 1]) {
                swap(B[j], B[j + 1]);
            }
        }
    }
    for (int i = 0; i < size; i++) {
        if (A[i] != B[i]) {
            return false;
        }
    }
    return true;
}

void ts9() {
    int size;
    cin >> size;
    int* A = new int[size];
    int* B = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < size; i++) {
        cin >> B[i];
    }
    if (is_permutation(A, B, size)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}

int main() {
    //ts1();
    //ts2();
    //ts3();
    //ts4();
    //ts5();
    //ts6();
    //ts7();
    //ts8();
    ts9();
}