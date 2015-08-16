#ifndef CLASS_H_
#define CLASS_H_

#define _peopleNameLength 11
#define _courseNameLength 25
#define _passwordLength 20
#include <iostream>
using namespace std;

class people;      //人类

class admin;       //管理员类
class teacher;     //老师类
class student;     //学生类
class course;      //课程
class OLNode;      //成绩节点

class listBase;    //链表基础类

class adminList;   //管理员表
class teacherList; //老师表
class studentList; //学生表
class courseList;  //课程表
class gradeList;   //成绩表

class adminOperation;    //管理员菜单
class teacherOperation;  //教师菜单
class studentOperation;  //学生菜单

class System;   //成绩管理系统

typedef adminList A;
typedef teacherList T;
typedef studentList S;
typedef courseList C;
typedef gradeList G;

class people {
public:
	people(char* name="NULL",char* password="NULL");
	people(people & people);
	void set(char* name="NULL",char* password="NULL");
	char* getPassword();
	char* getName();
	virtual ~people() {};
    friend ostream &operator <<(ostream &output,people &p);
	friend ofstream &operator <<(ofstream &outf,people &p);
protected:
	char name[_peopleNameLength];
	char password[_passwordLength];
};

class admin: public people {
public:
	friend class adminList;
	admin(char* name="NULL",char* password="NULL");
	admin(admin & admin);
	~admin() {};
private:
	admin * next;
};
class teacher: public people {
public:
	friend class teacherList;
	teacher(char* name="NULL",char* password="NULL");
	teacher(teacher & teacher);
	~teacher() {};
private:
	teacher * next;
};
class student: public people {
public:
	friend class studentList;
	student(char* name="NULL",char* password="NULL");
	student(student & student);
	~student() {};
private:
	double GPA;     //gpa,由成绩表中计算得出,初始化为-1
	int totalCredit;  //已给分课程的总学分,由成绩表中计算得出,初始化为0
	student * next;
};
class course {
public:
	friend class courseList;
	course(char *name="NULL", char *teacher="NULL", int credit=0);
	course(course &C);
	~course() {};
	void set(char *name="NULL", char *teacher="NULL", int credit=0);//0为不可能的值,用于判断是否赋值
	void print();//只打印非初值的量
	void clear();
	bool isEmpty();
	friend ostream &operator <<(ostream &output,course &c);//完整输出到屏幕
	friend ofstream &operator <<(ofstream &outf,course &c);//完整输出到屏幕
private:
	char name[_courseNameLength];
	char teacher[_peopleNameLength];
	int credit;//学分,初始化为0
	int studentNum;//学生数量,由成绩表统计得出,初始化为0
	course * next;
};
class OLNode {
public:
	friend class gradeList;
	OLNode(int row=0, int col=0, int score=0);
	OLNode(OLNode &N);
	~OLNode() {};
	void print();
	friend ofstream &operator <<(ofstream &outf,OLNode &N);
private:
	int row;//从1开始编号
	int col;//从1开始编号
	int grade;
	int rank;
	OLNode *right;
	OLNode *down;
};

class listBase {
public:
	virtual ~listBase() {};
	virtual void Import()=0;
	virtual void Export()=0;
	virtual void showAll()=0;
	virtual void clearCurrent()=0;
	virtual bool isCurrent()=0;
};
class adminList:public listBase {
public:
	adminList();
	adminList(adminList & L);
	~adminList();
	bool isExists(admin *aim, int flag=1);
	bool isCorrect(admin *aim); //返回姓名密码是否正确
	void Import();
	void Export();
	void setAdmin(char *name="NULL", char *password="NULL");
	bool addAdmin(admin *add);
	bool deleteAdmin();
	void showAll();
	void printTitle(int rank=0);//若rank为空,打印current对应的姓名
	void showCurrent();
	void clearCurrent();
	bool isCurrent();
private:
	int length;
	admin *head, *tail, *current;
};
class teacherList:public listBase {
public:
	teacherList();
	teacherList(teacherList & L);
	~teacherList();
	bool isExists(teacher *aim, int flag=1);
	bool isCorrect(teacher *aim); //返回姓名密码是否正确
	void Import();
	void Export();
	void setTeacher(char *name="NULL", char *password="NULL");
	bool addTeacher(teacher *add);
	bool deleteTeacher();
	void showAll();
	void printTitle(int rank=0);//若rank为空,打印current对应的姓名
	void getName(char *buff);
	void showCurrent();
	void clearCurrent();
	bool isCurrent();
private:
	int length;
	teacher *head, *tail, *current;
};
class studentList:public listBase {
public:
	studentList();
	studentList(studentList & L);
	~studentList();
	void Import();
	void Export();
	bool isExists(student *aim, int flag=1);
	bool isCorrect(student *aim); //返回姓名密码是否正确
	int find(student *aim,int rank=0);//返回找到的个数,如果找到一个,current不为空
	int getRank();//返回current所指节点的序号,头结点记为1,若current为空返回0;
	int getLength();
	void setStudent(char *name="NULL", char *password="NULL");
	bool addStudent(student *add);
	bool deleteStudent();
	void showAll();
	void showAllt();                                                     //测试用记得删!!!
	void printTitle(int rank=0);//若rank为空,打印current对应的姓名
	void showCurrent();
	void showSTU(int rank=0);
	void setSTU(int totalCredit, double GPA, int rank=0);
	int rankInAll(int rank=0);
	void clearCurrent();
	bool isCurrent();
private:
	int length;
	student *head, *tail, *current;
};
class courseList:public listBase {
public:
	courseList();
	courseList(courseList & L);
	~courseList();
	bool isExists(course *aim);
	int find(course *aim, bool print=0, int rank=0);//返回找到的个数,如果找到一个,current不为空
	int getRank();//返回current所指节点的序号,头结点记为1,若current为空返回0;
	int getLength();
	int getCredit(int rank=0);
	void setStudentNum(int n);
	void printStudentNum();
	void Import();
	void Export();
	bool addCourse(course *add);
	bool deleteCourse();
	void showAll();
	void printTitle(int rank=0);
	void clearCurrent();
	bool isCurrent();
private:
	int length;
	course *head,*tail, *current;
};
class gradeList: public listBase, public studentList, public courseList {
public:
	gradeList(int r=1,int c=1);
	gradeList(gradeList &C);
	~gradeList();
	void set(int r=1,int c=1);
	void Import();
	void Export();
	bool findNode(int m, int n);//要改current
	bool showNode(int m, int n);
	bool isExist(int m, int n);//不改current
	bool addNode(OLNode *Node);
	bool deleteNode();
	bool addRow();
	bool addCol();
	bool deleteRow(int m);
	bool deleteCol(int n);
	void showAll();
	void showAllt();
	void showRow(int r);
	void showCol(int c);
	void refreshRank();
	void refreshStudent();
	int maxInRow();
	int minInRow();
	double meanInRow();
	void quickSort(OLNode **P, int length);//按成绩降序排列
	void clearCurrent();
	bool isCurrent();
private:
	int rowMax;
	int colMax;
	OLNode *current;
	OLNode **rowHead;
	OLNode **colHead; 
};

#endif CLASS_H_