#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student {
private:
    int age, standard;
    std::string first_name, last_name;
public:
    void set_age(int age) {
        this->age = age;
    }
    int get_age() const {
        return this->age;
    }
    void set_first_name(std::string first_name) {
        this->first_name = first_name;
    }
    std::string get_first_name() const {
        return this->first_name;
    }
    void set_last_name(std::string last_name) {
        this->last_name = last_name;
    }
    std::string get_last_name() const {
        return this->last_name;
    }
    void set_standard(int standard) {
        this->standard = standard;
    }
    int get_standard() const {
        return this->standard;
    }

    std::string to_string() {
        std::stringstream ss;
        ss << this->age << ',' << this->first_name << ',' << this->last_name << ',' << this->standard << std::endl;
        return ss.str();
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}

class Box {
private:
    int l,b,h;
public:
    Box() : l(0),b(0),h(0) {}
    Box(int _l, int _b, int _h) : l(_l),b(_b),h(_h) {}
    Box(const Box& B) {
        this->l = B.l;
        this->b = B.b;
        this->h = B.h;
    }

    int getLength() const { return this->l; }
    int getBreadth() const { return this->b; }
    int getHeight() const { return this->h; }
    long long int CalculateVolume() const { return l*b*h; }

    bool operator< (const Box& B) {
        return ((this->l < B.l) || (this->b < B.b && this->l == B.l) || (this->h < B.h && this->l == B.l && this->b == B.b));
    }

    friend std::ostream& operator<< (std::ostream& out, const Box& B) {
        out << B.l << " " << B.b << " " << B.h;
        return out;
    }
};