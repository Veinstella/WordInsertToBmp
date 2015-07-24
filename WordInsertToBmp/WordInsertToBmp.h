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
	WORD bfType;//文件类型，必须是0x424D，即字符“BM”   
	DWORD bfSize;//文件大小   
	WORD bfReserved1;//保留字   
	WORD bfReserved2;//保留字   
	DWORD bfOffBits;//从文件头到实际位图数据的偏移字节数   
}BITMAPFILEHEADER;  

typedef struct tagBITMAPINFOHEADER{  
	DWORD biSize;//信息头大小   
	LONG biWidth;//图像宽度   
	LONG biHeight;//图像高度   
	WORD biPlanes;//位平面数，必须为1   
	WORD biBitCount;//每像素位数   
	DWORD  biCompression; //压缩类型   
	DWORD  biSizeImage; //压缩图像大小字节数   
	LONG  biXPelsPerMeter; //水平分辨率   
	LONG  biYPelsPerMeter; //垂直分辨率   
	DWORD  biClrUsed; //位图实际用到的色彩数   
	DWORD  biClrImportant; //本位图中重要的色彩数   
}BITMAPINFOHEADER; //位图信息头定义   
*/
class WordInsertToBmp
{
private:
	BITMAPFILEHEADER strHead;    
	BITMAPINFOHEADER strInfo;
	CJList * m_list;//链表存储字体位图
	int m_bmpWidth;//需要存储的Bmp图片的宽度，默认初始化为0
	int m_bmpHeight;//需要存储的Bmp图片的高度,默认初始化为72像素
	char * m_bmpName;//图片名字
	char * m_fontLocation;//字体路径
public:
	WordInsertToBmp();
	~WordInsertToBmp();
	/**
	*@brief 字体嵌入，输出一张所需的字体图片
	*@param szGBK 需要嵌入的字符串
	*@param font_size 字符串中每个字体的大小5-72
	*@param red 字体的红色分量，应为0-255之间
	*@param green 字体的绿色分量，应为0-255之间
	*@param blue 字体的蓝色分量，应为0-255之间
	*@return 0 成功
	*@return -1 失败 
	*/
	int wordToBmp(char* szGBK,int font_size,unsigned char red,unsigned char green,unsigned char blue);
	//GBK转unicode
	int gbk2UnicodeConvert(const char *szGbk,int inlen,unsigned short *szUnicode,int *outlen);
	//显示位图文件头信息   
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