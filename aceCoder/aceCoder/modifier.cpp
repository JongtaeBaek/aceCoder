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
	bool firstName = false;
	bool lastName = false;
	bool middleNumber = false;
	bool lastNumber = false;
	bool yearCheck = false;
	bool monthCheck = false;
	bool dayCheck = false;

	if (opt1 == "p") printOpt = true;
	if (opt2 == "-f")
	{
		firstName = true;
	}
	else if (opt2 == "-l")
	{
		lastName = true;
		lastNumber = true;
	}
	else if (opt2 == "-m")
	{
		middleNumber = true;
		firstName = true;
		monthCheck = true;
	}
	else if (opt2 == "-y")
	{
		yearCheck = true;
	}
	else if (opt2 == "-d")
	{
		dayCheck = true;
	}

	if (opt3 != " ")
	{
		cout << "not supported option" << endl;
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
		else if (findingIndex == "name")
		{
			string verifyName = iter->name;
			string expectName = findingValue;
			int positionOfBlank = verifyName.find(" ");
			if (firstName == true)
			{
				verifyName = verifyName.substr(0, positionOfBlank);
			}
			else if (lastName == true)
			{
				verifyName = verifyName.substr(positionOfBlank + 1, verifyName.size() - positionOfBlank);
			}
			if (expectName == verifyName)
			{
				findingMember.push_back(iter);
			}
		}
		else if (findingIndex == "cl")
		{
			CL expectCl = getCL(findingValue);
			if (iter->cl == expectCl)
			{
				findingMember.push_back(iter);
			}
		}
		else if (findingIndex == "phoneNum")
		{
			string verifyPhoneNum = iter->phoneNum;
			string expectPhoneNum = findingValue;
			if (middleNumber == true)
			{
				verifyPhoneNum = verifyPhoneNum.substr(4, 4);
			}
			else if (lastNumber == true)
			{
				verifyPhoneNum = verifyPhoneNum.substr(9,4);
			}
			if (expectPhoneNum == verifyPhoneNum)
			{
				findingMember.push_back(iter);
			}
		}
		else if (findingIndex == "birthday")
		{
			unsigned int savedbirthday = iter->birthday;
			if (yearCheck == true)
			{
				savedbirthday = savedbirthday / 10000;
			}
			else if (monthCheck == true)
			{
				savedbirthday = (savedbirthday % 10000) / 100;
			}
			else if (dayCheck == true)
			{
				savedbirthday = savedbirthday % 100;
			}
			if (savedbirthday == stoul(findingValue))
			{
				findingMember.push_back(iter);
			}
		}
		else if (findingIndex == "certi")
		{
			CERTI expectCerti = getCELTI(findingValue);
			if (iter->certi == expectCerti)
			{
				findingMember.push_back(iter);
			}
		}
	}
	if (findingMember.empty() == true) return -1;

	if (printOpt == true)
	{
		sortMemberList();
		printSearchList();
	}

	for (auto changeMember : findingMember)
	{
		if (changingIndex == "name")
		{
			changeMember->name = changingValue;
		}
		else if (changingIndex == "cl")
		{
			changeMember->cl = getCL(changingValue);
		}
		else if (changingIndex == "phoneNum")
		{
			changeMember->phoneNum = changingValue;
		}
		else if (changingIndex == "birthday")
		{
			changeMember->birthday = stoul(changingValue);
		}
		else if (changingIndex == "certi")
		{
			changeMember->certi = getCELTI(changingValue);
		}
	}

	return 0;
}