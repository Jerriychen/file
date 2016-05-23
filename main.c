#include<stdio.h>
#include<string.h>
#define MaxStrSize 256

typedef struct {
    char ch[MaxStrSize]; //ch��һ��������256���ַ����ַ�����
    int length;
} SString;//����˳������

void CreatTextFile();
void SubStrCount();
void SubStrInd();
void line();

int main()
{
int n;
 do {
       printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
       printf("              1.     �����ı��ļ�                \n");
       printf("              2.     �����ִ��ļ���              \n");
       printf("              3.     �����ִ��Ķ�λ              \n");
       printf("              4.     ��������                    \n");
       printf("              5.     �˳���������                \n");
       printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
       printf("��ѡ��(1--5):");
       scanf("%d",&n);
       switch(n)
       {
         case 1 : CreatTextFile();break;
         case 2 : SubStrCount();break;
         case 3 : SubStrInd();break;
         case 4 : line();break;
         case 5 : return 0;
         default:printf("ѡ���������ѡ \n");
        }
    }while(1);
}


int PartPosition (SString s1,SString s2,int k)
{
    int i,j;
    i=k-1;          //ɨ��s1���±꣬��Ϊc�������±��Ǵ�0��ʼ������������1
    j=0;            //ɨ��s2�Ŀ�ʼ�±�
    while(i<s1.length && j<s2.length)
    {
        if(s1.ch[i]==s2.ch[j])
        {i++;j++;}  //����ʹ�±�������һ���ַ�λ��
       else
        {i=i-j+1;j=0;}
    }
   if (j>=s2.length)
      return i-s2.length;
   else
      return -1;//��ʾs1�в�����s2������-1
      //��ʾs1�д���s2����������ʼλ��
} //��������

void CreatTextFile()
{
    SString S;
    char fname[10],yn;
    FILE *fp;
    printf("����Ҫ�������ļ�����");
    scanf("%s",fname);
    fp=fopen(fname,"w");
    yn='n';//���������־��ֵ
    while(yn=='n'||yn=='N')
    {
        printf("������һ���ı���");
        gets(S.ch);
        gets(S.ch);
        S.length=strlen(S.ch);
        fwrite(&S,S.length,1,fp);
        fprintf(fp,"%c",10);//�����뻻��
        printf("����������( Y or N ) ��");
        yn=getchar();
    }
    fclose(fp);
    printf("�����ļ�����!\n\n");
}

void SubStrCount()            //ͳ�Ƶ��ʳ��ֵĸ���
{
    FILE *fp;
    SString S,T;//��������������
    char fname[10];
    int i=0,j,k;
    printf("�����ı��ļ�����");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    printf("����Ҫͳ�Ƽ����ĵ��ʣ�");
    scanf("%s",T.ch);
    T.length=strlen(T.ch);
    while(!feof(fp))
    {   //ɨ�������ı��ļ�
        // fread(&S.ch,1,sizeof(S),fp);//����һ���ı�
       memset(S.ch,'\0',256);
       fgets(S.ch,100,fp);
       S.length=strlen(S.ch);
       k=0; //��ʼ����ʼ����λ��
       while(k<S.length-1) //������������S
       {
       j=PartPosition(S,T,k);//���ô�ƥ�亯��
       if(j<0 ) break;
       else {
              i++;//���ʼ�������1
              k=j+T.length;//������һ�ִ��ļ���
            }
        }
    }
    printf("����%s���ı��ļ�%s�й�����%d��\n\n",T.ch,fname,i);
}


void SubStrInd()            //�������ʳ������ı��ļ��е��кš���������λ��
{
    FILE *fp;
    SString S,T; //��������������
    char fname[10];
    int i,j,k,l,m;
    int wz[20]; //���һ�����ִ�ƥ��Ķ��λ��
    printf("�����ı��ļ�����");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    printf("����Ҫ�����ĵ��ʣ�");
    scanf("%s",T.ch);
    T.length=strlen(T.ch);
    l=0; //�м�������0

    while(!feof(fp))
    { //ɨ�������ı��ļ�
        memset(S.ch,'\0',256);
        fgets(S.ch,256,fp);
        S.length=strlen(S.ch);
        l++; //�м���������1
        k=0;//��ʼ����ʼ����λ��
        i=0; //��ʼ�����ʼ�����
        while(k<S.length-1) //������������S
            {
            j=PartPosition(S,T,k); //���ô�ƥ�亯��
            if(j<0) break;
            else  {
                   i++;//���ʼ�������1
                   wz[i]=j;//��¼ƥ�䵥��λ��
                   k=j+T.length;}//������һ�ִ�����
            }
       if(i>0)
        {
         printf("�кţ�%d,������%d,λ��Ϊ��",l,i);
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
    SString S; //��������������
    char fname[10];
    int l;
    printf("�����ı��ļ�����");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    l=0; //�м�������0

    while(!feof(fp))
    {
        fgets(S.ch,256,fp);
        l++; //�м���������1
    }
    printf("��������Ϊ:%2d\n\n",l);
}


