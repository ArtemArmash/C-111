#include <iostream>
using namespace std;

class Product {
public:
    char name[100];
    double price;

    Product(const char* productName, double productPrice) {
        int i = 0;
        while (productName[i] != '\0' && i < 99) {
            name[i] = productName[i];
            ++i;
        }
        name[i] = '\0';
        price = productPrice;
    }
};

class Order {
private:
    char customerName[100];
    char deliveryAddress[100];
    int orderNumber;
    Product* products[10];

public:
    Order(const char* name, const char* address, int number) {
        int i = 0;
        while (name[i] != '\0' && i < 99) {
            customerName[i] = name[i];
            ++i;
        }
        customerName[i] = '\0';

        i = 0;
        while (address[i] != '\0' && i < 99) {
            deliveryAddress[i] = address[i];
            ++i;
        }
        deliveryAddress[i] = '\0';

        orderNumber = number;
        for (int j = 0; j < 10; ++j) {
            products[j] = nullptr;
        }
    }

    void addProduct(const Product& product, int index) {
        if (index >= 0 && index < 10) {
            if (products[index] == nullptr) {
                products[index] = new Product(product);
            }
            else {
                cout << "Error " << index << endl;
            }
        }
        else {
            cout << "Error." << endl;
        }
    }

    void removeProduct(int index) {
        if (index >= 0 && index < 10) {
            delete products[index];
            products[index] = nullptr;
        }
        else {
            cout << "Error." << endl;
        }
    }

    void printProducts() const {
        for (int i = 0; i < 10; ++i) {
            if (products[i] != nullptr) {
                cout << "Product " << i + 1 << ": " << products[i]->name << "| Price: " << products[i]->price << endl;
            }
        }
    }

    double calculateTotalPrice() const {
        double total = 0.0;
        for (int i = 0; i < 10; ++i) {
            if (products[i] != nullptr) {
                total += products[i]->price;
            }
        }
        return total;
    }

    void printOrderInfo() const {
        cout << "Order ¹" << orderNumber << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Delivery Address: " << deliveryAddress << endl;
        cout << "Products in the order:" << endl;
        printProducts();
        cout << "Total Price: " << calculateTotalPrice() << endl;
    }
    ~Order() {
        for (int i = 0; i < 10; ++i) {
            delete products[i];
        }
    }
};

int main() {
    Product product1("Product1", 25.99);
    Product product2("Product2", 15.49);

    Order order("Smith", "New York", 123);
    order.addProduct(product1, 0);
    order.addProduct(product2, 1);

    cout << "Order information before removing a product:" << endl;
    order.printOrderInfo();

    order.removeProduct(0);

    cout << "\nOrder information after removing a product:" << endl;
    order.printOrderInfo();
}
