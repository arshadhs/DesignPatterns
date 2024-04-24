#include<iostream>
using namespace std;

#pragma once
class singleton
{
public:
   static singleton* Instance();
protected:
   singleton() { i = 99; cout << "\ni= " << i; }
   singleton(const singleton&) = delete;
   singleton operator =(const singleton&) = delete;

private:
   static singleton* obj;
   int i;
};

singleton* singleton::obj = nullptr;

singleton* singleton::Instance()
{
   if (obj == nullptr)
   {
      obj = new singleton;
      cout << "\nInstance === (" << obj << ") i = " << obj->i;
   }
   cout << "\nInstance (" << obj << ") i = " << obj->i;
   return obj;
}

int singletonMain()
{
   singleton::Instance();

   singleton* p1 = singleton::Instance();
   singleton* p2 = p1->Instance();
   singleton& ref = *singleton::Instance();

   return 0;
}



