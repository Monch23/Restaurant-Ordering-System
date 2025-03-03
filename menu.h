#ifndef MENU_H
#define MENU_H
#include "dish.h"
#include <vector>
#include <string>

class Menu {
    private:
        std::vector<Dish*> m_dishes;
    public:
        Menu();
        Menu(const Menu &other);
        Menu &operator=(const Menu &rhs);
        Menu(Menu &&other) noexcept;
        Menu &operator=(Menu &&rhs) noexcept;
        ~Menu();

        void add_dish(Dish *dish);
        void display_menu(void) const;
        Dish *get_dish_by_name(const std::string &dish_name);
};

#endif