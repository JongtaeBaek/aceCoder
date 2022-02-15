#include "pch.h"
#include "modifier.h"
#include "member.h"
#include "ParameterChecker.h"

void sortMemberList(void)
{

}
void printSearchList(void)
{

}

Modifier::Modifier(vector<member>& inputList) : memberList(inputList)
{
}

Modifier::~Modifier()
{

}
int Modifier::Run(vector<string> values)
{
	string opt1 = values[MODPARAINDEX::MODIDXFIRSTOPT];
	string opt2 = values[MODPARAINDEX::MODIDXSECONDOPT];
	string opt3 = values[MODPARAINDEX::MODIDXTHIRDOPT];
	string findingIndex = values[MODPARAINDEX::MODIDXSEARCHOPTION];
	string findingValue = values[MODPARAINDEX::MODIDXSEARCHVALUE];
	string changingIndex = values[MODPARAINDEX::MODIDXCHANGEOPTION];
	string changingValue = values[MODPARAINDEX::MODIDXCHANGEVALUE];

	bool printOpt = false;
	if (opt1 == "p") printOpt = true;
	bool firstName = false;
	bool lastName = false;
	bool middleNumber = false;
	bool lastNumber = false;
	bool yearCheck = false;
	bool monthCheck = false;
	bool dayCheck = false;

	if (opt1 == "p") printOpt = true;

	switch (*opt2.c_str())
	{
	case 'f':
		firstName = true;
		break;
	case 'l':
		lastName = true;
		lastNumber = true;
		break;
	case 'm':
		firstName = true;
		monthCheck = true;
		break;
	case 'y':
		yearCheck = true;
		break;
	case 'd':
		dayCheck = true;
		break;
	default:
		break;
	}

	switch (*opt3.c_str())
	{
	default:
		cout << "not supported option" << endl;
		break;
	}

	vector<vector<member>::iterator> findingMember;
	vector<member>::iterator iter = memberList.begin();

	for (; iter != memberList.end(); iter++ )
	{
		if (findingIndex == "employeeNum")
		{
			if (iter->employeeNum == stoul(findingValue))
			{
				findingMember.push_back(iter);
			}
		}
		if (findingIndex == "name")
		{
			string verifyName = iter->name;
			string expectName = findingValue;
			if (firstName == true)
			{
				expectName.find(' ');
			}
			if (lastName == true)
			{
				expectName.find(' ');
			}
			if (expectName == findingValue)
			{
				findingMember.push_back(iter);
			}
		}
		if (findingIndex == "cl")
		{
			CL expectCl = getCL(findingValue);
			if (iter->cl == expectCl)
			{
				findingMember.push_back(iter);
			}
		}
		if (findingIndex == "phoneNum")
		{
			string verifyPhoneNum = iter->phoneNum;
			string expectPhoneNum = findingValue;
			if (middleNumber == true)
			{
				expectPhoneNum.find('-');
			}
			if (lastNumber == true)
			{
				expectPhoneNum.find('-');
			}
			if (expectPhoneNum == verifyPhoneNum)
			{
				findingMember.push_back(iter);
			}
		}
		if (findingIndex == "birthday")
		{
			unsigned int expectbirthday = iter->birthday;
			if (yearCheck == true)
			{
				expectbirthday &= 0xF0;
			}
			if (monthCheck == true)
			{
				expectbirthday &= 0xF0;
			}
			if (dayCheck == true)
			{
				expectbirthday &= 0xF0;
			}
			if (iter->birthday == stoul(findingValue))
			{
				findingMember.push_back(iter);
			}
		}
		if (findingIndex == "certi")
		{
			CERTI expectCerti = getCELTI(findingValue);
			if (iter->certi == expectCerti)
			{
				findingMember.push_back(iter);
			}
		}
	}
	if (findingMember.empty() == true) return -1;

	sortMemberList();
	printSearchList();

	for (auto changeMember : findingMember)
	{
		if (changingIndex == "name")
		{
			changeMember->name = changingValue;
		}
		if (changingIndex == "cl")
		{
			changeMember->cl = getCL(changingValue);
		}
		if (changingIndex == "phoneNum")
		{
			changeMember->phoneNum = changingValue;
		}
		if (changingIndex == "birthday")
		{
			changeMember->birthday = stoul(changingValue);
		}
		if (changingIndex == "certi")
		{
			changeMember->certi = getCELTI(changingValue);
		}
	}

	return 0;
}