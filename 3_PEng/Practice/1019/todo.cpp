#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

class Todo {
		private:
        string task;
    public:
        Todo();
        void setTask(istream& fin);
        const string&  getTask() const;
};

class TodoList {
    private:
        static vector<Todo> list;
        static int size;
    public:
        TodoList();
        void addTodo(Todo &t);
        void printList();
        int getListsize();
};

Todo::Todo() {};
TodoList::TodoList() {};

const string& Todo::getTask() const{
  return task;
}

void Todo::setTask(istream& fin) {
  cout << "Set task string: \n" ;
  getline(fin >> ws, task);
}

int TodoList::size = 0;
vector<Todo> TodoList::list;

void TodoList::addTodo(Todo& t) {
    list.push_back(t);
    size ++;
}
void TodoList::printList(){
  for(int i=1;i<=size;i++){
    cout << "[" << i << "]: ";
    cout << list[i-1].getTask();
    cout << endl;
  }
}
int TodoList::getListsize(){
  return size;
}

int main() {
    TodoList list;
    int iter;
    cout << "How many tasks to be created? ";
    cin >> iter;

    Todo todo[iter];
    while(iter--) {
      todo[iter].setTask(cin);
      list.addTodo(todo[iter]);
    }
    list.printList();
    cout << "List size = " << list.getListsize() << endl;
}
