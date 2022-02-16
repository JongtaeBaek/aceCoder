#pragma once
#include "member.h"
#include <vector>
#include <fstream>

enum PARAINDEX {
	IDXCMD =0, IDXFIRSTOPT, IDXSECONDOPT, IDXTHIRDOPT,
	IDXEMPLOYEENUM, IDXNAME, IDXCL, IDXPHONENUM, IDXBIRTHDAY, IDXCERTI, PARAINDEXEND
};

const int MAXNAMESIZE = 15;
const int PHONNUBERSIZE = 13;
const int EMPLOYEENUMSIZE = 8;
const int BIRTHDAYSIZE = 8;

class ParameterChecker {
public:
	member convert(vector<string>& values) const {
		member result{ 0 };
		result.employeeNum = stoi(values[IDXEMPLOYEENUM]);
		result.name = values[IDXNAME];
		result.cl = getCL(values[IDXCL]);
		result.phoneNum = values[IDXPHONENUM];
		result.birthday = stoi(values[IDXBIRTHDAY]);
		result.certi = getCELTI(values[IDXCERTI]);
		return result;
	}

	vector<string> loadTxt(const string& filename) const {
		vector<string> results;
		std::ifstream input(filename);
		for (std::string line; getline(input, line); )
		{
			results.emplace_back(line);
		}

		return results;
	}

	vector<string> parse(const string& inputstring, const string& delimeter = ",") const {
		vector<string> results;
		auto fPos = inputstring.find_first_not_of(delimeter, 0);
		auto lPos = inputstring.find_first_of(delimeter, fPos);
		while (string::npos != fPos || string::npos != lPos) {
			results.emplace_back(inputstring.substr(fPos, lPos - fPos));
			fPos = inputstring.find_first_not_of(delimeter, lPos);
			lPos = inputstring.find_first_of(delimeter, fPos);
		}
		
		return results;
	}	

	virtual bool isValid(const vector<string>& values)  {		
		return false;
	}

	CL getCL(string& str) const {
		if (str == "CL1")
			return CL::CL1;
		else if (str == "CL2")
			return CL::CL2;
		else if (str == "CL3")
			return CL::CL3;

		return CL::CL4;
	}

	CERTI getCELTI(string& str) const {
		if (str == "ADV")
			return CERTI::ADV;
		else if (str == "PRO")
			return CERTI::PRO;

		return CERTI::EX;
	}
};