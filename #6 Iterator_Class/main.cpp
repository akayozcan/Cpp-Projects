#include "PFArray.cpp"
#include <algorithm>

using namespace PFArr;

void testfor_each(int i){cout<<i<<" ";}
bool test_sort (int i,int j) {return (i<j); }

int main(){

    cout<<"# Testing no param constructor for PFArray #"<<endl;
    PFArray <int> test1;
    cout<<"No param constructor worked!\n"<<endl;

    cout<<"# Testing no param constructor for diff type(string) PFArray #"<<endl;
    PFArray <string> test2;
    cout<<"No param constructor worked!\n"<<endl;

    cout<<"# Testing copy constructor <Deep Copy> #"<<endl;
    PFArray <int> test3(test1);
    cout<<"Copied all data to test3!\n"<<endl;

    cout<<"# Testing move constructor <Shallow Copy> #"<<endl;
    PFArray <string> test4(move(test2));
    cout<<"Move adress of test2 to test4!\n"<<endl;

    cout<<"# Testing asg operator <Deep Copy> #\n"<<endl;
    test3=test1;
    cout<<"Asg operator Worked!"<<endl;

    cout<<"# Testing move asg operator <Shallow Copy> \n"<<endl;
    test3=move(test1);
    cout<<"Asg operator Worked!"<<endl;

    cout<<"================================================================"<<endl;
    int x=5;
    int *pt=&x;

    cout<<"# Testing Iterator class pointer param const #"<<endl;
    PFArray <int>::Iterator testIt(pt);
    cout<<"TestIt(pt) created!\n"<<endl;

    cout<<"# Testing operator* function #"<<endl;
    cout<<"*testIt = "<<*testIt<<endl<<endl;

    PFArray <int> t_arr1;
    for(int i=1;i<=5;++i)
        t_arr1.push_back(i*10);

    cout<<"My test array {10,20,30,40,50}"<<endl;
    cout<<"# Testing Iterator = asg operator #"<<endl;
    testIt=t_arr1.begin();
    cout<<"testIt=begin() so (it have to 10) ="<<*testIt<<endl; 

    cout<<"\n# Testing Iterator -- and ++ operator #"<<endl;
    cout<<"Do Three times ++:"<<endl;
    ++testIt;
    ++testIt;
    ++testIt;
    cout<<*testIt<<endl;
    cout<<"Do one time --"<<endl;
    testIt--;
    cout<<*testIt<<endl;
    
    cout<<"\n\n================================================================"<<endl;
    cout<<"Creating new array..."<<endl;
    PFArray <int> MyPFArr;
    PFArray <int>::Iterator MyIt;

    cout<<"#Push_back function working 5 times...#"<<endl;
    for(int i=1;i<=5;++i)
        MyPFArr.push_back(10*i);
    
    PFArray <int> tempArr;
    tempArr=MyPFArr;

    cout<<"\n# Printing MyPFArr on the screen using iterator... #"<<endl;

    for(MyIt=MyPFArr.begin();MyIt != MyPFArr.end();++MyIt)
        cout<<*MyIt<<" ";
    cout<<endl<<endl;

    cout<<"# TESTING EMPTY() #"<<endl;
    cout<<"Is MyPFArr empty (0-false,1-true): "<<MyPFArr.empty()<<endl<<endl;

    cout<<"# TESTING SIZE() #"<<endl;
    cout<<"Size of MyPFArr is "<<MyPFArr.size()<<endl<<endl;

    cout<<"# TESTING ERASE() #"<<endl;
    cout<<"Last element and first element erasing..."<<endl;

    MyPFArr.erase(MyPFArr.begin());
    MyPFArr.erase(MyPFArr.end());

    for(MyIt=MyPFArr.begin();MyIt != MyPFArr.end();++MyIt)
        cout<<*MyIt<<" ";
    cout<<endl<<endl;

    cout<<"# TESTING CLEAR() #"<<endl;
    MyPFArr.clear();
    cout<<"Size of cleared array:"<<MyPFArr.size()<<endl<<endl;

    cout<<"# TESTING BEGIN() #"<<endl;
    cout<<"BEGIN():"<<*tempArr.begin()<<endl<<endl;

    cout<<"# TESTING END() #"<<endl;
    cout<<"END():"<<*(tempArr.end()-1)<<endl<<endl;

    cout<<"\n\n================================================================"<<endl;


    cout<<"# FOR_EACH WORKING... #"<<endl;
    for_each(tempArr.begin(),tempArr.end(),testfor_each);
    cout<<endl<<endl;
    
    cout<<"# FIND WORKING FOR 30  #"<<endl;
    MyIt = find (tempArr.begin(), tempArr.end(), 30);
    if (MyIt != tempArr.end())
        cout << "Element found in myvector: \n" << *MyIt << '\n';
    else
        cout << "Element not found in myvector\n";
    cout<<endl;

    cout<<"# FIND WORKING FOR 70  #"<<endl;
    MyIt = find (tempArr.begin(), tempArr.end(), 70);
    if (MyIt != tempArr.end())
        cout << "Element found in myvector: \n" << *MyIt << '\n';
    else
        cout << "Element not found in myvector\n";
    cout<<endl;

    cout<<"# SORT WORKING! #"<<endl;
    cout<<"Adding new number to arr {44,15,34,8}..."<<endl;
    tempArr.push_back(44);
    tempArr.push_back(15);
    tempArr.push_back(34);
    tempArr.push_back(8);
    
    cout<<"MY NEW ARR:"<<endl;
    tempArr.print();
    sort (tempArr.begin(), tempArr.end(), test_sort);     //(12 26 32 33 45 53 71 80)
    cout << "\n\nMy arr contains:";
    for (MyIt=tempArr.begin(); MyIt!=tempArr.end(); ++MyIt)
      cout << ' ' << *MyIt;
    cout << "\n\n\n";

    cout<<"# TRY - EXCEPTİON WORKING 1 EXP #"<<endl;
    PFArray <int> excp;
    excp.erase(MyIt);


    return 0;
}
