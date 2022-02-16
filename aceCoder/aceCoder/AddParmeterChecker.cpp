#include "pch.h"
#include "ADDParmeterChecker.h"

bool AddParmeterChecker::isValid(const vector<string>& values) {
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