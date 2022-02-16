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
	"SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV",
	"SCH,NONE",
	"SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PROSCH,01122329,DN WD,CL4,010-7174-5680,20071117,PROSCH,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PROSCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PROSCH,08123556,WN XV,CL1,010-7986-5047,20100614,PRO",
	"SCH,8",
	"SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PROSCH,01122329,DN WD,CL4,010-7174-5680,20071117,PROSCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADVSCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PROSCH,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV",
	"SCH,1",
	"SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PROSCH,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO",
	"SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO",
	"SCH,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV",
	"SCH,NONE",
	"SCH,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV",
	"SCH,NONE",
	"SCH,1"

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

	//ASSERT_EQ(testoutput[12], sch->run(testinput[12]));

	for (int i = 0; i < 13; i++) {
		ASSERT_EQ(testoutput[i], sch->run(testinput[i]));
	}
	
	delete add;
	delete para;
	delete sch;
}