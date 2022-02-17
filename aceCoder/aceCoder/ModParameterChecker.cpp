#include "pch.h"
#include "ModParameterChecker.h"

bool ModParameterChecker::isValid(const vector<string>& values) {
	if (values.size() != MODPARAINDEX::MODPARAMSIZE)
		return false;

	for (int i = 0; i < values.size(); i++) {
		if (i == MODPARAINDEX::MODIDXCMD) {
			if (isCMDValid(values[i]) == false)
				return false;
		}
		else if (i == MODPARAINDEX::MODIDXOPT1) {
			if (isOPT1Valid(values[i]) == false)
				return false;
		}
		else if (i == MODPARAINDEX::MODIDXOPT2) {
			if (isOPT2Valid(values[i]) == false)
				return false;
		}
		else if (i == MODPARAINDEX::MODIDXOPT3) {
			if (isOPT3Valid(values[i]) == false)
				return false;
		}
		else if (i == MODPARAINDEX::MODIDXSEARCHOPTION) {
			if (isSearchingFieldValid(values[i]) == false)
				return false;
		}
		else if (i == MODPARAINDEX::MODIDXCHANGEOPTION) {
			if (isChangingFieldValid(values[i]) == false)
				return false;
		}
		else if (i == MODPARAINDEX::MODIDXSEARCHVALUE) {
			if (isFieldvalueValid(values[i], values[MODIDXSEARCHOPTION], values[MODIDXOPT2]) == false)
				return false;
		}
		else if (i == MODPARAINDEX::MODIDXCHANGEVALUE) {
			if (isFieldvalueValid(values[i], values[MODIDXCHANGEOPTION], values[MODIDXOPT2]) == false)
				return false;
		}
	}

	return true;
}

bool ModParameterChecker::isFieldvalueValid(const string& str, const string& fieldname, const string& opt2) {
	if (fieldname == "employeeNum") {
		if (isEmpoleeNumValid(str) == false) {
			return false;
		}
		return true;
	}
	else if (fieldname == "name") {
		if (isNameValid(str) == false) {
			return false;
		}
		return true;
	}
	else if (fieldname == "cl") {
		if (isCLValid(str) == false) {
			return false;
		}
		return true;
	}
	else if (fieldname == "phoneNum") {
		if (opt2 == "-m") {
			if (isMiddlePhoneNumValid(str) == false) {
				return false;
			}
			return true;
		}
		else if (opt2 == "-l") {
			if (isLastPhoneNumValid(str) == false) {
				return false;
			}
			return true;
		}
		else if (opt2 == " ") {
			if (isPhoneNumValid(str) == false) {
				return false;
			}
			return true;
		}
	}
	else if (fieldname == "birthday") {
		if (opt2 == "-y") {
			if (isBirthdayYearValid(str) == false) {
				return false;
			}
			return true;
		}
		else if (opt2 == "-m") {
			if (isBirthdayMonthValid(str) == false) {
				return false;
			}
			return true;
		}
		else if (opt2 == "-d") {
			if (isBirthdayDayValid(str) == false) {
				return false;
			}
			return true;
		}
		else if (opt2 == " ") {
			if (isBirthdayValid(str) == false) {
				return false;
			}
			return true;
		}
	}
	else if (fieldname == "certi") {
		if (isCERTIValid(str) == false) {
			return false;
		}
		return true;
	}
	return true;
}