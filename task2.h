class Events{
public:
    virtual void getEvent() = 0;
    virtual ~Events() {};
};

class Hotel: public Events{
public:
    void getEvent() {
        std::cout << "Booking Hotel" << std::endl;
    }
};

class Park: public Events{
    void getEvent() {
        std::cout << "Park visiting" << std::endl;
    }
};

class Food: public Events{
public:
    virtual void getEvent() = 0;
    virtual ~Food() {};
};

class Dinner: public Food{
public:
    //Тут некая путаница, поэтому немного исправим по
    //аналогии с ланчем и брейкфастом
    //Dinner(const std::string &type) : _type("breakfast") {}
    Dinner() : _type("dinner") {}
    void getEvent(){
        std::cout << "Food " << _type << std::endl;
    } ;
private:
    std::string _type;
};

class Lunch: public Food{
public:
    Lunch() : _type("lunch") {}
    void getEvent(){
        std::cout << "Food " << _type << std::endl;
    } ;
private:
    std::string _type;
};

class Breakfast: public Food{
public:
    Breakfast() : _type("breakfast") {}
    void getEvent(){
        std::cout << "Food " << _type << std::endl;
    } ;
private:
    std::string _type;
};

class Special: public Events{
public:
    virtual void getEvent() = 0;
    virtual ~Special() {};
};

class Skating:public Special{
public:
    //Skating(const std::string &type) : _type("skating") {}
    Skating() : _type("skating") {}

    void getEvent(){
        std::cout << _type << std::endl;
    } ;
private:
    std::string _type;
};

class Circus:public Special{
public:
    //Circus(const std::string &type) : _type("circus") {}
    Circus() : _type("circus") {}
    void getEvent(){
        std::cout << _type << std::endl;
    } ;
private:
    std::string _type;
};

class EventsDay{
public:
    std::vector<Events*> _events;

    void showInfo(){
        for (const auto &event : _events)
            event->getEvent();
    }

    virtual ~EventsDay(){
        for(const auto &event: _events)
            delete event;
    }

};

class EventsDayBuilder{
protected:
    EventsDay* _eventsDay { nullptr };
public:
   virtual void createHotel() {}
   virtual void createPark() {}

   virtual void createDinner() {}
   virtual void createLunch() {}
   virtual void createBreakfast() {}

   virtual void createSkating() {}
   virtual void createCircus() {}

   virtual void createEventsDay() = 0;


   EventsDay* getEventsDay() const {
       return _eventsDay;
   }

   ~EventsDayBuilder() {
       delete _eventsDay;
   }
};

class FirstDayBuilder: public EventsDayBuilder{
public:
    void createEventsDay() override{
        _eventsDay = new EventsDay;
    }

    void createHotel() override{
        _eventsDay->_events.push_back(new Hotel);
    }

    void createPark() override{
        _eventsDay->_events.push_back(new Park);
    }

    void createDinner() override{
        _eventsDay->_events.push_back(new Dinner);
    }
};

class SecondDayBuilder: public EventsDayBuilder{
public:
    void createEventsDay() override{
        _eventsDay = new EventsDay;
    }

    void createHotel() override{
        _eventsDay->_events.push_back(new Hotel);
    }

    void createPark() override{
        _eventsDay->_events.push_back(new Park);
    }

    void createBreakfast() override{
        _eventsDay->_events.push_back(new Breakfast);
    }

    void createDinner() override{
        _eventsDay->_events.push_back(new Dinner());
    }

    void createSkating() override{
        _eventsDay->_events.push_back(new Skating);
    }

};

class ThirdDayBuilder: public EventsDayBuilder{
public:
    void createEventsDay() override{
        _eventsDay = new EventsDay;
    }

    void createPark() override{
        _eventsDay->_events.push_back(new Park);
    }

    void createBreakfast() override{
        _eventsDay->_events.push_back(new Breakfast);
    }

    void createLunch() override{
        _eventsDay->_events.push_back(new Lunch);
    }

   void createCircus() override{
        _eventsDay->_events.push_back(new Circus);
    }
};

class Client{
public:
    EventsDay* createOneDay(EventsDayBuilder& builder){
        builder.createEventsDay();
        builder.createHotel();
        builder.createPark();
        builder.createBreakfast();
        builder.createLunch();
        builder.createDinner();
        builder.createSkating();
        builder.createCircus();

        return builder.getEventsDay();
    }
};
