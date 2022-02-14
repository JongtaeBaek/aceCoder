#pragma once

#include"pch.h"
#include<string>
using namespace std;

enum CL {
	CL1 = 1,
	CL2,
	CL3,
	CL4
};

enum CERTI {
	ADV = 0,
	PRO,
	EX
};

struct member {
	unsigned int employeeNum;
	string name;
	CL cl;
	string phoneNum;
	unsigned int birthday;
	CERTI certi;
};

int add();
int del();
int search();
int modify();
