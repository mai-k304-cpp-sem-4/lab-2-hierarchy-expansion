#pragma once    
#include <windows.h>
#include <conio.h>
#include <iostream>    
using namespace std;
#include "Point.h"
#include "GetConlWin.h"
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

HDC hdc;
void main() {
	setlocale(LC_ALL, "ru");
	cout << "Введите размер шага: ";
	int shift;
	cin >> shift;
	int deltaHeight = 60;
	int deltaWidth = 60;
	cout << "Для выхода нажмите на 1";
	int x0 = 130, y0 = 250; // Начальные координаты
	HWND hwnd = GetConcolWindow();
	if (hwnd != NULL) {
		hdc = GetWindowDC(hwnd);
		if (hdc != 0) {
			VGlass BGlass(x0, y0);
			BGlass.expand(deltaHeight, deltaWidth);
			BGlass.show();
			while (!KEY_DOWN(49)) {
				BGlass.drug(shift);
			}
		}
	}
}