#include "pch.h"
#include "modifier.h"
#include "member.h"

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

int Modifier::Run(char opt1, char opt2, char opt3,
	string findingIndex, string findingValue, string changingIndex, string changingValue)
{
	bool printOpt = false;
	if (opt1 == 'p') printOpt = true;
	bool firstName = false;
	bool lastName = false;
	bool middleNumber = false;
	bool lastNumber = false;
	bool yearCheck = false;
	bool monthCheck = false;
	bool dayCheck = false;

	if (opt1 == 'p') printOpt = true;

	switch (opt2)
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

	switch (opt3)
	{
	default:
		cout << "not supported option" << endl;
		break;
	}

	vector<vector<member>::iterator> findingMember;
	vector<member>::iterator iter = memberList.begin();

	//for (auto findMember : memberList)
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
			CL expectCl = CL::CL1;
			if (findingValue == "CL1") expectCl = CL::CL1;
			if (findingValue == "CL2") expectCl = CL::CL2;
			if (findingValue == "CL3") expectCl = CL::CL3;
			if (findingValue == "CL4") expectCl = CL::CL4;
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
			CERTI expectCerti = CERTI::ADV;
			if (findingValue == "ADV") expectCerti = CERTI::ADV;
			if (findingValue == "PRO") expectCerti = CERTI::PRO;
			if (findingValue == "EX") expectCerti = CERTI::EX;
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
			CL changeCl;
			if (changingValue == "CL1") changeCl = CL::CL1;
			if (changingValue == "CL2") changeCl = CL::CL2;
			if (changingValue == "CL3") changeCl = CL::CL3;
			if (changingValue == "CL4") changeCl = CL::CL4;
			changeMember->cl = changeCl;
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
			CERTI changeCerti;
			if (changingValue == "ADV") changeCerti = CERTI::ADV;
			if (changingValue == "PRO") changeCerti = CERTI::PRO;
			if (changingValue == "EX") changeCerti = CERTI::EX;
			changeMember->certi = changeCerti;
		}
	}

	return 0;
}