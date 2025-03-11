#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class ItemBase
{
public:
    std::string name;
    int price;
    int weight;

    void setItem(const std::string& itemData)
    {
        std::istringstream iss(itemData);
        iss >> name >> price >> weight;
    }

    // ����� ��� ������ ������ � ������� �� �����
    void readShopData(std::ifstream& file, std::string& store_name, std::vector<ItemBase>& items)
    {
        std::string line;

        while (std::getline(file, line))
        {
            if (line.substr(0, 4) == "Shop")
            {
                store_name = line.substr(4);
            }
            else if (line.substr(0, 5) == "items")
            {
                int val = std::stoi(line.substr(5));
                for (int i = 0; i < val; ++i)
                {
                    if (std::getline(file, line))
                    {
                        ItemBase item;
                        item.setItem(line);
                        items.push_back(item); // ���������� ������ � ������
                    }
                }
                break; // ���������� ������ ����� ��������� ���� �������
            }
        }
    }
};

class Shop
{
protected:
    std::string store_name;
    std::vector<ItemBase> items;
    double average_price = 0.0; // ���������� ��� ������� ����
    double average_weight = 0.0; // ���������� ��� �������� ����

public:
    void addItem(const ItemBase& item)
    {
        items.push_back(item);
        calculateAverage(); // ��������� ������� �������� ��� ���������� ������
    }

    void calculateAverage()
    {
        if (items.empty()) return; // �������� �� ������ ������

        double total_price = 0;
        double total_weight = 0;

        for (const auto& item : items)
        {
            total_price += item.price;
            total_weight += item.weight;
        }

        average_price = total_price / items.size();
        average_weight = total_weight / items.size();
    }

    void displayAverage() const
    {
        std::cout << "�������� ��������: " << store_name << std::endl;
        std::cout << "������� ����: " << average_price << std::endl;
        std::cout << "������� ���: " << average_weight << std::endl;
    }

    void setStoreName(const std::string& name)
    {
        store_name = name;
    }
};

class Shop_Vegetables : public Shop
{
public:
    void readShopData(std::ifstream& file)
    {
        ItemBase item;
        item.readShopData(file, store_name, items); // ������ ������ � ������� �� �����
        calculateAverage(); // ��������� ������� �������� ����� ���������� ���� �������
    }
};

class Shop_Coffee : public Shop
{
public:
    void readShopData(std::ifstream& file)
    {
        ItemBase item;
        item.readShopData(file, store_name, items); // ������ ������ � ������� �� �����
        calculateAverage(); // ��������� ������� �������� ����� ���������� ���� �������
    }
};

class Shop_TableGame : public Shop
{
public:
    void readShopData(std::ifstream& file)
    {
        ItemBase item;
        item.readShopData(file, store_name, items); // ������ ������ � ������� �� �����
        calculateAverage(); // ��������� ������� �������� ����� ���������� ���� �������
    }
};

int main()
{
    setlocale(0, "");
    // ��������� ���� ���� ���.
    std::ifstream file("C:/Users/Makas/OneDrive/������� ����/��������.txt");

    if (!file.is_open())
    {
        std::cerr << "������ �������� �����!" << std::endl;
        return 1; // ��������� ��������� ��� ������ �������� �����.
    }

    Shop_Vegetables vegetableShop;
    vegetableShop.readShopData(file); // ������ ������ ��� �������� ��������

    Shop_Coffee coffeeShop;
    coffeeShop.readShopData(file); // ������ ������ ��� ��������� ��������

    Shop_TableGame tableGameShop;
    tableGameShop.readShopData(file); // ������ ������ ��� �������� ���������� ���

    file.close(); // ��������� ���� ����� ��������� ���� ���������.

    // ���������� ������� �������� ��� ������� ��������
    vegetableShop.displayAverage();
    coffeeShop.displayAverage();
    tableGameShop.displayAverage();

    return 0;
}