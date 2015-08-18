#include <iostream>
#include <fstream>
#include <iomanip>
#include "class.h"
#include "head.h"
using namespace std;

ostream &operator <<(ostream &output,people &p) {
	output.setf(ios_base::left);
	output<<setw(_peopleNameLength+1)<<p.name<<setw(_passwordLength+1)<<p.password;
	return output;
}
ofstream &operator <<(ofstream &outf,people &p) {
    outf.setf(ios_base::left);
	outf<<setw(_peopleNameLength+1)<<p.name<<setw(_passwordLength+1)<<p.password;
	return outf;
}
ostream &operator <<(ostream &output,course &c) {
	output.setf(ios_base::left);
	output<<setw(_courseNameLength+1)<<c.name<<setw(_peopleNameLength+1)
		<<c.teacher<<" "<<setw(2)<<c.credit;
	return output;
}//完整输出到屏幕
ofstream &operator <<(ofstream &outf,course &c) {
	outf.setf(ios_base::left);
	outf<<setw(_courseNameLength+1)<<c.name<<setw(_peopleNameLength+1)
		<<c.teacher<<" "<<setw(2)<<c.credit;
	return outf;
}//完整输出到文件
ofstream &operator <<(ofstream &outf,OLNode &N) {
	outf.setf(ios_base::left);
	outf<<setw(3)<<N.row<<" "<<setw(3)<<N.col<<" "<<N.grade;
	return outf;
}

void showTime() {
	time_t timer = time(NULL);
	struct tm * t = localtime(&timer);
	printf( "%d/%02d/%02d %02d:%02d:%02d",//没有用cout,因为设置场宽和格式控制太繁琐
		1900 + t->tm_year, t->tm_mon+1, t->tm_mday,
		t->tm_hour, t->tm_min, t->tm_sec);
}
bool inputInt(int &state,int max) {
	int k=0;
	char s[12];
	while(k++,fgets(s,12,stdin), s[strlen(s)-1]!='\n' || strcmp(s,"quit\n") && (atoi(s)>max || atoi(s)<=0)) {
		fflush(stdin);	
		if(k>2) {
			cout<<"错误次数过多!\n";
			_sleep(_delay);//延时1秒
			//防止在延时时误操作
			return 0;
		}
		cout<<"输入数据非法!\n请重新输入序号:";
	}
	fflush(stdin);
	s[strlen(s)-1]='\0';//清掉读入的回车
	if(!strcmp(s,"quit")) {
		state=0;
		return 1;
	}
	state=atoi(s);
	return 1;
}
bool inputBool() {
	char Y[3];
	int k=0;
	while(k++,fgets(Y,3,stdin), Y[strlen(Y)-1]!='\n' || Y[0]!='Y' && Y[0]!='y' && Y[0]!='n') {
		fflush(stdin);
		if(k>2) {
			cout<<"错误次数过多!\n";
			_sleep(_delay);
			return 0;
		}
		cout<<"输入数据非法!\n请重新输入(Y/n):";
	}
	fflush(stdin);	
	if(Y[0]=='n') return 0;
	else return 1;
}
bool inputString(char *s,int max) {
	int k=0;
	while(k++,fgets(s,max,stdin), s[strlen(s)-1]!='\n') {
		fflush(stdin);
		if(k>2) {
			cout<<"错误次数过多!\n";
			_sleep(_delay);
			return 0;
		}
		cout<<"输入字符串过长!\n请重新输入:";

	}
	fflush(stdin);
	s[strlen(s)-1]='\0';//清掉读入的回车
	if(!strcmp(s,"quit")) return 0;
	return 1;
}
bool inputGrade(int &grade,int max) {
	int k=0;
	char s[12];
	while(k++,fgets(s,12,stdin), s[strlen(s)-1]!='\n' || strcmp(s,"quit\n") && (atoi(s) > max || atoi(s) < -1)) {
		fflush(stdin);	
		if(k>2) {
			cout<<"错误次数过多!\n";
			_sleep(_delay);//延时1秒
			//防止在延时时误操作
			return 0;
		}
		cout<<"输入数据非法!\n请重新输入成绩:";
	}
	fflush(stdin);
	s[strlen(s)-1]='\0';//清掉读入的回车
	if(!strcmp(s,"quit")) {
		return 0;
	}
	grade=atoi(s);
	return 1;
}
