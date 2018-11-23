#include <iostream>

#include <executionHandler/Noop.hpp>
#include <Wrapper.hpp>
#include <SampleClass.hpp>


using namespace std;
using namespace wrapper;


Wrapper<SampleClass> getSmartPointer() {
  auto content = new SampleClass();
  Wrapper<SampleClass> xx(content, new Noop<SampleClass>(content), true);
  return xx;
}

int main() {

  {
    auto smartPointer = getSmartPointer();
    Wrapper<SampleClass> x2 = smartPointer;

    //X unused;
    auto r =smartPointer->f();
    std::cout << "return value '" << r << "' received!\n";
    smartPointer->g();
    x2->g();
    smartPointer= x2;
    x2->g();
  }
  cout << "the wrapper freed the memory by now!\n";

  return 0;
}
