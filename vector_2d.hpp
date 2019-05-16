#ifndef MY_GAME_VECTOR_2D
#define MY_GAME_VECTOR_2D

#include <cmath>
#include <iostream>
#define PI 3.14159265

template <typename T>
class Vector_2d
{
	private:
        	T 		x_;
        	T 		y_;
	public:
        	Vector_2d(T x, T y);
		float 		abs();
        	float 		getAngle();
        	float 		getSin();
        	float 		getCos();
		float		operator *  (const Vector_2d&);	
};


template <typename T>
Vector_2d<T>::Vector_2d (T x, T y):
	x_(x),
	y_(y)
	{}

template <typename T>
float Vector_2d<T>::abs()
{
        return sqrt((x_ * x_)+(y_ * y_));
}

template <typename T>
float Vector_2d<T>::getAngle()
{
	if(x_ >= 0)
		return asin(getSin())*180/PI;
	if(x_ < 0)
		return -asin(getSin())*180/PI + 180;
}
	
template <typename T>
float Vector_2d<T>::getSin()
{
        return y_/abs();
}

template <typename T>
float Vector_2d<T>::getCos()
{
        return x_/abs();
}

template <typename T>
float Vector_2d<T>::operator * (const Vector_2d<T>& rhv)
{
	float result = x_ * rhv.x_ + y_ * rhv.y_;
	return result;
}	


#endif //MY_GAME_VECTOR_2D

