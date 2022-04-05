class Pizza{
protected:
    std::string type{};
    Pizza(const std::string &type): type { type } {}
public:
    virtual void prepare() const {
        std::cout << "\n*******\n";
        std::cout << "Пицца \'" << type << "\'.\n";
    };

    virtual void bake() const{
        std::cout << "Готовится..\n";
    };

    virtual void cut() const{
        std::cout << "Разрезаем на равные доли..\n";
    };

    virtual void box() const{
        std::cout << "Упаковываем в коробку. Готово!\n";
        std::cout << "*******\n";
    };

    ~Pizza(){}
};

class CheesePizza:public Pizza{
public:
    CheesePizza(): Pizza ("с сыром") {}
};

class GreekPizza:public Pizza{
public:
    GreekPizza(): Pizza ("греческая") {}
};

class PepperoniPizza:public Pizza{
public:
    PepperoniPizza(): Pizza ("пепперони") {}
};

class PizzaFactory{
public:
    virtual Pizza* createPizza() = 0;
    virtual ~PizzaFactory(){};
};

class CheesePizzaFactory: public PizzaFactory{
public:
    Pizza* createPizza() override{
        return new CheesePizza;
    }
};

class GreekPizzaFactory: public PizzaFactory{
public:
    Pizza* createPizza() override{
        return new GreekPizza;
    }
};

class PepperoniPizzaFactory: public PizzaFactory{
public:
    Pizza* createPizza() override{
        return new PepperoniPizza;
    }
};

//Функция-клиент выводит информацию о заказываемой пицце.
//Ей всё равно, какой тип пиццы "прилетает" её в качестве
//агумента.
//Pizza* orderPizza(const std::string &type){
void orderPizza(Pizza *pizza){
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
}