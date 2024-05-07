#include<iostream>
#include<mutex>

// https://www.geeksforgeeks.org/modern-c-design-patterns-tutorial/

using namespace std;

class singleton {
   public:
      static singleton* Instance();
   protected:
      singleton() { i = 99; cout << "\ni= " << i; }

      // Delete the copy constructor and assignment operator to prevent cloning
      singleton(const singleton&) = delete;
      singleton operator =(const singleton&) = delete;

   private:
      static singleton* obj;      // Static pointer to the singleton instance
      int i;

      static std::mutex mutex_;  // Mutex to ensure thread safety
};

// Initialize static members
singleton* singleton::obj = nullptr;
std::mutex singleton::mutex_;

// Static method to get the singleton instance
singleton* singleton::Instance() {
   // Lock the mutex before accessing the instance
   std::lock_guard<std::mutex> lock(mutex_);

   if (obj == nullptr) {
      obj = new singleton;
      cout << "\nInstance === (" << obj << ") i = " << obj->i;
   }
   cout << "\nInstance (" << obj << ") i = " << obj->i;
   return obj;
}

int main() {
   singleton::Instance();

   singleton* p1 = singleton::Instance();
   singleton* p2 = p1->Instance();
   singleton& ref = *singleton::Instance();

   return 0;
}