#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

typedef struct Point{
  double x,y;
}Point_s;

double get_distance_between(Point_s one, Point_s two){
  double x1 = one.x, y1 = one.y, x2 = two.x, y2 = two.y, result;
  result = hypot(x-x1, y-y1);
  return result;
}

class Point_c{
public:
  double x,y;
  double get_distance_to(Point_c);
};
double Point_c::get_distance_to(Point_c second){
  double x2 = second.x, y2 = second.y, result;
  result = hypot(x-x2, y-y2);
  return result;
}

int main(){
  int i, n;
  double x1, y1, x2, y2;
  Point_s one, two;
  Point_c first, second;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> x1 >> y1 >> x2 >> y2;
    one.x = x1, first.x = x1, one.y = y1, first.y = y1;
    two.x = x2, second.x = x2, two.y = y2, second.y = y2;
    cout << get_distance_between(one, two) << endl << first.get_distance_to(second) << endl;
  }

  return 0;
}
