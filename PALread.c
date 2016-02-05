#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*仙剑读心术2.0版 by Shannon Zhang
  共128个人物
  程序设计完工日期2016-02-05
  问题设计完工日期2016-02-?? 
  1+2+4+8+16+32+64=127个问题
  人物位置：Role.txt 
  问题位置：Question.txt 
*/

void boom()
{
	printf("都说了别瞎按，你咋就不听呢\n");
	printf("读心术选择爆炸，BOOM！\n");
	system("pause");
	exit(1);
}

//从文件p中接收第n行字符串，保存在str中 
char *getfileline(char *p,int n, char *str){
	FILE *fp;
	int i;
	//打不开文件，NULL
	if ((fp=fopen(p,"r"))==NULL){
		printf("ERROR!未能正确打开文件\n");
		return NULL;
	}
	//文件不足n行，NULL
	//假设一行不超过200字符
	for(i=1;i<n;i++)
		if ((fgets(str,200,fp))==NULL) {
			fclose(fp);
			return NULL;
		}
	//如果获得正常数据，返回str地址
	fgets(str,200,fp);
	fclose(fp);
	return str;
}

int main(){
	int choice;
	int m;//循环变量 
	int r=1;//人物编号 
	int q=1;//问题编号 
	char p[200];//容纳文本的字符数组 
	
	printf("***********************************************\n");
	printf("----------并不靠谱的仙剑读心术 2.0版-----------\n");
	printf("  按1开始读心术\n  按2退出\n  别瞎按\n");
	scanf("%d",&choice);
	if((choice==1)||(choice==2)){
		switch(choice){
			case 1:;break; 
			case 2:exit(1);
		}		
	}
	else{
		boom();	
	}

	for(m=1;m<8;m++){
		printf("第 %d 个问题：\n",m);
		getfileline("Question.txt", q, p);
		puts(p);
		printf("请输入1（是）或0（不是）\n");
		scanf("%d",&choice);
		if((choice==1)||(choice==0)){
			switch(choice){
				case 1:{
					q = q*2+1;
					r = r+pow(2,7-m);
					break; 
				}
				case 0:{
					q = q*2;
					break; 
				}
			default:boom(); 
			}		
		}
	}
	
	printf("下面是见证奇迹的时刻，我猜你想的是：\n");
	getfileline("Role.txt", r, p);//文件地址，需要抓第几行，一次最多抓多少字符 
	puts(p);//输出所抓字符数组
	printf("谢谢使用，欢迎再来~\n");
	main();
}
