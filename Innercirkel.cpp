#include "math.h"
#include "displayprogram.h"
#include <time.h>
#include "Innercirkel.h"
#include "Yttercirkel.h"
#include "Rektangel.h"


Innercirkel::Innercirkel  (Rektangel* r,Canvas & cv, int cx,int cy, int rad, Colorf cf)
{
	_cv = &cv;
	_cx = cx;
	_cy = cy;
	_rad = rad;
	_cf = cf;
	srand(time(NULL));
	_hy = rand()%8+1;
	_hx = rand()%8+1;
	_pi = arctan(1)*4
}

void Innercirkel::update()
{
	cp.x += _hx;
	cp.y += _hy;

	//Hit test
	if(cp.y - _rad < rul.y)
		_hy = -_hy;
	if(cp.x - _rad < rul.x)
		_hx = -_hx;
	if(cp.y + _rad > rlr.y)
		_hy = -_hy;
	if(cp.x + _rad > rlr.x)
		_hx = -_hx;
}
void Innercirkel::draw(Font & font)
{
	_cv->fill_circle(cp.x, cp.y, _rad, _cf);
}

void Innercirkel::set(int x, int y, int width, int height)
{
	rul = Point(x,y);
	rlr = Point((x+width),(y+height));
	cp = Point(((rlr.x + rul.x)/2), ((rlr.y + rul.y)/2));
	if ((width) < (height))
		_rad = width/10;
	else
		_rad = height/10;
}