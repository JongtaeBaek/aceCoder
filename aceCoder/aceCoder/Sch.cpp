#include "pch.h"
#include "Sch.h"

#define MAX_FIND_MEMBER 5

enum commandField {
	CMD,
	OPT1,
	OPT2,
	OPT3,
	FILED_NAME,
	FILED_VALUE
};

enum nameField {
	FIRST_NAME,
	LAST_NAME
};

enum phonenumField {
	FIRST_NUM,
	MIDDLE_NUM,
	LAST_NUM
};

enum birthdayField {
	YEAR,
	MONTH,
	DAY,
	FULL
};

enum fieldName {
	MEMBER_NAME,
	MEMBER_ID,
	MEMBER_PHONE_NUM,
	MEMBER_CL,
	MEMBER_CERTI,
	MEMBER_BIRTH,
};

enum optionName {
	OPT_FIRST,
	OPT_LAST,
	OPT_MIDDLE,
	OPT_YEAR,
	OPT_MONTH,
	OPT_DAY,
	OPT_BLANK
};

string getOptionname(optionName name)
{
	switch (name) {
	case OPT_FIRST:return "-f";
	case OPT_LAST:return "-l";
	case OPT_MIDDLE:return "-m";
	case OPT_YEAR:return "-y";
	case OPT_MONTH:return "-m";
	case OPT_DAY:return "-d";
	case OPT_BLANK:return " ";
	}
}

string getFieldname(fieldName name)
{
	switch (name){
	case MEMBER_NAME:return "name";
	case MEMBER_ID:return "employeeNum";
	case MEMBER_PHONE_NUM:return "phoneNum";
	case MEMBER_CL:return "cl";
	case MEMBER_CERTI:return "certi";
	case MEMBER_BIRTH:return "birthday";
	}
}

string getBirthday(int birthDay, birthdayField field) {
	switch (field) {
	case YEAR:return to_string(birthDay).substr(0, 4);
	case MONTH:return to_string(birthDay).substr(4, 2);
	case DAY:return to_string(birthDay).substr(6, 2);
	case FULL:return to_string(birthDay);
	}
}

vector<string> split(string str, string divid) {
	vector<string> ret;
	char* character = strtok((char*)str.c_str(), divid.c_str());
	while (character) {
		ret.push_back(character);
		character = strtok(NULL, divid.c_str());
	}
	return ret;
}

string Sch::convert_CL(CL cl) {
	switch (cl) {
		case CL1:return "CL1";
		case CL2:return "CL2";
		case CL3:return "CL3";
		case CL4:return "CL4";
	}
}

string Sch::convert_CERTI(CERTI cl) {
	switch (cl) {
		case ADV:return "ADV";
		case PRO:return "PRO";
		case EX:return "EX";
	}

}

void insert(vector<member>& members_, member member_) {
	if (members_.size() >= MAX_FIND_MEMBER) {
		return;
	}
	members_.push_back(member_);
}

int Sch::search(string cmd, vector<member>& retmembers_, vector<member>& members_) {
	int ret = 0;
	vector <string> cmd_arr = split(cmd, ",");
	ParameterChecker* schpara = new SchParameterChecker();

	if (cmd_arr[FILED_NAME] == getFieldname(MEMBER_NAME)) {
		if (cmd_arr[OPT2] == getOptionname(OPT_FIRST)) {
			for (auto member : members_) {
				vector <string> name_arr = split(member.name, " ");
				if (name_arr[FIRST_NAME] == cmd_arr[FILED_VALUE]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[OPT2] == getOptionname(OPT_LAST)) {
			for (auto member : members_) {
				vector <string> name_arr = split(member.name, " ");
				if (name_arr[LAST_NAME] == cmd_arr[FILED_VALUE]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[OPT2] == getOptionname(OPT_BLANK)) {
			for (auto member : members_) {
				if (member.name == cmd_arr[FILED_VALUE]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else {
			return ret;
		}
	}
	else if (cmd_arr[FILED_NAME] == getFieldname(MEMBER_CL)) {
		for (auto member : members_) {
			if (convert_CL(member.cl) == cmd_arr[FILED_VALUE]) {
				insert(retmembers_, member);
				ret++;
			}
		}
	}
	else if (cmd_arr[FILED_NAME] == getFieldname(MEMBER_PHONE_NUM)) {
		if (cmd_arr[OPT2] == getOptionname(OPT_MIDDLE)) {
			for (auto member : members_) {
				vector <string> phonenum_arr = split(member.phoneNum, "-");
				if (phonenum_arr[MIDDLE_NUM] == cmd_arr[FILED_VALUE]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[OPT2] == getOptionname(OPT_LAST)) {
			for (auto member : members_) {
				vector <string> phonenum_arr = split(member.phoneNum, "-");
				if (phonenum_arr[LAST_NUM] == cmd_arr[FILED_VALUE]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[OPT2] == getOptionname(OPT_BLANK)) {
			for (auto member : members_) {
				if (member.phoneNum == cmd_arr[FILED_VALUE]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else {
			return ret;
		}
	}
	else if (cmd_arr[FILED_NAME] == getFieldname(MEMBER_BIRTH)) {
		if (cmd_arr[OPT2] == getOptionname(OPT_YEAR)) {
			for (auto member : members_) {
				if (getBirthday(member.birthday, YEAR) == cmd_arr[FILED_VALUE]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[OPT2] == getOptionname(OPT_MONTH)) {
			for (auto member : members_) {
				if (getBirthday(member.birthday, MONTH) == cmd_arr[FILED_VALUE]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[OPT2] == getOptionname(OPT_DAY)) {
			for (auto member : members_) {
				if (getBirthday(member.birthday, DAY) == cmd_arr[FILED_VALUE]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[OPT2] == getOptionname(OPT_BLANK)) {
			for (auto member : members_) {
				if (getBirthday(member.birthday, FULL) == cmd_arr[FILED_VALUE]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else {
			return ret;
		}
	}
	else if (cmd_arr[FILED_NAME] == getFieldname(MEMBER_CERTI)) {
		for (auto member : members_) {
			if (convert_CERTI(member.certi) == cmd_arr[FILED_VALUE]) {
				insert(retmembers_, member);
				ret++;
			}
		}
	}
	else if (cmd_arr[FILED_NAME] == getFieldname(MEMBER_ID)) {
		for (auto member : members_) {
			if (schpara->getEmployeeNumString(member.employeeNum) == cmd_arr[FILED_VALUE]) {
				insert(retmembers_, member);
				ret++;
			}
		}
	}
	else {
		return ret;
	}

	return ret;

}

