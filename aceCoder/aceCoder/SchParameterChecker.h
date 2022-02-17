#pragma once
#include "ParameterChecker.h"

#define MIDDLE_PHONENUM_LENGTH 4
#define LAST_PHONENUM_LENGTH 4

#define YEAR_LENGTH 4
#define MONTH_LENGTH 2
#define DAY_LENGTH 2

enum SCHPARAINDEX {
	CMDIDX, 
	OPT1IDX,
	OPT2IDX,
	OP3IDX,
	FIELDIDX,
	FIELDVALUEIDX,
	SCHPARAENDIDX
};

class SchParameterChecker : public ParameterChecker {
public:
	SchParameterChecker() = default;
	virtual ~SchParameterChecker() = default;

public:
	virtual bool isValid(const vector<string>& values) override;

private:
	bool isFieldvalueValid(const string& str, const string& fieldname, const string& opt2);

	bool isCMDValid(const string& str) {
		if (str != "ADD" && str != "DEL" && str != "SCH" && str != "MOD")
			return false;
		return true;
	}

	bool isOPT1Valid(const string& str) {
		if (str != " " && str != "-p")
			return false;
		return true;
	}

	bool isOPT2Valid(const string& str) {
		if (str != " " && str != "-f" && str != "-m" && str != "-l" && str != "-y" && str != "-m" && str != "-d")
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
		if (str.size() > PHONNUBERSIZE || str.substr(0, 3) != "010" || str.substr(3, 1) != "-" || str.substr(3, 1) != "-" || str.substr(8, 1) != "-")
			return false;

		return true;
	}

	bool isMiddlePhoneNumValid(const string& str) {
		if (str.size() > MIDDLE_PHONENUM_LENGTH )
			return false;

		return true;
	}

	bool isLastPhoneNumValid(const string& str) {
		if (str.size() > LAST_PHONENUM_LENGTH)
			return false;

		return true;
	}

	bool isBirthdayValid(const string& str) {
		if (str.size() > BIRTHDAYSIZE)
			return false;
		return true;
	}

	bool isBirthdayYearValid(const string& str) {
		if (str.size() > YEAR_LENGTH)
			return false;
		return true;
	}

	bool isBirthdayMonthValid(const string& str) {
		if (str.size() > MONTH_LENGTH)
			return false;
		return true;
	}

	bool isBirthdayDayValid(const string& str) {
		if (str.size() > DAY_LENGTH)
			return false;
		return true;
	}

	bool isCELTIValid(const string& str) {
		if (str != "ADV" && str != "PRO" && str != "EX")
			return false;
		return true;
	}

	bool isFieldValid(const string& str) {
		if (str != "employeeNum" && str != "name" && str != "cl" && str != "phoneNum" && str != "birthday" && str != "certi")
			return false;
		return true;
	}
};