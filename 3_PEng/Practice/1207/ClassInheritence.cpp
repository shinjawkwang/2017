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
  string getName() const{
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
Person::Person(const Person& person):name(person.name){
  cout << "Person(const Person&) called\n";
}
Person::~Person(){
  //free(this);
  cout << "~Person() called\n";
}
/* Person - Student Class */
class Student : public Person{
public:
  Student();
  Student(const Person& person);
};
Student::Student():Person(){
  cout << "Student() called\n";
}
Student::Student(const Person& person):Person(person.getName()){
  cout << "Student(const Person&) called\n";
}
/* Person - Worker Class */
class Worker : public Person{
public:
  Worker();
  Worker(string str);
  Worker(const Person& person);
  virtual ~Worker();
};
Worker::Worker():Person(){
  cout << "Worker() called\n";
}
Worker::Worker(string str):Person(str){
  cout << "Worker(string) called\n";
}
Worker::Worker(const Person& person):Person(person.getName()){
  cout << "Worker(const Person&) called\n";
}
Worker::~Worker(){
  cout << "~Worker() called\n";
}
/* Person - Worker - Doctor Class */
class Doctor : public Worker{
public:
  Doctor();
  Doctor(string str);
  Doctor(const Person& person);
};
Doctor::Doctor():Worker(){
  cout << "Doctor() called\n";
}
Doctor::Doctor(string str):Worker(str){
  cout << "Doctor(string) called\n";
}
Doctor::Doctor(const Person& person):Worker(person.getName()){
  cout << "Doctor(const Person&) called\n";
}
/* Person - Worker - Doctor - Manager Class */
class Manager : public Doctor{
public:
  Manager(const Person& person);
  ~Manager();
};
Manager::Manager(const Person& person):Doctor(person.getName()){
  cout << "Manager(const Person&) called\n";
}
Manager::~Manager(){
  cout << "~Manager() called\n";
}
/* Person - Patient Class */
class Patient : public Person{
public:
  Patient();
  Patient(string str);
};
Patient::Patient():Person("Default String"){
  cout << "Patient() called\n";
}
Patient::Patient(string str):Person(str){
  cout << "Patient(string) called\n";
}

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
    Doctor* doctor3 = new Doctor();
    delete doctor3;
    cout << "--\n";
    Patient patient2;
    cout << "--\n";
    Person person1;
    cout << "--\n";
    Worker* worker1 = new Worker(person1);
    delete worker1;
    cout << "--\n";
    Person person2(patient2);
    cout << "--\n";
    cout << "--\n";
    Student student2(person1);
    cout << "--\n";
    Worker worker2;

    return 0;
}
