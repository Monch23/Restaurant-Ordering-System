#include <iostream>
#include "dish.h"

// class Dish
Dish::Dish(const std::string &dish_name, double dish_price) :
    m_name{dish_name}, m_price{dish_price}
{}

Dish::Dish(const Dish &other) :
    m_name{other.get_name()}, m_price{other.get_price()}
{}

Dish &Dish::operator=(const Dish &rhs) {
    if (this == &rhs) {
        return *this;
    }

    m_name = rhs.get_name();
    m_price = rhs.get_price();

    return *this;
}

Dish::Dish(Dish &&other) noexcept :
    m_name{std::move(other.m_name)},
    m_price{other.get_price()}
{}

Dish &Dish::operator=(Dish &&rhs) noexcept {
    if (this == &rhs) {
        return *this;
    }
    
    m_name = std::move(rhs.m_name);
    m_price = rhs.m_price;

    return *this;
}

void Dish::display(void) const {
    std::cout << m_name << std::endl;
    std::cout << "Price: " << m_price << std::endl;
}

double Dish::get_price(void) const {
    return m_price; 
}

std::string Dish::get_name(void) const {
    return m_name;
}

// class Appetizer

Appetizer::Appetizer(const std::string &dish_name, double dish_price, bool spicy) : 
    Dish(dish_name, dish_price), m_is_spicy{spicy}
{}

void Appetizer::display(void) const {
    Dish::display();
    std::cout << (m_is_spicy ? "spicy" : "not spicy") << std::endl;
}

// class Entree

Entree::Entree(const std::string &dish_name, double dish_price, int calories) :
    Dish(dish_name, dish_price), m_calories{calories}
{}

void Entree::display(void) const {
    Dish::display();
    std::cout << m_calories << "kcal" << std::endl;
}

// class Dessert

Dessert::Dessert(const std::string &dish_name, double dish_price, bool nuts) :
    Dish(dish_name, dish_price), m_contains_nuts{nuts}
{}

void Dessert::display(void) const {
    Dish::display();
    std::cout << (m_contains_nuts ? "with nuts" : "nuts free") << std::endl;
}