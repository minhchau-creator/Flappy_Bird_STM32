#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void tickCountEvent1();
//    void buttonClicked1();
//    void buttonClicked2();
//    void buttonClicked2();
protected:
    long tickCounter = 0;
};

#endif // SCREEN1VIEW_HPP
