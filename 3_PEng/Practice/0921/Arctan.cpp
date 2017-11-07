#include<iostream>
#include<math.h>
using namespace std;
double atan2(double x, double y, double angle){
	cout << "atan2" << " : "; 
	double degree = atan2(y,x);
	if(angle >= 360){
		return 0;
	}
	return degree + (angle/180) * M_PI;
}
double atan2(double angle){
	cout << "atan2" << " : "; 
	if(angle >= 360){
		return 0;
	}
	return (angle/180) * M_PI;
}
int main(){
	int N, n;
	char mode;
	double x, y, angle, result;
	cin >> N;
	for(n=0;n<N;n++){
		cin >> mode;
		if(mode == 'c'){
			cin >> x >> y >> angle;
			result = atan2(x, y, angle);
		}
		else{
			cin >> angle;
			result = atan2(angle);
		}
		cout << result << endl;
	}
	return 0;
}