#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  double n1, n2, n3;
  cout << "Please enter three numbers: ";
  cin >> n1;
  cin >> n2;
  cin >> n3;
  if(n1 > n2 && n2 > n3){
    cout << "decreasing" << endl;
  }
  else if (n1 < n2 && n2 < n3){
    cout << "increasing" << endl;
  }
  else{
    cout << "neither" << endl;
  }
  return 0;
}
