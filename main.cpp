#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "open_hash.h"
#include "double_hash.h"
#include "chain_hash.h"
#include "timer.h"
#include "random.h"

using namespace std;
//int random_value(int x, int y);
//void open_hash_time_test(int iterations= 700);
//void open_hash_test();
//void double_hash_test();
//void test_simple_iterator_nested_class();
//int main()
//{
//    srand(time(NULL));
//    //open_hash_test();
//    double_hash_test();
//    //test_simple_iterator_nested_class();
//    cout << "Hello World!" << endl;
//    return 0;
//}

//void open_hash_test()
//{
//    open_hash<int> f;

//    char userinput;
//    cout<<"[S]ize [I]nsert [R]andom [D]elete [F]ind [?]exists? e[X]it  :"<<endl;
//    while(cin>>userinput)
//    {
//        int user_key;
//        userinput = toupper(userinput);
//        open_hash_time_test(f.CAPACITY);

//        switch (userinput)
//        {
//        case 'S':
//            break;
//        case 'R':
//        {
//            Random key;
//            Random value;
//            int k;
//            int v;
//            k = key.GetNumber(0,10000);
//            v = value.GetNumber(0,10000);
//            record(k,v);
//            cout<<"Key: "<<k<<"Value: "<<v<<"has been inserted"<<endl;
//            if(f.size()>=f.CAPACITY)
//            {
//                cout<<"full"<<endl;
//            }
//            else
//            {
//                f.insert(record(k,v));
//                cout<<f<<endl;
//            }
//        }
//            break;
//        case 'I':
//        {
//            int key,value;
//            cout<<"enter key and value"<<endl;
//            cin>>key>>value;
//            cout<<"record(key,value)"<<record(key,value)<<endl;
//            if(f.size()>=f.CAPACITY)
//            {
//                cout<<"full"<<endl;
//            }
//            else
//            {
//                f.insert(record(key,value));
//                cout<<f<<endl;
//            }

//        }
//            break;
//        case 'D':
//        {
//            cout<<"which key you want to delete"<<endl;
//            cin>>user_key;
//            f.remove(user_key);
//            cout<<f<<endl;
//        }
//            break;
//        case 'F':
//        {
//            cout<<"what key are you looking for?"<<endl;
//            cin>>user_key;
//            bool user_bool;
//            record i=0 ;
//            f.find(user_key,user_bool,i);
//            if(user_bool==true)
//            {
//                cout<<"found"<<endl;
//            }
//            else
//                cout<<"not found"<<endl;
//        }
//            break;
//        case '?':
//        {
//            cout<<"what key are you looking for?"<<endl;
//            cin>>user_key;
//            bool user_bool;
//            record i=0 ;
//            f.find(user_key,user_bool,i);
//            if(user_bool==true)
//            {
//                cout<<"found"<<endl;
//            }
//            else
//                cout<<"not found"<<endl;
//        }
//            break;
//        case 'X':
//        {
//            return;
//        }
//        default:
//        {
//        }
//            break;
//        }
//        userinput=NULL;
//        cout<<"[S]ize [I]nsert [R]andom [D]elete [F]ind [?]exists? e[X]it  :"<<endl;
//    }
//}

//void double_hash_test()
//{
//    double_hash<int> f;
//    char userinput;
//    cout<<"[S]ize [I]nsert [R]andom [D]elete [F]ind [?]exists? e[X]it  :"<<endl;
//    while(cin>>userinput)
//    {
//        int user_key;
//        userinput = toupper(userinput);
//        switch (userinput)
//        {
//        case 'S':
//            break;
//        case 'R':
//        {
//            Random key;
//            Random value;
//            int k;
//            int v;
//            k = key.GetNumber(0,10000);
//            v = value.GetNumber(0,10000);
//            record(k,v);
//            cout<<"Key: "<<k<<" Value: "<<v<<" has been inserted"<<endl;
//            if(f.size()>=f.CAPACITY)
//            {
//                cout<<"full"<<endl;
//            }
//            else
//            {
//                f.insert(record(k,v));
//                cout<<f<<endl;
//            }
//        }
//            break;
//        case 'I':
//        {
//            int key,value;
//            cout<<"enter key and value"<<endl;
//            cin>>key>>value;
//            cout<<"record(key,value)"<<record(key,value)<<endl;
//            f.insert(record(key,value));
//            cout<<f<<endl;
//        }
//            break;
//        case 'D':
//        {
//            cout<<"which key you want to delete"<<endl;
//            cin>>user_key;
//            f.remove(user_key);
//            cout<<f<<endl;
//        }
//            break;
//        case 'F':
//        {
//            cout<<"what key are you looking for?"<<endl;
//            cin>>user_key;
//            bool user_bool;
//            record i=0 ;
//            f.find(user_key,user_bool,i);
//            if(user_bool==true)
//            {
//                cout<<"found"<<endl;
//            }
//            else
//                cout<<"not found"<<endl;
//        }
//            break;
//        case '?':
//        {
//            cout<<"what key are you looking for?"<<endl;
//            cin>>user_key;
//            bool user_bool;
//            record i=0 ;
//            f.find(user_key,user_bool,i);
//            if(user_bool==true)
//            {
//                cout<<"found"<<endl;
//            }
//            else
//                cout<<"not found"<<endl;
//        }
//            break;
//        case 'X':
//        {
//            return;
//        }
//        default:
//        {
//        }
//            break;
//        }
//        userinput=NULL;
//        cout<<"[S]ize [I]nsert [R]andom [D]elete [F]ind [?]exists? e[X]it  :"<<endl;
//    }
//}


using namespace std;

//*******************************************************************************
//*******************************************************************************
//                          P R O T O T Y P E S
//*******************************************************************************
//*******************************************************************************
template <class T>
void print_array(T* a, long how_many);

template <class T>
bool exists_in_array(T* a, long how_many, const T& item);

template<class T>
void test_hash_table_interactive(T & hash, const string& descr);

template<class HASH_TABLE>
void test_hash_table_random(HASH_TABLE& h_table, long how_many, string hash_type);

void collision_test(int iterations=700);
void hash_table_time_test(int iterations=700);

void test_4k_plus_3();


template <class T>
void force_collision_double_hash(T& h);

void force_collision_double_hash();
void force_collision_double_hash_demo();

//*******************************************************************************
//*******************************************************************************
//                          M   A   I   N
//*******************************************************************************
//*******************************************************************************

int main(){
    cout<<endl<<endl<<endl<<"----------------------"<<endl<<endl<<endl;
    //random insertion, search test
    const bool RANDOM_CHAINED = false;
    const bool RANDOM_OPEN = false;
    //interactive testing of hash tables
    const bool INTERACTIVE_OPEN = false;
    const bool INTERACTIVE_CHAINED = false;
    const bool INTERACTIVE_DOUBLE = false;

    const bool COLLISION_TEST = false;         //comparison between open and double hashing
    const bool FORCED_COLLISION = false;
    const bool FORCED_COLLISION_DEMO = false;
    const bool TIME_TEST = true;               //time comparison between open, double, chained
    const bool debug = false;

    if (FORCED_COLLISION_DEMO){
        cout<<"-------------- FORCED COLLISION TEST ---------------"<<endl;
        //use SMALL_TABLE
        force_collision_double_hash_demo();
    }
    if (FORCED_COLLISION){
        cout<<"-------------- FORCED COLLISION TEST ---------------"<<endl;
        force_collision_double_hash();
    }
    if (TIME_TEST){
        cout<<"--------------- TIME TEST --------------------------"<<endl;
        hash_table_time_test();
    }
    if (COLLISION_TEST){
        cout<<"--------------- COLLISION TEST ----------------------"<<endl;
        collision_test();
    }

    if (INTERACTIVE_OPEN){
        cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
        open_hash<record> open;
        test_hash_table_interactive(open, "open_hash_table" );
    }

    if (INTERACTIVE_DOUBLE){
        cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
        double_hash<record> double_h;
        test_hash_table_interactive(double_h, "double_hash_table" );
    }

    if (INTERACTIVE_CHAINED){
        cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
        chained_hash<record> chained;
        test_hash_table_interactive(chained, "chained_hash_table" );
    }

    if (RANDOM_CHAINED){
        //----------- RANDOM TEST ------------------------------
        //. . . . . .  Chained Hash Table . . . . . . . . . . .;
        chained_hash<record> c_table;
        test_hash_table_random(c_table, 2500, "chained_hash_table<record>");
        if (debug) cout<<c_table<<endl;
    }

    if (RANDOM_OPEN){
        //----------- RANDOM TEST ------------------------------
        //. . . . . .  Simple Hash Table . . . . . . . . . . .;
        open_hash<record> h_table;
        test_hash_table_random(h_table, 500, "hash_table<record>");
        if (debug) cout<<h_table<<endl;
    }

    cout<<endl<<endl<<endl<<"---------------------------------"<<endl;

}
//************************************************************************************
//************************************************************************************
//                 R A N D O M   A U T O M A T E D   T E S T S
//************************************************************************************
//************************************************************************************

template<class HASH_TABLE>
void test_hash_table_random(HASH_TABLE& h_table, long how_many, string hash_type){
    //#undef INTERACTIVE_TEST //sets the table size to a 811
    const bool debug = false;
    const bool TMI = false;
    const long MAX_KEY_SIZE = 10000;
    record* a = new record[how_many];
    Random r;
    cout<<"********************************************************************************"<<endl;
    cout<<"                 R A N D O M   H A S H   T E S T: "<<hash_type<<endl;
    cout<<"********************************************************************************"<<endl;

    for (int i=0; i<how_many; i++){
        a[i] = record(r.GetNext(0,MAX_KEY_SIZE), r.GetNext(0, MAX_KEY_SIZE)*1.0);
        if (debug) cout<<i<<":"<<a[i]<<" was inserted "<<endl;
        h_table.insert(a[i]);
    }
    cout<<"---- ["<<how_many<<"] keys inserted."<<endl;



    if (debug) print_array(a, how_many);
    record result;
    bool test;
    long found_count = 0;
    long not_found_count = 0;
    cout<<endl<<endl<<"- - - - - - - - - Search for existing keys ----------------"<<endl;
    cout<<"Search for existing keys: "<<how_many/2<<" keys to be tested: "<<endl;
    for (int i= 0;i<how_many/2; i++)
    {
        int key = a[r.GetNext(0, how_many-1)]._key;
        if (h_table.find(key, test, result)){
            if (TMI) cout<<result<<" WAS FOUND."<<endl;;
            found_count++;
        }
        else{
            if (TMI) cout<<endl<<endl<<"Existing Key ["<<key<<"] WAS NOT FOUND ****** ERROR ******"<<endl;
            not_found_count ++;
        }
    }


    if (not_found_count >0)
        cout<<"EXISTING KEYS   LOOKUP      V E R I F I C A T I O N   F A I L E D!!"<<endl;
    else
        cout<<"EXISTING KEYS LOOKUP: VERIFID. EXISTING KEYS EXAMINED: "<<found_count<<endl;


    cout<<endl<<endl<<"- - - - - - - - - Search for non-existent keys ----------------"<<endl;
    not_found_count = 0;
    found_count = 0;

    cout<<"Search for nonexistent keys: "<<how_many/2<<" keys to be tested: "<<endl;
    for (int i=0; i<how_many/2; i++){
        int key;
        record key_record;

        do{
            key_record = record(r.GetNext(0, MAX_KEY_SIZE-1), 0.0);
        }while (exists_in_array(a, how_many, key_record));

        if (h_table.find(key_record._key,test, result)){
            if(TMI){
                cout<<endl<<endl<<key_record._key<<" NONEXISTENT KEYS LOOKUP VERIFICATION F A I L E D!!  ******"<<endl;
                cout<<"            result: "<<result<<endl;
            }
            found_count ++;
        }
        else{
            if (TMI) cout<<"NONEXISTENT KEY "<<key_record._key<<" WAS NOT FOUND: VERIFIED."<<endl;
            not_found_count ++;
        }
    }
    if (found_count >0)
        cout<<"NONEXISTENT KEYS LOOKUP      V E R I F I C A T I O N   F A I L E D!!"<<endl;
    else
        cout<<"NONEXISTENT KEYS LOOKUP: VERIFID. NONEXISTENT KEYS EXAMINED: "<<not_found_count<<endl;
    cout<<endl<<"------------------ END RANDOM TEST ----------------------"<<endl;

}
//************************************************************************************
//************************************************************************************
//                    I N T E R A C T I V E    T E S T
//************************************************************************************
//************************************************************************************

template<class T>
void test_hash_table_interactive(T &hash, const string& descr)
{
    char command;                    // A command character entered by the user
    bool found;                      // Value returned by find function
    record result;         // Value returned by find function
    const long MAX_KEY_SIZE = 10000;
    cout << "Table of "<<descr << endl;
    Random r;
    do
    {
        cout<<hash<<endl<<endl;
        int k;
        double v;
        char colon;
        cout<<"[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :";
        cin>>command;

        command = toupper(command);
        switch (command)
        {
        case 'S': cout << "Table Size: " << hash.size( ) << endl;
            break;
        case 'I':
            cout<<">>"; cin>>k>>colon>>v;
            hash.insert(record(k, v));
            cout <<k<<":"<<v<< " has been INSERTED." << endl;
            break;
        case 'R':
            k = r.GetNext(0,MAX_KEY_SIZE);
            v = r.GetNext(0, MAX_KEY_SIZE)*1.0;
            hash.insert(record(k, v));

            break;
        case 'D': cout<<">>"; cin>>k;
            if(hash.remove(k))
                cout << k<< " was REMOVED." << endl;
            else
                cout<<"remove("<<k<<") FAILED"<<endl;
            break;
        case '?': cout<<">>"; cin>>k;
            if (hash.is_present(k))
                cout << k<< " EXISTS." << endl;
            else
                cout << k<< " DOES NOT EXIST." << endl;
            break;
        case 'F': cout<<">>"; cin>>k;
            found = hash.find(k, found, result);
            if (found)
                cout << k<<":" << result._value << endl;
            else
                cout << k<<" NOT FOUND" << endl;
            break;
        case 'X': cout << "D O N E ." << endl;
            break;
        default:  cout << command << " is invalid. Sorry." << endl;
            break;
        }
    } while (command != 'X');

}

void test_4k_plus_3(){
    for (int i = 0; i<10; i++){
        cout<<4*i + 3<<" ["<<i<<"] * 4 + 3"<<endl;;
    }
}
//************************************************************************************
//************************************************************************************
//                         C O L L I S I O N    S T U D Y
//************************************************************************************
//************************************************************************************
void collision_test(int iterations){
    const bool debug = false;
    const long MAX_KEY_SIZE = 10000;

    Random r;
    open_hash<record> ohash;
    double_hash<record> dhash;
    cout<<"["<<iterations<<"] records inserted into open and double hash objects: "<<endl;
    for (int i = 0; i<iterations; i++){
        record rec(record(r.GetNext(0, MAX_KEY_SIZE), r. GetNext(0, MAX_KEY_SIZE)*1.0));
        ohash.insert(rec);
        if (debug) cout<<"["<<i<<"]"<<"ohash: inserted: "<<rec<<endl;
        dhash.insert(rec);
        if (debug) cout<<"["<<i<<"]"<<"dhash: inserted: "<<rec<<endl;
    }

    cout<<"open_hash collisions: "<<ohash.collisions()<<endl;
    cout<<"double_hash collisions: "<<dhash.collisions()<<endl;

}
void force_collision_double_hash_demo(){
    /*
     * this program forces collisions in a double_hash object by
     * inserting records that are CAPACITY apart in order to
     * examine how the table gets filled.
     */
    //use smaller table size:
    double_hash<record> h;
    int start = 3;
    record r;
    while(h.size() < h.CAPACITY){
        r = record(start, start*10);
        h.insert(r);
        start += h.CAPACITY;
        cout<<h<<endl;
        cin.get();

    }
    cout<<"------------ END FORCED COLLISION TEST -------------"<<endl;

}

template <class T>
void force_collision_double_hash(T& h){
    /*
     * this program forces collisions in a hash object by
     * inserting records that are CAPACITY apart in order to
     * examine how the table gets filled.
     */
    //TURN OFF SMALL_TABLE

    int start = 3;
    record r;
    while(h.size() < h.CAPACITY){
        r = record(start, start*10);
        h.insert(r);
        start += h.CAPACITY;
        cout<<h<<endl;
        //cin.get();

    }
    cout<<"------------ END FORCED COLLISION TEST -------------"<<endl;
}

void force_collision_double_hash(){
    open_hash<record> oh;
    double_hash<record> dh;
    cout<<"****************************************************************"<<endl;
    cout<<"*             FORCED COLLISION TEST: OPEN_HASH                 *"<<endl;
    cout<<"****************************************************************"<<endl;
    force_collision_double_hash(oh);
    cin.get();
    cout<<"****************************************************************"<<endl;
    cout<<"*             FORCED COLLISION TEST: DOUBLE_HASH                *"<<endl;
    cout<<"*****************************************************************"<<endl;
    force_collision_double_hash(dh);
    cout<<"********************   D O N E  ********************************"<<endl;

}

//************************************************************************************
//************************************************************************************
//                        T I M I N G    S T U D Y
//************************************************************************************
//************************************************************************************

void hash_table_time_test(int iterations){
    const int MAX_KEY_SIZE = 10000;
    record* a = new record[iterations];
    timer t_open;
    timer t_double;
    timer t_chained;
    open_hash<record> ohash;
    double_hash<record> dhash;
    chained_hash<record> chash;

    Random r;
    cout<<endl;
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //          generating random keys:
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    for (int i= 0; i<iterations; i++){
        a[i] = record(r.GetNext(0,MAX_KEY_SIZE), r.GetNext(0,MAX_KEY_SIZE)*1.0);
    }
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //          inserting keys:
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    cout<<"----------- Insertion  -------------------------------------"<<endl;
    t_open.start();
    for (int i=0; i<iterations; i++){
        ohash.insert(a[i]);
    }
    t_open.stop();
    t_double.start();
    for (int i=0; i<iterations; i++){
        dhash.insert(a[i]);
    }
    t_double.stop();
    t_chained.start();
    for (int i=0; i<iterations; i++){
        chash.insert(a[i]);
    }
    t_chained.stop();

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"open_hash:    collisons: "<<setw(5)<<right<<ohash.collisions()<<" time: "<<t_open.duration()<<endl;
    cout<<"double_hash:  collisons: "<<setw(5)<<right<<dhash.collisions()<<" time: "<<t_double.duration()<<endl;
    cout<<"chained_hash: collisons: "<<"  N/A"<<" time: "<<t_chained.duration()<<endl;

    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //          Search for existing keys:
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    int*existing = new int[iterations/2];
    for (int i=0; i<iterations/2; i++){
        existing[i] = a[r.GetNext(0,iterations-1)]._key;
    }
    t_open.start();
    for (int i= 0; i<iterations/2; i++){
        assert(ohash.is_present(existing[i]));
    }
    t_open.stop();
    t_double.start();
    for (int i= 0; i<iterations/2; i++){
        assert(dhash.is_present(existing[i]));
    }
    t_double.stop();
    t_chained.start();
    for (int i= 0; i<iterations/2; i++){
        assert(chash.is_present(existing[i]));
    }
    t_chained.stop();


    cout<<endl;
    cout<<"----------- Searching for existing keys -------------------"<<endl;
    cout<<"open_hash:    time: "<<t_open.duration()<<endl;
    cout<<"double_hash:  time: "<<t_double.duration()<<endl;
    cout<<"chained_hash: time: "<<t_chained.duration()<<endl;

    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //          Search for nonexistent keys:
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //nonexistent keys:
    int* nonexistent = new int[iterations/2];
    //-------   create a list of nonexistent keys: ----------
    for (int i = 0; i<iterations/2; i++){
        record rec;
        do{
            rec = record(r.GetNext(0,MAX_KEY_SIZE), 0.0);
        }while (exists_in_array(a, iterations, rec));
        nonexistent[i] = rec._key;
    }

    t_open.start();
    for (int i= 0; i<iterations/2; i++){
        assert(!ohash.is_present(nonexistent[i]));
    }
    t_open.stop();
    t_double.start();
    for (int i= 0; i<iterations/2; i++){
        assert(!dhash.is_present(nonexistent[i]));
    }
    t_double.stop();
    t_chained.start();
    for (int i= 0; i<iterations/2; i++){
        assert(!chash.is_present(nonexistent[i]));
    }
    t_chained.stop();

    cout<<endl;
    cout<<"----------- Searching for nonexistent keys -------------------"<<endl;
    cout<<"open_hash:    time: "<<t_open.duration()<<endl;
    cout<<"double_hash:  time: "<<t_double.duration()<<endl;
    cout<<"chained_hash: time: "<<t_chained.duration()<<endl;

}


//************************************************************************************
//************************************************************************************
//            U T I L I T Y   /   H E L P E R   F U N C T I O N S
//************************************************************************************
//************************************************************************************


template <class T>
void print_array(T* a, long how_many){
    cout<<"-------- PRINTING ARRAY ----------------"<<endl;
    for (int i = 0; i<how_many; i++){
        cout<<"["<<setw(4)<<setfill('0')<<i<<"]: "<<a[i]<<endl;
    }
}
template <class T>
bool exists_in_array(T* a, long how_many, const T& item){
    const bool debug = false;
    int i;
    for (i=0; i< how_many; i++){
        if (a[i] == item){
            if(debug) cout<<"exists_in_array("<<item<<"): returning TRUE: "<<a[i]<<endl;
            return true;
        }
    }
    if (debug) cout<<"exists_in_array("<<item<<"): returning FALSE. searched "<<i<<"rows."<<endl;
    return false;
}
