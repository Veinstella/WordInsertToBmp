#ifndef __BMPLOCATION_H__
#define __BMPLOCATION_H__

#include <ft2build.h>
#include FT_FREETYPE_H
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <JFC.h>

class BmpLocation : public CJObject
{
	JYX_DECLARE_DYNAMIC();
private:
	unsigned short m_word;
	FT_Bitmap m_bitmap;
	int m_fontSize;
public:
	BmpLocation();
	BmpLocation(unsigned short word,FT_Bitmap &bitmap,int fontSize);
	void setWord(unsigned short word);
	unsigned short  getWord() const;
	void setBitmap(FT_Bitmap &bitmap);
	FT_Bitmap getBitmap() const;
	void setFontSize(int font_size);
	int getFontSize()const;
	virtual ~BmpLocation();
	
};
#endif