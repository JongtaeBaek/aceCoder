#pragma once
#include "pch.h"
#include"Add.h"
#include "ParameterChecker.h"

TEST(PARAMETER_TESTSUITE, TEST_PARA) {
	string str = "ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO";
	ParameterChecker* para = new ParameterChecker();		
	EXPECT_TRUE(para->isValid(para->parse(str)));	
	str = "XXX, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906";
	EXPECT_FALSE(para->isValid(para->parse(str)));
	str = "XXX, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO";
	EXPECT_FALSE(para->isValid(para->parse(str)));
	str = "ADD, , , ,18050301,KYUMOK KIM,CL0,010-9777-6055,19980906,PRO";
	EXPECT_FALSE(para->isValid(para->parse(str)));
	str = "ADD, , , ,18050301,KYUMOK KIM,CL0,010-9777-6055,19980906,xx";
	EXPECT_FALSE(para->isValid(para->parse(str)));
}

TEST(ADD_TESTSUITE, TEST_VALID) {
	string str = "ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO";	
	Add *add = new Add(gmembers);
	member mem{ 18050301, string{ "KYUMOK KIM" }, CL::CL2, string{ "010-9777-6055" }, 19980906, CERTI::PRO };
	EXPECT_TRUE(add->isValid(mem));
	EXPECT_EQ(1, add->run(mem));

	EXPECT_FALSE(add->isValid(member{ 18050301, string{ "KYUMOK LEE" }, CL::CL3, string{ "010-9777-6051" }, 19980905, CERTI::ADV }));
	EXPECT_FALSE(add->isValid(member{ 18050302, string{ "" }, CL::CL3, string{ "010-9777-6051" }, 19980905, CERTI::ADV }));
	EXPECT_FALSE(add->isValid(member{ 18050302, string{ "KYUMOK LEE" }, CL::CL3, string{ "" }, 19980905, CERTI::ADV }));
	EXPECT_FALSE(add->isValid(member{ 18050302, string{ "KYUMOK LEE" }, CL::CL3, string{ "010-9777-6051" }, 0, CERTI::ADV }));
}