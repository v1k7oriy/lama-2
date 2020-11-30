#include<iostream>
#include<iomanip>
#include<string.h>
# define N 6

using namespace std;

class Shape{
public:
	virtual void print() { }; 
	virtual double area(){ return 0;} 
	virtual double volume(){ return 0;}
};

class TwoDShape : public Shape{
public:
	virtual void print() {}
	virtual double area() { return 0; }
};

class ThreeDShape : public Shape{
public:
	virtual void print() {}
	virtual double volume() { return 0; }
};


class rectangle : public TwoDShape{
	int height, side;
public:
	void print() {
		cout << "It's a rectangle. Length: " << height << ". Width: " << side << endl;
	}

	rectangle(int _height, int _side) : height(_height), side(_side) {}

	double area() { 
		return height * side; 
	}
};

class circle : public TwoDShape {
	int radius;
public:
	void print() {
		cout << "It's a circe. Radius: " << radius << endl;
	}

	circle(int _radius) : radius(_radius) {}

	double area() {
		return 3.14 * radius * radius;
	}
};

class cube : public ThreeDShape{
	int side;
public:
	void print() {
		cout << "It's a cube. Length and width: " << side << endl;
	}

	cube(int _side) : side(_side) {}

	double volume() { 
		return side * side * side; 
	}
};

class cylinder : public ThreeDShape{
	int height, radius;
public:
	void print() {
		cout << "It's a cylinder. Height: " << height << "Radius: " << radius << endl;
	}

	cylinder(int _height, int _radius) : height(_height), radius(_radius) {}

	double volume() { 
		return 3.14 * radius * radius * height; 
	}

};

class parallelepiped :public ThreeDShape {
	int height, width, length;
public:
	void print() {
		cout << "It'a a parallelepiped. Heiht: " << height << ". Width: " << width << ". Length: " << length << endl;
	}

	parallelepiped(int _height, int _width, int _length):height(_height),width(_width),length(_length){}

	double volume() { 
		return height * width * length; 
	}
};

class sphere :public ThreeDShape {
	int radius;
public:
	void print() {
		cout << "It's a sphere. Radius: " << radius << endl;
	}

	sphere(int _radius) :radius(_radius) {}

	double valume() {
		return 4 / 3 * 3.14 * radius * radius * radius;
	}
};

int main(){
	Shape* p[N];
	double volume, area;
	rectangle a(4, 2); 
	circle b(4); 
	cube c(3); 
	cylinder d(6, 1); 
	parallelepiped e(3, 5, 7);
	sphere f(8);
	p[0] = &a; 
	p[1] = &b; 
	p[2] = &c; 
	p[3] = &d;	
	p[4] = &e; 
	p[5] = &f;
	for (int i = 0; i < N; i++) {
		p[i]->print(); 
			area = p[i]->area(); 
			volume = p[i]->volume(); 
		if (area == 0)
			cout << "No area. ";
		else
			cout << "Area: " << area << ". "; 
		if (volume == 0)
			cout << "No volume." << endl << endl;
		else
			cout << "Volume: " << volume <<"." << endl << endl;
	}
	return 0;
}