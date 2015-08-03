//
//  CoolMath.h
//  CoolMath
//
//  Created by 唐如麟 on 15/5/18.
//  Copyright (c) 2015年 唐如麟. All rights reserved.
//

#ifndef CoolMath_h
#define CoolMath_h


#include "Vector.h"
#include "Matrix.h"
//#include "Plane.h"
namespace CM{
	Vector
	operator*(const Matrix & lhs,const Vector & rhs);
}
#endif
