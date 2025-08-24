#include <iostream>

using namespace std;

class Box
{
private:
    int *num;

public:
    // default
    Box()
    {
        num = new int(0);
    }
    // copy
    Box(const Box &obj)
    {
        num = new int(*obj.num);
    }
    // destructor
    ~Box()
    {
        delete num;
    }
    Box &operator=(const Box &obj)
    {
        if (this != &obj)
        {
            delete num;
            num = new int(*obj.num);
        }
        return *this;
    }
    void setNum(int number)
    {
        *num = number;
    }
    void displayNum()
    {
        cout << "The value of num is: " << *num << endl;
        cout << endl;
    }
};

int main()
{
    Box b1;
    b1.displayNum();

    b1.setNum(32);

    // deep copy constructor
    Box b2 = b1;
    b1.displayNum();
    b2.displayNum();

    b1.setNum(688);
    b1.displayNum();
    b2.displayNum();

    // deep copy assignment operator
    b2 = b1;
    b2.displayNum();
    b1.displayNum();

    return 0;
}

/* Demonstrate the behavior of both shallow and deep copy using test cases.

I have used some test cases to demonstrated deep copy using the constructor as well as the
custom copy assignment operator. By using deep copy we ensure that new memory is reserved
for the new object rather than the new object pointing to the other object's memory.

Hence when we delete or change one object, the other remains unaffected thus,
avoiding a double delete crash.


P.S, also sir as per your instruction, I have written a descriptive answer (this comment) to compare
deep vs shallow copy rather than coding the shallow copy part.
*/
