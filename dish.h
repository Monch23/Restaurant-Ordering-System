#ifndef DISH_H
#define DISH_H
#include <string>

class Dish {
    protected:
        std::string m_name;
        double m_price;
    public:
        Dish(const std::string &dish_name, double dish_price);
        Dish(const Dish &other);
        Dish &operator=(const Dish &rhs);
        Dish(Dish &&other) noexcept;
        Dish &operator=(Dish &&rhs) noexcept;

        void display(void) const;
        double get_price(void) const;
        std::string get_name(void) const;
};

class Appetizer : public Dish {
    private:
        bool m_is_spicy;
    public:
        Appetizer(const std::string &dish_name, double dish_price, bool spicy);
        void display(void) const;
};

class Entree : public Dish {
    private:
        int m_calories;
    public:
        Entree(const std::string &dish_name, double price, int calories);
        void display(void) const;
};

class Dessert : public Dish {
    private:
        bool m_contains_nuts;
    public:
        Dessert(const std::string &dish_name, double price, bool nuts);
        void display(void) const;
};

#endif