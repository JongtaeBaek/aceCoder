#pragma once
#include <string>
#include "member.h"
#include "ModParameterChecker.h"
#include "Command.h"
using namespace std;

class Modifier : public Command
{
public:
	Modifier(vector<member>& inputList, ParameterChecker* paramChecker);
	~Modifier();
	string run(const string& inputstring) override;
	string Modify(vector<string> values);
private:
	string GetSearchResult(vector<string>& values, vector<vector<member>::iterator>& findingMembers);
	void SearchMember(const vector<string>& values, vector<vector<member>::iterator>& findingMember);
	void ModifyRecord(vector<string>& values, vector<vector<member>::iterator>& findingMembers);
	string GetVerifyName(const vector<string>& values, const string& name);
	string GetVerifyPhoneNum(const vector<string>& values, const string& phoneNum);
	unsigned int GetVerifyBirthDay(const vector<string>& values, const unsigned int& birthDay);
	vector<member>& memberList;
	ParameterChecker* paramChecker;
};
