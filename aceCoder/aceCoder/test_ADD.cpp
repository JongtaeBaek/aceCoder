#pragma once
#include "pch.h"
#include"Add.h"

TEST(ADD_TEST, TEST_VALID) {
	string str = "ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO";	
	Add a;
	member mem{ 18050301, string{ "KYUMOK KIM" }, CL::CL2, string{ "010-9777-6055" }, 19980906, CERTI::PRO };
	EXPECT_TRUE(a.isValid(mem));
	EXPECT_EQ(1, a.run(mem));	

	EXPECT_FALSE(a.isValid(member{ 18050301, string{ "KYUMOK LEE" }, CL::CL3, string{ "010-9777-6051" }, 19980905, CERTI::ADV }));
	EXPECT_FALSE(a.isValid(member{ 18050302, string{ "" }, CL::CL3, string{ "010-9777-6051" }, 19980905, CERTI::ADV }));
	EXPECT_FALSE(a.isValid(member{ 18050302, string{ "KYUMOK LEE" }, CL::CL3, string{ "" }, 19980905, CERTI::ADV }));
	EXPECT_FALSE(a.isValid(member{ 18050302, string{ "KYUMOK LEE" }, CL::CL3, string{ "010-9777-6051" }, 0, CERTI::ADV }));
}