#include "order.h"
#include <iostream>
#include "dish.h"
#include "customer.h"

Order::Order(Customer *customer) :
    m_customer{customer}, m_total_price{0}
{}

Order::Order(const Order &other) {
    m_customer = other.m_customer;
    m_total_price = other.m_total_price;

    size_t orders_cnt = m_ordered_dishes.size();

    for (int i = 0; i < orders_cnt; ++i) {
        Dish *dish = new Dish{other.m_ordered_dishes[i]->get_name(), other.m_ordered_dishes[i]->get_price()};
        m_ordered_dishes.push_back(dish);
    }
}

Order &Order::operator=(const Order &rhs) {
    if (this == &rhs) {
        return *this;
    }

    m_customer = rhs.m_customer;
    m_total_price = rhs.m_total_price;

    size_t orders_cnt = m_ordered_dishes.size();

    for (int i = 0; i < orders_cnt; ++i) {
        delete m_ordered_dishes[i];
    }

    size_t rhs_orders_cnt = rhs.m_ordered_dishes.size();

    for (int i = 0; i < rhs_orders_cnt; ++i) {
        Dish *dish = new Dish{rhs.m_ordered_dishes[i]->get_name(), rhs.m_ordered_dishes[i]->get_price()};
        m_ordered_dishes.push_back(dish);
    }

    return *this;
}

Order::Order(Order &&other) noexcept :
    m_customer{other.m_customer},
    m_ordered_dishes{std::move(other.m_ordered_dishes)},
    m_total_price{other.m_total_price}
{
    other.m_customer = nullptr;
}

Order &Order::operator=(Order &&rhs) noexcept {
    if (this == &rhs) {
        return *this;
    }

    m_customer = rhs.m_customer;
    m_ordered_dishes = std::move(rhs.m_ordered_dishes);
    m_total_price = rhs.m_total_price;

    return *this;
}

Order::~Order() {
    size_t orders_cnt = m_ordered_dishes.size();

    for (int i = 0; i < orders_cnt; ++i) {
        delete m_ordered_dishes[i];
    }
}

void Order::add_dish(Dish *dish) {
    m_ordered_dishes.push_back(dish);
}

void Order::calculate_total(void) {
    size_t orders_cnt = m_ordered_dishes.size();

    for (int i = 0; i < orders_cnt; ++i) {
        m_total_price += m_ordered_dishes[i]->get_price();
    }
}

void Order::display_order(void) const {
    if (!m_customer) {
        return;
    }

    std::cout << "Customer: " << m_customer->get_name() << std::endl;

    size_t orders_cnt = m_ordered_dishes.size();

    if (!orders_cnt) {
        std::cout << "No orders yet" << std::endl;
        return;
    }

    for (int i = 0; i < orders_cnt; ++i) {
        m_ordered_dishes[i]->display();
    }

    std::cout << "Total Price: " << m_total_price << std::endl;
}

double Order::get_total_price(void) const {
    return m_total_price;
}