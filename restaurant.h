#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "customer.h"
#include "order.h"
#include "menu.h"
#include <string>
#include <vector>

class Restaurant {
    private:
        Menu m_menu;
        std::vector<Customer*> m_customers;
        std::vector<Order> m_orders;
    public:
        Restaurant();
        Restaurant(const Restaurant &other);
        Restaurant &operator=(const Restaurant &rhs);
        Restaurant(Restaurant &&other) noexcept;
        Restaurant &operator=(Restaurant &&rhs) noexcept;
        ~Restaurant();

        void show_menu(void) const;
        Customer *get_customer_by_name(const std::string &name);
        void place_new_order(const std::string &customer_name, const Order &new_order);
        void view_customer_order_history(const std::string &customer_name) const;
};

#endif