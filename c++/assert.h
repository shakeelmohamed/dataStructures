#include <cstdlib>
#include <iostream>

#ifndef ASSERT_DEF
#define ASSERT_DEF

using namespace std;

static void areEqual(int a, int b)
{
    if (a != b) {
        cout << "Test error: " << a << " and " << b << " are not equal." << endl;
        exit(1);
    }
}

static void isTrue(bool a)
{
    if (!a && a != 1)
    {
        cout << "Test error: " << a << " is not true (or 1)." << endl;
        exit(1);
    }
}

#endif