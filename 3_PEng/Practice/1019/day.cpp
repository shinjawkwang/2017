#include <iostream>
#include <cctype>
#include <string.h>
using namespace std;

class Month {
public:
  Month();
  int mValue;
  void inputMonthNumber(istream& fin);
  void inputMonthChar(istream& fin);
  void getMonthNumber(ostream& fout);
  void getMonthChar(ostream& fout);
  void ReturnNext();
};
Month::Month(){
  cout << "!=====> Default constructor <=====!\n" ;
}
void Month::inputMonthNumber(istream& fin){
  int var;
  cout << "Enter the month by number:";
  fin >> var;
  if(var < 1 || var > 12){
    cout << " \nInvalid month!\n";
    exit(0);
  }
  mValue = var;
}
void Month::inputMonthChar(istream& fin){
  char first, second, third;
  char month[3] = {first, second, third};
	cout << "Enter the month by letters: ";
  fin >> first >> second >> third;
  first = tolower(first);
  second = tolower(second);
  third = tolower(third);
  if(first == 'j' && second == 'a' && third == 'n')      mValue = 1;
  else if(first == 'f' && second == 'e' && third == 'b') mValue = 2;
  else if(first == 'm' && second == 'a' && third == 'r') mValue = 3;
  else if(first == 'a' && second == 'p' && third == 'r') mValue = 4;
  else if(first == 'm' && second == 'a' && third == 'y') mValue = 5;
  else if(first == 'j' && second == 'u' && third == 'n') mValue = 6;
  else if(first == 'j' && second == 'u' && third == 'l') mValue = 7;
  else if(first == 'a' && second == 'u' && third == 'g') mValue = 8;
  else if(first == 's' && second == 'e' && third == 'p') mValue = 9;
  else if(first == 'o' && second == 'c' && third == 't') mValue = 10;
  else if(first == 'n' && second == 'o' && third == 'v') mValue = 11;
  else if(first == 'd' && second == 'e' && third == 'c') mValue = 12;
  else{
    cout << " \nInvalid month!\n";
    exit(0);
  }
}
void Month::getMonthNumber(ostream& fout){
  fout << mValue << endl;
}
void Month::getMonthChar(ostream& fout){
  switch(mValue){
    case 1:
      fout << "Jan\n";
      break;
    case 2:
      fout << "Feb\n";
      break;
    case 3:
      fout << "Mar\n";
      break;
    case 4:
      fout << "Apr\n";
      break;
    case 5:
      fout << "May\n";
      break;
    case 6:
      fout << "Jun\n";
      break;
    case 7:
      fout << "Jul\n";
      break;
    case 8:
      fout << "Aug\n";
      break;
    case 9:
      fout << "Sep\n";
      break;
    case 10:
      fout << "Oct\n";
      break;
    case 11:
      fout << "Nov\n";
      break;
    case 12:
      fout << "Dec\n";
      break;
  }
}
void Month::ReturnNext(){
  if(mValue == 12)  mValue = 1;
  else              mValue ++;
}
int main(){
  Month mon;
  mon.inputMonthChar(cin);
  cout << "Current month in number is: ";
  mon.getMonthNumber(cout);
  cout << "Current month in letter is: ";
  mon.getMonthChar(cout);
  mon.ReturnNext();
  cout << "Next month in number is: ";
  mon.getMonthNumber(cout);
  cout << "Next month in letter is: ";
  mon.getMonthChar(cout);
}
