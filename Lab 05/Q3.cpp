#include <iostream>

using namespace std;


int sumTail(int n, int total)
{
    if (n == 0) {
        return total;
      }
  
  return sumTail(n - 1, total + n);
  }

// Non-tail recursive function
int sumNonTail(int n) 
{
    if (n == 0)
    return 0;
      
  return n + sumNonTail(n - 1);
}

int main()
{
    int n;
    cout<< "Enter a number: ";
    cin>> n;

    cout<< "Tail Recursion Sum (1 to " << n << "): " << sumTail(n, 0) << endl;
    cout<< "Non-Tail Recursion Sum (1 to " << n << "): " << sumNonTail(n) << endl;



  
    return 0;
}
