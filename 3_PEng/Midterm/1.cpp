#include <iostream>

using namespace std;

class counterType {
	public:
		int count;
		void setCount(int arg);
		void increase();
		void decrease();
		int peek();
		void print();
};
void counterType::setCount(int arg){
	count = arg;
}
void counterType::increase(){
	count ++;
}
void counterType::decrease(){
	if(count > 0)
		count --;
}
int counterType::peek(){
	return count;
}
void counterType::print(){
	cout << peek() << endl;
}
int main() {
	int input;
	counterType count;
	cin >> input;
	count.setCount(input);
	count.print();
	count.increase();
	count.print();
	count.decrease();
	count.print();
	count.decrease();
	count.print();
  return 0;
}
