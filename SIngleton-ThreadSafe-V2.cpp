// This demo showcases a thread-safe Singleton implementation in C++.
// This implementation follows standard C++ design patterns and was adapted for
// educational purposes ONLY.

#include <iostream>
#include <mutex>
#include <thread>

// Thread-safe singleton class.
class Singleton {
 public:
  // Deleted copy and move constructors and assignment operators.
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  // Accessor for the singleton instance.
  static Singleton& GetInstance() {
      // Static instance
    static Singleton instance_;
     return instance_;
  }

  void DisplayAddress() const {
    std::cout << "Object address = " << this << std::endl;
  }

 private:
  // Private constructor.
  Singleton() = default;
  ~Singleton() = default;
};

// Entry point.
int main() {
  std::thread t1([]() {
    Singleton::GetInstance().DisplayAddress();
  });

  std::thread t2([]() {
    Singleton::GetInstance().DisplayAddress();
  });

  t1.join();
  t2.join();

  return 0;
}
