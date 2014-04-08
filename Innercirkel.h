class Rektangel;
class Innercirkel
{public:
	Innercirkel (Rektangel* r,Canvas & cv, int cx,int cy, int rad, Colorf cf);
	void update();
	void draw(Font & font);
	void set(int x, int y, int width, int height);
private:
	Canvas * _cv;
	int _cx, _cy, _rad, _hy, _hx;
	Colorf _cf;
	Point cp, rul, rlr;
};
