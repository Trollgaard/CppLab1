class Rektangel
{public:
	Rektangel(Canvas & cv, int ulx,int uly, int width,int height, Colorf cf);
	void update();
	void draw(Font & font);
	void setul(int x, int y);
	void setlr(int x, int y);
	Pointf getul();
	Pointf getlr();
	int omkrets();
	int area();
	void setc2p(Yttercirkel * cp2);
private:
	Canvas * _cv;
	int _uly, _ulx, _width, _height;
	Colorf _cf;
	Pointf _ulPoint, _lrPoint, _rektText, _rektCp, _cp2;
	Innercirkel c1;
	char _text[100];
};