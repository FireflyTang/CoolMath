//
//  Matrix.h
//  CoolMath
//
//  Created by 唐如麟 on 15/5/18.
//  Copyright (c) 2015年 唐如麟. All rights reserved.
//

#ifndef __CoolMath__Matrix__
#define __CoolMath__Matrix__

#include "CoolMath.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include "assert.h"
#include "cmath"
#include "utils.h"

namespace CM{
	class Vector;
	class Matrix {
	public:
		Matrix(int _dimension=3);
		Matrix(int _dimension,const float* rhs);
		Matrix(const Matrix & rhs);
		~Matrix();
		
		operator float * ();
		float & operator[](const size_t i);
		float & operator[](const size_t i) const;
		Matrix & operator=(const Matrix & rhs);
		float & operator()(int i,int j);
		float & operator()(int i,int j) const;

		Matrix & operator+=(const Matrix & rhs);
		Matrix & operator-=(const Matrix & rhs);
		Matrix & operator*=(const float Scale);
		Matrix & operator/=(const float Scale);

		//float determinant(){};
		//Matrix invert(){};
		//Matrix transpose(){};
		//Matrix resize(int _dimension){};
			
		int dimension;
	protected:
		float * _Matrixf;
	};
	
	Matrix operator+(const Matrix & lhs,const Matrix & rhs);
	Matrix operator-(const Matrix & lhs,const Matrix & rhs);
	Matrix operator*(const Matrix & lhs,const float Scale);
	Matrix operator*(const float Scale,const Matrix & rhs);
	Matrix operator*(const Matrix & lhs,const Matrix & rhs);
	bool operator==(const Vector & lhs,const Vector & rhs);
	
	std::ostream & operator<< (std::ostream & os,Matrix & rhs);
	
	class IndentityMatrix : public Matrix{
	public:
		IndentityMatrix(int _dimension=3);
	};
	
	Matrix GetRotationMatrix(float angle,float x,float y,float z,int _Dimension=3);
	
	//defined in cpp
	extern IndentityMatrix IndentityMatrix3;
	extern IndentityMatrix IndentityMatrix4;
}



#endif /* defined(__CoolMath__Matrix__) */
