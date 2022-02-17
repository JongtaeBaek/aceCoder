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
		
		vector <member> retmembers; 
		int sum = search(cmd, retmembers, members_);
		
		if (sum == 0) {
			ret = "SCH,NONE\n";
			return ret;
		}

		if (schpara->parse(cmd)[1] == "-p") {
			for (auto& member : retmembers) {
				ret += "SCH," + schpara->getEmployeeNumString(member.employeeNum) + "," + member.name + "," + convert_CL(member.cl) + "," + member.phoneNum + "," + to_string(member.birthday) + "," + convert_CERTI(member.certi) + "\n";
			}
		}
		else {
			ret = "SCH," + to_string(sum) + "\n";
		}
		
		return ret;
	}
	
private:
	vector<member>& members_;
	int  search(string cmd, vector<member>& retmembers_, vector<member>& members_);
	vector<string> split(string s, string divid);
	string convert_CL(CL cl);
	string convert_CERTI(CERTI cl);
	string convert_ID(int num);
	bool compare_ID(const member &A, const member &B);
	void insert(vector<member>& members_, member member_);
};