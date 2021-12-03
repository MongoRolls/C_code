#include "game.h"
//打印出一个菜单
void menu()
{
	printf("*************************************************\n");
	printf("****************输入1来开始游戏*****************\n");		
	printf("****************输入0来退出游戏*****************\n");
	printf("*************************************************\n");
	printf("请输入数字----->");
}
void game()
{   
	char board[ROW][COL],result;
	//初始化棋盘棋子为空
	IntiBoard(board,ROW,COL);
	//打印棋盘情况
	DisplayBoard(board,ROW,COL);
	while(1)
	{
		//玩家走
		GamerMove(board,ROW,COL);
		judge(board,ROW,COL);
		//判定
		result=judge(board,ROW,COL);
		if( result=='*'){printf("电脑赢了");break;}
		if( result=='#'){printf("玩家赢了");break;}
		if(result=='c' ){}//删掉continue
		if(result==0) printf("平局了");
		//电脑走
		ComputerMove(board,ROW,COL);
		//判定游戏进程和胜利
		judge(board,ROW,COL);
		result=judge(board,ROW,COL);
		if( result=='*'){printf("电脑赢了");break;}
		if( result=='#'){printf("玩家赢了");break;}
		if(result=='c' ){continue;}
		if(result==0) printf("平局了");
	}
}


int main()
{   
	int input;
	do{
		menu();
		scanf_s("%d",&input);
		switch(input)
		{
		case 1:
			printf("进入井字棋游戏");
			game();
			goto end;
		case 0:
			printf("退出游戏\n");
			goto end;
		default:
			printf("输入错误,请重新选择\n");
		}
	}while(1);

end: return 0;
}
