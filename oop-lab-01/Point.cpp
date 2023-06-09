#include <windows.h>
#include <cmath>
#include "Point.h"
#include "Image.h"
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

extern HDC hdc;

Location::Location(int x, int y) : x(x), y(y) { };

Location::~Location(void) { };

int Location::getX(void) { return x; };	

int Location::getY(void) { return y; };

VPoint::VPoint(int initX, int initY) : Location(initX, initY) { visible = false; }

VPoint::~VPoint(void) { }

void VPoint::show(void) {
	visible = true;
	SetPixel(hdc, x, y, RGB(255, 0, 0));
	SetPixel(hdc, x + 1, y, RGB(255, 0, 0));
	SetPixel(hdc, x, y + 1, RGB(255, 0, 0));
	SetPixel(hdc, x + 1, y + 1, RGB(255, 0, 0));
}

void VPoint::hide(void) {
	visible = false;
	SetPixel(hdc, x, y, RGB(0, 0, 255));
	SetPixel(hdc, x + 1, y, RGB(0, 0, 255));
	SetPixel(hdc, x, y + 1, RGB(0, 0, 255));
	SetPixel(hdc, x + 1, y + 1, RGB(0, 0, 255));
}

bool VPoint::isVisible(void) { return visible; };

void VPoint::moveTo(int newX, int newY) {
	hide();
	x = newX;
	y = newY;
	show();
};

void VPoint::drug(const int& shift) {
	if (KEY_DOWN(VK_DOWN))
		moveTo(x, y + shift);
	if (KEY_DOWN(VK_UP))
		moveTo(x, y - shift);
	if (KEY_DOWN(VK_RIGHT))
		moveTo(x + shift, y);
	if (KEY_DOWN(VK_LEFT))
		moveTo(x - shift, y);
}

VGlass::VGlass(int initX, int initY, int initHeight, int initWidth) : VPoint(initX, initY) {
	height = initHeight;
	width = initWidth;
}

VGlass::~VGlass(void) { };

void VGlass::show(void) {
	visible = true;
	Image::glassShow(hdc, x, y);
}

void VGlass::hide(void) {
	visible = false;
	Image::glassHide(hdc, x, y);
}

void VGlass::moveTo(int newX, int newY) {
	hide();
	x = newX;
	y = newY;
	show();
}

void VGlass::drug(const int& shift) {
	if (KEY_DOWN(VK_DOWN))
		moveTo(x, y + shift);
	if (KEY_DOWN(VK_UP))
		moveTo(x, y - shift);
	if (KEY_DOWN(VK_RIGHT))
		moveTo(x + shift, y);
	if (KEY_DOWN(VK_LEFT))
		moveTo(x - shift, y);
}

void VGlass::expand(int deltaHeight, int deltaWidth) {
	hide();
	height += deltaHeight;
	width += deltaWidth;
	if (deltaHeight < 0) height = 5;
	if (deltaWidth < 0) width = 5;
	show();
}

void VGlass::reduce(int deltaHeight, int deltaWidth) {
	expand(-deltaHeight, -deltaWidth);
}