#include <iostream>
#include <string>
using namespace std;

/* Person Class */
class Person{
public:
  Person();
  Person(string str);
  Person(const Person& person);
  ~Person();
  string getName(){
    return name;
  }
private:
  string name;
};
Person::Person(){
  cout << "Person() called\n";
}
Person::Person(string str){
  name = str;
  cout << "Person(string) called\n";
}
Person::Person(const Person& person){
  name = person.name;
  cout << "Person(const Person&) called\n";
}
Person::~Person(){
  free(this);
  cout << "~Person() called\n";
}
/* Person - Student Class */
class Student : public Person{
public:
  Student();
  Student(Person person);
};
Student::Student():Person(){
  cout << "Student() called\n";
}
Student::Student(Person person):Person(person.getName()){
  cout << "Student(const Person&) called\n";
}
/* Person - Worker Class */
class Worker : public Person{
public:
  Worker();
  Worker(string str);
  Worker(Person person);
  ~Worker();
};
Worker::Worker():Person(){
  cout << "Worker() called\n";
}
Worker::Worker(string str){
  cout << "Worker(string) called\n";
}

class Doctor : public Worker{
public:
  Doctor();
  Doctor(string str);
  Doctor(const Person& person);
};
class Manager : public Doctor{
public:
  Manager(const Person& person);
};
class Patient : public Person{
public:
  Patient();
  Patient(string str);
};


int main()
{
    Patient patient1("Albert Einstein");
    cout << "--" << endl;
    Doctor doctor1;
    cout << "--" << endl;
    Doctor doctor2(patient1);
    cout << "--" << endl;
    Manager manager1(patient1);
    cout << "--" << endl;
    Student student1;
    cout << "--" << endl;

		//----------- Insert your code after here ---//

    return 0;
}

/*  Expected output
Person(string) called << 1
Patient(string) called
--
Person() called << 2
Worker() called << 1
Doctor() called
--
Person(string) called << 3
Worker(string) called << 2
Doctor(const Person&) called
--
Person(string) called << 4
Worker(string) called << 3
Doctor(string) called
Manager(const Person&) called << 1
--
Person() called << 5
Student() called
--
Person() called << 6
Worker() called << 4
Doctor() called
~Worker() called << 3
~Person() called << 5
--
Person(string) called << 6
Patient() called
--
Person() called << 7
--
Person(string) called << 8
Worker(const Person&) called << 4
~Worker() called << 3
~Person() called << 7
--
Person(const Person&) called << 8
--
--
Person(string) called << 9
Student(const Person&) called
--
Person() called << 10
Worker() called << 4
~Worker() called << 3
~Person() called << 9
<<
~Person() called << 8
~Person() called << 7
~Person() called << 6
~Person() called << 5
~Person() called << 4
~Manager() called << 0
~Worker() called << 2
~Person() called << 3
~Worker() called << 1
~Person() called << 2
~Worker() called << 0
~Person() called << 1
~Person() called << 0
*/
