#ifndef CHAIN_HASH_H
#define CHAIN_HASH_H
#include <iostream>
#include "../../../Documents/CS8(assignment)/AVLclass/avl.h"
#include "struct_record.h"

using namespace std;

template <class RecordType>
class chained_hash
{
public:
    enum
    {
        TABLE_SIZE = 811
    };
    // Or: static const int TABLE_SIZE = 811;

    chained_hash( )
    {
        total_records =0;

    }//CTOR

    bool insert(const record& entry)
    {
        if(size()>TABLE_SIZE){
            return false;
        }
        assert(entry._key>=0);
        size_t index = hash(entry._key);
        bool found = _data[index].insert(entry);
        if(!found)
        {
            ++total_records;
            return true;
        }
        else
        {
            return false;
        }
    }//insert entry

    bool remove(int key)
    {
        assert(key>=0);
        return _data[hash(key)].erase(record(key));
    }
    //remove this key

    bool find(int key, bool found, record& result)
    {
        assert(key>=0);
        int index = hash(key);
        tree_node<RecordType> *temp= NULL;
        found = _data[index].search(record(key),temp);
        if(found)
            result = temp->_item;
        return found;

    }
    //result <- record with key
    bool is_present(int key)
    {
        tree_node<RecordType> *temp;
        return _data[hash(key)].search(record(key),temp);
    }
    //is this key present in table?
    int size( ) const
    {
        return total_records;
    }
    //number of keys in the table
    friend ostream& operator << (ostream& outs,const chained_hash& h)
    {
        for(int i = 0;i<TABLE_SIZE;i++)
            outs<<"["<<i<<"]"<< endl<< h._data[i]<<endl;
        return  outs;
    }
    //print entire table with keys, etc.

private:
    avl<RecordType> _data[TABLE_SIZE];
    //table chains

    int total_records;
    //number of keys in the table

    size_t hash(int key) const
    {
        return key%TABLE_SIZE;
    }//hash function
};


#endif // CHAIN_HASH_H
