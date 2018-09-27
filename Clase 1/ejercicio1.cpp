#include <iostream>
using namespace std;

const double PI = 3.1415926;

int main() {
  double radio;
  PI = 2;
  cout << "Proporcione el radio del circulo: ";
  cin >> radio;
  cout << "El area es " << PI * (radio * radio) << endl;
  return 0;
}
