//
//  Plane.h
//  CoolMath
//
//  Created by 唐如麟 on 15/5/19.
//  Copyright (c) 2015年 唐如麟. All rights reserved.
//

#ifndef __CoolMath__Plane__
#define __CoolMath__Plane__
#include "Vector.h"
namespace CM{
	class Plane : public Vector{
	public:
		Plane();
		Plane(const Plane & rhs);
		Plane(Vector p1,Vector p2,Vector p3);
		Plane(float a,float b,float c,float d);
		Plane & operator=(const Plane & rhs);
		Vector normal();
	};
	
	std::ostream & operator<< (std::ostream & os,const Plane & rhs);
	
	float GetPointPlaneDistance(Plane & lhs, Vector & rhs);
}
#endif /* defined(__CoolMath__Plane__) */
