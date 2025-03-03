#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <vector>
class Dish;
class Customer;

class Order {
    private:
        Customer *m_customer;
        std::vector<Dish*> m_ordered_dishes;
        double m_total_price;
    public:
        Order(Customer *customer);
        Order(const Order &other);
        Order &operator=(const Order &rhs);
        Order(Order &&other) noexcept;
        Order &operator=(Order &&rhs) noexcept;
        ~Order();

        void add_dish(Dish *dish);
        void calculate_total(void);
        void display_order(void) const;
        double get_total_price(void) const;
};

#endif