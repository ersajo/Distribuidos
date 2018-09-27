#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
  int t1, t2;
  ostringstream ss;
  string out;
  cout << "Please enter the fisrt time: ";
  cin >> t1;
  cout << "Please enter the second time: ";
  cin >> t2;
  if(t1 > t2){
    ss << t2-t1+2360;
  }
  else{
    ss << t2-t1;
  }
  out = ss.str();
  if(out.length() < 4){
    cout << out.substr(0,1) << " Hours " << out.substr(1,3) << " minutes" << endl;
  }
  else{
    cout << out.substr(0,2) << " Hours " << out.substr(2,4) << " minutes" << endl;
  }
  return 0;
}
