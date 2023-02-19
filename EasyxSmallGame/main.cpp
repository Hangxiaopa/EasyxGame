# include <stdio.h>
# include <iostream>
# include <time.h>
# include <conio.h>
# include <graphics.h>
# include <stdlib.h>
using namespace std;
HWND hWnd;

void Start() {

	hWnd = initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	SetWindowText(hWnd, L"HXP Game");
	srand(time(0));
	setcolor(GREEN);
	setfillcolor(GREEN);
	return;
}

int GetRandNumber(int low, int high) {
	return (rand() % (high - low) + low);
}

int juedui(int x) {
	return x > 0 ? x : x * -1;
}

int main() {

	Start();
	char Input;
	int x = 20, y = 20;
	int baox = 200, baoy = 200;
	int coins = 0;
	TCHAR n = L'0';
	while (1) {
		cleardevice();
		
		fillcircle(x, y, 20);
		fillrectangle(baox, baoy, baox + 30, baoy + 30);
		settextcolor(RED);
		outtextxy(240 ,0, n);
		Input = _getch();
		switch(Input){
			case 'a':
				x -= 10;
				break;
			case 'd':
				x += 10;
				break;
			case 'w':
				y -= 10;
				break;
			case 's':
				y += 10;
				break;
		}
		if (x < -20) x = -20;
		if (x > 660) x = 660;
		if (y < -20)y = -20;
		if (y > 500)y = 500;
		if (juedui(x - baox) < 30 && juedui(y - baoy) < 30) {
			coins++;
			n++;
			baox = GetRandNumber(100, 500);
			baoy = GetRandNumber(100, 450);
			if (coins == 10) {
				MessageBox(hWnd, L"You Win!", L"You Win!", MB_OK);
				closegraph();
				return 0;
			}
		}

	}
	return 0;
}