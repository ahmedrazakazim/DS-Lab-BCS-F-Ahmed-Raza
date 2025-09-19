#include <iostream>

using namespace std:

int calculateFactorial(int n) {
if (n == 1) {
  return 1;
}
else
  return n*calculateFactorial(n-1); 

}

int main() {
int n;
  cout << "Enter a number: \n";
cin >> n;
  calculateFactorial(n);

  return 0;
}
