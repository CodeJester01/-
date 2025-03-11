#ifndef DATE_H
#define DATE_H
#pragma once

class date {
	int year;
	int month;
	int day;
public:
	date(int a = 2002, int b = 9, int c = 9);
	~date();
	int get_year();
	int get_month();
	int get_day();
	void change_year(int a);
	void change_month(int a);
	void change_day(int a);
};
#endif
