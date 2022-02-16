#pragma once
#include "pch.h"
#include "Sch.h"
#include "Add.h"

string testinput[] = {
	"SCH,-p,-d, ,birthday,04",
	"SCH, , , ,employeeNum,79110836",
	"SCH,-p, , ,certi,PRO",
	"SCH, , , ,certi,ADV",
	"SCH,-p, , ,cl,CL4",
	"SCH, ,-m, ,birthday,09",
	"SCH,-p,-y, ,birthday,2003",
	"SCH,-p, , ,employeeNum,05101762",
	"SCH,-p,-m, ,phoneNum,3112",
	"SCH,-p,-l, ,phoneNum,4605",
	"SCH,-p, , ,employeeNum,10127115",
	"SCH, ,-f, ,name,LDEXRI",
	"SCH, , , ,name,FB NTAWR",
};

string testoutput[] = {
	"SCH,-p,-d, ,birthday,04",
	"SCH, , , ,employeeNum,79110836",
	"SCH,-p, , ,certi,PRO",
	"SCH, , , ,certi,ADV",
	"SCH,-p, , ,cl,CL4",
	"SCH, ,-m, ,birthday,09",
	"SCH,-p,-y, ,birthday,2003",
	"SCH,-p, , ,employeeNum,05101762",
	"SCH,-p,-m, ,phoneNum,3112",
	"SCH,-p,-l, ,phoneNum,4605",
	"SCH,-p, , ,employeeNum,10127115",
	"SCH, ,-f, ,name,LDEXRI",
	"SCH, , , ,name,FB NTAWR",
};

TEST(SCH_TEST, TEST1) {
	vector<member> members;
	ParameterChecker* para = new ParameterChecker();
	vector<string>lines = para->loadTxt(".\\input\\inputAdd.txt");

	Add* add = new Add(members);
	for (const auto& line : lines) {
		vector<string> values = para->parse(line);
		ASSERT_TRUE(para->isValid(values));
		const member mem = para->convert(values);
		EXPECT_TRUE(add->isValid(mem));
		EXPECT_EQ(1, add->run(mem));
	}
	
	Sch* sch = new Sch(members);

	ASSERT_EQ("SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV", sch->run(testinput[0]));
	ASSERT_EQ("SCH,NONE", sch->run(testinput[1]));
	ASSERT_EQ("SCH,NONE", sch->run(testinput[2]));
	
	delete add;
	delete para;
	delete sch;
}