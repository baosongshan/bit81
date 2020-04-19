#include"Sysframe.h"

#define WIDTH 120
#define HEIGHT 30

/*
void SetCurPos(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {y, x};
	SetConsoleCursorPosition(handle, pos);
}

void DrawRow(int x, int y)
{
	for(int i=0; i<WIDTH-4; ++i)
	{
		SetCurPos(x, y+i);
		printf("=");
	}
}
void DrawCol(int x, int y)
{
	for(int i=0; i<HEIGHT; ++i)
	{
		SetCurPos(i, y);
		printf("||");
	}
}


void DrawFrame(char *title)
{
	//���ñ���
	char buffer[MAX_TITLE_BUFFER+5+1+1] = "title ";  //title=5 space=1 \0=1
	strcat(buffer, title);
	system(buffer);

	//���ÿͻ��˵Ŀ�Ⱥ͸߶�
	char mode[128] = {0};
	sprintf(mode, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(mode);

	//������ɫ
	system("color 0F");

	//���ƽ�����
	DrawCol(0, 0);
	DrawCol(0, WIDTH-2);

	DrawRow(0, 2);
	DrawRow(2, 2);
	DrawRow(4, 2);
	DrawRow(HEIGHT-4, 2);
	DrawRow(HEIGHT-2, 2);
}

void DrawMenu()
{
	//�ڿ�������������
}
*/

void SetCurPos(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(handle, pos);
} 

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 100, 0 };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor_info);
} 

void DrawCol(int x, int y)
{
	int i;
	for (i = 0; i < HEIGHT; ++i)
	{
		SetCurPos(x, y + i);
		printf("||");
	}
} 

void DrawRow(int x, int y)
{
	int i;
	for (i = 0; i < WIDTH - 4; ++i)
	{
		SetCurPos(x + i, y);
		printf("=");
	}
} 

void DrawFrame(char *title)
{
	char buffer[MAX_TITLE_SIZE + 6 + 1] = "title "; //6:title%20 1:\0
	strcat(buffer, title);
	system(buffer); //����ϵͳ����
	char mode[128] = { 0 };
	sprintf(mode, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(mode); //���ÿ���̨�ĳ��ȺͿ��
	system("color 0F");//������ɫ
	DrawCol(0, 0);
	DrawCol(WIDTH - 2, 0);
	DrawRow(2, 0);
	DrawRow(2, 2);
	DrawRow(2, 4);
	DrawRow(2, HEIGHT - 4);
	DrawRow(2, HEIGHT - 2);
} 

void SystemEnd()
{
	SetCurPos((WIDTH-4-strlen("�밴���������. . ."))/2, HEIGHT - 1);
} 

extern char *title;
void DrawMenu()
{
	//�����Լ����������ʵ��
	//���������
	SetCurPos((WIDTH - 4 - strlen(title)) / 2, 1);
	printf("%s", title);

	//���� ·��
	SetCurPos(2, 3);
	printf("%-30s %-85s", "����", "·��");

	//�˳�����
	SetCurPos((WIDTH - 4 - strlen("exit �˳�ϵͳ .")) / 2, HEIGHT - 3);
	printf("%s", "exit �˳�ϵͳ .");
	DrawRow(2, HEIGHT - 6);

	//SetCurPos((WIDTH-4-strlen("������:>"))/2, 15);
	SetCurPos(2, HEIGHT - 5);
	printf("%s", "������:>");
}