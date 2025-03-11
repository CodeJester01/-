#include  "date.h"

date::date(int a, int b, int c) {
	year = a;
	month = b;
	day = c;
}
date::~date() {
};
int date::get_year() { return year; }
int date::get_month() { return month; }
int date::get_day() { return day; }
void date::change_day(int a) {
	day = a;
}
void date::change_month(int a) {
	month = a;
}
void date::change_year(int a) {
	year = a;
}
