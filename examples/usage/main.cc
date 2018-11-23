#include <iostream>

#include <executionHandler/ExecutionHandler.hpp>
#include <Wrapper.hpp>
#include <SampleClass.hpp>


using namespace std;
using namespace wrapper;

/**
 * Custom prefix class that has access to the encapsulated data.
 */
template <class T> class CustomWrapper: public ExecutionHandler<T> {
public:

  CustomWrapper(T *value): ExecutionHandler<T>(value) {}
  virtual bool prefix() { cout<< "PRE"; return true; }
  virtual void suffix() { cout<< "SUF"; }
  virtual void onDestroy() {cout << "I realized I am being destroyed soon!\n";}
};


int main() {
  auto content = new SampleClass();
  
  // example: no memory removal
  auto xx = WRAPPER(content, CustomWrapper, false);
  auto x2 = xx;

  //X unused;
  if (xx->f()) std::cout << "return value received!\n";
  xx->g();
  x2->g();
  xx = x2;
  x2->g();

  return 0;

}
