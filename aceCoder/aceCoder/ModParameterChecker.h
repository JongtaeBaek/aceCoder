#pragma once
#include "ParameterChecker.h"

enum MODPARAINDEX {
	MODIDXCMD = 0,
	MODIDXOPT1,
	MODIDXOPT2,
	MODIDXOPT3,
	MODIDXSEARCHOPTION,
	MODIDXSEARCHVALUE,
	MODIDXCHANGEOPTION,
	MODIDXCHANGEVALUE,
	MODPARAMSIZE
};

class ModParameterChecker : public ParameterChecker {
public:
	ModParameterChecker() = default;
	virtual ~ModParameterChecker() = default;
	virtual bool isValid(const vector<string>& values) override;

private:
	static const int middlePhoneNumLength = 4;
	static const int lastPhoneNumLength = 4;

	static const int yearLength = 4;
	static const int monthLength = 2;
	static const int dayLength = 2;
	bool isFieldvalueValid(const string& str, const string& fieldname, const string& opt2);

	bool isCMDValid(const string& str) {
		if (str != "MOD")
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

	bool isOPT3Valid(const string& str) {
		if (str != " ")
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
		if (str.size() > middlePhoneNumLength)
			return false;

		return true;
	}

	bool isLastPhoneNumValid(const string& str) {
		if (str.size() > lastPhoneNumLength)
			return false;

		return true;
	}

	bool isBirthdayValid(const string& str) {
		if (str.size() > BIRTHDAYSIZE)
			return false;
		return true;
	}

	bool isBirthdayYearValid(const string& str) {
		if (str.size() > yearLength)
			return false;
		return true;
	}

	bool isBirthdayMonthValid(const string& str) {
		if (str.size() > monthLength)
			return false;
		return true;
	}

	bool isBirthdayDayValid(const string& str) {
		if (str.size() > dayLength)
			return false;
		return true;
	}

	bool isCERTIValid(const string& str) {
		if (str != "ADV" && str != "PRO" && str != "EX")
			return false;
		return true;
	}

	bool isSearchingFieldValid(const string& str) {
		if (str != "employeeNum" && str != "name" && str != "cl" && str != "phoneNum" && str != "birthday" && str != "certi")
			return false;
		return true;
	}

	bool isChangingFieldValid(const string& str) {
		if (str != "name" && str != "cl" && str != "phoneNum" && str != "birthday" && str != "certi")
			return false;
		return true;
	}
};
