#include "restaurant.h"
// #include "menu.h"
#include <iostream>
class Menu;

Restaurant::Restaurant() : m_menu{} {}

Restaurant::Restaurant(const Restaurant &other) : m_menu{other.m_menu} {
    size_t customers_cnt = other.m_customers.size();

    for (int i = 0; i < customers_cnt; ++i) {
        Customer *customer = new Customer(*other.m_customers[i]);
        m_customers.push_back(customer);
    }

    size_t orders_cnt = other.m_orders.size();

    for (int i = 0; i < orders_cnt; ++i) {
        m_orders.push_back(other.m_orders[i]);
    }
}

Restaurant &Restaurant::operator=(const Restaurant &rhs) {
    if (this == &rhs) {
        return *this;
    }

    size_t customers_cnt = m_customers.size();

    for (int i = 0; i < customers_cnt; ++i) {
        delete m_customers[i];
    }

    size_t rhs_customer_counts = rhs.m_customers.size();

    for (int i = 0; i < rhs_customer_counts; ++i) {
        Customer *customer = new Customer(*rhs.m_customers[i]);
        m_customers.push_back(customer);
    }

    m_orders = rhs.m_orders;

    return *this;
}

Restaurant::Restaurant(Restaurant &&other) noexcept :
    m_menu{std::move(other.m_menu)},
    m_customers{std::move(other.m_customers)},
    m_orders{std::move(other.m_orders)}
{}

Restaurant &Restaurant::operator=(Restaurant &&rhs) noexcept {
    if (this == &rhs) {
        return *this;
    }

    m_menu = std::move(rhs.m_menu);

    size_t customers_cnt = m_customers.size();

    for (int i = 0; i < customers_cnt; ++i) {
        delete m_customers[i];
    }

    m_customers = std::move(rhs.m_customers);
    m_orders = std::move(rhs.m_orders);

    return *this;
}

Restaurant::~Restaurant() {
    size_t customers_cnt = m_customers.size();

    for (int i = 0; i < customers_cnt; ++i) {
        delete m_customers[i];
    }
}

void Restaurant::show_menu(void) const {
    m_menu.display_menu();
}

Customer *Restaurant::get_customer_by_name(const std::string &name) {
    size_t customer_cnt = m_customers.size();

    for (int i = 0; i < customer_cnt; ++i) {
        if (m_customers[i]->get_name() == name) {
            return m_customers[i];
        }
    }

    std::cout << "Customer not found !" << std::endl;

    return nullptr;
}

void Restaurant::place_new_order(const std::string &customer_name, const Order &new_order) {
    Customer *customer = get_customer_by_name(customer_name);
    
    if (customer == nullptr) {
        std::cout << "Customer not found !" << std::endl;
        return;
    }

    m_orders.push_back(new_order);
}

void Restaurant::view_customer_order_history(const std::string &customer_name) const {
    size_t orders_cnt = m_orders.size();

    for (int i = 0; i < orders_cnt; ++i) {
        m_orders[i].display_order();
    }
}