#include <iostream>
#include <memory>
#include <map>
//#include <functional>

// Base class for the products
class Product {
public:
    virtual void display() const = 0;
    virtual ~Product() = default;
};

// Concrete product classes
class ConcreteProductA : public Product {
public:
    void display() const override {
        std::cout << "Concrete Product A" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void display() const override {
        std::cout << "Concrete Product B" << std::endl;
    }
};

// Factory class to create products
class Factory {
public:
    // Function to register product creation functions
    template<typename T>
    void registerProduct() {
        creators_[T::ID] = []() { return std::make_unique<T>(); };
    }

    // Function to create product based on ID
    std::unique_ptr<Product> createProduct(int id) {
        if (creators_.find(id) != creators_.end()) {
            return creators_[id]();
        }
        return nullptr; // Invalid ID
    }

private:
    std::map<int, std::function<std::unique_ptr<Product>()>> creators_;
};

// IDs for products
struct ProductID {
    static const int A = 0;
    static const int B = 1;
};

int main() {
    Factory factory;
    
    // Register product creation functions
    factory.registerProduct<ConcreteProductA>();
    factory.registerProduct<ConcreteProductB>();

    // Create products
    std::unique_ptr<Product> productA = factory.createProduct(ProductID::A);
    std::unique_ptr<Product> productB = factory.createProduct(ProductID::B);

    // Use products
    if (productA) productA->display();
    if (productB) productB->display();

    return 0;
}