#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

/* non-self modifying code */
int main()
{
	string data;
	ifstream fin;
	ofstream fout;

	fout.open("rawdata.txt");
	while (1) {
		getline(cin, data);
		if (data.compare("exit") == 0)
			break;
		fout << data << endl;
	}
	fout.close();
/* end */
fout.setf(ios::fixed | ios::showpoint | ios::right);
fout.width(12);
fout.precision(5);

double num;
fin.open("rawdata.txt");
fout.open("neat.txt");
while(fin >> data){
	//cout << "Starting first while . . .\n";
  stringstream stream(data);
  while(stream >> num){
		//cout << "Starting second while . . .\n";
		if(num>0){
			fout << showpos << setw(12) << num << endl;
		}
		else{
			fout << setw(12) << num << endl;
		}
  }
}
fin.close();
fout.close();

/* non-self modifying code */
	fin.open("neat.txt");
	string tmp;
	while (getline(fin, tmp))
		cout << tmp << endl;
	fin.close();
/* end */
	return 0;
}

/*
    +3.51200
   -54.00000
  +123.00000
    +0.51230
    +4.00000
  +124.00000
 +4214.30000
  -123.43000
   +53.00000
   +12.30000
   +25.00000
   -46.53000
   +12.53400
*/
