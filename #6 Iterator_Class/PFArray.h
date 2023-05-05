#ifndef PFARRAY_H
#define PFARRAY_H

#include <iostream>
#include <memory>

using namespace std;


namespace PFArr{

    template<class T> //templated PFArray class and Iterator inner class
    class PFArray {
        public:

            class Iterator{//inner class for iterate pointer...
                public:
                    Iterator(){};
                    Iterator(T *_p):ptr(_p){}//1 pointer param const
                    Iterator &operator=(const Iterator &oth){//assg operator overloaded
                        ptr=oth.ptr;
                        return *this;    
                    }
                    T &operator*(){return *ptr;}
                    T &operator->(){return ptr;}
                    Iterator &operator++(){
                        ++ptr;
                        return *this;
                    }
                    Iterator &operator--(){
                        --ptr;
                        return *this;
                    }
                    Iterator &operator--(int ignore){
                        ptr--;
                        return *this;
                    }
                    const bool operator==(const Iterator& oth) const{return (ptr == oth.ptr);}
                    const bool operator!=(const Iterator& oth) const{return (ptr != oth.ptr);}


                private:
                    T *ptr;
            };

        	PFArray();//constructor
        	PFArray(const PFArray<T>& copyPfa);//copy constructor #Deep Copy#
            PFArray(PFArray<T> && movePfa);//move constructor #Shallow Copy#
            PFArray<T> &operator=(const PFArray<T> &asgPfa);//asg operator overloding #Deep Copy#
            PFArray<T> &operator=(PFArray<T> &&moveAsg);//asg operator overloding #Shallow Copy#
            ~PFArray();//Destructor
            // big 5 created!!!

            T* begin();//Return iterator to beginning
            T* end();//Return iterator to end
            const bool empty() const;//is empty ?
            const int size() const;//return container size...
            PFArray<T> &erase(const PFArray<T>::Iterator iter);//erase pointing value
            void clear();//clear all content
            const T*cbegin() const;//Return const iterator to beginning 
            const T*cend() const;//Return const iterator to end
            void push_back(const T& element);//add element

            const void print() const;

        private:
        	shared_ptr <T> container; 
        	int capacity; 

    };
} 

#endif //PFARRAY_H
