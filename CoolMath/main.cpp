//
//  main.cpp
//  CoolMath
//
//  Created by 唐如麟 on 15/5/19.
//  Copyright (c) 2015年 唐如麟. All rights reserved.
//

#include "CoolMath.h"
#include <vector>

using namespace CM;
using namespace std;

int main(){
	Vector a(4);
	Vector b(1,0,0);
	//cout<<a;
	//cout<<b;
	Vector c=b+b+b;
	//cout<<c;
	
	//cout<<IndentityMatrix3;
	Matrix aa;
	//cout<<aa;
	aa(1,1)=2;
	//cout<<aa;
	Matrix r=GetRotationMatrix(-30, 0,0,1);
	//cout<<((r*r)*b==r*(r*b));
	cout<<xaxis;
	//cout<<r*b;
	
	Vector aaa(1,0,0);
	Vector bbb(0,1,0);
	Vector ccc(0,2,0);
	Plane  p(aaa,bbb,ccc);
	//cout << p;
	//cout << p.normal();
}