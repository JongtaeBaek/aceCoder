#include "pch.h"
#include "Sch.h"

vector<string> Sch::split(string s, string divid) {
	vector<string> v;
	char* c = strtok((char*)s.c_str(), divid.c_str());
	while (c) {
		v.push_back(c);
		c = strtok(NULL, divid.c_str());
	}
	return v;
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

string Sch::convert_ID(int num){
	stringstream ss;

	// the number is converted to string with the help of stringstream
	ss << num;
	string ret;
	ss >> ret;

	// Append zero chars
	int str_length = ret.length();
	for (int i = 0; i < 8 - str_length; i++)
		ret = "0" + ret;
	return ret;
}

void Sch::Sort_member(vector <member> &members) {
	//구현 예정
}

vector<member>  Sch::search(string cmd, vector<member>& members_) {
	vector<member> ret;

	vector <string> cmd_arr = split(cmd, ",");

	if (cmd_arr[4] == "name") {
		if (cmd_arr[2] == "-f") {
			for (auto member : members_) {
				vector <string> name_arr = split(member.name, " ");
				if (name_arr[0] == cmd_arr[5]) {
					ret.push_back(member);
						
				}
			}
		}
		else if (cmd_arr[2] == "-l") {
			for (auto member : members_) {
				vector <string> name_arr = split(member.name, " ");
				if (name_arr[1] == cmd_arr[5]) {
					ret.push_back(member);
				}
			}
		}
		else {
			return ret;
		}
	}
	else if (cmd_arr[4] == "cl") {
		for (auto member : members_) {
			if (convert_CL(member.cl) == cmd_arr[5]) {
				ret.push_back(member);
			}
		}
	}
	else if (cmd_arr[4] == "phoneNum") {
		if (cmd_arr[2] == "-m") {
			for (auto member : members_) {
				vector <string> phonenum_arr = split(member.phoneNum, "-");
				if (phonenum_arr[1] == cmd_arr[5]) {
					ret.push_back(member);
				}
			}
		}
		else if (cmd_arr[2] == "-l") {
			for (auto member : members_) {
				vector <string> phonenum_arr = split(member.phoneNum, "-");
				if (phonenum_arr[2] == cmd_arr[5]) {
					ret.push_back(member);
				}
			}
		}
		else {
			return ret;
		}
	}
	else if (cmd_arr[4] == "birthday") {
		if (cmd_arr[2] == "-y") {
			for (auto member : members_) {
				if (to_string(member.birthday).substr(0, 4) == cmd_arr[5]) {
					ret.push_back(member);
				}
			}
		}
		else if (cmd_arr[2] == "-m") {
			for (auto member : members_) {
				if (to_string(member.birthday).substr(4, 2) == cmd_arr[5]) {
					ret.push_back(member);
				}
			}
		}
		else if (cmd_arr[2] == "-d") {
			for (auto member : members_) {
				if (to_string(member.birthday).substr(6, 2) == cmd_arr[5]) {
					ret.push_back(member);
				}
			}
		}
		else {
			return ret;
		}
	}
	else {
		return ret;
	}

	return ret;

}