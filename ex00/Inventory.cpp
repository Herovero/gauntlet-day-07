#include "Inventory.hpp"

/*void Inventory::add(const std::string& item) {
    (void)item;
}*/
void Inventory::add(const std::string& item) { 
    m_items.push_back(item); 
}

void Inventory::remove(const std::string& item) {
    (void)item;
}

bool Inventory::has(const std::string& item) const {
    (void)item;
    return false;
}

/*int Inventory::count() const {
    return 0;
}*/
int Inventory::count() const { 
    return m_items.size(); 
}