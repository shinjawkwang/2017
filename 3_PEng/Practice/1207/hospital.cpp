#include <iostream>
#include <string>
using namespace std;

/* Person Class */
class Person{
private:
  string name;
public:
  Person(){}
  Person(string name);
  Person(const Person& person);
  string getName() const;
  void setName(string name);
  Person operator=(const Person& person);
  friend ostream& operator <<(ostream &outputStream, const Person& person);
};
string Person::getName() const {
  return name;
}
void Person::setName(string name) {
  this->name = name;
}
Person::Person(string name){setName(name);}
Person::Person(const Person& person){setName(person.getName());}
Person Person::operator=(const Person& person){
  name = person.getName();
  return *this;
}
ostream& operator <<(ostream &outputStream, const Person& person){
  outputStream << person.getName();
  return outputStream;
}

/* Person - Doctor Class */
class Doctor : public Person{
private:
  string special;
public:
  Doctor():Person(){}
  Doctor(const Person& person, string special);
  Doctor(string name, string special);
  string getSpecial() const;
  void setSpecial(string special);
  Doctor operator=(const Doctor& doctor);
  friend ostream& operator <<(ostream &outputStream, const Doctor& doctor);
};
string Doctor::getSpecial() const{
  return special;
}
void Doctor::setSpecial(string special){
  this->special = special;
}
Doctor::Doctor(const Person& person, string special):Person(person){
  setName(person.getName());
  setSpecial(special);
}
Doctor::Doctor(string name, string special):Person(name){
  setName(name);
  setSpecial(special);
}
Doctor Doctor::operator=(const Doctor& doctor){
  Person::operator=(doctor);
  special = doctor.getSpecial();
  return *this;
}
ostream& operator <<(ostream &outputStream, const Doctor& doctor){
  outputStream << "Doctor ";
  outputStream << doctor.getName();
  outputStream << " specialist in ";
  outputStream << doctor.getSpecial();
  return outputStream;
}

/* Person - Patient Class */
class Patient : public Person{
private:
  string illness;
  Doctor doctor;
public:
  Patient(){}
  Patient(const Person& person, string illness);
  Patient(string name, string illness);
  const Doctor& getDoctor() const{return doctor;}
  string getIllness() const{return illness;}
  void setDefalutDoctor();
  void setIllness(string ill){this->illness = ill;}
  Patient operator=(const Patient& patient);
  Patient operator=(const Doctor& doctor);
  friend ostream& operator <<(ostream &outputStream, const Patient& patient);
};
void Patient::setDefalutDoctor(){
  Doctor DefaultDoct("[[Person not set yet]]", "[[No speciality set]]");
  doctor = DefaultDoct;
}
Patient::Patient(const Person& person, string illness):Person(person){
  setName(person.getName());
  setIllness(illness);
  setDefalutDoctor();
}
Patient::Patient(string name, string illness):Person(name){
  setName(name);
  setIllness(illness);
  setDefalutDoctor();
}
Patient Patient::operator=(const Patient& patient){
  Person::operator=(patient);
  illness = patient.getIllness();
  return *this;
}
Patient Patient::operator=(const Doctor& doct){
  doctor = doct;
  return *this;
}
ostream& operator <<(ostream &outputStream, const Patient& patient){
  outputStream << patient.getName();
  outputStream << " has ";
  outputStream << patient.getIllness();
  outputStream << " and doctor is ";
  outputStream << patient.getDoctor();
  return outputStream;
}

int main()
{
    Person person1("Isaac Newton");
    Person person2(person1);

    Patient patient1(person1, "Fever");

    Patient patient2(Person("Thomas Edison"), "broken arm");

    Doctor doc1("Albert Einstein", "head");
    Doctor doc2("Nikola Tesla", "Bones");

    cout << doc1 << endl;
    cout << doc2 << endl << endl;
    patient1 = doc1;
    cout << patient1 << endl;
    cout << patient2 << endl;
    patient2 = doc2;
    cout << patient2 << endl;
    patient2 = patient1;
    cout << patient2 << endl;

    return 0;
}
