#include "menu.h"
#include <iostream>

Menu::Menu() {}

Menu::Menu(const Menu &other) {
    size_t dishes_cnt = other.m_dishes.size();

    for (int i = 0; i < dishes_cnt; ++i) {
        Dish * dptr = new Dish(other.m_dishes[i]->get_name(), other.m_dishes[i]->get_price());
        m_dishes.push_back(dptr);
    }
}

Menu &Menu::operator=(const Menu &rhs) {
    if (this == &rhs) {
        return *this;
    }

    size_t dishes_cnt = m_dishes.size();

    for (int i = 0; i < dishes_cnt; ++i) {
        delete m_dishes[i];
    }

    size_t rhs_dishes_cnt = rhs.m_dishes.size();

    for (int i = 0; i < rhs_dishes_cnt; ++i) {
        Dish *dish = new Dish{rhs.m_dishes[i]->get_name(), rhs.m_dishes[i]->get_price()};
        m_dishes.push_back(dish);
    }

    return *this;
    
}

Menu::Menu(Menu &&other) noexcept : m_dishes{std::move(other.m_dishes)} {}

Menu &Menu::operator=(Menu &&rhs) noexcept {
    if (this == &rhs) {
        return *this;
    }

    size_t dishes_cnt = m_dishes.size();

    for (int i = 0; i < dishes_cnt; ++i) {
        delete m_dishes[i];
    }

    m_dishes = std::move(rhs.m_dishes);

    return *this;
}

Menu::~Menu() {
    size_t dishes_cnt = m_dishes.size();

    for (int i = 0; i < dishes_cnt; ++i) {
        delete m_dishes[i];
    }
}

void Menu::add_dish(Dish *dish) {
    m_dishes.push_back(dish);
}

void Menu::display_menu(void) const {
    size_t dishes_cnt = m_dishes.size();

    for (int i = 0; i < dishes_cnt; ++i) {
        std::cout << m_dishes[i]->get_name() << std::endl;
        std::cout << "Price: " << m_dishes[i]->get_price() << std::endl;
    }
}

Dish *Menu::get_dish_by_name(const std::string &dish_name) {
    size_t dishes_cnt = m_dishes.size();

    for (int i = 0; i < dishes_cnt; ++i) {
        if (m_dishes[i]->get_name() == dish_name) {
            return m_dishes[i];
        }
    }

    std::cout << "' " << dish_name << " '" << "doesn't have in menu" << std::endl;

    return nullptr;
}