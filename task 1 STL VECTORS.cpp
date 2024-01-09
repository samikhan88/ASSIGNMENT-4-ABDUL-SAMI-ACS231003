#include <iostream>
#include <vector>

struct Product {
    int id;
    std::string name;
    double price;
};

std::vector<Product> inventory;

void addProduct(int id, std::string name, double price) {
    Product newProduct;
    newProduct.id = id;
    newProduct.name = name;
    newProduct.price = price;
    inventory.push_back(newProduct);
}

void removeProduct(int id) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            inventory.erase(it);
            break;
        }
    }
}

int main() {
    // Adding products to the inventory
    addProduct(1, "Product 1", 10.99);
    addProduct(2, "Product 2", 19.99);
    addProduct(3, "Product 3", 5.99);

    // Removing a product from the inventory
    removeProduct(2);

    // Displaying the current inventory
    std::cout << "Current Inventory:\n";
    for (const auto& product : inventory) {
        std::cout << "ID: " << product.id << ", Name: " << product.name << ", Price: $" << product.price << "\n";
    }

    return 0;
}