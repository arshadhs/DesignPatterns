#include<iostream>
#include <vector>
using namespace std;

// Observer Pattern
// https://www.geeksforgeeks.org/observer-pattern-c-design-patterns/?ref=lbp

class ObserverInterface {
public:
   virtual void update(float temp) = 0;
};

class Display : public ObserverInterface {
public:
   virtual void update(float temp) { cout << "\n Temperature: " << temp; }
};

class weatherStation {
   float temperature;
   vector<ObserverInterface*> observers;

public:
   void registerObserver(ObserverInterface* obj) { observers.push_back(obj); }

   void notifyObsever() {
      for (ObserverInterface* observer : observers)
      {
         observer->update(temperature);
      }
   }

   void setMeasurements(float temp) {
      temperature = temp;
      notifyObsever();
   }
};



int obsever()
{
   weatherStation wsObj;

   Display dObj_1;
   Display dObj_2;

   wsObj.registerObserver(&dObj_1);
   wsObj.registerObserver(&dObj_1);

   wsObj.setMeasurements(10);
   wsObj.setMeasurements(99);

   return 0;
}


