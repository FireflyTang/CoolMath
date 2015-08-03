//
//  Plane.cpp
//  CoolMath
//
//  Created by 唐如麟 on 15/5/19.
//  Copyright (c) 2015年 唐如麟. All rights reserved.
//

#include "Plane.h"
namespace CM{
	Plane::
	Plane():Vector(4){};
	
	Plane::
	Plane(Vector p1,Vector p2,Vector p3):Vector(4){
		Vector v1, v2;
		v1[0] = p3[0] - p1[0];
		v1[1] = p3[1] - p1[1];
		v1[2] = p3[2] - p1[2];
		v2[0] = p2[0] - p1[0];
		v2[1] = p2[1] - p1[1];
		v2[2] = p2[2] - p1[2];
		Vector planeEq0 = (v1.cross(v2)).normalized();
		_Vectorf[0]=planeEq0[0];_Vectorf[1]=planeEq0[1];_Vectorf[2]=planeEq0[2];
		_Vectorf[3] = -(planeEq0[0] * p3[0] + planeEq0[1] * p3[1] + planeEq0[2] * p3[2]);
	};
	
	Plane::
	Plane(float a,float b,float c,float d):Vector(a,b,c,d){};
	
	Plane &
	Plane::
	operator=(const Plane & rhs){
		for(int i=0;i<4;i++) _Vectorf[i]=rhs[i];
		return (*this);
	}
	
	Vector
	Plane::
	normal(){
		Vector temp(_Vectorf[0],_Vectorf[1],_Vectorf[2]);
		return temp;
	}
	
	float GetPointPlaneDistance(Plane & lhs, Vector & rhs){
		assert(rhs.dimension==3);
		return lhs[0]*rhs[0]+lhs[1]*rhs[1]+lhs[2]*rhs[2]+lhs[3];
	}
	
	std::ostream &
	operator<< (std::ostream & os,const Plane & rhs){
		os<<"    --------- Plane  ---------"<<std::endl;
		for(int i=0;i<4;i++)
			os<<std::fixed<<std::setw(10)<<std::setprecision(4)<<rhs[i];
		os<<std::endl<<"    --------------------------"<<std::endl<<std::endl;
		return os;
	}
}