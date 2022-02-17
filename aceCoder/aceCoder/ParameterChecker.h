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
	vector<string> loadTxt(const string& filename) const {
		vector<string> results;
		std::ifstream input(filename);
		if(input.is_open()){
			for (std::string line; getline(input, line); )
			{
				results.emplace_back(line);
			}
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

	string getCMD(const string& inputstring, const string& delimeter = ",") const {
		auto fPos = inputstring.find_first_not_of(delimeter, 0);
		auto lPos = inputstring.find_first_of(delimeter, fPos);
		if (string::npos != fPos || string::npos != lPos) {
			return inputstring.substr(fPos, lPos - fPos);
		}
		return string{};
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

	CERTI getCERTI(string& str) const {
		if (str == "ADV")
			return CERTI::ADV;
		else if (str == "PRO")
			return CERTI::PRO;

		return CERTI::EX;
	}

	int getEmployeeNum(const string& str) const {
		int orgnum = stoi(str);
		string tmp = str.substr(0, 2);
		const int num = stoi(tmp);

		if (num >= 0 && num <= 21) // 2000~2021
			orgnum += 2000000000;
		else
			orgnum += 1900000000;

		return orgnum;
	}

	string getEmployeeNumString(int num) {
		if (num < 2000000000)
			num -= 1900000000;
		else
			num -= 2000000000;

		std::stringstream strTmp;
		strTmp << std::setw(8) << std::setfill('0') << num;

		return strTmp.str();
	}


	string getClString(CL cl)
	{
		if (cl == CL::CL1) return "CL1";
		if (cl == CL::CL2) return "CL2";
		if (cl == CL::CL3) return "CL3";
		if (cl == CL::CL4) return "CL4";
	}

	string getCertiString(CERTI certi)
	{
		if (certi == CERTI::ADV) return "ADV";
		if (certi == CERTI::PRO) return "PRO";
		if (certi == CERTI::EX) return "EX";
	}

	member convert_4sort(vector<string>& values) const {
		member result{ 0 };
		result.employeeNum = getEmployeeNum(values[IDXEMPLOYEENUM]);
		result.name = values[IDXNAME];
		result.cl = getCL(values[IDXCL]);
		result.phoneNum = values[IDXPHONENUM];
		result.birthday = stoi(values[IDXBIRTHDAY]);
		result.certi = getCERTI(values[IDXCERTI]);
		return result;
	}
};