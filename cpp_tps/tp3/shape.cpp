#include <iostream>

using namespace std;

class Shape
{
    public:
		Shape(); 
    private :
	    float width;
        float height;
    public:
    float getw()
    {
        return width; 
    }
    void setw(float x)
    {
        width=x;
    }
    float geth()
    {
        return height ; 
    }

    void seth(float x)
    {
        height=x;
    }
};


Shape::Shape()
{
    int x;
    cout << "Enter the width";
    cin>> x;
    setw(x);
    int y;
    cout << "Enter the height";
    cin>> y;
    seth(y);
}

class Rectangle:public Shape
{
    public:
    float Area()
    {
        float a=geth();
        float b=getw();
        return a*b;
    }

};

class Triangle: public Shape
{
    public:
    float Area()
    {
        float a=geth();
        float b=getw();
        return (a*b)/2;
    }
};


int main()
{
    Rectangle R;
    cout<<"\nThe area of the Rectangle is:"<<R.Area();
    Triangle T;
    cout<<"\nThe area of the Triangle is:"<<T.Area();
    cout << "\n";
    return 0;
}