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

bool Sch::compare_ID(const member& A, const member& B) {
	unsigned int A_id_year = stoi(convert_ID(A.employeeNum).substr(0, 2));
	unsigned int B_id_year = stoi(convert_ID(B.employeeNum).substr(0, 2));

	unsigned int A_id = stoi(convert_ID(A.employeeNum).substr(2, 6));
	unsigned int B_id = stoi(convert_ID(B.employeeNum).substr(2, 6));
	
	A_id_year = (A_id_year < 22) ? A_id_year + 100 : A_id_year;
	B_id_year = (B_id_year < 22) ? B_id_year + 100 : B_id_year;

	if (A_id_year < B_id_year) {
		return true;
	}
	else if (A_id_year == B_id_year) {
		if (A_id < B_id) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void Sch::insert(vector<member>& members_, member member_) {
	for (int i = 0; i < members_.size();i++) {
		if (compare_ID(member_, members_[i])) {
			members_.insert(members_.begin() + i, member_);
			if (members_.size() > 5) {
				members_.pop_back();
			}
			return;
		}
	}

	members_.push_back(member_);
}


int Sch::search(string cmd, vector<member>& retmembers_, vector<member>& members_) {
	int ret = 0;
	vector <string> cmd_arr = split(cmd, ",");

	if (cmd_arr[4] == "name") {
		if (cmd_arr[2] == "-f") {
			for (auto member : members_) {
				vector <string> name_arr = split(member.name, " ");
				if (name_arr[0] == cmd_arr[5]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[2] == "-l") {
			for (auto member : members_) {
				vector <string> name_arr = split(member.name, " ");
				if (name_arr[1] == cmd_arr[5]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[2] == " ") {
			for (auto member : members_) {
				if (member.name == cmd_arr[5]) {
					insert(retmembers_, member);
					ret++;
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
				insert(retmembers_, member);
				ret++;
			}
		}
	}
	else if (cmd_arr[4] == "phoneNum") {
		if (cmd_arr[2] == "-m") {
			for (auto member : members_) {
				vector <string> phonenum_arr = split(member.phoneNum, "-");
				if (phonenum_arr[1] == cmd_arr[5]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[2] == "-l") {
			for (auto member : members_) {
				vector <string> phonenum_arr = split(member.phoneNum, "-");
				if (phonenum_arr[2] == cmd_arr[5]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[2] == " ") {
			for (auto member : members_) {
				if (member.phoneNum == cmd_arr[5]) {
					insert(retmembers_, member);
					ret++;
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
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[2] == "-m") {
			for (auto member : members_) {
				if (to_string(member.birthday).substr(4, 2) == cmd_arr[5]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[2] == "-d") {
			for (auto member : members_) {
				if (to_string(member.birthday).substr(6, 2) == cmd_arr[5]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else if (cmd_arr[2] == " ") {
			for (auto member : members_) {
				if (to_string(member.birthday) == cmd_arr[5]) {
					insert(retmembers_, member);
					ret++;
				}
			}
		}
		else {
			return ret;
		}
	}
	else if (cmd_arr[4] == "certi") {
		for (auto member : members_) {
			if (convert_CERTI(member.certi) == cmd_arr[5]) {
				insert(retmembers_, member);
				ret++;
			}
		}
	}
	else if (cmd_arr[4] == "employeeNum") {
		for (auto member : members_) {
			if (convert_ID(member.employeeNum) == cmd_arr[5]) {
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

