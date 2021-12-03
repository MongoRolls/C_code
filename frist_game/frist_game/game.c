#include"game.h"
//初始化棋盘棋子为空
void IntiBoard(char board[ROW][COL],int row,int col)
{   int i,j;
for(i=0;i<ROW;i++)
{   
	for(j=0;j<COL;j++)
	{
		board[i][j]=' ';
	}
}
}
//打印棋盘情况
void DisplayBoard(char board[ROW][COL],int row,int col)
{  
	int i; 
	printf("\n");
	for(i=0;i<row;i++)
	{
		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);	
		if(i<ROW-1)printf("---|---|---\n");

	}
}
//玩家走
void GamerMove(char board[ROW][COL],int row,int col)
{   
	int i,j;
	while(1)
	{
		printf("玩家走,请输入一个坐标---->");
		scanf_s("%d %d",&i,&j);

		if(i>3||i<1||j>3||j<1)//防止填到外面去了
		{
			printf("输入错误的坐标,请重新选择");
		}
		else if(board[i-1][j-1]=='#'||board[i-1][j-1]=='*'){printf("输入了重复的坐标");}
		else
		{
			board[i-1][j-1]='#';
			DisplayBoard(board,ROW,COL);
			break;
		}

	}
}

//电脑走
void ComputerMove(char board[ROW][COL],int row,int col)
{
	int i,j;
	printf("电脑走");
	while(1)
	{
		srand((unsigned)time(NULL));
		//随机数,
		i=rand()%row;
		Sleep(60);
		j=rand()%col;//随机数

		if(board[i][j]=='*'||board[i][j]=='#'){}//防止填到外面去了
		else
		{
			board[i][j]='*';
			DisplayBoard(board,ROW,COL);
			break;
		}
	}

}
//判定
char judge(char board[ROW][COL],int row,int col)
{   
	int i,j;
	//3个相同横的
	for(i=0;i<ROW;i++)
	{if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]){return board[i][0];}}
	//3个相同竖的
	for(j=0;j<ROW;j++)
	{if(board[0][j]==board[1][j]&&board[2][j]==board[1][j]){return board[0][j];}}
	//3个相同斜着的
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]){return board[1][1];}
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]){return board[1][1];}
	//检查是否还有空格的地方
	for(i=0;i<ROW;i++)
	{   
		for(j=0;j<COL;j++)
		{
			if(board[i][j]==' ')return 'c';//有空游戏继续
		}
	}
	return 0;

}

