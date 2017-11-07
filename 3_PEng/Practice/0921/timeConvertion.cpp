#include <iostream>
#include <stdio.h>
using namespace std;

int convert(int &hour){
	if(hour >= 12 && hour < 24){//PM
		if(hour>12)
			hour -= 12;
		return 1;
	}
	else{
		return 0;
	}
}

int main() {
	int hour, minuite, flag, n;
	char colon;
	cin >> n;
	for(int i=0;i<n;i++){
		scanf("%d%c%d", &hour, &colon, &minuite);
		flag  = convert(hour);
	
		if(flag)
			cout << hour << colon << minuite << " PM";
		else
			cout << hour << colon << minuite << " AM";
	}
  return 0;
}
