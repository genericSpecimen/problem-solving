#include <iostream>

using std::string;
using std::cout;
using std::endl;

class AbstractEmployee {
    virtual void askForPromotion() = 0;
};

class Employee : AbstractEmployee {
protected:
    string name;
    string company;
    int age;
public:    
    Employee(string _name, string _company, int _age) : name(_name), company(_company), age(_age) {}
    
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
    void setCompany(string company) {
        this->company = company;
    }
    string getCompany() {
        return company;
    }
    void setAge(int age) {
        if (age >= 18) {
            this->age = age;
        } else cout << "Employee must be at least 18 yo" << endl;
    }
    int getAge() {
        return this->age;
    }
    
    void askForPromotion() {
        if (age > 30) {
            cout << name << " got promoted." << endl;
        } else cout << name << ", no promotion for you." << endl;
    }
    
    virtual void work() {
        cout << name << " is doing generic work" << endl;
    }
    
    friend std::ostream& operator<< (std::ostream& os, const Employee& e) {
        os << "{";
        os << e.name << ", " << e.company << ", " << e.age;
        os << "}";
        return os;
    }
    
    
    
};

class Developer : public Employee {
public:
    string favpl;
    Developer(string name, string company, int age, string _favpl)
        : Employee(name, company, age), favpl(_favpl) {}
    void fixBug() {
        cout << this->name << " has fixed bug" << endl;
    }
    
    void work() {
        cout << this->name << " is developing" << endl;
    }
    
};

class Teacher : public Employee {
private:
    string subject;
public:
    Teacher(string name, string company, int age, string _subject)
        : Employee(name, company, age), subject(_subject) {
    }
    
    void prepareLesson() {
        cout << name << " is preparing " << subject << " lesson" << endl;
    }
    
    void work() {
        cout << this->name << " is teaching" << endl;
    }
};

int main() {
    Employee employee1("John", "Acme", 25);
    cout << employee1 << endl;
    employee1.askForPromotion();
    
    Employee employee2("Jane", "Acme", 35);
    cout << employee2 << endl;
    employee2.askForPromotion();
    
    Developer d("Daniel", "Acme", 40, "C++");
    d.fixBug();
    d.askForPromotion();
    
    Teacher t("Lisa", "Acme", 33, "Algorithms");
    t.prepareLesson();
    
    d.work();
    t.work();
    
    Employee* e = &d;
    e->work();
    
    e = &t;
    e->work();
    
}
