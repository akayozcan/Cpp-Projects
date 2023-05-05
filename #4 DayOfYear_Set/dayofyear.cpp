#include "dayofyear.hpp"

using namespace std;

namespace DYSDate{

    DayofYearSet::DayofYear::DayofYear():day(1),month(1)//DayofYear no parameter constructor...
    {}

    DayofYearSet::DayofYear::DayofYear(const int &dayValue,const int &monthValue)//DayofYear two param constructor...
    {
        setDate(dayValue,monthValue);
    }

    DayofYearSet::DayofYear::~DayofYear()
    {}

    bool DayofYearSet::DayofYear::testDate(int day_v,int month_v)//checks if the given month and day value valids
    {
        if(month_v<=0 || month_v>12) 
            return false;

        if(daysOfMonth[month_v-1]<day_v || day_v<=0) 
            return false;

        return true;
    }

    void DayofYearSet::DayofYear::setDate(int d,int m)//if the given values are valid,then it will asssign this values to day and month...
    {
        if(testDate(d,m) == false)
            cout<<"Invalid Date Value!"<<endl;
        
        day=d;
        month=m;
    }

    const bool DayofYearSet::DayofYear::operator==(const DayofYear &othObj) const //Checks if two objects are the same,same - return true..
    {
        if(getDay()==othObj.getDay() && getMonth() == othObj.getMonth()) return true;
        return false;
    }

    DayofYearSet::DayofYearSet():sizeOfDates(0)//DayofYearSet no param constructor...
    {}

    DayofYearSet::DayofYearSet(const list<DayofYear> &listDate)//DayofYearSet list param constructor..
    {                                                          //it takes list as parameter and equilaze list to DayofYear * array...
        sizeOfDates=listDate.size();
        dateArray=new DayofYear[sizeOfDates];

        int i=0,flag=0;
        for(auto it=listDate.begin();it != listDate.end();it++,i++){//iterator loop...
            if(check_duplicate(it->getDay(),it->getMonth()) == true)//if given objects is already valid,it doesn't make assignment...
                dateArray[i].setDate(it->getDay(),it->getMonth());
        }
    }

    const bool DayofYearSet::check_duplicate(int _d,int _m) const//if given objects is already DayofYear* array,return false...
    {
        for(int i=0;i<getSize();i++)
            if(dateArray[i].getDay() == _d && dateArray[i].getMonth() == _m) return false;

        return true; 
    }

    DayofYearSet::~DayofYearSet()//Destructors delete our DayofYar * array...
    {
        if(dateArray != nullptr)
        {
            delete [] dateArray;
            dateArray=nullptr;
        }    
    }

    DayofYearSet::DayofYearSet(const DayofYearSet &othSet)//copy const...
    {
        if(othSet.dateArray == this->dateArray) return;
        sizeOfDates=othSet.getSize();
        dateArray=new DayofYear[getSize()];

        for(int i=0;i<getSize();i++)
            dateArray[i]=othSet.getDates()[i];
    }

    const DayofYearSet &DayofYearSet::operator=(const DayofYearSet &othSet)//assignment operator overloded...
    {
        if(this == &othSet) return *this;
        sizeOfDates=othSet.getSize();

        dateArray=new DayofYear[getSize()];
        for(int i=0;i<getSize();i++)
            dateArray[i]=othSet.getDates()[i];

        return *this;
    }

    ostream& operator<<(ostream & output, const DayofYearSet& othSet)//stream insertion operator to print DayofYearSet datas on the screen...
    {
        output<<"There are "<<othSet.getSize()<<" dates in the set..."<<endl;
        output<<"DATES:"<<endl;

        for(int i=0;i<othSet.getSize();i++)
            output<<"DAY:"<<othSet.getDates()[i].getDay()<<"     MONTH:"<<othSet.getDates()[i].getMonth()<<endl;

        return output;
    } 

    const bool DayofYearSet::operator==(const DayofYearSet &othSet)const// checks if given two set are equal...
    {                                                                   //if they are equal,return true...
        int size1=getSize(),size2=othSet.getSize();
        int count;
        bool check=true;

        for(int i=0;i<size1;i++)
        {
            count=0;
            for(int j=0;j<size2;j++)
            {
                //if(getDates()[i].getDay() == othSet.getDates()[j].getDay() && getDates()[i].getMonth() == othSet.getDates()[j].getMonth())
                if(dateArray[i]==othSet.dateArray[j])
                    count++;
            }
            if(count == 0) 
                return false;
        }

        return true;
    }

    const bool DayofYearSet::operator!=(const DayofYearSet &othSet)const// checks if given two set aren't equal...
    {
        return !(*this == othSet);
    }

    void DayofYearSet::remove(int r_d,int r_m)//according to given day and month value,it remove this object from DayofYear* array...
    {
        int index=0;
        DayofYear *temp=dateArray;

        if(getSize() == 0)
        {
            cout<<"Set is Empty!"<<endl;
            exit(1);
        }

        for(index=0;index<getSize();index++)
        {
            if(getDates()[index].getDay() == r_d && getDates()[index].getMonth() == r_m)
                break;
        }       

        sizeOfDates-=1;
        dateArray = new DayofYear[getSize()];

        int k=0;
        for(int i=0;i<getSize();i++,k++)
        {
            if(k == index) k++;
            dateArray[i]=temp[k];
        }

        delete [] temp;
    }

    int DayofYearSet::size() const// return array size...
    {
        return getSize();
    }

    const DayofYearSet &DayofYearSet::operator+(const DayofYear &othObj)//Add DayofYear object to the valid set...
    {
        DayofYear *temp=dateArray;
        int flag=0;

        dateArray = new DayofYear[getSize()+1];//reallocate new memory...

        for(int i=0;i<getSize();i++)
        {
            if(temp[i]==othObj) flag++; 
            dateArray[i]=temp[i];
        }

        if(flag == 0)//flag for not add the same element in the set
        {
            dateArray[getSize()]=othObj;
            sizeOfDates++;
        }

        delete [] temp;
        return *this;
    }

    const DayofYearSet &DayofYearSet::operator-(const DayofYear &othObj)//remove given object from set...
    {
        remove(othObj.getDay(),othObj.getMonth());
        return *this;
    }

    const DayofYearSet DayofYearSet::operator^(const DayofYearSet &othSet) const //returns the intersection set of two sets
    {
        DayofYearSet temp;
        temp.dateArray = new DayofYear[getSize()];

        for(int i=0;i<getSize();i++)
        {
            for(int j=0;j<othSet.getSize();j++)
            {
                if(dateArray[i] == othSet.dateArray[j]) 
                {
                    temp.dateArray[temp.size()]=dateArray[i];
                    temp.sizeOfDates++;
                } 
            }
        }

        return temp;
    }

    const DayofYearSet &DayofYearSet::operator-(const DayofYearSet &othSet)//returns the difference set of two sets
    {
        DayofYearSet tempSet;
        tempSet=*this ^ othSet;

        for(int j=0;j<tempSet.getSize();j++)
            *this=*this-tempSet.dateArray[j];

        return *this;
    }

    const DayofYearSet DayofYearSet::operator+(const DayofYearSet &othSet)//returns the union set of two sets
    {
        DayofYearSet iscTemp;
        iscTemp= *this - othSet;

        DayofYearSet temp;
        temp.dateArray=new DayofYear[getSize()+othSet.getSize()];

        for(int i=0;i<othSet.getSize();i++)
            temp=iscTemp + othSet.dateArray[i];

        return temp;    
    }

    DayofYearSet::DayofYear &DayofYearSet::operator[](int index) //Returns the DayofYear object in the given index
    {
        return dateArray[index];
    }

    DayofYearSet DayofYearSet::operator!()//returns complement set
    {
        DayofYearSet temp;
        temp.dateArray=new DayofYear[365];
        int _size=0;
    
        for(int i=1;i<=12;i++)
        {
            for(int j=1;j<=temp.dateArray->getD_M()[i-1];j++)
            {
                temp.dateArray[_size].setDate(j,i);
                _size++;
            }
        }
        temp.sizeOfDates=_size;

        return temp-*this;
    }
}