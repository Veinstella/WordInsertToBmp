#include "WordInsertToBmp.h"
#include <JFC.h>
#include <iostream>

using namespace std;

int main(){   
	JYXInit();
	//��ʼ��WordInsertToBmp��
	WordInsertToBmp text; 
	char* szGBK="��a�ǲ�\n��123";
	//����WordToBmp
	text.wordToBmp(szGBK,14,255,0,255);
	const char * bmpName=text.getOutputBitmapName();
	int bmpWidth=text.getBitmapWidth();
	int bmpHeight=text.getBitmapHeight();
	cout<<"bmpName="<<bmpName<<endl;
	cout<<"bmpWidth="<<bmpWidth<<endl;
	cout<<"bmpHeight="<<bmpHeight<<endl;
	system("pause");  
	JYXExit();
}