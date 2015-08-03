//
//  Matrix.cpp
//  CoolMath
//
//  Created by 唐如麟 on 15/5/18.
//  Copyright (c) 2015年 唐如麟. All rights reserved.
//

#include "Matrix.h"
namespace CM{
	
	IndentityMatrix IndentityMatrix3(3);
	IndentityMatrix IndentityMatrix4(4);
	
	Matrix::
	Matrix(int _dimension):dimension(_dimension){
		_Matrixf=(float *)malloc(sizeof(float)*dimension*dimension);
		memset(_Matrixf,0,sizeof(float)*dimension*dimension);
	}
	
	Matrix::
	Matrix(int _dimension,const float* rhs):dimension(_dimension){
		_Matrixf=(float *)malloc(sizeof(float)*dimension*dimension);
		memcpy(_Matrixf,rhs,dimension*dimension*sizeof(float));
	}
	
	Matrix::
	Matrix(const Matrix & rhs):dimension(rhs.dimension){
		_Matrixf=(float*)malloc(sizeof(float)*dimension*dimension);
		memcpy(_Matrixf, rhs._Matrixf, sizeof(float)*dimension*dimension);
	}
	
	Matrix::
	~Matrix(){
		free(_Matrixf);
	}
	
	Matrix::
	operator float *(){
		return _Matrixf;
	}
	
	float &
	Matrix::
	operator[](const size_t i){
		assert(i<dimension*dimension);
		return _Matrixf[i];
	}
	
	float &
	Matrix::
	operator[](const size_t i) const {
		assert(i<dimension*dimension);
		return _Matrixf[i];
	}
	
	Matrix &
	Matrix::
	operator=(const Matrix & rhs){
		assert(dimension==rhs.dimension);
		memcpy(_Matrixf, rhs._Matrixf, sizeof(float)*dimension*dimension);
		return *this;
	}
	
	float &
	Matrix::
	operator()(int i,int j){
		assert(i<dimension && j<dimension);
		return _Matrixf[i*dimension+j];
	}
	
	float &
	Matrix::
	operator()(int i,int j) const {
		assert(i<dimension && j<dimension);
		return _Matrixf[i*dimension+j];
	}
	
	Matrix &
	Matrix::
	operator+=(const Matrix & rhs){
		assert(dimension==rhs.dimension);
		for(int i=0;i<dimension*dimension;i++) (*this)[i]+=rhs[i];
		return (*this);
	};
	
	Matrix &
	Matrix::
	operator-=(const Matrix & rhs){
		assert(dimension==rhs.dimension);
		for(int i=0;i<dimension*dimension;i++) (*this)[i]-=rhs[i];
		return (*this);
	};
	
	Matrix &
	Matrix::
	operator*=(const float Scale){
		for(int i=0;i<dimension*dimension;i++) (*this)[i]*=Scale;
		return (*this);
	};
	
	Matrix &
	Matrix::
	operator/=(const float Scale){
		assert(Scale!=0);
		for(int i=0;i<dimension*dimension;i++) (*this)[i]/=Scale;
		return (*this);
	};
	
	IndentityMatrix::
	IndentityMatrix(int _dimension):Matrix(_dimension){
		for(int i=0;i<dimension;i++) _Matrixf[i*dimension+i]=1;
	}
	
	Matrix
	operator+(const Matrix & lhs,const Matrix & rhs){
		assert(lhs.dimension==rhs.dimension);
		Matrix temp(lhs.dimension);
		for(int i=0;i<lhs.dimension*lhs.dimension;i++) temp[i]=lhs[i]+rhs[i];
		return temp;
	}
	
	Matrix
	operator-(const Matrix & lhs,const Matrix & rhs){
		assert(lhs.dimension==rhs.dimension);
		Matrix temp(lhs.dimension);
		for(int i=0;i<lhs.dimension*lhs.dimension;i++) temp[i]=lhs[i]-rhs[i];
		return temp;
	}
	
	Matrix
	operator*(const Matrix & lhs,const float Scale){
		Matrix temp(lhs.dimension);
		for(int i=0;i<lhs.dimension*lhs.dimension;i++) temp[i]=lhs[i]*Scale;
		return temp;
	}
	
	Matrix
	operator*(const float Scale,const Matrix & rhs){
		Matrix temp(rhs.dimension);
		for(int i=0;i<rhs.dimension*rhs.dimension;i++) temp[i]=rhs[i]*Scale;
		return temp;
	}
	
	Matrix
	operator*(const Matrix & lhs,const Matrix & rhs){
		assert(lhs.dimension==rhs.dimension);
	 Matrix temp(lhs.dimension);
		for(int i=0;i<lhs.dimension;i++)
			for(int j=0;j<lhs.dimension;j++)
				for(int k=0;k<lhs.dimension;k++)
					temp(i,j)+=lhs(i,k)*rhs(k,j);
		return temp;
	}
	
	bool
	operator==(const Matrix & lhs,const Matrix & rhs){
		assert(lhs.dimension==rhs.dimension);
		for(int i=0;i<lhs.dimension*lhs.dimension;i++)
			if(fabsf(lhs[i]-rhs[i])>EPSINON) return false;
		return true;
	}
	
	std::ostream &
	operator<< (std::ostream & os,Matrix & rhs){
		os<<"    --------- Matrix ---------"<<std::endl;
		for(int i=0;i<rhs.dimension;i++){
			for(int j=0;j<rhs.dimension;j++){
				os<<std::fixed<<std::setw(10)<<std::setprecision(4)<<rhs(i,j);
			}
			os<<std::endl;
		}
		os<<"    --------------------------"<<std::endl<<std::endl;;
		return os;
	}
	
	Matrix
	GetRotationMatrix(float angle, float x,float y,float z,int _dimension){
		assert(_dimension==3 || _dimension==4);
		Matrix temp(_dimension);
		
		float mag, s, c;
		float xx, yy, zz, xy, yz, zx, xs, ys, zs, one_c;
		
		s = float(sin(deg2rad(angle)));
		c = float(cos(deg2rad(angle)));
		
		mag = float(sqrtf( x*x + y*y + z*z ));
		
		// Identity matrix
		if (mag == 0.0f) return IndentityMatrix(_dimension);
		
		// Rotation matrix is normalized
		x /= mag;
		y /= mag;
		z /= mag;
		
		xx = x * x;
		yy = y * y;
		zz = z * z;
		xy = x * y;
		yz = y * z;
		zx = z * x;
		xs = x * s;
		ys = y * s;
		zs = z * s;
		one_c = 1.0f - c;
		
		temp(0,0) = (one_c * xx) + c;
		temp(0,1) = (one_c * xy) - zs;
		temp(0,2) = (one_c * zx) + ys;
		
		temp(1,0) = (one_c * xy) + zs;
		temp(1,1) = (one_c * yy) + c;
		temp(1,2) = (one_c * yz) - xs;
		
		temp(2,0) = (one_c * zx) - ys;
		temp(2,1) = (one_c * yz) + xs;
		temp(2,2) = (one_c * zz) + c;
		if(_dimension==4){
			temp(0,3) = 0.0f;
			temp(1,3) = 0.0f;
			temp(2,3) = 0.0f;
			temp(3,3) = 1.0f;
		}
		return temp;
	}
}






