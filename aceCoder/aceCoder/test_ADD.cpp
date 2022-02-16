#pragma once
#include "pch.h"
#include"Add.h"
#include "ADDParmeterChecker.h"

TEST(ADD_TESTSUITE, TEST_PARAMETER) {
	string str = "ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO";
	ParameterChecker* para = new AddParmeterChecker();
	EXPECT_TRUE(para->isValid(para->parse(str)));	
	str = "XXX, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906";
	EXPECT_FALSE(para->isValid(para->parse(str)));
	str = "XXX, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO";
	EXPECT_FALSE(para->isValid(para->parse(str)));
	str = "ADD, , , ,18050301,KYUMOK KIM,CL0,010-9777-6055,19980906,PRO";
	EXPECT_FALSE(para->isValid(para->parse(str)));
	str = "ADD, , , ,18050301,KYUMOK KIM,CL0,010-9777-6055,19980906,xx";
	EXPECT_FALSE(para->isValid(para->parse(str)));

	delete para;
}

TEST(ADD_TESTSUITE, TEST_VALID) {
	vector<member> members;
	string str = "ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO";	
	Add *add = new Add(members);
	member mem{ 18050301, string{ "KYUMOK KIM" }, CL::CL2, string{ "010-9777-6055" }, 19980906, CERTI::PRO };
	EXPECT_TRUE(add->isValid(mem));
	EXPECT_EQ(1, add->run(mem));

	EXPECT_FALSE(add->isValid(member{ 18050301, string{ "KYUMOK LEE" }, CL::CL3, string{ "010-9777-6051" }, 19980905, CERTI::ADV }));
	EXPECT_FALSE(add->isValid(member{ 18050302, string{ "" }, CL::CL3, string{ "010-9777-6051" }, 19980905, CERTI::ADV }));
	EXPECT_FALSE(add->isValid(member{ 18050302, string{ "KYUMOK LEE" }, CL::CL3, string{ "" }, 19980905, CERTI::ADV }));
	EXPECT_FALSE(add->isValid(member{ 18050302, string{ "KYUMOK LEE" }, CL::CL3, string{ "010-9777-6051" }, 0, CERTI::ADV }));

	delete add;
}

TEST(ADD_TESTSUITE, TEST_INPUTFILE) {
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\inputAdd.txt");
	ASSERT_NE(0, lines.size());
	Add* add = new Add(members);
	for (const auto& line : lines) {
		vector<string> values = para->parse(line);
		ASSERT_TRUE(para->isValid(values));
		const member mem = para->convert(values);
		EXPECT_TRUE(add->isValid(mem));
		EXPECT_EQ(1, add->run(mem));
	}

	delete add;
	delete para;
}

TEST(ADD_TESTSUITE, TEST_INPUTFILE2) {
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\input_20_20.txt");
	ASSERT_NE(0, lines.size());
	Add* add = new Add(members);
	for (const auto& line : lines) {
		vector<string> values = para->parse(line);
		if (values[IDXCMD] == "ADD")
		{
			if (!para->isValid(values))
				continue;
			const member mem = para->convert(values);
			if (!add->isValid(mem))
				continue;
			add->run(mem);
		}
		else
			continue;
	}

	EXPECT_EQ(20, members.size());

	delete add;
	delete para;
}