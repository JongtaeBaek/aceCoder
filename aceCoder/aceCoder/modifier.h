#pragma once
#include <string>
#include "member.h"
using namespace std;

class Modifier
{
public:
	Modifier(vector<member>& inputList);
	~Modifier();
	int Run(char opt1, char opt2, char opt3, string findingIndex, string findingValue, string changingIndex, string changingValue);
private:
	vector<member>& memberList;
};
