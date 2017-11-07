#include <iostream>
using namespace std;

double inch(double height){return height * 0.393701;}
double pound(double weight){return weight * 2.20462;}

double getHatsize(double weight, double height){
  double result;
  result = weight / height * 2.9;
  return result;
}
double getJacketsize(double height, double weight, int age){
  double result;
  int add;
  add = (age - 40) / 10;
  if(age >= 30)
    result = weight * height / 288 + static_cast<double> (add) * (1/8);
  else
    result = weight * height / 288;
  return result;
}
double getWaistsize(double weight, int age){
  double result;
  int add;
  add = (age-28) / 2;
  if(age > 28)
    result = weight / 5.7 + static_cast<double> (add) * (1/10);
  else
    result = weight / 5.7;
  return result;
}

int main(){
  double height, weight, hat_size, jack_size, wai_size;
  int age;
  cout << "Input your [height] in cm, [weight] in kg, and [age] in years:" << endl;
  cin >> height >> weight >> age;
  height = inch(height);
  weight = pound(weight);
  hat_size = getHatsize(weight, height);
  jack_size = getJacketsize(height, weight, age);
  wai_size = getWaistsize(weight, age);
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << "Hat size: " << hat_size << endl;
  cout << "Jacket size: " << jack_size << endl;
  cout << "Waist size: " << wai_size << endl;
  return 0;
}
