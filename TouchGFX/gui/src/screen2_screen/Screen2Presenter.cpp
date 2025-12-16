#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{

}

void Screen2Presenter::activate()
{

}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::UpdateImageX(int16_t x)
{
	model->update(x);
}

int16_t Screen2Presenter::GetImageX()
{
	return model->GetImageX();
}
