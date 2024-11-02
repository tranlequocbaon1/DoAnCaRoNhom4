#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "header.h"




void TimerCountDown() {
	int  time = 30;

	while (time > 0) {
		for (int i = 0; i < 10; ++i) {
			if (_kbhit()) {
				char key = _getch();
				if (key == '\r') {
					time = 30;
					break;
				}
			}
			Sleep(100); // Ngủ 0.1 giây
		}
		GotoXY(100, 2);
		std::cout << time;
		time--;
	}
}