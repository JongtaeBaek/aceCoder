#include "pch.h"
#include "modifier.h"
#include "member.h"
#include "ParameterChecker.h"

Modifier::Modifier(vector<member>& inputList, ParameterChecker* paramChecker)
	: memberList(inputList), paramChecker(paramChecker)
{
}

Modifier::~Modifier()
{
	if (paramChecker != nullptr) delete paramChecker;
}

string Modifier::run(const string& inputstring)
{
	if (paramChecker == nullptr)
	{
		cout << "modifier init fail" << endl;
		return "";
	}
	if (paramChecker->isValid(paramChecker->parse(inputstring)) == false) return "";
	return Modify(paramChecker->parse(inputstring));
}

string Modifier::Modify(vector<string> values)
{
	string result = "";

	vector<vector<member>::iterator> findingMember;
	SearchMember(values, findingMember);

	if (findingMember.empty() == true)
	{
		return "MOD,NONE\n";
	}

	result += GetSearchResult(values, findingMember);

	ModifyRecord(values, findingMember);

	return result;
}

void Modifier::SearchMember(const vector<string>& values, vector<vector<member>::iterator>& findingMember)
{
	vector<member>::iterator iter = memberList.begin();
	string findingValue = values[MODPARAINDEX::MODIDXSEARCHVALUE];

	if (values[MODPARAINDEX::MODIDXSEARCHOPTION] == "employeeNum")
	{
		for (; iter != memberList.end(); iter++)
		{
			if (iter->employeeNum == paramChecker->getEmployeeNum(findingValue))
			{
				findingMember.push_back(iter);
			}
		}
	}
	else if (values[MODPARAINDEX::MODIDXSEARCHOPTION] == "name")
	{
		for (; iter != memberList.end(); iter++)
		{
			if (findingValue == GetVerifyName(values, iter->name))
			{
				findingMember.push_back(iter);
			}
		}
	}
	else if (values[MODPARAINDEX::MODIDXSEARCHOPTION] == "cl")
	{
		for (; iter != memberList.end(); iter++)
		{
			if (iter->cl == paramChecker->getCL(findingValue))
			{
				findingMember.push_back(iter);
			}
		}
	}
	else if (values[MODPARAINDEX::MODIDXSEARCHOPTION] == "phoneNum")
	{
		for (; iter != memberList.end(); iter++)
		{
			if (findingValue == GetVerifyPhoneNum(values, iter->phoneNum))
			{
				findingMember.push_back(iter);
			}
		}
	}
	else if (values[MODPARAINDEX::MODIDXSEARCHOPTION] == "birthday")
	{
		for (; iter != memberList.end(); iter++)
		{
			if (stoul(findingValue) == GetVerifyBirthDay(values, iter->birthday))
			{
				findingMember.push_back(iter);
			}
		}
	}
	else if (values[MODPARAINDEX::MODIDXSEARCHOPTION] == "certi")
	{
		for (; iter != memberList.end(); iter++)
		{
			if (paramChecker->getCERTI(findingValue) == iter->certi)
			{
				findingMember.push_back(iter);
			}
		}
	}
}

string Modifier::GetSearchResult(vector<string>& values, vector<vector<member>::iterator>& findingMembers)
{
	string result;
	if (values[MODPARAINDEX::MODIDXOPT1] == "-p")
	{
		int printCount = 0;
		for (auto member : findingMembers)
		{
			printCount++;
			result += "MOD,";
			result += paramChecker->getEmployeeNumString(member->employeeNum);
			result += "," + member->name;
			result += "," + paramChecker->getClString(member->cl);
			result += "," + member->phoneNum;
			result += "," + to_string(member->birthday);
			result += "," + paramChecker->getCertiString(member->certi) + "\n";
			if (printCount == 5) break;
		}
	}
	else
	{
		result += "MOD," + to_string(findingMembers.size()) + "\n";
	}
	return result;
}

void Modifier::ModifyRecord(vector<string>& values, vector<vector<member>::iterator>& findingMembers)
{
	if (values[MODPARAINDEX::MODIDXCHANGEOPTION] == "name")
	{
		for (auto changeMember : findingMembers)
		{
			changeMember->name = values[MODPARAINDEX::MODIDXCHANGEVALUE];
		}
	}
	else if (values[MODPARAINDEX::MODIDXCHANGEOPTION] == "cl")
	{
		for (auto changeMember : findingMembers)
		{
			changeMember->cl = paramChecker->getCL(values[MODPARAINDEX::MODIDXCHANGEVALUE]);
		}
	}
	else if (values[MODPARAINDEX::MODIDXCHANGEOPTION] == "phoneNum")
	{
		for (auto changeMember : findingMembers)
		{
			changeMember->phoneNum = values[MODPARAINDEX::MODIDXCHANGEVALUE];
		}
	}
	else if (values[MODPARAINDEX::MODIDXCHANGEOPTION] == "birthday")
	{
		for (auto changeMember : findingMembers)
		{
			changeMember->birthday = stoul(values[MODPARAINDEX::MODIDXCHANGEVALUE]);
		}
	}
	else if (values[MODPARAINDEX::MODIDXCHANGEOPTION] == "certi")
	{
		for (auto changeMember : findingMembers)
		{
			changeMember->certi = paramChecker->getCERTI(values[MODPARAINDEX::MODIDXCHANGEVALUE]);
		}
	}
}

string Modifier::GetVerifyName(const vector<string>& values, const string& name)
{
	string verifyName = name;
	int positionOfBlank = verifyName.find(" ");
	if (values[MODPARAINDEX::MODIDXOPT2] == "-f")
	{
		verifyName = verifyName.substr(0, positionOfBlank);
	}
	else if (values[MODPARAINDEX::MODIDXOPT2] == "-l")
	{
		verifyName = verifyName.substr(positionOfBlank + 1, verifyName.size() - positionOfBlank);
	}
	return verifyName;
}

string Modifier::GetVerifyPhoneNum(const vector<string>& values, const string& phoneNum)
{
	string verifyPhoneNum = phoneNum;
	static const int middleNumStartPos = 4;
	static const int lastNumStartPos = 9;
	static const int splitPhoneNumSize = 4;

	if (values[MODPARAINDEX::MODIDXOPT2] == "-m")
	{
		verifyPhoneNum = verifyPhoneNum.substr(middleNumStartPos, splitPhoneNumSize);
	}
	else if (values[MODPARAINDEX::MODIDXOPT2] == "-l")
	{
		verifyPhoneNum = verifyPhoneNum.substr(lastNumStartPos, splitPhoneNumSize);
	}

	return verifyPhoneNum;
}

unsigned int Modifier::GetVerifyBirthDay(const vector<string>& values, const unsigned int& birthDay)
{
	unsigned int savedbirthday = birthDay;
	if (values[MODPARAINDEX::MODIDXOPT2] == "-y")
	{
		savedbirthday = savedbirthday / 10000;
	}
	else if (values[MODPARAINDEX::MODIDXOPT2] == "-m")
	{
		savedbirthday = (savedbirthday % 10000) / 100;
	}
	else if (values[MODPARAINDEX::MODIDXOPT2] == "-d")
	{
		savedbirthday = savedbirthday % 100;
	}
	return savedbirthday;
}
