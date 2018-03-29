#include <iostream>

class Display
{
public:
    virtual ~Display(){std::cout<<"Distrutto il Display"<<"\n";}
    virtual void setup(){std::cout<<"Setup del disegno dal Display"<<"\n";}
    virtual void loop(){std::cout<<"loop del disegno dal Display"<<"\n";}
    void draw(Display &display)
    {
        std::cout<<"----------"<<"\n";
        display.setup();
        std::cout<<"main loop"<<"\n";
        display.loop();
        std::cout<<"----------"<<"\n";

    }
    Display(){init();}
protected:
    bool init(){std::cout<<"init dei vari oggetti Display"<<"\n";}
};

class App: public Display
{
public:
    virtual ~App(){std::cout<<"Distrutto l' App"<<"\n";}
    App():Display(){}
    virtual void setup() override{std::cout<<"Init del disegno dall'App"<<"\n";}
    virtual void loop()override{std::cout<<"loop del disegno dall'App"<<"\n";}
};

int main()
{
    App app;
    Display *display = &app;
    display->draw(app);

    Display disp2;
    display->draw(disp2);
    return 0;
}
