//
//  CoolMath.h
//  CoolMath
//
//  Created by 唐如麟 on 15/5/18.
//  Copyright (c) 2015年 唐如麟. All rights reserved.
//

#ifndef __CoolMath__Vector__
#define __CoolMath__Vector__

#include "CoolMath.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include "assert.h"
#include "cmath"
#include "utils.h"

namespace CM{
	class Matrix;
	class Vector {
	public:
		Vector(int _dimension=3);
		Vector(int _dimension,const float* rhs);
		Vector(float x,float y,float z);
		Vector(float x,float y,float z,float w);
		Vector(const Vector & rhs);
		~Vector();
		void set(const float x,const float y,const float z);
		void set(const float x,const float y,const float z,const float w);
		void set(int _dimension,const float * rhs);
		
		operator float * ();
		float & operator[](const size_t i);
		float & operator[](const size_t i) const;
		Vector & operator=(const Vector & rhs);
		Vector & operator+=(const Vector & rhs);
		Vector & operator-=(const Vector & rhs);
		Vector & operator*=(const float Scale);
		Vector & operator/=(const float Scale);

		float length() const;
		Vector normalized() const;
		float dot(const Vector & rhs) const;
		Vector cross(const Vector & rhs) const;
		//Vector resize(int _dimension){};
		
		int dimension;
	protected:
		float * _Vectorf;
	};
	Vector operator+(const Vector & lhs,const Vector & rhs);
	Vector operator-(const Vector & lhs,const Vector & rhs);
	Vector operator-(const Vector & lhs);
	Vector operator*(const Vector & lhs,const float Scale);
	Vector operator*(const float Scale,const Vector & rhs);
	Vector operator/(const Vector & lhs,const float Scale);
	bool operator==(const Vector & lhs,const Vector & rhs);
	
	std::ostream & operator<< (std::ostream & os,const Vector & rhs);
	
	Vector GetVectorProjectOn(const Vector &lhs,const Vector & rhs);
	float GetPointsDistance(const Vector & lhs,const Vector & rhs);
	float GetVectorsAngle(const Vector & lhs,const Vector & rhs);
	Vector GetVectorsNormal(const Vector & lhs,const Vector & rhs);
	
	//defined in cpp
	extern Vector xaxis;
	extern Vector yaxis;
	extern Vector zaxis;
	extern Vector origin;
}

#endif /* defined(__CoolMath__Vector__) */
