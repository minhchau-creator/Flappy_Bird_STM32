#include <gui/screen2_screen/Screen2View.hpp>
#include "cmsis_os.h"
#include "main.h"
#include "stdio.h"
#include <cstdlib>
#include <math.h>
#include <string.h>

extern osMessageQueueId_t Queue1Handle;
extern uint16_t birdX;

extern uint32_t scorePlaying;
extern uint32_t scoreBest;

extern uint32_t tickKernel;

uint32_t gameSpeed = 1;
uint16_t holeX = 0;
uint16_t holeY = 0;
uint16_t halfSpace = 50;

float sinValue = 0;
float birdY = 160.0f;         // vị trí chim theo trục Y
float birdVelocity = 0.0f;    // vận tốc tức thời
float gravity = 0.2f;        // gia tốc rơi (thử từ 0.2 đến 0.5)
float jumpStrength = -3.5f;   // vận tốc khi nhấn nút

bool isJumping = false;       // cờ đánh dấu đang bay lên
static uint8_t rand_n = 0;

Screen2View::Screen2View()
{
	tickCount = 0;
}

void Screen2View::setupScreen()
{
    localImageX = presenter->GetImageX();
	Screen2ViewBase::setupScreen();
	circle1.setX(birdX);
	holeX = 265;
	holeY = 160;


	scorePlaying = 0;
	//Text Progress
	textProgress1.setValue(scorePlaying);
	textProgress1.invalidate();
	//Reset Queue
	osMessageQueueReset(Queue1Handle);

	gameSpeed = 1;
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
	presenter->UpdateImageX(localImageX);
	//Callback setup Screen each time press START
	setupScreen();
}

void Screen2View::scoringFunct() {

	//TODO: Fix exact colision of lamb and image1 for Scoring

	if(holeX == 10){
		scorePlaying += 1;
	}

	if( ((birdY + 30 >= holeY + halfSpace) || (birdY <= holeY - halfSpace))
		&& !(birdX > holeX + 50 || birdX + 30 < holeX)){
		application().gotoScreen1ScreenWipeTransitionEast();
	}

	//Update High score
	if (scoreBest < scorePlaying) {
		scoreBest = scorePlaying;
	}

	//Update score Playing
	textProgress1.setValue(scorePlaying);

}

void Screen2View::handleTickEvent(){
	textProgress1.invalidate();
	Screen2ViewBase::handleTickEvent();

	tickCount++;

	//Random
	if (tickCount % 300 == 0) {
		rand_n = osKernelGetTickCount() % (320 - 40 - 2 * halfSpace);
	}
	//Game speeding
	if (scorePlaying > 10) {
		gameSpeed = 2;

	} else if (scorePlaying > 30) {
		gameSpeed = 3;

	} else if (scorePlaying > 70) {
		gameSpeed = 4;

	}
	holeX = 270 - (tickCount * gameSpeed % 300);
	holeY = rand_n + halfSpace + 20;

	boxWithBorder2.setX(holeX);
	boxWithBorder1.setX(holeX);

	boxWithBorder2.setY(holeY + halfSpace);
	boxWithBorder1.setY(holeY - halfSpace - boxWithBorder1.getHeight());


	//Moving bird
	char cmd[5];  // bộ đệm để nhận lệnh
	if (osMessageQueueGet(Queue1Handle, &cmd, NULL, 0) == osOK) {
		if (strcmp(cmd, "jump") == 0) {
			birdVelocity = jumpStrength;   // bật lên

		}
	}

	// Cập nhật vật lý
	birdVelocity += gravity;      // tăng dần do trọng lực
	birdY += birdVelocity;        // cập nhật vị trí chim

	// Giới hạn không cho rơi xuống dưới đáy
	//	if (birdY > 240) birdY = 240;
	if (birdY < 0)   birdY = 0;
	if (birdY > 290)  birdY = 290;

	circle1.setY((int)birdY);        // cập nhật vị trí cho chim

	scoringFunct();

	invalidate();

}
