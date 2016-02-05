# PAL-read-your-mind
基于决策树的、采用C语言编制的读心术小程序，共包含仙剑奇侠传128个角色，范围包括仙一到仙六
程序设计：
完成于2016-02-05
函数：
void boom() 对输入字符进行查错，若不符合要求则报错，退出程序
char *getfileline(char *p,int n, char *str) 从文件p中接收第n行字符串，保存在str中
int main() 主函数，包括获得问题编号、人物编号的语句
