//
//  CoolMath.cpp
//  CoolMath
//
//  Created by 唐如麟 on 15/5/19.
//  Copyright (c) 2015年 唐如麟. All rights reserved.
//

#include "CoolMath.h"
namespace CM{
	Vector
	operator*(const Matrix & lhs,const Vector & rhs){
		assert(lhs.dimension==rhs.dimension);
		Vector temp(lhs.dimension);
		for(int i=0;i<lhs.dimension;i++)
			for(int k=0;k<lhs.dimension;k++)
				temp[i]+=lhs(i,k)*rhs[k];
		return temp;
	}
}