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
  Singleton(Singleton&&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  Singleton& operator=(Singleton&&) = delete;

  // Accessor for the singleton instance.
  static Singleton* GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr) {
      instance_ = new Singleton();
    }
    return instance_;
  }

  void DisplayAddress() const {
    std::cout << "Object address = " << this << std::endl;
  }

 private:
  // Private constructor.
  Singleton() = default;

  // Static instance and mutex.
  static Singleton* instance_;
  static std::mutex mutex_;
};

// Definition of static members.
Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mutex_;

// Entry point.
int main() {
  std::thread t1([]() {
    Singleton::GetInstance()->DisplayAddress();
  });

  std::thread t2([]() {
    Singleton::GetInstance()->DisplayAddress();
  });

  t1.join();
  t2.join();

  return 0;
}
