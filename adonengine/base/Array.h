#ifndef _ARRAY_H_
#define _ARRAY_H_
#include "counter.h"
#include <cstddef>
#include <new>
#include <iostream>
#include <vector>
#include <utility>


namespace AdonEngine
{
  namespace Base
  {
    template<class T>
    class Array : Base::Counter<Array<T>>
    {
    public:
      using Base::Counter<Array>::GetCount;
      Array();
      explicit Array(const int& count);
      Array(const Array<T>&);
      virtual ~Array();
      const std::size_t& SizeOf();
      
      const int& Count();
      
      T& operator[](std::size_t);
      const T&  operator[]  (std::size_t) const;
      
      Array<T>& operator=(const Array<T>&);
    private:
      
      int count;
      T* arr;
    };
  }
}

template<class T>
AdonEngine::Base::Array<T>::Array() : arr(nullptr), count(0){
}

template<class T>
AdonEngine::Base::Array<T>::Array(const int& count): arr(new(std::nothrow) T[count]()), count(count){
}

template<class T>
AdonEngine::Base::Array<T>::Array(const Array< T >& original):count(original.count){
      arr = new T[count];
      for (int i = 0; i < count; ++i) {
        arr[i] = original.arr[i];
      }
}

template<class T>
AdonEngine::Base::Array<T>::~Array()
{
  delete [] arr;
}

template<class T>
const int& AdonEngine::Base::Array<T>::Count(){
  return this->count;
}

template<class T>
const std::size_t& AdonEngine::Base::Array<T>::SizeOf(){
  return count*sizeof(T);
}

template<class T>
T& AdonEngine::Base::Array<T>::operator[](std::size_t index){
  return arr[index];
}

template<class T>
const T& AdonEngine::Base::Array<T>::operator[](std::size_t index) const {
  return arr[index];
}

template<class T>
AdonEngine::Base::Array<T>& AdonEngine::Base::Array<T>::operator=(const Array& other){
  Array<T> copy(other);
  
  std::swap(arr,copy.arr);
  std::swap(count,copy.count);
}


#endif // _ARRAY_H_