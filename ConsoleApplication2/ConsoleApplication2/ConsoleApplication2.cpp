// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>

enum type {VEC_ZERO, VEC_ONE, VEC_RAND};
enum OperationType {Copy, Paste};

class Vector3D
{
public:
	Vector3D();
	Vector3D(type Vec);
	Vector3D(Vector3D* TheObjectInQuestion, OperationType WatDo);
	Vector3D(double X, double Y, double Z);
	void Print();
	~Vector3D();

private:
	double X;
	double Y;
	double Z;
	static int ile;
};

Vector3D::Vector3D()
{
	this->X = DBL_MIN;
	this->Y = DBL_MIN;
	this->Z = DBL_MIN;
	++ile;
}

Vector3D::Vector3D(type Vec)
{
	switch (Vec)
	{
	case VEC_ZERO:
		this->X = 0;
		this->Y = 0;
		this->Z = 0;
		break;
	case VEC_ONE:
		this->X = 1;
		this->Y = 1;
		this->Z = 1;
		break;
	case VEC_RAND:
		this->X = rand();
		this->Y = rand();
		this->Z = rand();
		break;
	default:
		break;
	}
	++ile;
}

Vector3D::Vector3D(double X, double Y, double Z)
{
	this->X;
	this->Y;
	this->Z;
	++ile;
}

Vector3D::Vector3D(Vector3D* TheObjectInQuestion, OperationType WatDo)
{
	switch (WatDo)
	{
	
	case Copy:
		this->X = TheObjectInQuestion->X;
		this->Y = TheObjectInQuestion->Y;
		this->Z = TheObjectInQuestion->Z;
		break;

	case Paste:
		this->X = TheObjectInQuestion->X;
		this->Y = TheObjectInQuestion->Y;
		this->Z = TheObjectInQuestion->Z;
		delete TheObjectInQuestion;
		break;
	default:
		break;
	}
	++ile;
}

Vector3D::~Vector3D()
{
	--ile;
}

void Vector3D::Print()
{
	std::cout << "(" << X << ", " << Y << ", " << Z << ") ";
}

int main()
{
	srand(time(NULL));
    return 0;
}

