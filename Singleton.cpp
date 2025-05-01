// This code is for demonstration purposes only.
// This implementation follows standard C++ design patterns and was adapted 
// for educational use.

#include <iostream>

// Thread-unsafe Singleton class (for educational demo only).
class Singleton {
 public:
  // 3. Delete copy and move constructors.
  Singleton(const Singleton&) = delete;
  Singleton(Singleton&&) = delete;

  // Delete copy and move assignment operators.
  Singleton& operator=(const Singleton&) = delete;
  Singleton& operator=(Singleton&&) = delete;

  // Static method to access the Singleton instance.
  static Singleton* GetInstance() {
    if (instance_ == nullptr) {
      instance_ = new Singleton();
    }
    return instance_;
  }

  // Example member function to display address.
  void DisplayAddress() const {
    std::cout << "Object address = " << this << std::endl;
  }

 private:
  // 1. Private constructor.
  Singleton() = default;

  // 2. Static instance pointer.
  static Singleton* instance_;
};

// 4. Static member initialization.
Singleton* Singleton::instance_ = nullptr;

// Driver function.
int main() {
  Singleton* instance1 = Singleton::GetInstance();
  instance1->DisplayAddress();

  Singleton* instance2 = Singleton::GetInstance();
  instance2->DisplayAddress();

  return 0;
}
