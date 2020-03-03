#ifndef STRUCT_RECORD_H
#define STRUCT_RECORD_H
#include <iostream>
#include <fstream>
using namespace std;

struct record
{
    int _key;
    double _value;
    bool duplicated = false;
    int real_index;
    record(int k=0, double v=0, bool d= false, int i = 0):_key(k), _value(v), duplicated(d), real_index(i){}
    friend bool operator == (const record& left, const record& right)
    {
        return left._key == right._key;
    }
    friend bool operator >(const record& LHS, const record& RHS)
    {
        return LHS._key > RHS._key;
    }
    friend ostream& operator <<(ostream& outs, const record& print_me)
    {
        outs<<setw(4)<<print_me._key<<":"<<setw(4)<<print_me._value;
        return outs;
    }
    friend bool operator <(const record& LHS, const record& RHS)
    {
        return LHS._key < RHS._key;
    }

};

#endif // STRUCT_RECORD_H
