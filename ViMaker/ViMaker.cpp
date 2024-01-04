// ViMaker.cpp: определяет точку входа для приложения.

#include "ViMaker.h"
#include "application.h"

void main(void) {
	auto app = std::make_unique<Application>("ViMaker");
	app->loop();
}