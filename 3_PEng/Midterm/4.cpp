#include <iostream>

using namespace std;
class Student{
	public:
		string studentID, studentName;
		int age, score;
		void print_studentInfo();
		Student(string id, string name, int ageIn, int scoreIn);
		Student(string id, string name);
		Student();
};
Student::Student(){
	studentID = "2017311311";
	studentName = "HONG GIL DONG";
	age = 20;
	score = 90;
}
Student::Student(string id, string name, int ageIn, int scoreIn){
	studentID = id;
	studentName = name;
	age = ageIn;
	score = scoreIn;
}
Student::Student(string id, string name){
	studentID = id;
	studentName = name;
	age = 20;
	score = 90;
}
void Student::print_studentInfo(){
	cout << studentID << "\t" << studentName << "\t" << age << "\t" << score << endl;
}
int main() {
	Student a("2017312724", "KIM IN SU", 20, 80);
  Student b("2014312134", "MOON SE JONG");
  Student c;
  a.print_studentInfo();
  b.print_studentInfo();
  c.print_studentInfo();
  b = Student("2016312342", "PARK KEONG SU");
  b.print_studentInfo();
  return 0;
}
