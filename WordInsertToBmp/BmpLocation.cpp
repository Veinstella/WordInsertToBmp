#include <JFC.h>
#include "BmpLocation.h"


JYX_BEGIN_DYNAMIC(BmpLocation,CJObject)
JYX_END_DYNAMIC(CJObject)

BmpLocation::BmpLocation()
{
	
}
BmpLocation::BmpLocation(unsigned short word,FT_Bitmap & bitmap,int font_size)
{
	m_word=word;
	m_bitmap=bitmap;
	m_fontSize=font_size;
}

BmpLocation::~BmpLocation()
{

}

void BmpLocation::setWord(unsigned short word)
{
	m_word=word;
}

void BmpLocation::setBitmap(FT_Bitmap &bitmap)
{
	m_bitmap = bitmap;
}

unsigned short BmpLocation::getWord() const
{
	return m_word;
}

FT_Bitmap BmpLocation::getBitmap() const
{
	return m_bitmap;
}

void BmpLocation::setFontSize(int fontSize)
{
	m_fontSize=fontSize;
}

int BmpLocation::getFontSize() const
{
	return m_fontSize;
}