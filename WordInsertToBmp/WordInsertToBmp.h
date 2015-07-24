#pragma once
#ifndef __WORDINSERTTOBMP_H__
#define __WORDINSERTTOBMP_H__

#include <ft2build.h>
#include FT_FREETYPE_H
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include "BmpLocation.h"
#include <JFC.h>

typedef unsigned char BYTE;  
typedef unsigned short WORD;  
//typedef unsigned int DWORD;  
typedef long LONG;

typedef struct tagIMAGEDATA  
{  
	BYTE blue;  
	BYTE green;  
	BYTE red;  
}IMAGEDATA;   

/*typedef struct  tagBITMAPFILEHEADER{  
	WORD bfType;//�ļ����ͣ�������0x424D�����ַ���BM��   
	DWORD bfSize;//�ļ���С   
	WORD bfReserved1;//������   
	WORD bfReserved2;//������   
	DWORD bfOffBits;//���ļ�ͷ��ʵ��λͼ���ݵ�ƫ���ֽ���   
}BITMAPFILEHEADER;  

typedef struct tagBITMAPINFOHEADER{  
	DWORD biSize;//��Ϣͷ��С   
	LONG biWidth;//ͼ����   
	LONG biHeight;//ͼ��߶�   
	WORD biPlanes;//λƽ����������Ϊ1   
	WORD biBitCount;//ÿ����λ��   
	DWORD  biCompression; //ѹ������   
	DWORD  biSizeImage; //ѹ��ͼ���С�ֽ���   
	LONG  biXPelsPerMeter; //ˮƽ�ֱ���   
	LONG  biYPelsPerMeter; //��ֱ�ֱ���   
	DWORD  biClrUsed; //λͼʵ���õ���ɫ����   
	DWORD  biClrImportant; //��λͼ����Ҫ��ɫ����   
}BITMAPINFOHEADER; //λͼ��Ϣͷ����   
*/
class WordInsertToBmp
{
private:
	BITMAPFILEHEADER strHead;    
	BITMAPINFOHEADER strInfo;
	CJList * m_list;//����洢����λͼ
	int m_bmpWidth;//��Ҫ�洢��BmpͼƬ�Ŀ�ȣ�Ĭ�ϳ�ʼ��Ϊ0
	int m_bmpHeight;//��Ҫ�洢��BmpͼƬ�ĸ߶�,Ĭ�ϳ�ʼ��Ϊ72����
	char * m_bmpName;//ͼƬ����
	char * m_fontLocation;//����·��
public:
	WordInsertToBmp();
	~WordInsertToBmp();
	/**
	*@brief ����Ƕ�룬���һ�����������ͼƬ
	*@param szGBK ��ҪǶ����ַ���
	*@param font_size �ַ�����ÿ������Ĵ�С5-72
	*@param red ����ĺ�ɫ������ӦΪ0-255֮��
	*@param green �������ɫ������ӦΪ0-255֮��
	*@param blue �������ɫ������ӦΪ0-255֮��
	*@return 0 �ɹ�
	*@return -1 ʧ�� 
	*/
	int wordToBmp(char* szGBK,int font_size,unsigned char red,unsigned char green,unsigned char blue);
	//GBKתunicode
	int gbk2UnicodeConvert(const char *szGbk,int inlen,unsigned short *szUnicode,int *outlen);
	//��ʾλͼ�ļ�ͷ��Ϣ   
	void showBmpHead(BITMAPFILEHEADER pBmpHead) const;
	void showBmpInforHead(tagBITMAPINFOHEADER pBmpInforHead) const;
	BITMAPFILEHEADER getBitmapFileHead() const;
	BITMAPINFOHEADER getBitmapInfoHead() const;
	int getBitmapWidth() const;
	int getBitmapHeight()const;
	void setOutputBitmapName(char * bmpName);
	const char * getOutputBitmapName()const;
	void setFontLocation(char* fontLocation);
	const char * getFontLocation() const;
};


#endif