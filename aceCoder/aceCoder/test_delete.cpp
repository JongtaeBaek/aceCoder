#include "pch.h"
#include"delete.h"
#include"Add.h"

member mem[22] = {
	{ 15123099, string{ "VXIHXOTH JHOP" }, CL::CL3, string{ "010-3112-2609" }, 19771211, CERTI::ADV },
	{ 17112609, string{ "FB NTAWR" }, CL::CL4, string{ "010-5645-6122" }, 19861203, CERTI::PRO },
	{ 18115040, string{ "TTETHU HBO" }, CL::CL3, string{ "010-4581-2050" }, 20080718, CERTI::ADV },
	{ 88114052, string{ "NQ LVARW" }, CL::CL4, string{ "010-4528-3059" }, 19911021, CERTI::PRO },
	{ 19129568, string{ "SRERLALH HMEF" }, CL::CL2, string{ "010-4528-3059" }, 19640910, CERTI::PRO },
	{ 17111236, string{ "VSID TVO" }, CL::CL1, string{ "010-3669-1077" }, 20120718, CERTI::PRO },
	{ 18117906, string{ "TWU QSOLT" }, CL::CL4, string{ "010-6672-7186" }, 20030413, CERTI::PRO },
	{ 8123556, string{ "WN XV" }, CL::CL1, string{ "010-7986-5047" }, 20100614, CERTI::PRO },
	{ 2117175, string{ "SBILHUT LDEXRI" }, CL::CL4, string{ "010-2814-1699" }, 19950704, CERTI::ADV },
	{ 3113260, string{ "HH LTUPF" }, CL::CL2, string{ "010-5798-5383" }, 19791018, CERTI::PRO },
	{ 14130827, string{ "RPO JK" }, CL::CL4, string{ "010-3231-1698" }, 20090201, CERTI::ADV },
	{ 1122329, string{ "DN WD" }, CL::CL4, string{ "010-7174-5680" }, 20071117, CERTI::PRO },
	{ 8108827, string{ "RTAH VNUP" }, CL::CL4, string{ "010-9031-2726" }, 19780417, CERTI::ADV },
	{ 85125741, string{ "FBAH RTIJ" }, CL::CL1, string{ "010-8900-1478" }, 19780228, CERTI::ADV },
	{ 8117441, string{ "BMU MPOSXU" }, CL::CL3, string{ "010-2703-3153" }, 20010215, CERTI::ADV },
	{ 10127115, string{ "KBU MHU" }, CL::CL3, string{ "010-3284-4054" }, 19660814, CERTI::ADV },
	{ 12117017, string{ "LFIS JJIVL" }, CL::CL1, string{ "010-7914-4067" }, 20120812, CERTI::PRO },
	{ 11125777, string{ "TKOQKIS HC" }, CL::CL1, string{ "010-6734-2289" }, 19991001, CERTI::PRO },
	{ 11109136, string{ "QKAHCEX LTODDO" }, CL::CL4, string{ "010-2627-8566" }, 19640130, CERTI::PRO },
	{ 5101762, string{ "VCUHLE HMU" }, CL::CL4, string{ "010-3988-9289" }, 20030819, CERTI::PRO },
	{ 5111762, string{ "SANG GU" }, CL::CL4, string{ "010-7777-9212" }, 19940819, CERTI::PRO },
	{ 1462, string{ "SANG DU" }, CL::CL4, string{ "010-7798-1565" }, 19940805, CERTI::PRO },
};

TEST(DEL_TESTSUITE, TEST_EMPLOYEENUM) {

	vector<member> members;
	Add* add = new Add(members);
	Del* del = new Del(members);

	for (int i = 0; i < 20; i++) {
		EXPECT_TRUE(add->isValid(mem[i]));
		add->run(mem[i]);
	}

	EXPECT_EQ(1, del->Delete(members, "employeeNum", "14130827", " ", " "));
	EXPECT_EQ(1, del->Delete(members, "employeeNum", "10127115", " ", " "));
	EXPECT_EQ(1, del->Delete(members, "employeeNum", "18115040", "-p", " "));
	EXPECT_EQ(0, del->Delete(members, "employeeNum", "99999999", "-p", " "));

	delete add;
	delete del;
}

TEST(DEL_TESTSUITE, TEST_NAME) {

	vector<member> members;
	Add* add = new Add(members);
	Del* del = new Del(members);

	for (int i = 0; i < 20; i++) {
		EXPECT_TRUE(add->isValid(mem[i]));
		add->run(mem[i]);
	}

	EXPECT_EQ(1, del->Delete(members, "name", "KBU MHU", " ", " "));
	EXPECT_EQ(1, del->Delete(members, "name", "VCUHLE HMU", "-p", " "));
	EXPECT_EQ(1, del->Delete(members, "name", "RTAH VNUP", " ", " "));
	EXPECT_EQ(0, del->Delete(members, "name", "Sanggu", " ", " "));

	delete add;
	delete del;
}

TEST(DEL_TESTSUITE, TEST_NAME_FL) {

	vector<member> members;
	Add* add = new Add(members);
	Del* del = new Del(members);

	for (int i = 0; i < 20; i++) {
		EXPECT_TRUE(add->isValid(mem[i]));
		add->run(mem[i]);
	}

	EXPECT_EQ(1, del->Delete(members, "name", "KBU MHU", " ", " "));
	EXPECT_EQ(1, del->Delete(members, "name", "VCUHLE", " ", "-f"));
	EXPECT_EQ(1, del->Delete(members, "name", "VNUP", " ", "-l"));
	EXPECT_EQ(0, del->Delete(members, "name", "Sanggu YEO", " ", " "));

	delete add;
	delete del;
}

TEST(DEL_TESTSUITE, TEST_CL) {

	vector<member> members;
	Add* add = new Add(members);
	Del* del = new Del(members);
	
	for (int i = 0; i < 20; i++) {
		EXPECT_TRUE(add->isValid(mem[i]));
		add->run(mem[i]);
	}

	EXPECT_EQ(5, del->Delete(members, "cl", "CL1", "-p", " "));
	EXPECT_EQ(2, del->Delete(members, "cl", "CL2", "-p", " "));
	EXPECT_EQ(4, del->Delete(members, "cl", "CL3", "-p", " "));
	EXPECT_EQ(0, del->Delete(members, "cl", "CL3", "-p", " "));
	EXPECT_EQ(9, del->Delete(members, "cl", "CL4", "-p", " "));

	delete add;
	delete del;
}

TEST(DEL_TESTSUITE, TEST_PHONENUM) {

	vector<member> members;
	Add* add = new Add(members);
	Del* del = new Del(members);

	for (int i = 0; i < 20; i++) {
		EXPECT_TRUE(add->isValid(mem[i]));
		add->run(mem[i]);
	}

	EXPECT_EQ(1, del->Delete(members, "phoneNum", "010-8900-1478", " ", " "));
	EXPECT_EQ(1, del->Delete(members, "phoneNum", "010-5798-5383", " ", " "));
	EXPECT_EQ(0, del->Delete(members, "phoneNum", "010-5798-5383", " ", " "));
	EXPECT_EQ(0, del->Delete(members, "phoneNum", "010-9999-9999", " ", " "));
	EXPECT_EQ(1, del->Delete(members, "phoneNum", "6672", "-p", "-m"));
	EXPECT_EQ(1, del->Delete(members, "phoneNum", "1077", "-p", "-l"));
	EXPECT_EQ(0, del->Delete(members, "phoneNum", "9999", "-p", "-l"));
	delete add;
	delete del;
}

TEST(DEL_TESTSUITE, TEST_BIRTHDAY) {

	vector<member> members;
	Add* add = new Add(members);
	Del* del = new Del(members);

	for (int i = 0; i < 20; i++) {
		EXPECT_TRUE(add->isValid(mem[i]));
		add->run(mem[i]);
	}

	EXPECT_EQ(1, del->Delete(members, "birthday", "20030819", " ", " "));
	EXPECT_EQ(0, del->Delete(members, "birthday", "20030819", " ", " "));
	EXPECT_EQ(0, del->Delete(members, "birthday", "99999999", "-p", " "));
	EXPECT_EQ(1, del->Delete(members, "birthday", "19780228", "-p", " "));
	EXPECT_EQ(2, del->Delete(members, "birthday", "2012", "-p", "-y"));
	EXPECT_EQ(2, del->Delete(members, "birthday", "12", " ", "-m"));
	EXPECT_EQ(2, del->Delete(members, "birthday", "17", " ", "-d"));

	delete add;
	delete del;
}

TEST(DEL_TESTSUITE, TEST_CERTI) {

	vector<member> members;
	Add* add = new Add(members);
	Del* del = new Del(members);

	for (int i = 0; i < 20; i++) {
		EXPECT_TRUE(add->isValid(mem[i]));
		add->run(mem[i]);
	}

	EXPECT_EQ(8, del->Delete(members, "certi", "ADV", " ", " "));
	EXPECT_EQ(0, del->Delete(members, "certi", "ADV", "-p", " "));
	EXPECT_EQ(12, del->Delete(members, "certi", "PRO", "-p", " "));
	EXPECT_EQ(0, del->Delete(members, "certi", "EX", " ", " "));

	delete add;
	delete del;
}


TEST(DEL_TESTSUITE, TEST_RUN) {

	vector<member> members;
	Add* add = new Add(members);
	Del* del = new Del(members);

	for (int i = 0; i < 20; i++) {
		EXPECT_TRUE(add->isValid(mem[i]));
		add->run(mem[i]);
	}

	EXPECT_EQ("DEL,1\n", del->run("DEL, , , ,employeeNum,18115040"));
	del->run("DEL,-p, , ,cl,CL4");

	delete add;
	delete del;
}

TEST(DEL_TESTSUITE, TEST_PRINT) {

	vector<member> members;
	Add* add = new Add(members);
	Del* del = new Del(members);

	for (int i = 0; i < 22; i++) {
		EXPECT_TRUE(add->isValid(mem[i]));
		add->run(mem[i]);
	}

	EXPECT_EQ("DEL,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO\nDEL,00001462,SANG DU,CL4,010-7798-1565,19940805,PRO\nDEL,01122329,DN WD,CL4,010-7174-5680,20071117,PRO\nDEL,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV\nDEL,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\n" \
		, del->run("DEL,-p, , ,cl,CL4"));

	EXPECT_EQ("DEL,NONE\n", del->run("DEL,-p, , ,cl,CL4"));

	delete add;
	delete del;
}