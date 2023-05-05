#include "PFArray.h"

namespace PFArr{

    template <class T> 
    PFArray<T>::PFArray():capacity(0)//constructor
    {
        container=nullptr;
    }

    template <class T>
    PFArray<T>::~PFArray()//destructor
    {
        //inteantionaly empty
    }

    template <class T>
    PFArray<T>::PFArray(const PFArray<T> &copyPfa):capacity(copyPfa.capacity)//copy constructor #Deep Copy#
    {   
        container.reset();//empty all content
        container = shared_ptr<T> (new T(capacity));//create new size

        for(int i=0;i<capacity;i++)
            container.get()[i] = copyPfa.container.get()[i];
    }

    template<class T>
    PFArray<T>::PFArray(PFArray<T> && movePfa):capacity(movePfa.capacity)//move constructor #Shallow Copy#
    {
        // container.reset();
        // container = shared_ptr<T> (new T(capacity));

        container=move(movePfa.container);
    }

    template<class T>
    PFArray<T> &PFArray<T>::operator=(const PFArray<T> &asgPfa)//asgn operator overloding  for  #Deep Copy#
    {
        capacity=asgPfa.capacity;
        container = shared_ptr<T> (new T(capacity));

        for(int i=0;i<capacity;i++)
            container.get()[i]=asgPfa.container.get()[i]; //returned stored pointer
        
        return *this;
    }

    template<class T>
    PFArray<T> &PFArray<T>::operator=(PFArray<T> &&movePfg)////move asgn operator overloding  for  #Shallow Copy#
    {
        capacity=movePfg.capacity;
        container=move(movePfg.container);

        return *this;
    }

    template <class T>
    void PFArray<T>::push_back(const T& element)//Add element to container...
    {
        try//excption handling
        { 
            shared_ptr<T> temp(new T[capacity+1]);//Create +1 capacity container 
        
            for(int i=0;i<capacity;i++)
                temp.get()[i]=container.get()[i];
            temp.get()[capacity]=element;

            capacity++;//increase conteiner size
            container=move(temp); 
        } 
        catch (std::bad_alloc & exception) 
        { 
           std::cerr << "bad_alloc detected: " << exception.what(); 
        } 
    }

    template <class T>
    const void PFArray<T>::print() const//print content of conteiner on the screen
    {
        for(int i=0;i<capacity;i++)
            cout<<container.get()[i]<<" ";
    }

    template <class T>  //return pointer of first value
    T *PFArray<T>::begin()
    {
        return container.get();
    }

    template <class T>
    T *PFArray<T>::end() //return pointer of last value
    {
        return container.get()+capacity;
    }

    template <class T> 
    const bool PFArray<T>::empty() const //check if container is empty
    {
        if(container == nullptr) return true;
        return false;
    }

    template<class T>
    const int PFArray<T>::size() const //return size of container
    {
        return capacity;
    }

    template<class T>
    void PFArray<T>::clear() //delete all element in container
    {
        capacity=0;
        container=nullptr;
    }
    
    template <class T>
    PFArray<T> & PFArray<T>::erase(const PFArray<T>::Iterator iter) //Erase element pointed by the given iterator
    {
        try
        {
            if(empty() == true) throw("Container is already empty!");

            PFArray<T>::Iterator it;
            shared_ptr<T> temp(new T[capacity-1]);//create -1 capacity container

            int index=0;
            for(it=begin();it != end();++it)
                if(it != iter) temp.get()[index++]=*it; //assg container values to temp container except iter...

            container=move(temp);
            capacity--; //lower capacity 1
        }
        catch(const char* e)
        {
            cerr <<e<< "" << '\n';
        }

        return *this;
    }

    template <class T>
    const T *PFArray<T>::cbegin() const//return const pointer of first value
    {
        return container.get();
    }

    template <class T>
    const T *PFArray<T>::cend() const//return const pointer of last value
    {
        return container.get()+capacity;
    }
}