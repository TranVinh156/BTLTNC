#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student
{
public:
    void set_age(int age) {age_ = age;};
    void set_standard(int standard) {standard_ = standard;};
    void set_first_name(string first_name) {first_name_ = first_name;};
    void set_last_name(string last_name) {last_name_ = last_name;};

    int get_age() const {return age_;};
    int get_standard() const {return standard_;};
    string get_first_name() const {return first_name_;};
    string get_last_name() const {return last_name_;};
    void to_string()
    {
        cout << age_ << "," << first_name_ << "," << last_name_ << "," << standard_;
    }
private:
    int age_;
    int standard_;
    string first_name_;
    string last_name_;
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
    st.to_string();
    
    return 0;
}
