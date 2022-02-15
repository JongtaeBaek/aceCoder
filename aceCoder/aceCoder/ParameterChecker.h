#pragma once
#include "member.h"
#include <vector>
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
	
	bool isCMDValid(const string& str) {
		if (str != "ADD" && str != "DEL" && str != "SCH" && str != "MOD")
			return false;
		return true;
	}

	bool isEmpoleeNumValid(const string& str) {
		if (str.size() > EMPLOYEENUMSIZE)
			return false;
		return true;
	}

	bool isNameValid(const string& str) {
		if (str.size() > MAXNAMESIZE)
			return false;
		return true;
	}

	bool isCLValid(const string& str) {
		if (str != "CL1" && str != "CL2" && str != "CL3" && str != "CL4")
			return false;
		return true;
	}

	bool isPhoneNumValid(const string& str) {
		if (str.size() > PHONNUBERSIZE || str.substr(0, 3) != "010"|| str.substr(3, 1) != "-" || str.substr(3, 1) != "-" || str.substr(8, 1) != "-")
			return false;
			
		return true;
	}

	bool isBirthdayValid(const string& str) {
		if (str.size() > BIRTHDAYSIZE)
			return false;
		return true;
	}

	bool isCELTIValid(const string& str) {
		if (str != "ADV" && str != "PRO" && str != "EXPERT")
			return false;
		return true;
	}

	bool isValid(const vector<string>& values)  {
		if (values.size() != PARAINDEX::PARAINDEXEND)
			return false;

		for (int i = 0; i < values.size(); i++) {
			if (i == PARAINDEX::IDXCMD) {
				if (isCMDValid(values[i]) == false)
					return false;					
			}
			else if (i == PARAINDEX::IDXEMPLOYEENUM) {
				if (isEmpoleeNumValid(values[i]) == false)
					return false;
			}
			else if (i == PARAINDEX::IDXNAME) {
				if (isNameValid(values[i]) == false)
					return false;
			}
			else if (i == PARAINDEX::IDXCL) {
				if (isCLValid(values[i]) == false)
					return false;
			}
			else if (i == PARAINDEX::IDXPHONENUM) {
				if (isPhoneNumValid(values[i]) == false)
					return false;
			}
			else if (i == PARAINDEX::IDXBIRTHDAY) {
				if (isBirthdayValid(values[i]) == false)
					return false;
			}
			else if (i == PARAINDEX::IDXCERTI) {
				if (isCELTIValid(values[i]) == false)
					return false;
			}
		}

		return true;
	}
private:

};