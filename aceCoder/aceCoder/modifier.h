#pragma once
#include <string>
#include "member.h"
#include "ParameterChecker.h"
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

class Modifier : public ParameterChecker
{
public:
	Modifier(vector<member>& inputList);
	~Modifier();
	string run(const string& inputstring);
	string Modify(vector<string> values);
private:
	vector<member>& memberList;
};
