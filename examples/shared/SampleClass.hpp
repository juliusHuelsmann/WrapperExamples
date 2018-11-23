
#include <iostream>

using namespace std;

class SampleClass {
public:
  SampleClass() { cout << "constructor\n"; }
  ~SampleClass() { cout << "destructor()\n"; }
  int f() const { cout << "f"; return 1; }
  void g() const { cout << "g"; }
};
