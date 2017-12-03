#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Cell;
class Table;

/* non-self modifying code */
class Cell
{
	string data;
public:
	Cell(string data);
	string get_data();
};
/* end */

/* non-self modifying code */
class Table
{
	int max_row_size, max_col_size;
	Cell*** data_table;

public:
	Table(int max_row_size, int max_col_size);
	~Table();

	void reg_cell(Cell* c, int row, int col);
/* end */
	int getRow(){return max_row_size;}
  int getCol(){return max_col_size;}
  Cell* getDT(int row, int col){return data_table[row][col];}
};

/* For Cell Class */
Cell::Cell(string data):data(data){}
string Cell::get_data(){return data;}

/* For Table Class */
Table::Table(int max_row_size, int max_col_size):
  max_row_size(max_row_size),
  max_col_size(max_col_size){
  data_table = new Cell**[max_row_size];
  for(int i=0;i<max_row_size;i++){
    data_table[i] = new Cell*[max_col_size];
  }
  for(int i=0;i<max_row_size;i++){
    for(int j=0;j<max_col_size;j++){
      data_table[i][j] = NULL;
    }
  }
}
Table::~Table(){
  for (int i=0;i<max_row_size;i++){
     delete[] data_table[i];
   }
  delete[] data_table;
}
void Table::reg_cell(Cell *c, int row, int col){
  if(row<max_row_size&&col<max_col_size){
      data_table[row][col]=c;
   }
}


/* non-self modifying code */
int main()
{
	int X, Y;

	cin >> X >> Y;
	cin.ignore(100, '\n');

	Table table(X, Y);

	while (true) {
		string tmp, data;
		stringstream sstream;
		int x, y;

		getline(cin, tmp);

		sstream.str(tmp);
		sstream >> x;

		if (x == -1)
			break;

		sstream >> y >> data;

		table.reg_cell(new Cell(data), x, y);
	}
/* end */
  ofstream fout("test.txt");
  int i, j, total=4 + table.getCol();
  int *cnt = new int[table.getCol()];
  for(i=0;i<table.getCol();i++){cnt[i] = 2;}
  for(i=0;i<table.getCol();i++){
    for(j=0;j<table.getRow();j++){
      if(table.getDT(j, i)){
        if(table.getDT(j, i)->get_data().length() > cnt[i]){
          cnt[i] = table.getDT(j, i)->get_data().length();
        }
      }
    }
  }
  for(i=0;i<table.getCol();i++){
    total += cnt[i];
  }
  for(i=0;i<=table.getRow();i++){
    for(j=0;j<=table.getCol();j++){
      if(!j){
        if(i){
          fout << left << setw(4) << i;
        }
        else{
          fout << "    ";
        }
      }
      else{
        if(!i){ //A B C D E..
          char alpha = j - 1 + 'A';
          fout << left << setw(cnt[j-1]) << alpha;
        }
        else{
          if(table.getDT(i-1, j-1)){
            fout << left << setw(cnt[j-1]) << table.getDT(i-1, j-1)->get_data();
          }
          else{
            for(int k=0;k<cnt[j-1];k++){
              fout << " ";
            }
          }
        }
      }
      if(j != table.getCol()){
        fout << "|";
      }
      else{
        fout << "\n";
      }
    }
    for(j=0;j<=total && i != table.getRow();j++){
      fout << "-";
    }
    if(i != table.getRow())
      fout << "\n";
  }
  fout.close();
/* non-self modifying code */
	ifstream fin("test.txt");
	string tmp;
	while (getline(fin, tmp))
		cout << tmp << endl;
	fin.close();
}
/* end */
/*
    |A    |B  |C          |D |E
--------------------------------
1   |jirej|   |           |  |
--------------------------------
2   |     |ere|gfewegewege|  |
--------------------------------
3   |     |   |           |  |
--------------------------------
4   |     |   |12215252   |  |
--------------------------------
5   |     |   |           |  |


 */
