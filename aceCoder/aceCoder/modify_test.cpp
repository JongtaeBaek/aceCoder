#include "pch.h"
#include "member.h"
#include "modifier.h"


TEST(MODIFY_TEST_SUITE, TEST_FailToFindMemberThenReturnMinusValue) {
	// given empty list
	vector<member> testList;

	// when input empty list and run
	Modifier* modifier = new Modifier(testList);
	char option1 = ' ';
	char option2 = ' ';
	char option3 = ' ';
	string finding1 = "name";
	string finding2 = "A B";
	string changing1 = "CL";
	string changing2 = "CL3";

	// then modifier run return minus value
	EXPECT_EQ(-1, modifier->Run(option1, option2, option3, finding1, finding2, changing1, changing2));
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
	char option1 = ' ';
	char option2 = ' ';
	char option3 = ' ';
	string finding1 = "name";
	string finding2 = "A B";
	string changing1 = "cl";
	string changing2 = "CL3";

	// then modifier run return success(0) and cl changed
	EXPECT_EQ(0, modifier->Run(option1, option2, option3, finding1, finding2, changing1, changing2));
	EXPECT_EQ(CL::CL3 , testList.begin()->cl);
}