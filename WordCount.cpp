#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int CountW(char *file)//�����ļ��ʵ���Ŀ 
{  
	FILE *fp;
    char buffer[5000];
    char c;
    int bufferlen=0;
    int LastComma = 0; // �ϸ��ַ��Ƿ��ǿո�򶺺�(1��ʾ��  0��ʾ����)
    int WordCount=0;
    int i;
    if((fp=fopen(file,"r"))==NULL)
	{
        printf("�ļ����ܴ�\n");
        exit(0);
    }
	while(fgets(buffer,1000,fp)!=NULL)
	{	
        bufferlen=strlen(buffer);
        for(i=0;i<bufferlen;i++)
		{
            c=buffer[i];
            if(c==' ' ||c==',')
			{
                if(LastComma==0)
				{
                    WordCount++;
                }
                LastComma=1;
            }
			else if(c!='\n'&&c!='\r')
			{
                LastComma=0;
            }
 
        } 
        if(LastComma==0)
            WordCount++;
        LastComma=1;
    }
    fclose(fp); 
		printf("WordNum��%d\n",WordCount);                     	
}
int CountC(char *file) //�����ļ����ַ��� 
	{   
		FILE *fp;
		int CharCount=0;
    	fp = fopen(file, "r");
    	char a;
    	if(NULL==(fp=fopen(file,"r")))
    		{
        		printf("�ļ�Ϊ��");
    		}
    	while (!feof(fp))
    		{
        		a=fgetc(fp);
                	CharCount++;
    		}
    		
    	fclose(fp);
		printf("CharNum:%d ",CharCount-1);//��ҵ��û��˵�� �س���'\r' ���ַ��� �����Լ�ȥ�س����������ַ� 
	}
	
int main(int argc, char* argv[])             
{
    FILE *fp;
    while(1)
    {
    	if(strcmp(argv[1],"-h")&&strcmp(argv[1],"-w")&&strcmp(argv[1],"-c"))
    		{
            	printf("û�иù���\n!��ʾ!\n-w ������������\n-c �����ַ�����\n"); 
            	return 0;
    		}
		if(!strcmp(argv[1],"-h"))
    		{
		    	printf("\n-w ������������\n-c �����ַ�����\n");
		    	return 0;
			}
        if((fp=fopen(argv[2],"r"))==NULL)
        	{  
        		printf("û�и��ļ�\n\n\n");
        		scanf("%s%s%s",argv[0],argv[1],argv[2]);
        		continue;
        	}
        else if(!strcmp(argv[1],"-w")) 
        	{ 
        		CountW(argv[2]);                
        	} 
		else if(!strcmp(argv[1],"-c"))  
        	{ 
				CountC(argv[2]);     
        	} 
		printf("\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
    }
    return 0;
}
