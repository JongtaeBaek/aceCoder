#include "pch.h"
#include "SchParameterChecker.h"

bool SchParameterChecker::isValid(const vector<string>& values) {
	if (values.size() != SCHPARAINDEX::SCHPARAENDIDX)
		return false;

	for (int i = 0; i < values.size(); i++) {
		if (i == SCHPARAINDEX::CMDIDX) {
			if (isCMDValid(values[i]) == false)
				return false;
		}
		else if (i == SCHPARAINDEX::OPT1IDX) {
			if (isOPT1Valid(values[i]) == false)
				return false;
		}
		else if (i == SCHPARAINDEX::OPT2IDX) {
			if (isOPT2Valid(values[i]) == false)
				return false;
		}
		else if (i == SCHPARAINDEX::FIELDIDX) {
			if (isFieldValid(values[i]) == false)
				return false;
		}
		else if (i == SCHPARAINDEX::FIELDVALUEIDX) {
			if (isFieldvalueValid(values[i], values[FIELDIDX], values[OPT2IDX]) == false)
				return false;
		}
	}

	return true;
}

bool SchParameterChecker::isFieldvalueValid(const string& str, const string& fieldname, const string& opt2) {
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
		if (isCELTIValid(str) == false) {
			return false;
		}
		return true;
	}
	return true;
}