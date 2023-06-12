#pragma once

class Location {
protected:
	int x;
	int y;
public:
	Location(int InitX, int InitY);
	~Location();
	int getX();
	int getY();
};

class VPoint : public Location {
protected:
	bool visible;
public:
	VPoint(int initX, int initY);
	~VPoint();
	virtual void show();
	virtual void hide();
	bool isVisible();
	void moveTo(int newX, int newY);
	void drug(int shift);
};

class VGlass : public VPoint {
private:
	int height;
	int width;
public:
	VGlass(int initX = 10, int initY = 10, int initHeight = 60, int initWidth = 60);
	~VGlass();
	virtual void show();
	virtual void hide();
};

#pragma once