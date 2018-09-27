#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  string pattern1, pattern2;
  pattern1 = "+--+--+--+";
  pattern2 = "|  |  |  |";
  for(int i=0; i < 3; i++){
    cout << pattern1 << endl;
    cout << pattern2 << endl;
  }
  cout << pattern1 << endl;
  return 0;
}
