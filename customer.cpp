#include "customer.h"
#include "order.h"

Customer::Customer(const std::string &customer_name, const std::string &contact) :
    m_name{customer_name}, m_contact_info{contact}
{}

Customer::Customer(const Customer &other) :
    m_name{other.m_name}, m_contact_info{other.m_contact_info}
{
    size_t orders_count = m_order_history.size();

    for (int i = 0; i < orders_count; ++i) {
        m_order_history.push_back(other.m_order_history[i]);
    }
}

Customer &Customer::operator=(const Customer &rhs) {
    if (this == &rhs) {
        return *this;
    }

    m_name = rhs.m_name;
    m_contact_info = rhs.m_contact_info;
    m_order_history = rhs.m_order_history;

    return *this;
}

Customer::Customer(Customer &&other) noexcept :
    m_name{std::move(other.m_name)}, 
    m_contact_info{std::move(other.m_contact_info)},
    m_order_history{std::move(other.m_order_history)}
{}

Customer &Customer::operator=(Customer &&rhs) noexcept {
    if (this == &rhs) {
        return *this;
    }

    m_name = std::move(rhs.m_name);
    m_contact_info = std::move(rhs.m_contact_info);
    m_order_history = std::move(rhs.m_order_history);

    return *this;
}

void Customer::place_order(Order order) {
    m_order_history.push_back(std::move(order));
}

void Customer::view_order_history(void) const {

}

std::string Customer::get_name(void) const {
    return m_name;
}