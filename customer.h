#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>

class Order;

class Customer {
    private:
        std::string m_name;
        std::string m_contact_info;
        std::vector<Order> m_order_history;
    public:
        Customer(const std::string &customer_name, const std::string &contact);
        Customer(const Customer &other);
        Customer &operator=(const Customer &rhs);
        Customer(Customer &&other) noexcept;
        Customer &operator=(Customer &&rhs) noexcept;
        ~Customer() = default;

        void place_order(Order order);
        void view_order_history(void) const;
        std::string get_name(void) const;
};

#endif