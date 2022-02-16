#include "pch.h"
#include"member.h"
#include"delete.h"
#include<stdio.h>
#include<iostream>

static vector<member> big_five;
char flag[MAXDATA] = { 0 , };

string member_condition[NUM_OF_CONDITION] = {
	"employeeNum",
	"name",
	"cl",
	"phoneNum",
	"birthday",
	"certi"
};

string cl_position[4] = {
	"CL1", "CL2", "CL3", "CL4"
};

string certi_level[3] = {
	"ADV", "PRO", "EX"
};

static void print_info(struct member m)
{
	cout << "DEL," << m.employeeNum << "," << m.name << "," << cl_position[m.cl - 1] << "," << m.phoneNum << "," << m.birthday << "," << certi_level[m.certi] << endl;
}

static void initialize_flag(void)
{
	for (int i = 0; i < MAXDATA; i++)
		flag[i] = 0;
}

static int erase_start(vector<member>& gmembers, char* flag)
{
	for (int i = gmembers.size() - 1; i >= 0; i--)
	{
		if (flag[i]) {
			gmembers.erase(gmembers.begin() + i);
		}
	}

	return 0;
}

static int compare_employeeNum(unsigned int a, unsigned int b)
{
	unsigned int a_year = a / 1000000, b_year = b / 1000000;
	unsigned int a_Num = a % 1000000, b_Num = b % 1000000;

	a_year = (a_year <= 21) ? a_year + 100 : a_year;
	b_year = (b_year <= 21) ? b_year + 100 : b_year;

	if (a_year < b_year)
		return 1;

	else if (a_year > b_year)
		return 0;

	if (a_Num < b_Num)
		return 1;

	return 0;
}

static void save_big_five_member(struct member a)
{
	int i = 0;
	int size = big_five.size();

	if (big_five.empty()) {
		big_five.push_back(a);
		return;
	}

	for (i = 0; i < size; i++) {
		if (compare_employeeNum(a.employeeNum, big_five[i].employeeNum)) {//신입이 사번이 더 높다
			big_five.emplace(big_five.begin() + i, a);
			break;
		}
	}

	if(i == size)
		big_five.push_back(a);

	if (big_five.size() >= 6)
		big_five.pop_back();

	return;
}

static void print_big_five(void)
{
	for (int i = 0; i < big_five.size(); i++) {
		print_info(big_five[i]);
	}
	cout << endl;

	return;
}

static int Delete_employeeNum(vector<member>& gmembers, string str, int option1, int option2)
{
	int sum = 0;
	int cond = stoi(str);

	for (int i = 0; i < gmembers.size(); i++)
	{
		if (cond == gmembers[i].employeeNum) {
			flag[i] = 1;
			sum++;
			save_big_five_member(gmembers[i]);
			//printf("hit\n");
		}
			
	}

	erase_start(gmembers, flag);

	//printf("[%s] %s\n", __func__, str);
	return sum;
}

static int Delete_name(vector<member>& gmembers, string str, int option1, int option2)
{
	int sum = 0;

	for (int i = 0; i < gmembers.size(); i++)
	{
		int position_of_blank = gmembers[i].name.find(" ");
		string database_name;


		if (option2 == FIRST_NAME) {
			database_name = gmembers[i].name.substr(0, position_of_blank);
			//printf("[SGSGSGSGSTEST]\n%s\n", database_name);
		}

		else if (option2 == LAST_NAME) {
			database_name = gmembers[i].name.substr(position_of_blank+1, gmembers[i].name.size()- position_of_blank);
			//printf("[SGSGSGSGSTESTasd]\n%s %s\n", database_name, str);
		}

		else if (option2 == FULL_NAME) {
			database_name = gmembers[i].name;
		}

		if (!str.compare(database_name)) {
			flag[i] = 1;
			sum++;
			save_big_five_member(gmembers[i]);
			//printf("hit\n");
		}
			
	}

	erase_start(gmembers, flag);

	//printf("[%s] %s\n", __func__, str);
	return sum;
}

static int Delete_cl(vector<member>& gmembers, string str, int option1, int option2)
{
	int sum = 0;
	int cond;

	for (int i = 1; i <= 4; i++) {
		if (!str.compare(cl_position[i-1])) {
			cond = i;
			break;
		}
	}

	for (int i = 0; i < gmembers.size(); i++)
	{
		if (gmembers[i].cl == cond) {
			flag[i] = 1;
			sum++;
			save_big_five_member(gmembers[i]);
			//printf("hit\n");
		}
			
	}

	erase_start(gmembers, flag);
	//print_save();
	/*
	printf("[%s] %s %d\n", __func__, str, gmembers.size());

	for (int i = 0; i < gmembers.size(); i++)
	{
		print_info(gmembers[i]);
	}
	*/
	return sum;
}

static int Delete_phoneNum(vector<member>& gmembers, string str, int option1, int option2)
{
	int sum = 0;

	for (int i = 0; i < gmembers.size(); i++)
	{
		int position_of_blank = gmembers[i].phoneNum.find(" ");
		string database_name;


		if (option2 == MIDDLE_PHONENUM) {
			database_name = gmembers[i].phoneNum.substr(4, 4);
		}

		else if (option2 == LAST_PHONENUM) {
			database_name = gmembers[i].phoneNum.substr(9, 4);
		}

		else if (option2 == FULL_PHONENUM) {
			database_name = gmembers[i].phoneNum;
		}

		if (!str.compare(database_name)) {
			flag[i] = 1;
			sum++;
			save_big_five_member(gmembers[i]);
		}

	}

	erase_start(gmembers, flag);

	//printf("[%s] %s\n", __func__, str);
	return sum;
}

static int Delete_birthday(vector<member>& gmembers, string str, int option1, int option2)
{
	int sum = 0;
	int cond = stoi(str);

	for (int i = 0; i < gmembers.size(); i++)
	{
		unsigned int database_birthday;

		if (option2 == YEAR_BIRTHDAY) {
			database_birthday = gmembers[i].birthday/10000;
		}

		else if (option2 == MONTH_BIRTHDAY) {
			database_birthday = (gmembers[i].birthday % 10000) / 100;
		}

		else if (option2 == DAY_BIRTHDAY) {
			database_birthday = gmembers[i].birthday % 100;
		}

		else if (option2 == FULL_BIRTHDAY) {
			database_birthday = gmembers[i].birthday;
		}

		if (database_birthday == cond) {
			flag[i] = 1;
			sum++;
			save_big_five_member(gmembers[i]);
			//printf("hit\n");
		}
			
	}

	erase_start(gmembers, flag);

	//printf("[%s] %s\n", __func__, str);
	return sum;
}

static int Delete_certi(vector<member>& gmembers, string str, int option1, int option2)
{
	int sum = 0;
	int level;

	for (int i = 0; i < 3; i++) {
		if (!str.compare(certi_level[i])) {
			level = i;
			break;
		}
	}

	for (int i = 0; i < gmembers.size(); i++)
	{
		if (gmembers[i].certi == level) {
			flag[i] = 1;
			sum++;
			save_big_five_member(gmembers[i]);
			//printf("hit\n");
		}
			
	}

	erase_start(gmembers, flag);

	//printf("[%s] %s\n", __func__, str);
	return sum;
}

static int (*Delete_Condition[NUM_OF_CONDITION])(vector<member>& gmembers, string str, int option1, int option2)
{
	Delete_employeeNum,
	Delete_name,
	Delete_cl,
	Delete_phoneNum,
	Delete_birthday,
	Delete_certi
};

static void initialize_condition(void)
{
	big_five.clear();
	big_five.reserve(6);
	initialize_flag();
}

static void print_output(int option1, int sum)
{
	if (big_five.empty()) {
		cout << "DEL,NONE" << endl;
		return;
	}
		
	if (option1 == PRINT_ON) {
		print_big_five();
		return;
	}

	cout << "DEL," << sum << endl;
}

static int check_option(string condition, string opt1, string opt2, int& option1, int& option2)
{
	if (!opt1.compare(" ")) {
		option1 = PRINT_OFF;
	}

	else if (!opt1.compare("-p")) {
		option1 = PRINT_ON;
	}

	else
		return -1;

	if (!condition.compare("name")) {
		if (!opt2.compare(" ")) {
			option2 = FULL_NAME;
			return 0;
		}

		else if (!opt2.compare("-f")) {
			option2 = FIRST_NAME;
			return 0;
		}

		else if (!opt2.compare("-l")) {
			option2 = LAST_NAME;
			return 0;
		}
		return -1;
	}

	else if (!condition.compare("phoneNum")) {
		if (!opt2.compare(" ")) {
			option2 = FULL_PHONENUM;
			return 0;
		}

		else if (!opt2.compare("-m")) {
			option2 = MIDDLE_PHONENUM;
			return 0;
		}

		else if (!opt2.compare("-l")) {
			option2 = LAST_PHONENUM;
			return 0;
		}
		return -1;
	}
	
	else if (!condition.compare("birthday")) {
		if (!opt2.compare(" ")) {
			option2 = FULL_BIRTHDAY;
			return 0;
		}

		else if (!opt2.compare("-y")) {
			option2 = YEAR_BIRTHDAY;
			return 0;
		}

		else if (!opt2.compare("-m")) {
			option2 = MONTH_BIRTHDAY;
			return 0;
		}

		else if (!opt2.compare("-d")) {
			option2 = DAY_BIRTHDAY;
			return 0;
		}
		return -1;
	}

	return 0;
}

int Delete(vector<member> &members, string condition, string str, string opt1, string opt2)
{
	int i = 0;
	int sum = 0;
	int option1, option2;

	initialize_condition();
	for (i = 0; i < NUM_OF_CONDITION; i++) {
		if (!condition.compare(member_condition[i]))
			break;
	}

	if (i == NUM_OF_CONDITION) {
		return -1;
	}

	if (check_option(condition, opt1, opt2, option1, option2) == -1)
		return -1;

	sum = Delete_Condition[i](members, str, option1, option2);
	print_output(option1, sum);


	return sum;

}