#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "member.h"
#include "SchParameterChecker.h"

class Sch {
public:
	Sch(vector<member>& members) : members_(members) {}
	virtual ~Sch() = default;

	string run(string cmd) {
		string ret = "";

		ParameterChecker* schpara = new SchParameterChecker();
		vector<string> values = schpara->parse(cmd);
		if (!schpara->isValid(values))
			return "";
		
		vector <member> members = search(cmd, members_);
		
		Sort_member(members);
		
		if (members.empty()) {
			ret = "SCH,NONE\n";
			return ret;
		}

		if (schpara->parse(cmd)[1] == "-p") {
			for (auto& member : members) {
				if (members.size() > 5 && compare_fifth_member(member, members[5])) {
					break;
				}
				ret += "SCH," + convert_ID(member.employeeNum) + "," + member.name + "," + convert_CL(member.cl) + "," + member.phoneNum + "," + to_string(member.birthday) + "," + convert_CERTI(member.certi) + "\n";
			}
		}
		else {
			ret = "SCH," + to_string(members.size()) + "\n";
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
	bool compare_fifth_member(const member &A, const member &B);
	bool compare_ID(const member &A, const member &B);
	void Sort_member(vector <member> &members);
};