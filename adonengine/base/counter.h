#ifndef __COUNTER_H_
#define __COUNTER_H_


namespace AdonEngine
{
  namespace Base
  {
    template <class T>
    class Counter
    {
    private:
      static int count;
    public:
      Counter()
      {
	count++;
      }  
      Counter(const Counter &c)
      {
	count++;
      }   
      ~Counter()
      {
	count--;
      }    
      static int GetCount() {
	
	return count;
      }
    };
    template<class T> 
    int AdonEngine::Base::Counter<T>::count = 0; 
  }
}


#endif // __COUNTER_H_