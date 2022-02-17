#pragma once
#include"pch.h"
#include"member.h"
#include<sstream>
#include<vector>
#include "Command.h"
using namespace std;

#define MAXDATA		(100000)

#define NONE		(0)

#define PRINT_OFF	(0)
#define PRINT_ON	(1)

#define FULL_NAME	(0)
#define FIRST_NAME	(1)
#define LAST_NAME	(2)

#define	FULL_PHONENUM	(0)
#define MIDDLE_PHONENUM (1)
#define LAST_PHONENUM	(2)

#define FULL_BIRTHDAY	(0)
#define YEAR_BIRTHDAY	(1)
#define MONTH_BIRTHDAY	(2)
#define DAY_BIRTHDAY	(3)

//int Delete(vector<member>& members, string condition, string str, string opt1, string opt2);


class Del : public Command {
public:
	Del(vector<member>& members);
	virtual ~Del() = default;

	int Delete(vector<member>& members, string condition, string str, string opt1, string opt2);
	
	string run(const string& cmd) override {
		vector<string> arg;
		arg.clear();
		istringstream ss(cmd);
		string stringBuffer;
		int sum;
		while (getline(ss, stringBuffer, ',')) {
			arg.push_back(stringBuffer);
		}
		sum = Delete(members_, arg[4], arg[5], arg[1], arg[2]);
		if (sum != -1) {
			return OutputReturn(arg[4], arg[1], arg[2], sum);
		}
		return string();
	};
private:
	vector<member>& members_;
	string OutputReturn(string condition, string opt1, string opt2, int sum);
};
