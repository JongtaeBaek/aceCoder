#include "pch.h"
#include "member.h"
#include "modifier.h"


TEST(MODIFY_TEST_SUITE, TEST_FailToFindMemberWithEmptyListThenReturnMinusValue) {
	// given empty list
	vector<member> testList;

	// when input empty list and Modify
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

	// then modifier Modify return minus value
	string resultStr = "MOD,NONE\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
}

TEST(MODIFY_TEST_SUITE, TEST_FailToFindMemberWithWrongNameThenReturnMinusValue) {
	// given empty list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 12345678;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when input empty list and run
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("A A");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return minus value
	string resultStr = "MOD,NONE\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_NE(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_FailToFindMemberWithWrongEmployeeNumThenReturnMinusValue) {
	// given empty list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 12345678;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when input empty list and run
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back("employeeNum");
	cmdString.push_back("121260099");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return minus value
	string resultStr = "MOD,NONE\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_NE(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_FailToFindMemberWithWrongCLThenReturnMinusValue) {
	// given empty list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 12345678;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when input empty list and run
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back("cl");
	cmdString.push_back("CL2");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return minus value
	string resultStr = "MOD,NONE\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_NE(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_FailToFindMemberWithWrongPhoneNumThenReturnMinusValue) {
	// given empty list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 12345678;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when input empty list and run
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back("phoneNum");
	cmdString.push_back("010-5678-1234");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return minus value
	string resultStr = "MOD,NONE\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_NE(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_FailToFindMemberWithWrongBirthDayThenReturnMinusValue) {
	// given empty list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 12345678;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when input empty list and run
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back("birthday");
	cmdString.push_back("19990213");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return minus value
	string resultStr = "MOD,NONE\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_NE(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_FailToFindMemberWithWrongCertiThenReturnMinusValue) {
	// given empty list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 12345678;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when input empty list and run
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back("certi");
	cmdString.push_back("PRO");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return minus value
	string resultStr = "MOD,NONE\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_NE(CL::CL3, testList.begin()->cl);
}
TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithName) {
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
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3 , testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithEmployeeNum) {
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
	cmdString.push_back("employeeNum");
	cmdString.push_back("12345678");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithCL) {
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
	cmdString.push_back("cl");
	cmdString.push_back("CL1");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithPhoneNum) {
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
	cmdString.push_back("phoneNum");
	cmdString.push_back("010-1234-5678");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithBItrhDay) {
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
	cmdString.push_back("birthday");
	cmdString.push_back("19990215");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithCerti) {
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
	cmdString.push_back("certi");
	cmdString.push_back("ADV");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier run return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithFirstNameOption) {
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
	cmdString.push_back("-f");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("A");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithLastNameOption) {
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
	cmdString.push_back("-l");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("B");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithMiddlePhoneNumOption) {
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
	cmdString.push_back("-m");
	cmdString.push_back(" ");
	cmdString.push_back("phoneNum");
	cmdString.push_back("1234");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithLastPhoneNumOption) {
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
	cmdString.push_back("-l");
	cmdString.push_back(" ");
	cmdString.push_back("phoneNum");
	cmdString.push_back("5678");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithBirthDayYearOption) {
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
	cmdString.push_back("-y");
	cmdString.push_back(" ");
	cmdString.push_back("birthday");
	cmdString.push_back("1999");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithBirthDayMonthOption) {
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
	cmdString.push_back("-m");
	cmdString.push_back(" ");
	cmdString.push_back("birthday");
	cmdString.push_back("02");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToChangeMemberCLWithBirthDayDayOption) {
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
	cmdString.push_back("-d");
	cmdString.push_back(" ");
	cmdString.push_back("birthday");
	cmdString.push_back("15");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,1\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}


TEST(MODIFY_TEST_SUITE, TEST_FailToPrintDoNotFindMemberWithWrongCertiThenReturnMinusValueAndPrintNone) {
	// given empty list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 12345678;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when input empty list and Modify
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back("-p");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back("certi");
	cmdString.push_back("PRO");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return minus value
	string resultStr = "MOD,NONE\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_NE(CL::CL3, testList.begin()->cl);
}
TEST(MODIFY_TEST_SUITE, TEST_SuccessToPrintMemberInfoAndChangeClWithName) {
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
	cmdString.push_back("-p");
	cmdString.push_back(" ");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("A B");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,12345678,A B,CL1,010-1234-5678,19990215,ADV\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	EXPECT_EQ(CL::CL3, testList.begin()->cl);
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToPrintMultiMemberInfoAndChangeClWithName) {
	// given test member list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 12345670;
	testMember.name = "A A";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345671;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345672;
	testMember.name = "A C";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345673;
	testMember.name = "A D";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345674;
	testMember.name = "A E";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when find name and change cl
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back("-p");
	cmdString.push_back("-f");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("A");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,12345670,A A,CL1,010-1234-5678,19990215,ADV\nMOD,12345671,A B,CL1,010-1234-5678,19990215,ADV\nMOD,12345672,A C,CL1,010-1234-5678,19990215,ADV\nMOD,12345673,A D,CL1,010-1234-5678,19990215,ADV\nMOD,12345674,A E,CL1,010-1234-5678,19990215,ADV\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	for (auto member : testList)
	{
		EXPECT_EQ(CL::CL3, member.cl);
	}
}


TEST(MODIFY_TEST_SUITE, TEST_SuccessToPrintMultiMemberInfoOverFiveAndChangeClWithName) {
	// given test member list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 12345670;
	testMember.name = "A A";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345671;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345672;
	testMember.name = "A C";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345673;
	testMember.name = "A D";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345674;
	testMember.name = "A E";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345675;
	testMember.name = "A F";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when find name and change cl
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back("-p");
	cmdString.push_back("-f");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("A");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,12345670,A A,CL1,010-1234-5678,19990215,ADV\nMOD,12345671,A B,CL1,010-1234-5678,19990215,ADV\nMOD,12345672,A C,CL1,010-1234-5678,19990215,ADV\nMOD,12345673,A D,CL1,010-1234-5678,19990215,ADV\nMOD,12345674,A E,CL1,010-1234-5678,19990215,ADV\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	for (auto member : testList)
	{
		EXPECT_EQ(CL::CL3, member.cl);
	}
}


TEST(MODIFY_TEST_SUITE, TEST_SuccessToPrintSortedMultiMemberInfoOverFiveAndChangeClWithName) {
	// given test member list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 80345670;
	testMember.name = "A A";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 90345675;
	testMember.name = "A F";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345672;
	testMember.name = "A C";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);
	
	testMember.employeeNum = 74345671;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345674;
	testMember.name = "A E";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345673;
	testMember.name = "A D";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when find name and change cl
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back("-p");
	cmdString.push_back("-f");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("A");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,74345671,A B,CL1,010-1234-5678,19990215,ADV\nMOD,80345670,A A,CL1,010-1234-5678,19990215,ADV\nMOD,90345675,A F,CL1,010-1234-5678,19990215,ADV\nMOD,12345672,A C,CL1,010-1234-5678,19990215,ADV\nMOD,12345673,A D,CL1,010-1234-5678,19990215,ADV\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	for (auto member : testList)
	{
		EXPECT_EQ(CL::CL3, member.cl);
	}
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToPrintSortedMultiMemberInfoOverFiveWithFirstZeroEmployeeNum) {
	// given test member list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 80345670;
	testMember.name = "A A";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 90345675;
	testMember.name = "A F";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 8345672;
	testMember.name = "A C";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 74345671;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345674;
	testMember.name = "A E";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345673;
	testMember.name = "A D";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when find name and change cl
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back("-p");
	cmdString.push_back("-f");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("A");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,74345671,A B,CL1,010-1234-5678,19990215,ADV\nMOD,80345670,A A,CL1,010-1234-5678,19990215,ADV\nMOD,90345675,A F,CL1,010-1234-5678,19990215,ADV\nMOD,08345672,A C,CL1,010-1234-5678,19990215,ADV\nMOD,12345673,A D,CL1,010-1234-5678,19990215,ADV\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	for (auto member : testList)
	{
		EXPECT_EQ(CL::CL3, member.cl);
	}
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToPrintSortedMultiMemberInfoOverFiveWithManyZeroEmployeeNum) {
	// given test member list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 80345670;
	testMember.name = "A A";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 5;
	testMember.name = "A F";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 8345672;
	testMember.name = "A C";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 74345671;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345674;
	testMember.name = "A E";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345673;
	testMember.name = "A D";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when find name and change cl
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back("-p");
	cmdString.push_back("-f");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("A");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,74345671,A B,CL1,010-1234-5678,19990215,ADV\nMOD,80345670,A A,CL1,010-1234-5678,19990215,ADV\nMOD,00000005,A F,CL1,010-1234-5678,19990215,ADV\nMOD,08345672,A C,CL1,010-1234-5678,19990215,ADV\nMOD,12345673,A D,CL1,010-1234-5678,19990215,ADV\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	for (auto member : testList)
	{
		EXPECT_EQ(CL::CL3, member.cl);
	}
}

TEST(MODIFY_TEST_SUITE, TEST_SuccessToPrintMemberCountOverFiveAndChangeClWithName) {
	// given test member list
	vector<member> testList;
	member testMember;
	testMember.employeeNum = 80345670;
	testMember.name = "A A";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 90345675;
	testMember.name = "A F";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345672;
	testMember.name = "A C";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 74345671;
	testMember.name = "A B";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345674;
	testMember.name = "A E";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	testMember.employeeNum = 12345673;
	testMember.name = "A D";
	testMember.cl = CL::CL1;
	testMember.phoneNum = "010-1234-5678";
	testMember.birthday = 19990215;
	testMember.certi = CERTI::ADV;
	testList.push_back(testMember);

	// when find name and change cl
	Modifier* modifier = new Modifier(testList);
	vector<string> cmdString;
	cmdString.push_back("MOD");
	cmdString.push_back("");
	cmdString.push_back("-f");
	cmdString.push_back(" ");
	cmdString.push_back("name");
	cmdString.push_back("A");
	cmdString.push_back("cl");
	cmdString.push_back("CL3");

	// then modifier Modify return success(0) and cl changed
	string resultStr = "MOD,5\n";
	EXPECT_TRUE(resultStr == modifier->Modify(cmdString));
	for (auto member : testList)
	{
		EXPECT_EQ(CL::CL3, member.cl);
	}
}