#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	double money_recieved, rate, month, year, result_money, result_month;
	cin >> money_recieved >> rate >> month;
	year = month / 12;
	result_money = money_recieved / (1 - rate * year);
	result_month = result_money / month;
	printf("%.2lf %.2lf", result_money, result_month);
  return 0;
}
