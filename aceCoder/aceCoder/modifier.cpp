#include "pch.h"
#include "modifier.h"
#include "member.h"
#include "ParameterChecker.h"

string ConvertCl(CL cl)
{
	if (cl == CL::CL1) return "CL1";
	if (cl == CL::CL2) return "CL2";
	if (cl == CL::CL3) return "CL3";
	if (cl == CL::CL4) return "CL4";
}

string ConvertCerti(CERTI certi)
{
	if (certi == CERTI::ADV) return "ADV";
	if (certi == CERTI::PRO) return "PRO";
	if (certi == CERTI::EX) return "EX";
}

string ConvertID(int num) {
	stringstream ss;

	// the number is converted to string with the help of stringstream
	ss << num;
	string ret;
	ss >> ret;

	// Append zero chars
	int str_length = ret.length();
	for (int i = 0; i < 8 - str_length; i++)
		ret = "0" + ret;
	return ret;
}

bool CompareEmployeeNum(unsigned int a, unsigned int b)
{
	unsigned int a_year = a / 1000000, b_year = b / 1000000;
	unsigned int a_Num = a % 1000000, b_Num = b % 1000000;

	a_year = (a_year <= 21) ? a_year + 100 : a_year;
	b_year = (b_year <= 21) ? b_year + 100 : b_year;

	if (a_year < b_year)
		return true;

	else if (a_year > b_year)
		return false;

	if (a_Num < b_Num)
		return true;

	return false;
}

void SaveSortMemberList(vector<member>& sortedList, member selectedMember)
{
	if (sortedList.empty())
	{
		sortedList.push_back(selectedMember);
		return;
	}
	unsigned int lastEmployeeNum = sortedList.back().employeeNum;
	unsigned int selectedEmployeeNum = selectedMember.employeeNum;

	if ((sortedList.size() < 5) || (CompareEmployeeNum(selectedEmployeeNum, lastEmployeeNum)))
	{
		int i = 0;
		for (; i < sortedList.size(); i++)
		{
			lastEmployeeNum = sortedList[i].employeeNum;
			if (CompareEmployeeNum(selectedEmployeeNum, lastEmployeeNum))
			{
				sortedList.insert(sortedList.begin() + i, selectedMember);
				break;
			}
		}
		if (i == sortedList.size()) sortedList.push_back(selectedMember);
	}

	if (sortedList.size() > 5) sortedList.pop_back();

}

string PrintList(vector<member>& findingMembers)
{
	string result;
	for (auto member : findingMembers)
	{
		result += "MOD,";
		result += ConvertID(member.employeeNum);
		result += "," + member.name;
		result += "," + ConvertCl(member.cl);
		result += "," + member.phoneNum;
		result += "," + to_string(member.birthday);
		result += "," + ConvertCerti(member.certi) + "\n";
	}
	return result;
}

Modifier::Modifier(vector<member>& inputList) : memberList(inputList)
{
}

Modifier::~Modifier()
{

}
string Modifier::run(const string& inputstring)
{
	return Modify(parse(inputstring));
}

string Modifier::Modify(vector<string> values)
{
	string result = "";
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

	if (opt1 == "-p") printOpt = true;
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
	vector<member> sortedMember;
	vector<member>::iterator iter = memberList.begin();

	if (findingIndex == "employeeNum")
	{
		for (; iter != memberList.end(); iter++)
		{
			if (iter->employeeNum == stoul(findingValue))
			{
				if (printOpt == true) SaveSortMemberList(sortedMember, *iter);
				findingMember.push_back(iter);
			}
		}
	}
	else if (findingIndex == "name")
	{
		string expectName = findingValue;

		for (; iter != memberList.end(); iter++)
		{
			string verifyName = iter->name;
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
				if (printOpt == true) SaveSortMemberList(sortedMember, *iter);
				findingMember.push_back(iter);
			}
		}
	}
	else if (findingIndex == "cl")
	{
		CL expectCl = getCL(findingValue);
		for (; iter != memberList.end(); iter++)
		{
			if (iter->cl == expectCl)
			{
				if (printOpt == true) SaveSortMemberList(sortedMember, *iter);
				findingMember.push_back(iter);
			}
		}
	}
	else if (findingIndex == "phoneNum")
	{
		string expectPhoneNum = findingValue;
		for (; iter != memberList.end(); iter++)
		{
			string verifyPhoneNum = iter->phoneNum;

			if (middleNumber == true)
			{
				verifyPhoneNum = verifyPhoneNum.substr(4, 4);
			}
			else if (lastNumber == true)
			{
				verifyPhoneNum = verifyPhoneNum.substr(9, 4);
			}
			if (expectPhoneNum == verifyPhoneNum)
			{
				if (printOpt == true) SaveSortMemberList(sortedMember, *iter);
				findingMember.push_back(iter);
			}
		}
	}
	else if (findingIndex == "birthday")
	{
		for (; iter != memberList.end(); iter++)
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
				if (printOpt == true) SaveSortMemberList(sortedMember, *iter);
				findingMember.push_back(iter);
			}
		}
	}
	else if (findingIndex == "certi")
	{
		CERTI expectCerti = getCELTI(findingValue);
		for (; iter != memberList.end(); iter++)
		{
			if (iter->certi == expectCerti)
			{
				if (printOpt == true) SaveSortMemberList(sortedMember, *iter);
				findingMember.push_back(iter);
			}
		}
	}

	if (findingMember.empty() == true)
	{
		return "MOD,NONE\n";
	}

	if (printOpt == true)
	{
		result += PrintList(sortedMember);
	}
	else
	{
		if (findingMember.size() > 5)
		{
			result += "MOD,5\n";
		}
		else
		{
			result += "MOD," + to_string(findingMember.size()) + "\n";
		}
	}

	if (changingIndex == "name")
	{
		for (auto changeMember : findingMember)
		{
			changeMember->name = changingValue;
		}
	}
	else if (changingIndex == "cl")
	{
		for (auto changeMember : findingMember)
		{
			changeMember->cl = getCL(changingValue);
		}
	}
	else if (changingIndex == "phoneNum")
	{
		for (auto changeMember : findingMember)
		{
			changeMember->phoneNum = changingValue;
		}
	}
	else if (changingIndex == "birthday")
	{
		for (auto changeMember : findingMember)
		{
			changeMember->birthday = stoul(changingValue);
		}
	}
	else if (changingIndex == "certi")
	{
		for (auto changeMember : findingMember)
		{
			changeMember->certi = getCELTI(changingValue);
		}
	}

	return result;
}