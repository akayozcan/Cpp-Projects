#include "dayofyear.hpp"
using namespace DYSDate;

int main(){

    DayofYearSet::DayofYear date1(29,3);
    decltype(date1) date2(1,5);
    decltype(date1) date3(17,4);
    decltype(date1) date4(29,7);

    decltype(date1) date5(2,3);
    decltype(date1) date6(29,3);
    decltype(date1) date7(17,8);
    decltype(date1) date8(1,5);

    decltype(date1) date9(4,4);
    decltype(date1) date10(8,9);
    decltype(date1) t_date;


    list<DayofYearSet::DayofYear> dateList1 {date1,date2,date3};
    decltype(dateList1) dateList2 {date5,date6,date7,date8};
    decltype(dateList1) dateList3 {date5,date2,date6,date4,date9,date10};
    decltype(dateList1) tempList;

    DayofYearSet dateSet1(dateList1);
    DayofYearSet dateSet2(dateList2);
    DayofYearSet dateSet3(dateList3);

    DayofYearSet::DayofYear t_const(24,12);
    cout<<"# DayofYear two param constructor worked! #\n"<<endl;

    DayofYearSet t_cst(dateList1);
    cout<<"# DayofYearSet list param constructor worked! #\n"<<endl;
    
    DayofYearSet t_copy(dateSet1);
    cout<<"# DayofYear copy constructor created! #\n"<<endl;

    t_copy=dateSet1;
    cout<<"# DayofYear assignment operator worked! #\n"<<endl;
    cout<<"Printing their assign values!"<<endl;
    cout<<t_copy<<endl;

    cout<<"---------------------------------------------------"<<endl;

    cout<<"# Testing invalid day and month values... #"<<endl;
    cout<<"1.D:0 M:5"<<endl;
    t_date.setDate(0,5);
    cout<<"1.D:30 M:2"<<endl;
    t_date.setDate(30,2);

    cout<<"---------------------------------------------------"<<endl;
    cout<<"# 1.Testing DayofYear == operator... #"<<endl;
    cout<<"date1(29,3) == date2(1,5) => It must return 0"<<endl;
    cout<<"Return Value:"<<(date1==date2)<<endl<<endl;
    
    cout<<"# 2.Testing DayofYearSet == operator... #"<<endl;
    cout<<"datelist1 == datelist2 => It must return 0"<<endl;
    cout<<"Return Value:"<<(dateList1==dateList2)<<endl<<endl;

    cout<<"# 2.Testing DayofYearSet != operator... #"<<endl;
    cout<<"datelist1 == datelist2 => It must return 1"<<endl;
    cout<<"Return Value:"<<(dateList1!=dateList2)<<endl<<endl;
    cout<<"---------------------------------------------------"<<endl;

    cout<<"# size() function working... #"<<endl;
    cout<<"Size of dateSet1:"<<dateSet1.size()<<endl;
    cout<<"Size of dateSet2:"<<dateSet2.size()<<endl<<endl;
    
    cout<<"Adding date1,date2,date3 object in tempList..."<<endl;
    tempList.push_back(date1);
    tempList.push_back(date2);
    tempList.push_back(date3);
    DayofYearSet tempSet1(tempList);
    cout<<"# Printing set objects with operator<< (stream insertion)... #"<<endl;
    cout<<tempSet1<<endl;
    cout<<"# remove() function working and removing date2... #"<<endl;
    tempSet1.remove(date2.getDay(),date2.getMonth());
    cout<<tempSet1<<endl;
    cout<<"# Remove date3 element from the set with operator- ... #"<<endl;
    cout<<tempSet1-date3<<endl;

    cout<<"----------------------------------------------------"<<endl;
    
    cout<<"# Adding date4 and date5 element in dateSet1 with operator+ ... #"<<endl;
    cout<<dateSet1<<endl;
    dateSet1=dateSet1+date4;
    dateSet1=dateSet1+date5;
    cout<<dateSet1<<endl;
    cout<<"----------------------------------------------------"<<endl<<endl;

    cout<<"# Testing Union Set (operator+)... #"<<endl;
    cout<<dateSet1<<endl;
    cout<<dateSet2<<endl;
    tempSet1=dateSet1+dateSet2;
    cout<<"UNION SET:"<<endl<<tempSet1<<endl;

    cout<<"----------------------------------------------------"<<endl<<endl;
    
    cout<<"# Testing Difference Set ... #"<<endl;
    cout<<tempSet1<<endl;
    cout<<dateSet2<<endl;
    cout<<"DIFFERENCE SET:"<<endl<<tempSet1-dateSet2<<endl;

    cout<<"----------------------------------------------------"<<endl<<endl;
    cout<<"# Testing Intersection Set... #"<<endl;
    cout<<dateSet3<<endl;
    cout<<dateSet2<<endl;
    cout<<"INTERSECTION SET:"<<endl<<(dateSet3^dateSet2)<<endl;
    
    cout<<"----------------------------------------------------"<<endl<<endl;
    cout<<"# Testing Complement Set (operator!)... #"<<endl;
    cout<<"# Testing operator[]... #"<<endl;
    dateSet3=!dateSet3;
    cout<<"{ ";
    for(int i=0;i<dateSet3.size();i++)
        cout<<"("<<dateSet3[i].getDay()<<","<<dateSet3[i].getMonth()<<"),";
    cout<<" }"<<endl;

    return 0;
}
