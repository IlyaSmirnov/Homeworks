#include "example.h"
#include "myerror.h"

using namespace std;

int main()
{

    try
    {
        Example example[7];
        MyError::throwException1();
    }
    catch(MyError::Exception1 &)
    {
        cout << "Error\n";
    }

    return 0;
}

