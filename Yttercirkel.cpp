#include "displayprogram.h"
#include<time.h>
#include"Innercirkel.h"
#include"Yttercirkel.h"
#include "Rektangel.h"

    Yttercirkel::Yttercirkel(Rektangel* r,Canvas & cv, int cx,int cy, int rad, Colorf cf)
	{
		_cv = &cv;
		_cx = cx;
		_cy = cy;
		_rad = rad;
		_cf = cf;
		srand(time(NULL));
		_hy = rand()%8+1;
		_hx = rand()%8+1;
		_r = r;
		//r->setc2p(this); //Den borde vara här tyckte Bengt, men orkar inte klura ut vad som behövs då
	}

	void Yttercirkel::update()
	{
		ul = Point(0,0);
		lr.x = _cv->get_width();
		lr.y = _cv->get_height();
		
		rul = _r->getul();
		rlr = _r->getlr();

		if ((rlr.x - rul.x) < (rlr.y - rul.y))
			_rad = (rlr.x - rul.x)/8;
		else
			_rad = (rlr.y - rul.y)/8;

		cp.x += _hx;
		cp.y += _hy;

		//Hit test fönster
		if(cp.y - _rad < ul.y)
			_hy = -_hy;
		if(cp.y + _rad > lr.y)
			_hy = -_hy;
		if(cp.x - _rad < ul.x)
			_hx = -_hx;
		if(cp.x + _rad > lr.x)
			_hx = -_hx;

		//Hit test rektangel
		if((cp.y - _rad < rlr.y) && (cp.x > rul.x) && (cp.x < rlr.x) && (cp.y + _rad > rlr.y))
			_hy = -_hy;
		if((cp.y + _rad > rul.y) && (cp.x > rul.x) && (cp.x < rlr.x) && (cp.y - _rad < rul.y))
			_hy = -_hy;
		if((cp.x - _rad < rlr.x) && (cp.y > rul.y) && (cp.y < rlr.y) && (cp.x + _rad > rlr.x))
			_hx = -_hx;
		if((cp.x + _rad > rul.x) && (cp.y > rul.y) && (cp.y < rlr.y) && (cp.x - _rad < rul.x))
			_hx = -_hx;
	}
	void Yttercirkel::draw(Font & font)
	{
		update();
		_r->setc2p(this);
		_cv->fill_circle(cp.x, cp.y, _rad, _cf);
	}
	void Yttercirkel::set(int x, int y, int width, int height)
	{
		cp.x = x;
		cp.y = y;
	}
	Point Yttercirkel::getc()
	{
		return cp;
	}

