#include <iostream>
#include <vector>
#include "task1.h"
#include "task2.h"
#include "task3.h"


int main() {
    //*************** task1 ******************

    //Закажем пиццу 'Пепперони'
    PizzaFactory *pizzaFactory { new PepperoniPizzaFactory };

    //Используется фабричный метод
    Pizza *pizza { pizzaFactory->createPizza() };

    //Вывод информации
    orderPizza(pizza);

    delete pizza;
    delete pizzaFactory;

    //*************** task2 ******************

    //Клиент, у которого есть три дня для отдыха
    Client client;

    FirstDayBuilder firstDayBuilder;
    SecondDayBuilder secondDayBuilder;
    ThirdDayBuilder thirdDayBuilder;

    EventsDay* firstDay { client.createOneDay(firstDayBuilder) };
    EventsDay* secondDay { client.createOneDay(secondDayBuilder) };
    EventsDay* thirdDay { client.createOneDay(thirdDayBuilder) };

    std::cout << "First day:\n";
    firstDay->showInfo();

    std::cout << "\nSecond day:\n";
    secondDay->showInfo();

    std::cout << "\nThird day:\n";
    thirdDay->showInfo();
	
    //*************** task3 ******************

    //Начнём рисовать карандашом
    PencilDrawingImplementor pencilImpl;
    Rectangle rectangle(&pencilImpl);

    rectangle.draw();

    //Увеличим толщину линий
    rectangle.resize(5.7);

    rectangle.draw();

    //Сменим карандаш на кисть
    BrushDrawingImplementor brushDrawingImplementor;
    rectangle.setDrawingImplementor(&brushDrawingImplementor);

    rectangle.draw();

	return 0;
}
