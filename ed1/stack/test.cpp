#include <iostream>
#include "stackvet.h"

using namespace std;

int main()
{
    // Test wether class instantiation is possbile in different types
    StackVet<int> t1(10);
    StackVet<string> t2(10);
    StackVet<double> t3(15);

}