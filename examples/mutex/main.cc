#include <iostream>
#include <thread>
#include <mutex>

#include <Wrapper.hpp>
#include <SampleClass.hpp>
#include <executionHandler/ExecutionHandler.hpp>







template <class T> class Session: public wrapper::ExecutionHandler<T> {
  public:

    Session(T* value) : wrapper::ExecutionHandler<T>(value), mut() { }

    virtual ~Session() = default;

    /**
     * Create new session.
     */
    static Session<T>* createSession(T* content, bool handleMemory=false) {

    }

    virtual bool prefix() {
      std:: cout << "locked\n";
        mut.lock();
      return true;
    }


    virtual void suffix() {
      mut.unlock();
      std:: cout << "unlocked\n";
    }

    virtual void onDestroy() {}


  private:
    std::mutex mut;
};





int main() {

  // 
  // Here only one thread is trying to access the content, so 
  // there is no need for locking. But this only serves demo 
  // purpose
  //
  auto session = wrapper::WRAPPER(new SampleClass(), Session, true);

  session->f();
  session->g();
  auto x2 = session;
  x2->f();

  return 0;
}
