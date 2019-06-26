#include <iostream>
#include <vector>

class Person {
public:
    std::string name;
    int age;
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person {
public:
    static int p_id;
    int publications, cur_id;
    Professor() {
        this->cur_id = ++p_id;
    }
    void getdata() {
        // input name, age, publications of professor
        std::cin >> this->name >> this->age >> this->publications;
    }
    void putdata() {
        // print name, age, publications, cur_id of professor
        std::cout << this->name << " " << this->age << " "  << this->publications << " "  << this->cur_id << std::endl;
    }
};

int Professor::p_id = 0;

class Student : public Person {
public:
    static int s_id;
    int marks[6];
    int cur_id;
    Student() {
        this->cur_id = ++s_id;
    }
    void getdata() {
        // input name, age, marks of student in 6 subjects
        std::cin >> name >> age;
        for(int i=0;i<6;i++) std::cin >> marks[i];
    }
    void putdata() {
        // print name, age, sum of marks and cur_id of student
        int sum = 0;
        for(int i=0;i<6;i++) sum += marks[i];
        std::cout << this->name << " "  << this->age <<  " " << sum << " " << this->cur_id << std::endl;
    }
};

int Student::s_id = 0;

int main() {
    int n,val;
    std::cin >> n;
    std::vector<Person*> persons;
    for(int i=0;i<n;i++) {
        std::cin >> val;
        if(val == 1) { // professor
            persons[i] = new Professor;
        } else { // student
            persons[i] = new Student;
        }
        persons[i]->getdata();
    }

    for(int i=0;i<n;i++) persons[i]->putdata();
}