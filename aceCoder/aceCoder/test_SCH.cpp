#pragma once
#include "pch.h"
#include "Sch.h"
#include "Add.h"
#include "SchParameterChecker.h"
#include "ADDParmeterChecker.h"

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
	"SCH,-p, , ,certi,EX",
};

string testoutput[] = {
	"SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV\n",
	"SCH,NONE\n",
	"SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO\nSCH,01122329,DN WD,CL4,010-7174-5680,20071117,PRO\nSCH,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO\nSCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\nSCH,08123556,WN XV,CL1,010-7986-5047,20100614,PRO\n",
	"SCH,8\n",
	"SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO\nSCH,01122329,DN WD,CL4,010-7174-5680,20071117,PRO\nSCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV\nSCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\nSCH,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV\n",
	"SCH,1\n",
	"SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\nSCH,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO\n",
	"SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\n",
	"SCH,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV\n",
	"SCH,NONE\n",
	"SCH,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV\n",
	"SCH,NONE\n",
	"SCH,1\n",
	"SCH,00000052,ABC DEF,CL2,010-1234-3655,19901017,EX\nSCH,00004052,ABC DEF,CL2,010-1234-3655,19901017,EX\nSCH,00104050,ABC DEF,CL2,010-1234-3655,19901017,EX\nSCH,00104052,ABC DEF,CL2,010-1234-3655,19901017,EX\nSCH,00104152,ABC DEF,CL2,010-1234-3655,19901017,EX\n",
};

TEST(SCH_TEST, SCH_PARAM_TEST) {
	vector<member> members;
	ParameterChecker* schpara = new SchParameterChecker();
	vector<string>lines = schpara->loadTxt(".\\input\\input_search_test.txt");

	for (const auto& line : lines) {
		if (line.substr(0, 3) != "SCH") {
			continue;
		}
		vector<string> values = schpara->parse(line);
		ASSERT_TRUE(schpara->isValid(values));
	}

	delete schpara;
}

TEST(SCH_TEST, FUNC_TEST) {
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\inputSearch.txt");

	Add* add = new Add(members);
	for (const auto& line : lines) {
		vector<string> values = para->parse(line);
		ASSERT_TRUE(para->isValid(values));
		const member mem = para->convert(values);
		EXPECT_TRUE(add->isValid(mem));
		add->run(mem);
	}
	
	Sch* sch = new Sch(members);

	for (int i = 0; i < 14; i++) {
		ASSERT_EQ(testoutput[i], sch->run(testinput[i]));
	}
	
	delete add;
	delete para;
	delete sch;
}