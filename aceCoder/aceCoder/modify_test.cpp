#include "pch.h"
#include "member.h"
#include "modifier.h"


TEST(MODIFY_TEST_SUITE, TEST_FailToFindMemberThenReturnMinusValue) {
	// given empty list
	vector<member> testList;

	// when input empty list and run
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("A B");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return minus value
	EXPECT_EQ(-1, modifier->Run(cmdString));
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberWithName) {
	// given test member list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 12345678;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when find name and change cl
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("A B");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return success(0) and cl changed
	EXPECT_EQ(0, modifier->Run(cmdString));
	EXPECT_EQ(CL::CL3 , testList.begin()->cl);
}

