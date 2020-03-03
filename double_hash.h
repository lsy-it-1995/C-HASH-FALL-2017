#ifndef double_hash_H
#define double_hash_H

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <iomanip>
#include <fstream>
#include "struct_record.h"

using namespace std;

template<class RecordType>
class double_hash
{
public:
    static const size_t CAPACITY = 811;
    double_hash();
    void insert(const record& entry);
    bool remove(int key);
    bool is_present(int key) const;
    bool find(int key, bool &found, record &result) const;
    size_t size() const
    {
        return used;
    }
    size_t collisions();
    friend ostream& operator <<(ostream &outs, const double_hash &print_me)
    {
        for(unsigned int i = 0;i<CAPACITY;i++)
        {
            outs<<setfill('0')<<"["<<i<<"] ";
            if(print_me.data[i]==PREVIOUSLY_USED)
                outs<<"- - - -";
            else if(print_me.data[i]._key!=-1)
            {
                outs <<print_me.data[i]<<"("<< print_me.data[i].real_index <<")";
                if(print_me.data[i].duplicated)
                {
                    outs<<"*";
                }
            }
            outs << endl;
        }
        outs<<"collision: "<<print_me.collision<<endl;
        return outs;
    }
private:
    static const int NEVER_USED = -1;
    static const int PREVIOUSLY_USED = -2;
    record data[CAPACITY];
    size_t used;
    size_t collision = 0;
    size_t hash(int key) const;
    size_t hash2(int key) const;
    size_t next_index(size_t index, int key) const;
    void find_index(int key, bool &found, size_t &index) const;
    bool never_used(size_t index) const;
    bool is_vacant(size_t index) const;
};
template<class RecordType>
size_t double_hash<RecordType>::collisions()
{
    return collision;
}

template <class RecordType>
void double_hash<RecordType>::insert(const record &entry)
{

    bool already_present = false;
    size_t index;
    assert(entry._key>=0);
    find_index(entry._key,already_present,index);
    if(used>CAPACITY)
        return;

    if(!already_present)
    {
        assert(size()<CAPACITY);

        index = hash(entry._key);
        if(is_vacant(index))
        {
            data[index].real_index = index;
            data[index]._value = entry._value;
            data[index]._key = entry._key;
        }
        else
        {
            unsigned int before_change = index;
            while(!is_vacant(index))
            {
                index = next_index(index,entry._key);
                data[index].duplicated = true;
                collision ++;
            }
            data[index].duplicated = true;
            data[index].real_index = before_change;
            data[index]._value = entry._value;
            data[index]._key = entry._key;
        }
        ++used;
    }
}

template <class RecordType>
bool double_hash<RecordType>::remove(int key)
{
    bool found = false;
    size_t index;
    assert(key>=0);
    find_index(key,found,index);
    if(found)
    {
        data[index]._key = PREVIOUSLY_USED;
        data[index]._value = PREVIOUSLY_USED;
        data[index].real_index = PREVIOUSLY_USED;
        --used;
        return true;
    }
    else
    {
        cout<<"the number doesn't existed"<<endl;
        return false;
    }
}

template<class RecordType>
double_hash<RecordType>::double_hash()
{
    bool debug = false;
    size_t i;
    used = 0;
    collision = 0;
    if(debug) cout << "DEFAULT CONSTRUCTOR" << endl;
    if(debug) cout << NEVER_USED << endl;
    for(i = 0;i<CAPACITY;++i)
    {
        data[i]._key = NEVER_USED;
        if(debug) cout << "data[" << i << "] key: " << data[i]._key << endl;
    }
}

template<class RecordType>
bool double_hash<RecordType>::is_present(int key) const
{
    bool found;
    size_t index;
    assert(key >= 0);
    find_index(key, found, index);
    return found;
}

template<class RecordType>
bool double_hash<RecordType>::find(int key, bool &found, record &result) const
{
    size_t index;
    find_index(key,found,index);
    if(found)
    {
        result  = data[index];
        cout<<data[index]<<endl;
    }
    return found;
}

template<class RecordType>
size_t double_hash<RecordType>::hash(int key) const
{
    return key%(CAPACITY);
}
template<class RecordType>
size_t double_hash<RecordType>::hash2(int key) const
{
    return 1+(key%(CAPACITY-2));
}
template<class RecordType>
size_t double_hash<RecordType>::next_index(size_t index, int key) const
{
    bool debug = false;
    if(debug) cout << "inside next_index" << endl << "current index: " << index << endl << "next index should be: " << ((index+1)%CAPACITY) << endl;
    return (index + hash2(key)) % CAPACITY;
}

template<class RecordType>
void double_hash<RecordType>::find_index(int key, bool &found, size_t &index) const
{
    size_t count;
    count = 0;
    index = hash(key);
    while((count<CAPACITY)&&(!never_used(index))&&(data[index]._key!=key))
    {
        ++count;
        index = next_index(index,key);
    }
    found = (data[index]._key==key);
}

template<class RecordType>
bool double_hash<RecordType>:: never_used(size_t index) const
{
    return (data[index]._key==NEVER_USED);
}

template<class RecordType>
bool double_hash<RecordType>::is_vacant(size_t index) const
{
    bool debug = false;
    if(debug) cout << "inside is_vacant" << endl << "index: " << index << endl << "data[index]._key: " << data[index]._key << endl;
    return data[index]._key<0;
}

#endif // double_hash_H
