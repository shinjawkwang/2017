#include <iostream>
#include <cstring>
using namespace std;

class Complex{
private:
	double real;
  double img;
  double get_number(const char *str, int from, int to);
public:
  Complex();
  Complex(double inptreal, double inptimg);
  Complex(const char *str);
  const Complex operator +(const Complex& b);
  const Complex operator -(const Complex& b);
  const Complex operator *(const Complex& b);
  const Complex operator /(const Complex& b);
  void operator =(const Complex& b);
  void operator +=(const Complex& b);
  void operator -=(const Complex& b);
  void operator *=(const Complex& b);
  void operator /=(const Complex& b);
  void println();
  friend ostream& operator <<(ostream &outputStream, const Complex &oupt);
  friend const Complex operator+(const char *str, const Complex &a);
  friend const Complex operator-(const char *str, const Complex &a);
  friend const Complex operator*(const char *str, const Complex &a);
  friend const Complex operator/(const char *str, const Complex &a);
};

const Complex Complex::operator +(const Complex& b){
  return Complex(real + b.real, img + b.img);
}
const Complex Complex::operator -(const Complex& b){
  return Complex(real - b.real, img - b.img);
}
const Complex Complex::operator *(const Complex& b){
  return Complex(real*b.real - img*b.img, real*b.img + img*b.real);
}
const Complex Complex::operator /(const Complex& b){
  return Complex((real*b.real + img*b.img)/(b.real*b.real + b.img*b.img), (-real*b.img + img*b.real)/(b.real*b.real + b.img*b.img));
}
void Complex::operator =(const Complex& b){
  real = b.real;
  img = b.img;
}
void Complex::operator +=(const Complex& b){
  real += b.real;
  img += b.img;
}
void Complex::operator -=(const Complex& b){
  real -= b.real;
  img -= b.img;
}
void Complex::operator *=(const Complex& b){
  double temp = real;
  real = real*b.real - img*b.img;
  img = temp*b.img + img*b.real;
}
void Complex::operator /=(const Complex& b){
  double temp = real;
  real = (real*b.real + img*b.img) / (b.real*b.real + b.img*b.img);
  img = (-temp*b.img + img*b.real) / (b.real*b.real + b.img*b.img);
}
void Complex::println(){
  cout << real << " + " << img << "i\n";
}
ostream& operator <<(ostream &outputStream, const Complex &oupt){
  double opreal, opimg;
  opreal = oupt.real, opimg = oupt.img;
  outputStream << opreal;
  outputStream << " + ";
  outputStream << opimg;
  outputStream << "i";
  return outputStream;
}

Complex::Complex(){}
Complex::Complex(double inptreal, double inptimg){
  real = inptreal; img = inptimg;
}
Complex::Complex(const char* str){
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    int pos_i = -1;
    for(int i = 0; i != end; i ++) {
        if(str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    if(pos_i == -1) {
        real = get_number(str, begin, end - 1);
        return ;
    }

    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if(pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char *str, int from, int to){
    bool minus = false;
    if(from > to) return 0;

    if(str[from] == '-') minus = true;
    if(str[from] == '-' || str[from] == '+') from ++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for(int i = from; i <= to; i ++) {
        if(isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        }
        else if(str[i] == '.') integer_part = false;
        else if(isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        }
        else break;
    }

    if(minus) num *= -1.0;

    return num;
}
const Complex operator+(const char *str, const Complex &a){
  Complex b = Complex(str);
  return Complex(a.real + b.real, a.img + b.img);
}
const Complex operator-(const char *str, const Complex &a){
  Complex b = Complex(str);
  return Complex(b.real - a.real, b.img - a.img);
}
const Complex operator*(const char *str, const Complex &a){
  Complex b = Complex(str);
  return Complex(a.real*b.real - a.img*b.img, a.real*b.img + a.img*b.real);
}
const Complex operator/(const char *str, const Complex &a){
  Complex b = Complex(str);
  return Complex((b.real*a.real + b.img*a.img)/(a.real*a.real + a.img*a.img), (-b.real*a.img + b.img*a.real)/(a.real*a.real + a.img*a.img));
}

int main(){
	Complex a(0, 0);
  cout << "<------Using Public------>\n";
	a = a + "-1.1 + i3.923";
	a.println();
	a = a - "1.2 -i1.823";
	a.println();
	a = a * "2.3+i22";
	a.println();
	a = a / "-12+i55";
	a.println();
	a += "-1.1 + i3.923";
	a.println();
	a -= "1.2 -i1.823";
	a.println();
	a *= "2.3+i22";
	a.println();
	a /= "-12+i55";
	a.println();

  cout << "\n<------Using Freind------>\n";
  Complex b(0, 0);
	b = "-1.1 + i3.923" + b;
	cout << b << endl;
	b = "1.2 -i1.823" - b;
	cout << b << endl;
	b = "2.3+i22" * b;
	cout << b << endl;
	b = "-12+i55" / b;
	cout << b << endl;

  return 0;
}
