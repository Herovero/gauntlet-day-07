#include "Inventory.hpp"

/*void Inventory::add(const std::string& item) {
    (void)item;
}*/
void Inventory::add(const std::string& item) { 
    m_items.push_back(item); 
}

/*void Inventory::remove(const std::string& item) {
    (void)item;
}*/
/*void Inventory::remove(const std::string& item) {
    (void)item;
    if (!m_items.empty()) {
        m_items.pop_back(); 
    }
}*/
void Inventory::remove(const std::string& item) {
    for (auto it = m_items.begin(); it != m_items.end(); ++it) {
        if (*it == item) {
            m_items.erase(it);
            return;
        }
    }
}

/*bool Inventory::has(const std::string& item) const {
    (void)item;
    return false;
}*/
bool Inventory::has(const std::string& item) const {
    for (std::size_t i = 0; i < m_items.size(); ++i) {
        if (m_items[i] == item) {
            return true;
        }
    }
    return false;
}

/*int Inventory::count() const {
    return 0;
}*/
int Inventory::count() const { 
    return m_items.size(); 
}