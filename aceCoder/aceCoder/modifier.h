#pragma once
#include <string>
#include "member.h"
#include "ParameterChecker.h"
#include "Command.h"
using namespace std;

enum MODPARAINDEX {
	MODIDXCMD = 0,
	MODIDXFIRSTOPT,
	MODIDXSECONDOPT,
	MODIDXTHIRDOPT,
	MODIDXSEARCHOPTION,
	MODIDXSEARCHVALUE,
	MODIDXCHANGEOPTION,
	MODIDXCHANGEVALUE
};

class Modifier : public ParameterChecker , public Command
{
public:
	Modifier(vector<member>& inputList);
	~Modifier();
	string run(const string& inputstring) override;
	string Modify(vector<string> values);
	string PrintList(vector<member>& findingMembers);
private:
	vector<member>& memberList;
};
