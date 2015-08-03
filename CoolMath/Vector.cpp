//
//  CoolMath.cpp
//  CoolMath
//
//  Created by 唐如麟 on 15/5/18.
//  Copyright (c) 2015年 唐如麟. All rights reserved.
//

#include "Vector.h"
namespace CM{
	Vector xaxis(1,0,0);
	Vector yaxis(0,1,0);
	Vector zaxis(0,0,1);
	Vector origin(0,0,0);
	
	Vector::
	Vector(int _dimension):dimension(_dimension){
		_Vectorf=(float *)malloc(sizeof(float)*dimension);
		memset(_Vectorf, 0,sizeof(float)*dimension);
	}
	
	Vector::
	Vector(int _dimension,const float * rhs):dimension(_dimension){
		_Vectorf=(float *)malloc(sizeof(float)*dimension);
		memcpy(_Vectorf,rhs,dimension*sizeof(float));
	}
	
	Vector::
	Vector(const float x,const float y,const float z):dimension(3){
		_Vectorf=(float *)malloc(sizeof(float)*dimension);
		_Vectorf[0]=x;
		_Vectorf[1]=y;
		_Vectorf[2]=z;
	}
	
	Vector::
	Vector(const float x,const float y,const float z,float w):dimension(4){
		_Vectorf=(float *)malloc(sizeof(float)*dimension);
		_Vectorf[0]=x;
		_Vectorf[1]=y;
		_Vectorf[2]=z;
		_Vectorf[3]=w;
	}
	
	Vector::
	Vector(const Vector & rhs):dimension(rhs.dimension){
		_Vectorf=(float *)malloc(sizeof(float)*dimension);
		memcpy(_Vectorf, rhs._Vectorf, dimension*sizeof(float));
	}
	
	Vector::
	~Vector(){
		free(_Vectorf);
	}
	
	void
	Vector::
	set(float x, float y, float z){
		assert(dimension==3);
		_Vectorf[0]=x;
		_Vectorf[1]=y;
		_Vectorf[2]=z;
	}
	
	void
	Vector::
	set(float x, float y, float z,float w){
		assert(dimension==4);
		_Vectorf[0]=x;
		_Vectorf[1]=y;
		_Vectorf[2]=z;
		_Vectorf[3]=w;
	}
	
	void
	Vector::
	set(int _dimension,const float * rhs){
		assert(_dimension==dimension);
		memcpy(_Vectorf, rhs, sizeof(float)*dimension);
	}
	
	Vector::
	operator float * (){
		return _Vectorf;
	}
	
	float &
	Vector::
	operator[](const size_t i){
		assert(i<dimension);
		return _Vectorf[i];
	}
	
	float &
	Vector::
	operator[](const size_t i) const{
		assert(i<dimension);
		return _Vectorf[i];
	}
	
	Vector &
	Vector::
	operator=(const Vector & rhs){
		assert(dimension==rhs.dimension);
		memcpy(_Vectorf, rhs._Vectorf, dimension*sizeof(float));
		return *this;
	}
	
	
	float
	Vector::
	length() const{
		float sum=0;
		for(int i=0;i<dimension;i++) sum+=_Vectorf[i]*_Vectorf[i];
		return sqrtf(sum);
	}
	
	Vector
	Vector::
	normalized() const{
		return (*this)/sqrtf(length());
	}
	
	float
	Vector::
	dot(const Vector & rhs) const{
		assert(dimension==rhs.dimension);
		float sum=0;
		const Vector & lhs=*this;
		for(int i=0;i<dimension;i++)
			sum+=lhs[i]*rhs[i];
		return sum;
	}
	
	Vector
	Vector::
	cross(const Vector & rhs) const {
		assert(dimension==3 && rhs.dimension==3);
		Vector temp(dimension);
		const Vector & lhs = *this;
		temp[0] = lhs[1]*rhs[2] - rhs[1]*lhs[2];
		temp[1] = -lhs[0]*rhs[2] + rhs[0]*lhs[2];
		temp[2] = lhs[0]*rhs[1] - rhs[0]*lhs[1];
		return temp;
	}
	
	Vector
	operator+(const Vector & lhs,const Vector & rhs){
		assert(lhs.dimension==rhs.dimension);
		Vector temp(lhs.dimension);
		for(int i=0;i<lhs.dimension;i++) temp[i]=lhs[i]+rhs[i];
		return temp;
	}
	
	Vector
	operator-(const Vector & lhs,const Vector & rhs){
		assert(lhs.dimension==rhs.dimension);
		Vector temp(lhs.dimension);
		for(int i=0;i<lhs.dimension;i++) temp[i]=lhs[i]-rhs[i];
		return temp;
	}
	
	Vector
	
	operator-(const Vector & lhs){
		Vector temp(lhs.dimension);
		for(int i=0;i<lhs.dimension;i++) temp[i]=-lhs[i];
		return temp;
	}
	
	Vector
	operator*(const Vector & lhs,const float Scale){
		Vector temp(lhs.dimension);
		for(int i=0;i<lhs.dimension;i++) temp[i]=lhs[i]*Scale;
		return temp;
	}
	
	Vector
	operator*(const float Scale,const Vector & rhs){
		Vector temp(rhs.dimension);
		for(int i=0;i<rhs.dimension;i++) temp[i]=rhs[i]*Scale;
		return temp;
	}
	
	Vector
	operator/(const Vector & lhs,const float Scale){
		assert(Scale!=0);
		Vector temp(lhs.dimension);
		for(int i=0;i<lhs.dimension;i++) temp[i]=lhs[i]/Scale;
		return temp;
	}
	
	Vector &
	Vector::
	operator+=(const Vector & rhs){
		assert(dimension==rhs.dimension);
		for(int i=0;i<dimension;i++) (*this)[i]+=rhs[i];
		return *this;
	}
	Vector&
	Vector::
	operator-=(const Vector & rhs){
		assert(dimension==rhs.dimension);
		for(int i=0;i<dimension;i++) (*this)[i]-=rhs[i];
		return *this;
	}
	
	Vector &
	Vector::
	operator*=(const float Scale){
		for(int i=0;i<dimension;i++) (*this)[i]*=Scale;
		return (*this);
	}
	
	Vector &
	Vector::
	operator/=(const float Scale){
		assert(Scale!=0);
		for(int i=0;i<dimension;i++) (*this)[i]/=Scale;
		return (*this);
	}
	
	bool
	operator==(const Vector & lhs,const Vector & rhs){
		assert(lhs.dimension==rhs.dimension);
		for(int i=0;i<lhs.dimension;i++)
			if(fabsf(lhs[i]-rhs[i])>EPSINON) return false;
		return true;
	}
	
	std::ostream &
	operator<< (std::ostream & os,const Vector & rhs){
		os<<"    --------- Vector ---------"<<std::endl;
		for(int i=0;i<rhs.dimension;i++)
			os<<std::fixed<<std::setw(10)<<std::setprecision(4)<<rhs[i];
		os<<std::endl<<"    --------------------------"<<std::endl<<std::endl;
		return os;
	}
	
	Vector
	GetVectorProjectOn(const Vector & lhs,const Vector & rhs){
		assert(lhs.dimension==rhs.dimension);
		Vector unit=rhs.normalized();
		return lhs.dot(unit)*unit;
	}
	
	float
	GetVectorDistance(const Vector & lhs,const Vector & rhs){
		assert(lhs.dimension==rhs.dimension);
		return (lhs-rhs).length();
	}
	
	float
	GetVectorAngle(const Vector & lhs,const  Vector & rhs){
		return rad2deg( acosf(lhs.dot(rhs) ));
	}
	
	Vector
	GetVectorNormal(const Vector & lhs,const Vector & rhs){
		return (lhs.cross(rhs)).normalized();
	}
}










