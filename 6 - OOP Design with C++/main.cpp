/*
CSE241
HW6
TUGAY İPEK
161044034
*/
#include <iostream>
#include "GTUSet.cpp"
#include "GTUIterator.cpp"
#include "GTUVector.cpp"

using namespace std;
using namespace GTU;

template<class GTUIterator, class T>
  GTUIterator find (GTUIterator first, GTUIterator last, const T& val);


template<class GTUIterator, class T>
  T for_each(GTUIterator first, GTUIterator last, T val);

template<class GTUIterator, class UP>
  GTUIterator find_if (GTUIterator first, GTUIterator last, UP pre);

int main() {
    cout<<"------>>>>> SET <<<<<------"<<endl;
    cout<<"------------S1-------------"<<endl<<endl;
    GTUSet<int> S1;
    GTUSet<string> S2;
    //INSERT TEST
    try {
        S1.insert(3);
        S1.insert(9); 
        S1.insert(2);
        S1.insert(8);
    }
    catch (const exception& e){
        cout<<e.what()<<endl;
    }
    //INSERT TEST
    try {
        S2.insert("tugay");
        S2.insert("ipek");
        S2.insert("umarım");
        S2.insert("dersi");
        S2.insert("geçer");
    }
    catch (const exception& e){
        cout<<e.what()<<endl;
    }
    //PRINT ELEMENTS
    cout << "{ ";
    for (auto cursor = S1.begin(); cursor != S1.end() ; cursor++) {
        cout << *cursor << " ";
    }
    cout << *(S1.end()) <<" }" <<endl<<endl;
    //BEGIN TEST
    auto cursorS1 = S1.begin();
    cout<<"Iter Begin "<<*cursorS1<<endl<<endl;
    //END TEST
    cursorS1 = S1.end();
    cout<<"Iter End "<<*cursorS1<<endl<<endl;
    //SIZE & MAX. SIZE TEST
    cout<<"Size : "<<S1.size()<<endl;   
    cout<<"Max. Size : "<<S1.max_size()<<endl<<endl;   
    //ERASE TEST
    S1.erase(9);
    cout<< "Erase: Element 9 is erased."<<endl<<endl;
    //PRINT ELEMENTS
    cout << "{ ";
    for (auto cursor = S1.begin(); cursor != S1.end() ; cursor++) {
        cout << *cursor << " ";
    }
    cout << *(S1.end()) <<" }" <<endl<<endl;
    //FIND TEST
    auto founded = find(S1.begin(),S1.end(),2); //eğer bulamazsa son elemanı return eder
    cout << "Find(2) : "<< "Element "<< *founded << " is founded."<<endl<<endl;

    cout<<"------------S2-------------"<<endl<<endl;
    //PRINT ELEMENTS
    cout << "{ ";
    for (auto cursor = S2.begin(); cursor != S2.end() ; cursor ++) {
        cout << *cursor << " ";
    }
    cout << *(S2.end()) <<" }" <<endl<<endl;
    //BEGIN TEST
    auto cursorS2 = S2.begin();
    cout<<"Iter Begin "<<*cursorS2<<endl<<endl;
    //END TEST
    cursorS2 = S2.end();
    cout<<"Iter End "<<*cursorS2<<endl<<endl;
    //SIZE & MAX. SIZE TEST
    cout<<"Size : "<<S2.size()<<endl;   
    cout<<"Max. Size : "<<S2.max_size()<<endl<<endl;
    //ERASE TEST
    S2.erase("umarım");
    cout<< "Erase: Element 'umarım' is erased."<<endl<<endl;
    //PRINT ELEMENTS
    cout << "{ ";
    for (auto cursor = S2.begin(); cursor != S2.end() ; cursor ++) {
        cout << *cursor << " ";
    }
    cout << *(S2.end()) <<" }" <<endl<<endl;
    //FIND TEST
    auto founded2 = find(S2.begin(),S2.end(),"dersi"); //eğer bulamazsa son elemanı return eder
    cout << "Find(""dersi"") : "<< "Element "<< *founded2 << " is founded."<<endl<<endl;

    cout<<"--------------------------"<<endl<<endl;

    S1.clear();
    S2.clear();
    if(!(S1.begin().getCursor()))
        cout<<"Sets is clear."<<endl<<endl;

    cout<<"------>>>>> VECTOR <<<<<------"<<endl;
    cout<<"------------V1-------------"<<endl<<endl;
    GTUVector<int> V1;
    GTUVector<string> V2;
    //INSERT TEST
    try {
        V1.insert(3);
        V1.insert(9);
        V1.insert(2);
        V1.insert(8);
    }
    catch (const exception& e){
        cout<<e.what()<<endl;
    }
    //INSERT TEST
    try {
        V2.insert("tugay");
        V2.insert("ipek");
        V2.insert("umarım");
        V2.insert("dersi");
        V2.insert("geçer");
    }
    catch (const exception& e){
        cout<<e.what()<<endl;
    }
    //PRINT ELEMENTS
    cout << "{ ";
    for (auto cursor = V1.begin(); cursor != V1.end() ; cursor++) {
        cout << *cursor << " ";
    }
    cout << *(V1.end()) <<" }" <<endl<<endl;
    //BEGIN TEST
    auto cursorV1 = V1.begin();
    cout<<"Iter Begin "<<*cursorV1<<endl<<endl;
    //END TEST
    cursorV1 = V1.end();
    cout<<"Iter End "<<*cursorV1<<endl<<endl;
    //SIZE & MAX. SIZE TEST
    cout<<"Size : "<<V1.size()<<endl;   
    cout<<"Max. Size : "<<V1.max_size()<<endl<<endl;  
    //ERASE TEST
     V1.erase(9);
    cout<< "Erase: Element 9 is erased."<<endl<<endl;
    //PRINT ELEMENTS
    cout << "{ ";
    for (auto cursor = V1.begin(); cursor != V1.end() ; cursor++) {
        cout << *cursor << " ";
    }
    cout << *(V1.end()) <<" }" <<endl<<endl;
    //FIND TEST
    auto foundedV1 = find(V1.begin(),V1.end(),2); //eğer bulamazsa son elemanı return eder
    cout << "Find(2) : "<< "Element "<< *founded << " is founded."<<endl<<endl;

    cout<<"------------V2-------------"<<endl<<endl;
    //PRINT ELEMENTS
    cout << "{ ";
    for (auto cursor = V2.begin(); cursor != V2.end() ; cursor ++) {
        cout << *cursor << " ";
    }
    cout << *(V2.end()) <<" }" <<endl<<endl;
    //BEGIN TEST
    auto cursorV2 = V2.begin();
    cout<<"Iter Begin "<<*cursorV2<<endl<<endl;
    //END TEST
    cursorV2 = V2.end();
    cout<<"Iter End "<<*cursorV2<<endl<<endl;
    //SIZE & MAX. SIZE TEST
    cout<<"Size : "<<V2.size()<<endl;   
    cout<<"Max. Size : "<<V2.max_size()<<endl<<endl;
    //ERASE TEST
    V2.erase("umarım");
    cout<< "Erase: Element 'umarım' is erased."<<endl<<endl;
    //PRINT ELEMENTS
    cout << "{ ";
    for (auto cursor = V2.begin(); cursor != V2.end() ; cursor ++) {
        cout << *cursor << " ";
    }
    cout << *(V2.end()) <<" }" <<endl<<endl;
    //FIND TEST
    auto foundedV2 = find(V2.begin(),V2.end(),"dersi"); //eğer bulamazsa son elemanı return eder
    cout << "Find('dersi') : "<< "Element '"<< *founded2 << "' is founded."<<endl<<endl;
    
    cout<<"--------------------------"<<endl<<endl;

    V1.clear();
    V2.clear();
    if(!(V1.begin().getCursor()))
        cout<<"Vectors is clear."<<endl<<endl;

    return 0;
}

template<class GTUIterator, class T>
  GTUIterator find (GTUIterator f_val, GTUIterator l_val, const T& val)
{
  while (f_val != l_val) {
    if (*f_val == val) return f_val;
    ++f_val;
  }
  return l_val;
}

template<class GTUIterator, class T>
  T for_each(GTUIterator f_val, GTUIterator l_val, T val)
{
  while (f_val != l_val) {
    val (*f_val);
    ++f_val;
  }
  return val;
}
template<class GTUIterator, class UP>
  GTUIterator find_if (GTUIterator f_val, GTUIterator l_val, UP pre)
{
  while (f_val != l_val) {
    if (pre(*f_val)) return f_val;
    ++f_val;
  }
  return l_val;
}