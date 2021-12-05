/*
编写一个C程序，实现以下功能：
输入n个人的身高，然后从n个人中选出身高差值最小的两个人作为礼仪
（如果差值相同的话，选取其中最高的两个人），要求输出两个礼仪的身高。
   5 170 170 185 160 155
*/
#include <stdio.h>
int main()
{
	int i,n,temp,k=1;//
	float h,maxH=0,maxH1=0,maxH2=0;
	int height[2200]={0};
	printf("请输入有多少个人\n");
	scanf_s("%d",&n);
	printf("请输入这些人的身高(单位为cm,精确到0.1cm,身高不能超过220cm)\n");
	for(i=0;i<n;i++)
	{
		scanf_s("%f",&h);
		temp=(int)h*10;
		height[temp]++;
		h=0;
	}
	//printf("%d",height[1700]);
	//检查身高是否有相同的
	for(i=0;i<2200;i++)
	{
		if(height[i]>1){maxH=(float)i;}
	}
	if(maxH!=0){printf("%.1f\n",maxH/10);goto end;}
	
	//身高不一致的
	while(1)
	{
		for(i=0;i<2200;i++)
		{
			if(height[i]!=0&&height[i+k]!=0)
			{
			maxH1=(float)i;
			maxH2=(float)(i+k);
			}
			if(maxH1!=0&&maxH2!=0){printf("%.1f %.1f \n",maxH1/10,maxH2/10);goto end;}
		}
		k++;
	}
	end:
	return 0;
}