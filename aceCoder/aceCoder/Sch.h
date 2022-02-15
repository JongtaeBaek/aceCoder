#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "member.h"
#include "ParameterChecker.h"


class Sch {
public:
	Sch(vector<member>& members) : members_(members) {}
	virtual ~Sch() = default;

	string run(string cmd) {
		ParameterChecker* para = new ParameterChecker();
		if (para->isValid(para->parse(cmd))) {
			return "";
		}

		vector <member> members = search(cmd, members_);
		Sort_member(members);
		
		string ret = "";
		if (para->parse(cmd)[1] == "-p") {
			for (const auto& member : members) {
				cout << (ret += "SCH," + convert_ID(member.employeeNum) + "," + member.name + "," + convert_CL(member.cl) + "," + member.phoneNum + "," + to_string(member.birthday) + "," + convert_CERTI(member.certi)) << endl;
			}
		}
		else if (!ret.empty()){
			cout << (ret += "SCH," + to_string(members.size())) << endl;
		}
		else {
			cout << (ret = "SCH,NONE") << endl;
		}
		
		return ret;
	}
	
private:
	vector<member>& members_;
	vector<member>  search(string cmd, vector<member>& members_);
	vector<string> split(string s, string divid);
	string convert_CL(CL cl);
	string convert_CERTI(CERTI cl);
	string convert_ID(int num);
	void Sort_member(vector <member> &members);
};