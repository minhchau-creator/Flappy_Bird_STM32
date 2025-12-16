#include <gui/screen1_screen/Screen1View.hpp>

extern uint32_t scoreBest;

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    textProgress1.setValue(scoreBest);
    textProgress1.invalidate();

}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
    setupScreen();
}

void Screen1View::tickCountEvent1()
{
	tickCounter += 1;

}
