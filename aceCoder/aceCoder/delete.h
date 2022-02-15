#pragma once
#include"pch.h"
#include"member.h"


#define MAXDATA (100000)
#define OPTION_PRINT 1

#define FIRST_NAME 0
#define LAST_NAME 1
#define MIDDLE_PHONENUM 0
#define LAST_PHONENUM 1
#define YEAR_BIRTHDAY 0
#define MONTH_BIRTHDAY 1
#define DAY_BIRTHDAY 2



enum condition {
	EMPLOYEENUM = 0,
	NAME,
	CL,
	PHONENUM,
	BIRTHDAY,
	CERTI,
	NUM_OF_CONDITION
};

int Delete(vector<member>& members, string condition, string str, int option1, int option2);