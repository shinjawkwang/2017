#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int math_mid, math_fin, eng_mid, eng_fin;
	float math_sum, eng_sum, math_avg, eng_avg;
	cout << "Midterm scores (math & eng) : ";
	cin >> math_mid >> eng_mid;
	cout << "Final scores (math & eng) : ";
	cin >> math_fin >> eng_fin;
	math_sum = math_mid + math_fin;
	eng_sum = eng_mid + eng_fin;
	math_avg = math_sum / 2;
	eng_avg = eng_sum / 2;
	cout <<"Subject\tSum\tAvg" << endl;
	printf("Math\t%.0f\t%.3f\n", math_sum, math_avg);
	printf("English\t%.0f\t%.3f\n", eng_sum, eng_avg);
  return 0;
}
