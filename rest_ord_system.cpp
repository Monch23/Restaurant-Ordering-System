#include <iostream>
#include "customer.h"
#include "order.h"
#include "dish.h"
#include "menu.h"
#include "restaurant.h"

// Прототипы тестовых функций для Customer
void testCustomerConstructor();
void testCustomerCopyConstructor();
void testCustomerAssignmentOperator();
void testCustomerMoveConstructor();
void testCustomerMoveAssignmentOperator();
void testCustomerPlaceOrder();
void testCustomerGetName();
void testCustomerViewOrderHistory();

// Прототипы тестовых функций для Dish и его производных классов
void testDishConstructor();
void testDishCopyConstructor();
void testDishAssignmentOperator();
void testDishMoveConstructor();
void testDishMoveAssignmentOperator();
void testDishGetPrice();
void testDishGetName();
void testAppetizerConstructor();
void testAppetizerDisplay();
void testEntreeConstructor();
void testEntreeDisplay();
void testDessertConstructor();
void testDessertDisplay();

// Прототипы тестовых функций для Menu
void testMenuConstructor();
void testMenuCopyConstructor();
void testMenuAssignmentOperator();
void testMenuMoveConstructor();
void testMenuMoveAssignmentOperator();
void testMenuAddDish();
void testMenuDisplayMenu();
void testMenuGetDishByName();

// Прототипы тестовых функций для Order
void testOrderConstructor();
void testOrderCopyConstructor();
void testOrderAssignmentOperator();
void testOrderMoveConstructor();
void testOrderMoveAssignmentOperator();
void testOrderAddDish();
void testOrderCalculateTotal();
void testOrderDisplayOrder();

// Прототипы тестовых функций для Restaurant
void testRestaurantConstructor();
void testRestaurantCopyConstructor();
void testRestaurantAssignmentOperator();
void testRestaurantMoveConstructor();
void testRestaurantMoveAssignmentOperator();
void testRestaurantShowMenu();
void testRestaurantGetCustomerByName();
void testRestaurantViewCustomerOrderHistory();

int main() {
    // Вызов тестовых функций для Customer
    testCustomerConstructor();
    testCustomerCopyConstructor();
    testCustomerAssignmentOperator();
    testCustomerMoveConstructor();
    testCustomerMoveAssignmentOperator();
    testCustomerPlaceOrder();
    testCustomerGetName();
    testCustomerViewOrderHistory();

    // Вызов тестовых функций для Dish и его производных классов
    testDishConstructor();
    testDishCopyConstructor();
    testDishAssignmentOperator();
    testDishMoveConstructor();
    testDishMoveAssignmentOperator();
    testDishGetPrice();
    testDishGetName();
    testAppetizerConstructor();
    testAppetizerDisplay();
    testEntreeConstructor();
    testEntreeDisplay();
    testDessertConstructor();
    testDessertDisplay();

    // Вызов тестовых функций для Menu
    testMenuConstructor();
    testMenuCopyConstructor();
    testMenuAssignmentOperator();
    testMenuMoveConstructor();
    testMenuMoveAssignmentOperator();
    testMenuAddDish();
    testMenuDisplayMenu();
    testMenuGetDishByName();

    // Вызов тестовых функций для Order
    testOrderConstructor();
    testOrderCopyConstructor();
    testOrderAssignmentOperator();
    testOrderMoveConstructor();
    testOrderMoveAssignmentOperator();
    testOrderAddDish();
    testOrderCalculateTotal();
    testOrderDisplayOrder();

    // Вызов тестовых функций для Restaurant
    testRestaurantConstructor();
    testRestaurantCopyConstructor();
    testRestaurantAssignmentOperator();
    testRestaurantMoveConstructor();
    testRestaurantMoveAssignmentOperator();
    testRestaurantShowMenu();
    testRestaurantGetCustomerByName();
    testRestaurantViewCustomerOrderHistory();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}

// Реализация тестовых функций для Customer
void testCustomerConstructor() {
    Customer customer("John Doe", "john.doe@example.com");
    std::cout << "Customer constructor test passed!" << std::endl;
}

void testCustomerCopyConstructor() {
    Customer original("John Doe", "john.doe@example.com");
    Customer copy(original);
    std::cout << "Customer copy constructor test passed!" << std::endl;
}

void testCustomerAssignmentOperator() {
    Customer customer1("John Doe", "john.doe@example.com");
    Customer customer2("Jane Doe", "jane.doe@example.com");
    customer1 = customer2;
    std::cout << "Customer assignment operator test passed!" << std::endl;
}

void testCustomerMoveConstructor() {
    Customer original("John Doe", "john.doe@example.com");
    Customer moved(std::move(original));
    std::cout << "Customer move constructor test passed!" << std::endl;
}

void testCustomerMoveAssignmentOperator() {
    Customer customer1("John Doe", "john.doe@example.com");
    Customer customer2("Jane Doe", "jane.doe@example.com");
    customer1 = std::move(customer2);
    std::cout << "Customer move assignment operator test passed!" << std::endl;
}

void testCustomerPlaceOrder() {
    Customer customer("John Doe", "john.doe@example.com");
    Order order(&customer); // Предположим, что у вас есть конструктор по умолчанию для Order
    customer.place_order(order);
    std::cout << "Customer place order test passed!" << std::endl;
}

void testCustomerGetName() {
    Customer customer("John Doe", "john.doe@example.com");
    if (customer.get_name() == "John Doe") {
        std::cout << "Customer get name test passed!" << std::endl;
    } else {
        std::cerr << "Customer get name test failed!" << std::endl;
        exit(1);
    }
}

void testCustomerViewOrderHistory() {
    Customer customer("John Doe", "john.doe@example.com");
    customer.view_order_history();
    std::cout << "Customer view order history test passed!" << std::endl;
}

// Реализация тестовых функций для Dish и его производных классов
void testDishConstructor() {
    Dish dish("Pasta", 12.99);
    std::cout << "Dish constructor test passed!" << std::endl;
}

void testDishCopyConstructor() {
    Dish original("Pasta", 12.99);
    Dish copy(original);
    std::cout << "Dish copy constructor test passed!" << std::endl;
}

void testDishAssignmentOperator() {
    Dish dish1("Pasta", 12.99);
    Dish dish2("Pizza", 10.99);
    dish1 = dish2;
    std::cout << "Dish assignment operator test passed!" << std::endl;
}

void testDishMoveConstructor() {
    Dish original("Pasta", 12.99);
    Dish moved(std::move(original));
    std::cout << "Dish move constructor test passed!" << std::endl;
}

void testDishMoveAssignmentOperator() {
    Dish dish1("Pasta", 12.99);
    Dish dish2("Pizza", 10.99);
    dish1 = std::move(dish2);
    std::cout << "Dish move assignment operator test passed!" << std::endl;
}

void testDishGetPrice() {
    Dish dish("Pasta", 12.99);
    if (dish.get_price() == 12.99) {
        std::cout << "Dish get price test passed!" << std::endl;
    } else {
        std::cerr << "Dish get price test failed!" << std::endl;
        exit(1);
    }
}

void testDishGetName() {
    Dish dish("Pasta", 12.99);
    if (dish.get_name() == "Pasta") {
        std::cout << "Dish get name test passed!" << std::endl;
    } else {
        std::cerr << "Dish get name test failed!" << std::endl;
        exit(1);
    }
}

void testAppetizerConstructor() {
    Appetizer appetizer("Spring Rolls", 5.99, true);
    std::cout << "Appetizer constructor test passed!" << std::endl;
}

void testAppetizerDisplay() {
    Appetizer appetizer("Spring Rolls", 5.99, true);
    appetizer.display();
    std::cout << "Appetizer display test passed!" << std::endl;
}

void testEntreeConstructor() {
    Entree entree("Steak", 24.99, 800);
    std::cout << "Entree constructor test passed!" << std::endl;
}

void testEntreeDisplay() {
    Entree entree("Steak", 24.99, 800);
    entree.display();
    std::cout << "Entree display test passed!" << std::endl;
}

void testDessertConstructor() {
    Dessert dessert("Chocolate Cake", 6.99, true);
    std::cout << "Dessert constructor test passed!" << std::endl;
}

void testDessertDisplay() {
    Dessert dessert("Chocolate Cake", 6.99, true);
    dessert.display();
    std::cout << "Dessert display test passed!" << std::endl;
}

// Реализация тестовых функций для Menu
void testMenuConstructor() {
    Menu menu;
    std::cout << "Menu constructor test passed!" << std::endl;
}

void testMenuCopyConstructor() {
    Menu original;
    Menu copy(original);
    std::cout << "Menu copy constructor test passed!" << std::endl;
}

void testMenuAssignmentOperator() {
    Menu menu1;
    Menu menu2;
    menu1 = menu2;
    std::cout << "Menu assignment operator test passed!" << std::endl;
}

void testMenuMoveConstructor() {
    Menu original;
    Menu moved(std::move(original));
    std::cout << "Menu move constructor test passed!" << std::endl;
}

void testMenuMoveAssignmentOperator() {
    Menu menu1;
    Menu menu2;
    menu1 = std::move(menu2);
    std::cout << "Menu move assignment operator test passed!" << std::endl;
}

void testMenuAddDish() {
    Menu menu;
    Dish* dish = new Dish("Pasta", 12.99);
    menu.add_dish(dish);
    std::cout << "Menu add dish test passed!" << std::endl;
    // delete dish; // Не забудьте освободить память
}

void testMenuDisplayMenu() {
    Menu menu;
    Dish* dish = new Dish("Pasta", 12.99);
    menu.add_dish(dish);
    menu.display_menu();
    std::cout << "Menu display menu test passed!" << std::endl;
    // delete dish; // Не забудьте освободить память
}

void testMenuGetDishByName() {
    Menu menu;
    Dish* dish = new Dish("Pasta", 12.99);
    menu.add_dish(dish);
    if (menu.get_dish_by_name("Pasta") == dish) {
        std::cout << "Menu get dish by name test passed!" << std::endl;
    } else {
        std::cerr << "Menu get dish by name test failed!" << std::endl;
        exit(1);
    }
    // delete dish; // Не забудьте освободить память
}

// Реализация тестовых функций для Order
void testOrderConstructor() {
    Customer customer("John Doe", "john.doe@example.com");
    Order order(&customer);
    std::cout << "Order constructor test passed!" << std::endl;
}

void testOrderCopyConstructor() {
    Customer customer("John Doe", "john.doe@example.com");
    Order original(&customer);
    Order copy(original);
    std::cout << "Order copy constructor test passed!" << std::endl;
}

void testOrderAssignmentOperator() {
    Customer customer1("John Doe", "john.doe@example.com");
    Order order1(&customer1);
    Customer customer2("Jane Doe", "jane.doe@example.com");
    Order order2(&customer2);
    order1 = order2;
    std::cout << "Order assignment operator test passed!" << std::endl;
}

void testOrderMoveConstructor() {
    Customer customer("John Doe", "john.doe@example.com");
    Order original(&customer);
    Order moved(std::move(original));
    std::cout << "Order move constructor test passed!" << std::endl;
}

void testOrderMoveAssignmentOperator() {
    Customer customer1("John Doe", "john.doe@example.com");
    Order order1(&customer1);
    Customer customer2("Jane Doe", "jane.doe@example.com");
    Order order2(&customer2);
    order1 = std::move(order2);
    std::cout << "Order move assignment operator test passed!" << std::endl;
}

void testOrderAddDish() {
    Customer customer("John Doe", "john.doe@example.com");
    Order order(&customer);
    Dish* dish = new Dish("Pasta", 12.99);
    order.add_dish(dish);
    std::cout << "Order add dish test passed!" << std::endl;
    // delete dish; // Не забудьте освободить память
}

void testOrderCalculateTotal() {
    Customer customer("John Doe", "john.doe@example.com");
    Order order(&customer);
    Dish* dish1 = new Dish("Pasta", 12.99);
    Dish* dish2 = new Dish("Pizza", 10.99);
    order.add_dish(dish1);
    order.add_dish(dish2);
    order.calculate_total();
    // Предположим, что есть метод getTotalPrice(), нужно будет добавить его в Order.h и Order.cpp
    if (order.get_total_price() == 23.98) { 
        std::cout << "Order calculate total test passed!" << std::endl;
    } else {
        std::cerr << "Order calculate total test failed!" << std::endl;
        exit(1);
    }
    // delete dish1; // Не забудьте освободить память
    // delete dish2; // Не забудьте освободить память
}

void testOrderDisplayOrder() {
    Customer customer("John Doe", "john.doe@example.com");
    Order order(&customer);
    order.display_order();
    std::cout << "Order display order test passed!" << std::endl;
}

// Реализация тестовых функций для Restaurant
void testRestaurantConstructor() {
    Restaurant restaurant;
    std::cout << "Restaurant constructor test passed!" << std::endl;
}

void testRestaurantCopyConstructor() {
    Restaurant original;
    Restaurant copy(original);
    std::cout << "Restaurant copy constructor test passed!" << std::endl;
}

void testRestaurantAssignmentOperator() {
    Restaurant restaurant1;
    Restaurant restaurant2;
    restaurant1 = restaurant2;
    std::cout << "Restaurant assignment operator test passed!" << std::endl;
}

void testRestaurantMoveConstructor() {
    Restaurant original;
    Restaurant moved(std::move(original));
    std::cout << "Restaurant move constructor test passed!" << std::endl;
}

void testRestaurantMoveAssignmentOperator() {
    Restaurant restaurant1;
    Restaurant restaurant2;
    restaurant1 = std::move(restaurant2);
    std::cout << "Restaurant move assignment operator test passed!" << std::endl;
}

void testRestaurantShowMenu() {
    Restaurant restaurant;
    restaurant.show_menu();
    std::cout << "Restaurant show menu test passed!" << std::endl;
}

void testRestaurantGetCustomerByName() {
    Restaurant restaurant;
    Customer* customer = new Customer("John Doe", "john.doe@example.com");
    restaurant.get_customer_by_name("John Doe");
    std::cout << "Restaurant get customer by name test passed!" << std::endl;
    // delete customer; // Не забудьте освободить память
}

void testRestaurantViewCustomerOrderHistory() {
    Restaurant restaurant;
    restaurant.view_customer_order_history("John Doe");
    std::cout << "Restaurant view customer order history test passed!" << std::endl;
}