// Implementor
class DrawingImplementor {
public:
    virtual void drawRectangle(double) = 0;

    virtual ~DrawingImplementor() {
    }
};

// Abstraction
class Shape {
public:
    virtual void draw()= 0; // low-level
    virtual void resize(double pct) = 0; // high-level
    virtual ~Shape() {
    }
};

class BrushDrawingImplementor: public DrawingImplementor{
public:
    void drawRectangle(double lineWidth) override{
        std::cout << "Рисуем кистью толщиной " << lineWidth << ".\n";
    }
};

class PencilDrawingImplementor: public DrawingImplementor{
public:
    void drawRectangle(double lineWidth) override{
        std::cout << "Рисуем карандашом толщиной " << lineWidth << ".\n";
    }
};

class Rectangle: public Shape {
private:
    DrawingImplementor* _drawingImplementor;
    double lineWidth = 1.0;
public:
    Rectangle(DrawingImplementor *impl): _drawingImplementor { impl } {}

    void setDrawingImplementor(DrawingImplementor *impl) {
        _drawingImplementor = impl;
    }

    void draw() override{
        _drawingImplementor->drawRectangle(lineWidth);
    }

    void resize(double pct) override{
        lineWidth = pct;
    }
};

