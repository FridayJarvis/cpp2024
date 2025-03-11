#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class ItemBase {
public:
    virtual ~ItemBase() {}
};

class Item : public ItemBase {
public:
    std::string name;
    double price;
    double weight;

    Item(std::string _name, double _price, double _weight)
        : name(_name), price(_price), weight(_weight) {}
};

class Shop {
public:
    std::string name;
    std::vector<Item> items;

    Shop(std::string _name) : name(_name) {}

    void addItem(const Item& item) {
        items.push_back(item);
    }

    // ����� ��� ���������� ������� ���� ������� � ��������
    double averagePrice() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.price;
        }
        return (items.size() > 0) ? total / items.size() : 0;
    }

    // ����� ��� ���������� �������� ���� ������� � ��������
    double averageWeight() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.weight;
        }
        return (items.size() > 0) ? total / items.size() : 0;
    }
};

std::vector<Shop> File(const std::string& filename) {
    std::ifstream file(filename);  // ��������� ���� ��� ������
    std::vector<Shop> shops;       // ������ ��� �������� �������� ���������
    std::string line;              // ������ ��� ���������� �������� ������ �� �����

    while (std::getline(file, line)) {
        if (line.find("Shop") != std::string::npos) {
            std::stringstream ss(line);
            std::string shopLabel;
            std::string shopName;
            ss >> shopLabel >> shopName;

            Shop shop(shopName);

            std::getline(file, line); // ������ ������ � ����������� �������
            int itemCount = 0;
            std::stringstream(line) >> shopLabel >> itemCount; // ��������� ���������� �������

            // ������ ���������� � ������ ������
            for (int i = 0; i < itemCount; ++i) {
                std::getline(file, line);
                std::stringstream itemStream(line);
                std::string itemName;
                double itemPrice, itemWeight;
                itemStream >> itemName >> itemPrice >> itemWeight;

                Item item(itemName, itemPrice, itemWeight); // ������� ������ ������
                shop.addItem(item); // ��������� ����� � �������
            }

            shops.push_back(shop); // ��������� ������� � ������ ���������
        }
    }

    return shops; // ���������� ������ ���� ���������
}

int main() {
    std::string filename = "stores.txt";
    std::vector<Shop> shops = File(filename);

    for (const auto& shop : shops) {
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Shop: " << shop.name << std::endl;
        std::cout << "Average Price: " << shop.averagePrice() << std::endl;
        std::cout << "Average Weight: " << shop.averageWeight() << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}