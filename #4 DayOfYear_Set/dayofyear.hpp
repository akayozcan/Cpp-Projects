#ifndef DAYOFYEAR_HPP
#define DAYOFYEAR_HPP

#include <list>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

namespace DYSDate{

    class DayofYearSet{
        public:
            class DayofYear{
                public:

                    DayofYear();
                    DayofYear(const int &dayValue,const int &monthValue);
                    ~DayofYear();

                    const bool operator==(const DayofYear &othObj) const;

                    int getDay()const{return day;}
                    int getMonth()const{return month;}
                    vector <int> getD_M()const {return daysOfMonth;}//return daysofmonth array...
                    void setDay(int d){day=d;}
                    void setMonth(int m){month=m;}
                    void setDate(int d,int m);

                private:
                    int month;
                    int day;
                    vector <int> daysOfMonth={31,28,31,30,31,30,31,31,30,31,30,31};//hold days of months...
                    bool testDate(int,int);
            };

            DayofYearSet();
            DayofYearSet(const list<DayofYear> &dateArr);
            ~DayofYearSet();
            DayofYearSet(const DayofYearSet &othSet);
            const DayofYearSet &operator=(const DayofYearSet &othSet);


            int getSize() const{return sizeOfDates;}
            DayofYear * getDates() const{return dateArray;}

            friend ostream& operator<<(ostream & output,const DayofYearSet& othSet);//to print datas... 
            const bool operator==(const DayofYearSet &othSet) const;//equality operator
            const bool operator!=(const DayofYearSet &othSet) const;//not equality operator
            const DayofYearSet &operator+(const DayofYear &othObj);//add obj to set
            const DayofYearSet operator+(const DayofYearSet &othSet);//union set
            const DayofYearSet &operator-(const DayofYear &othObj);//delete obj from set
            const DayofYearSet &operator-(const DayofYearSet &othSet);//difference set
            const DayofYearSet operator^(const DayofYearSet &othSet) const;//intersection set
            DayofYearSet operator!();//complement set
            DayofYear & operator [](int index);//index operator

            void remove(int,int);
            int size() const;


        private:
            DayofYear * dateArray=nullptr;
            int sizeOfDates;
            const bool check_duplicate(int,int) const;
    };
}


#endif //DAYOFYEAR_HPP