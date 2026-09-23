#include <iostream>

using namespace std;

struct  Student {
    char name[51];
    char surname[51];
    unsigned int age;
    unsigned int grade;
    unsigned int mark_count;
    int* marks;
};

int main() {
    Student st;
    cin >> st.name >> st.surname >> st.age >> st.grade >> st.mark_count;
    cout << st.name << " " << st.surname << " " << st.age << " " << st.grade << " " << st.mark_count << endl;

    cout << endl;

    st.marks = new int[st.mark_count];
    for (int i = 0; i < st.mark_count; i++)
        cin >> st.marks[i];

    for (int i = 0; i < st.mark_count; i++)
        cout << st.marks[i] << " ";
    
    return 0;
}