#include "displayprogram.h"
#include "Innercirkel.h"
#include "Yttercirkel.h"
#include "Rektangel.h"

Rektangel::Rektangel(Canvas & cv, int ulx,int uly, int width,int height, Colorf cf): _cv(&cv), c1(this, cv, 10, 10, 10, Colorf(0,255,0,255))
	{
		_ulx = ulx;
		_uly = uly;
		_width = width;
		_height = height;
		_cf = cf;
	}

void Rektangel::setc2p(Yttercirkel * cp2)
{
	_cp2 = Pointf(cp2->getc()); //Lagrar den yttre cirkelns mittpunkt
}

void Rektangel::update()
{
	_width = int(_lrPoint.x - _ulPoint.x);
	_height = int(_lrPoint.y - _ulPoint.y);
	//Lagrar rektangelns mittpunkt
	_rektCp.x = _lrPoint.x - (_width/2);
	_rektCp.y = _lrPoint.y - (_height/2);
}

void Rektangel::draw(Font & font)
{
	//Ser till att nedre högra punkten inte är ovanför eller till vänster om den övre vänstra punkten
	if(_ulPoint.x < _lrPoint.x && _ulPoint.y < _lrPoint.y)
	{
		_cv->fill_rect(_ulPoint, _lrPoint, _cf);
		_cv->draw_line(_rektCp, _cp2, Colorf(255,255,255,255));

		_rektText = Pointf(_ulPoint.x, (_lrPoint.y + 25));
		_text << "Omkrets = " << omkrets() << ", Area = " << area();
		font.draw_text(*_cv, _rektText, _text.str(), Colorf(0,0,0,1));

		c1.update();
		c1.draw(font);
	}
}
void Rektangel::setul(int x, int y)
{
	_ulPoint = Pointf(float(x), float(y));
}

void Rektangel::setlr(int x, int y)
{
	_lrPoint = Pointf(float(x), float(y));
	c1.set(int(_ulPoint.x), int(_ulPoint.y), _width, _height);
}

Pointf Rektangel::getul(){return _ulPoint;}
Pointf Rektangel::getlr(){return _lrPoint;}

int Rektangel::omkrets()
{
	int rektOmkrets = (_width + _height)*2;
	return rektOmkrets;
}

int Rektangel::area()
{
	int rektArea = _width*_height;
	return rektArea;
}