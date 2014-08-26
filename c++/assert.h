#include <cstdlib>
#include <iostream>
#include <string>

#ifndef ASSERT_DEF
#define ASSERT_DEF

using namespace std;

static void areEqualInts(int a, int b)
{
    if (a != b)
    {
        cout << "Test error: " << a << " and " << b << " are not equal." << endl;
        exit(1);
    }
}

static void areEqualStrings(string a, string b)
{
    if (a.compare(b) != 0)
    {
        cout << "Test error: " << a << " and " << b << " are not equal." << endl;
        exit(1);
    }
}

static void areNotEqualInts(int a, int b)
{
    if (a == b)
    {
        cout << "Test error: " << a << " and " << b << " are equal." << endl;
        exit(1);
    }
}

static void areNotEqualStrings(string a, string b)
{
    if (a.compare(b) == 0)
    {
        cout << "Test error: " << a << " and " << b << " are equal." << endl;
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

static void isFalse(bool a)
{
    isTrue(!a);
}

#endif