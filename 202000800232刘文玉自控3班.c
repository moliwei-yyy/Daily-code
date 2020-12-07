#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h> 
#include<conio.h>
#include<math.h>
int snake[10][2] = { 0 };
int snake_tail[10][2] = { 0 };
int apple[2];
int len = 3;
int score = 0;
char ch = '0';

void gotoxy(int x, int y)
{
	COORD p;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	p.X = 2 * x; p.Y = y;
	SetConsoleCursorPosition(handle, p);
}//光标坐标函数
void color(int a)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}//颜色函数
void wall_info() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	int wall[23][23] = { 0 };
	int i, j, k, m;
	for (i = 1; i <= 21 && i >= 1; i++) {
		for (j = 1; j <= 21 && j >= 1; j++)
			wall[i][j] = 1;
	}
	for (k = 0; k >= 0 && k <= 22; k++) {
		for (m = 0; m >= 0 && m <= 22; m++) {
			color(11);
			if (wall[k][m] == 1) printf("■");
			else printf("□");
		}
		printf("\n");
	}
	color(14);
	gotoxy(24, 3);
	printf("学号：202000800232 姓名：刘文玉");
	gotoxy(24, 5);
	printf("按 W A S D移动方向");
	gotoxy(24, 7);
	printf("按任意键暂停");
	gotoxy(24, 9);
	printf("得分：");
	
 	color(14);
	gotoxy(29, 9);
	printf("%d", score);
	gotoxy(29, 29);


}//初始化地图
void snake_apple() {

	int i;
	srand(time(NULL));
	for (i = 0; i < 2; ++i) {
		apple[i] = rand() % 21 + 1;
	}
	color(12);
	gotoxy(apple[0], apple[1]);
	printf("●");


	snake[0][0] = 10;
	snake[0][1] = 10;
	gotoxy(snake[0][0], snake[0][1]);
	color(14);
	printf("¤");

	snake[1][0] = snake[0][0];
	snake[1][1] = snake[0][1] + 1;
	gotoxy(snake[1][0], snake[1][1]);
	printf("★");
	snake[2][0] = snake[1][0];
	snake[2][1] = snake[1][1] + 1;
	gotoxy(snake[2][0], snake[2][1]);
	printf("★");
}//初始化苹果与蛇
void movesnake()
{
	int i;
	int score = 0;

	for (i = 0; i < 10; i++)
	{
		snake_tail[i][0] = snake[i][0];
		snake_tail[i][1] = snake[i][1];
	}

	if (_kbhit())
	{
		ch = _getch();
	}
	switch (ch)
	{
	case 'w':snake[0][1]--; break;
	case 's':snake[0][1]++; break;
	case 'a':snake[0][0]--; break;
	case 'd':snake[0][0]++; break;
	default:
		return;

	}
	gotoxy(snake[0][0], snake[0][1]);
	color(14);
	printf("¤");

	for (i = 1; i < len; i++)
	{
		snake[i][0] = snake_tail[i - 1][0];
		snake[i][1] = snake_tail[i - 1][1];
		gotoxy(snake[i][0], snake[i][1]);
		color(14);
		printf("★");
		gotoxy(snake[i + 1][0], snake[i + 1][1]);
		color(11);
		printf("■");


	}
	if (len == 10) {
		gotoxy(snake[1][0], snake[1][1]);
		color(14);
		printf("★");

	}
	gotoxy(0, 0);
	color(11);
	printf("□");




	Sleep(fabs(200 - 0.5 * score));
}
void eat_apple() {

	score++;
	len++;
	if (len > 10) {
		len = 10;
	}
	int i;
	for (i = 0; i < 2; ++i) {
		apple[i] = rand() % 21 + 1;
		srand(time(NULL));
	}
	color(12);
	gotoxy(apple[0], apple[1]);
	printf("●");
    color(14);
	gotoxy(29, 9);
	printf("%d", score);
}

int if_wall() {
	if (snake[0][0] == 0 || snake[0][1] == 0 || snake[0][0] == 22 || snake[0][1] == 22) {
		gotoxy(10, 10);
		color(14);
		printf("游戏失败!!");

		Sleep(INFINITE);
		return 1;
	}
	else return 0;

}




int main() {
	wall_info();

	snake_apple();


	while (1) {
		movesnake();

		if (snake[0][0] == apple[0] && snake[0][1] == apple[1]) {
			eat_apple();
		}
		
		if (if_wall()) break;
		if(score >= 10){
			gotoxy(10,10);
			color(14);
			printf("恭喜通关！！！"); 
			gotoxy(23,23);
			break;
		}

	}
	return 0;

}
