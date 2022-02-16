#pragma once
#include "ParameterChecker.h"

class AddParmeterChecker : public ParameterChecker {
public:
	AddParmeterChecker() = default;
	virtual ~AddParmeterChecker() = default;

public:
	virtual bool isValid(const vector<string>& values) override;

private:
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
		if (str.size() > PHONNUBERSIZE || str.substr(0, 3) != "010" || str.substr(3, 1) != "-" || str.substr(3, 1) != "-" || str.substr(8, 1) != "-")
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
};