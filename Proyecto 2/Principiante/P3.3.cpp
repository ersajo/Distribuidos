#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  double n1, n2, n3;
  double max;
  cout << "Please enter three numbers: ";
  cin >> n1;
  cin >> n2;
  cin >> n3;
  max = n1;
  for(int i = 0; i < 2; i++){
    if(n2 > max) max = n2;
    if(n3 > max) max = n3;
  }
  cout << "The largest number is " << max << endl;
  return 0;
}
