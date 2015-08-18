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
}//�����������Ļ
ofstream &operator <<(ofstream &outf,course &c) {
	outf.setf(ios_base::left);
	outf<<setw(_courseNameLength+1)<<c.name<<setw(_peopleNameLength+1)
		<<c.teacher<<" "<<setw(2)<<c.credit;
	return outf;
}//����������ļ�
ofstream &operator <<(ofstream &outf,OLNode &N) {
	outf.setf(ios_base::left);
	outf<<setw(3)<<N.row<<" "<<setw(3)<<N.col<<" "<<N.grade;
	return outf;
}

void showTime() {
	time_t timer = time(NULL);
	struct tm * t = localtime(&timer);
	printf( "%d/%02d/%02d %02d:%02d:%02d",//û����cout,��Ϊ���ó���͸�ʽ����̫����
		1900 + t->tm_year, t->tm_mon+1, t->tm_mday,
		t->tm_hour, t->tm_min, t->tm_sec);
}
bool inputInt(int &state,int max) {
	int k=0;
	char s[12];
	while(k++,fgets(s,12,stdin), s[strlen(s)-1]!='\n' || strcmp(s,"quit\n") && (atoi(s)>max || atoi(s)<=0)) {
		fflush(stdin);	
		if(k>2) {
			cout<<"�����������!\n";
			_sleep(_delay);//��ʱ1��
			//��ֹ����ʱʱ�����
			return 0;
		}
		cout<<"�������ݷǷ�!\n�������������:";
	}
	fflush(stdin);
	s[strlen(s)-1]='\0';//�������Ļس�
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
			cout<<"�����������!\n";
			_sleep(_delay);
			return 0;
		}
		cout<<"�������ݷǷ�!\n����������(Y/n):";
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
			cout<<"�����������!\n";
			_sleep(_delay);
			return 0;
		}
		cout<<"�����ַ�������!\n����������:";

	}
	fflush(stdin);
	s[strlen(s)-1]='\0';//�������Ļس�
	if(!strcmp(s,"quit")) return 0;
	return 1;
}
bool inputGrade(int &grade,int max) {
	int k=0;
	char s[12];
	while(k++,fgets(s,12,stdin), s[strlen(s)-1]!='\n' || strcmp(s,"quit\n") && (atoi(s) > max || atoi(s) < -1)) {
		fflush(stdin);	
		if(k>2) {
			cout<<"�����������!\n";
			_sleep(_delay);//��ʱ1��
			//��ֹ����ʱʱ�����
			return 0;
		}
		cout<<"�������ݷǷ�!\n����������ɼ�:";
	}
	fflush(stdin);
	s[strlen(s)-1]='\0';//�������Ļس�
	if(!strcmp(s,"quit")) {
		return 0;
	}
	grade=atoi(s);
	return 1;
}
