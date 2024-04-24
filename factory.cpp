#include <iostream>

//https://www.geeksforgeeks.org/factory-method-pattern-c-design-patterns/


/// Factory Menthod :: promotes flexibility and decoupling between the client and product classes.

///
/// Product
///

// Abstract Product
class shape
{
public:
   virtual void draw() = 0;
   virtual ~shape() {}; // Virtual destructor for polymorphism
};

// Concrete Product
class shapeSquare : public shape
{
public:
   void draw () { std::cout << "Drawing a Square" << std::endl; }
};

class shapeCircle : public shape
{
public:
   void draw () { std::cout << "Drawing a Circle" << std::endl; }
};

///
/// Creator
/// 

/// The abstract creator (ShapeFactory) defines the factory method (createShape())

// Abstract Creator
class shapeFactory
{
public:
   virtual shape* shapeCreator() = 0;
   virtual ~shapeFactory() {}; // Virtual destructor for polymorphism
};

/// Concrete creators (CircleFactory and SquareFactory) implement this method to create concrete prodcuts (Circle and Square).

// Concrete Creator
class squareFactory : public shapeFactory
{
public:
   shape* shapeCreator() { return new shapeSquare(); }
};

class circleFactory : public shapeFactory
{
public:
   shape* shapeCreator() override { return new shapeCircle(); }
};

///
/// Client
///

int factory()
{
   ///The client code interacts with the abstract creator, creating products without needing to know their specific types.

   //. create instances of the concrete creators
   shapeFactory* cFactory = new circleFactory();
   shapeFactory* sFactory = new squareFactory();

   // use them to create instances of concrete products
   shape* c = cFactory->shapeCreator();
   shape* s = sFactory->shapeCreator();

   // produces the expected output
   c->draw();
   s->draw();

   delete cFactory;
   delete sFactory;
   delete c;
   delete s;

   return 0;
}


