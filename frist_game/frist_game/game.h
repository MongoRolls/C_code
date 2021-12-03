#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#define ROW 3
#define COL 3
	//函数的声明
//初始化棋盘
	void IntiBoard(char board[ROW][COL],int row,int col);
		//打印棋盘情况
	void DisplayBoard(char board[ROW][COL],int row,int col);
	   //玩家走
		void GamerMove(char board[ROW][COL],int row,int col);
		//电脑走
		void ComputerMove(char board[ROW][COL],int row,int col);
		//判定
		char judge(char board[ROW][COL],int row,int col);