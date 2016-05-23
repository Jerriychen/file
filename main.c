#include<stdio.h>
#include<string.h>
#define MaxStrSize 256

typedef struct {
    char ch[MaxStrSize]; //ch是一个可容纳256个字符的字符数组
    int length;
} SString;//定义顺序串类型

void CreatTextFile();
void SubStrCount();
void SubStrInd();
void line();

int main()
{
int n;
 do {
       printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
       printf("              1.     建立文本文件                \n");
       printf("              2.     单词字串的计数              \n");
       printf("              3.     单词字串的定位              \n");
       printf("              4.     文章行数                    \n");
       printf("              5.     退出整个程序                \n");
       printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
       printf("请选择(1--5):");
       scanf("%d",&n);
       switch(n)
       {
         case 1 : CreatTextFile();break;
         case 2 : SubStrCount();break;
         case 3 : SubStrInd();break;
         case 4 : line();break;
         case 5 : return 0;
         default:printf("选择错误，重新选 \n");
        }
    }while(1);
}


int PartPosition (SString s1,SString s2,int k)
{
    int i,j;
    i=k-1;          //扫描s1的下标，因为c中数组下标是从0开始，串中序号相差1
    j=0;            //扫描s2的开始下标
    while(i<s1.length && j<s2.length)
    {
        if(s1.ch[i]==s2.ch[j])
        {i++;j++;}  //继续使下标移向下一个字符位置
       else
        {i=i-j+1;j=0;}
    }
   if (j>=s2.length)
      return i-s2.length;
   else
      return -1;//表示s1中不存在s2，返回-1
      //表示s1中存在s2，返回其起始位置
} //函数结束

void CreatTextFile()
{
    SString S;
    char fname[10],yn;
    FILE *fp;
    printf("输入要建立的文件名：");
    scanf("%s",fname);
    fp=fopen(fname,"w");
    yn='n';//输入结束标志初值
    while(yn=='n'||yn=='N')
    {
        printf("请输入一行文本：");
        gets(S.ch);
        gets(S.ch);
        S.length=strlen(S.ch);
        fwrite(&S,S.length,1,fp);
        fprintf(fp,"%c",10);//是输入换行
        printf("结束输入吗？( Y or N ) ：");
        yn=getchar();
    }
    fclose(fp);
    printf("建立文件结束!\n\n");
}

void SubStrCount()            //统计单词出现的个数
{
    FILE *fp;
    SString S,T;//定义两个串变量
    char fname[10];
    int i=0,j,k;
    printf("输入文本文件名：");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    printf("输入要统计计数的单词：");
    scanf("%s",T.ch);
    T.length=strlen(T.ch);
    while(!feof(fp))
    {   //扫描整个文本文件
        // fread(&S.ch,1,sizeof(S),fp);//读入一行文本
       memset(S.ch,'\0',256);
       fgets(S.ch,100,fp);
       S.length=strlen(S.ch);
       k=0; //初始化开始检索位置
       while(k<S.length-1) //检索整个主串S
       {
       j=PartPosition(S,T,k);//调用串匹配函数
       if(j<0 ) break;
       else {
              i++;//单词计数器加1
              k=j+T.length;//继续下一字串的检索
            }
        }
    }
    printf("单词%s在文本文件%s中共出现%d次\n\n",T.ch,fname,i);
}


void SubStrInd()            //检索单词出现在文本文件中的行号、次数及其位置
{
    FILE *fp;
    SString S,T; //定义两个串变量
    char fname[10];
    int i,j,k,l,m;
    int wz[20]; //存放一行中字串匹配的多个位置
    printf("输入文本文件名：");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    printf("输入要检索的单词：");
    scanf("%s",T.ch);
    T.length=strlen(T.ch);
    l=0; //行计数器置0

    while(!feof(fp))
    { //扫描整个文本文件
        memset(S.ch,'\0',256);
        fgets(S.ch,256,fp);
        S.length=strlen(S.ch);
        l++; //行计数器自增1
        k=0;//初始化开始检索位置
        i=0; //初始化单词计数器
        while(k<S.length-1) //检索整个主串S
            {
            j=PartPosition(S,T,k); //调用串匹配函数
            if(j<0) break;
            else  {
                   i++;//单词计数器加1
                   wz[i]=j;//记录匹配单词位置
                   k=j+T.length;}//继续下一字串检索
            }
       if(i>0)
        {
         printf("行号：%d,次数：%d,位置为：",l,i);
         for(m=1;m<=i;m++)
             printf("%2d ",wz[m]+1);
         printf("\n");
        }
     }
     printf("\n");
}

void line()
{
    FILE *fp;
    SString S; //定义两个串变量
    char fname[10];
    int l;
    printf("输入文本文件名：");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    l=0; //行计数器置0

    while(!feof(fp))
    {
        fgets(S.ch,256,fp);
        l++; //行计数器自增1
    }
    printf("文章行数为:%2d\n\n",l);
}


