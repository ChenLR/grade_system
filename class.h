#ifndef CLASS_H_
#define CLASS_H_

#define _peopleNameLength 11
#define _courseNameLength 25
#define _passwordLength 20
#include <iostream>
using namespace std;

class people;      //����

class admin;       //����Ա��
class teacher;     //��ʦ��
class student;     //ѧ����
class course;      //�γ�
class OLNode;      //�ɼ��ڵ�

class listBase;    //���������

class adminList;   //����Ա��
class teacherList; //��ʦ��
class studentList; //ѧ����
class courseList;  //�γ̱�
class gradeList;   //�ɼ���

class adminOperation;    //����Ա�˵�
class teacherOperation;  //��ʦ�˵�
class studentOperation;  //ѧ���˵�

class System;   //�ɼ�����ϵͳ

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
	double GPA;     //gpa,�ɳɼ����м���ó�,��ʼ��Ϊ-1
	int totalCredit;  //�Ѹ��ֿγ̵���ѧ��,�ɳɼ����м���ó�,��ʼ��Ϊ0
	student * next;
};
class course {
public:
	friend class courseList;
	course(char *name="NULL", char *teacher="NULL", int credit=0);
	course(course &C);
	~course() {};
	void set(char *name="NULL", char *teacher="NULL", int credit=0);//0Ϊ�����ܵ�ֵ,�����ж��Ƿ�ֵ
	void print();//ֻ��ӡ�ǳ�ֵ����
	void clear();
	bool isEmpty();
	friend ostream &operator <<(ostream &output,course &c);//�����������Ļ
	friend ofstream &operator <<(ofstream &outf,course &c);//�����������Ļ
private:
	char name[_courseNameLength];
	char teacher[_peopleNameLength];
	int credit;//ѧ��,��ʼ��Ϊ0
	int studentNum;//ѧ������,�ɳɼ���ͳ�Ƶó�,��ʼ��Ϊ0
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
	int row;//��1��ʼ���
	int col;//��1��ʼ���
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
	bool isCorrect(admin *aim); //�������������Ƿ���ȷ
	void Import();
	void Export();
	void setAdmin(char *name="NULL", char *password="NULL");
	bool addAdmin(admin *add);
	bool deleteAdmin();
	void showAll();
	void printTitle(int rank=0);//��rankΪ��,��ӡcurrent��Ӧ������
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
	bool isCorrect(teacher *aim); //�������������Ƿ���ȷ
	void Import();
	void Export();
	void setTeacher(char *name="NULL", char *password="NULL");
	bool addTeacher(teacher *add);
	bool deleteTeacher();
	void showAll();
	void printTitle(int rank=0);//��rankΪ��,��ӡcurrent��Ӧ������
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
	bool isCorrect(student *aim); //�������������Ƿ���ȷ
	int find(student *aim,int rank=0);//�����ҵ��ĸ���,����ҵ�һ��,current��Ϊ��
	int getRank();//����current��ָ�ڵ�����,ͷ����Ϊ1,��currentΪ�շ���0;
	int getLength();
	void setStudent(char *name="NULL", char *password="NULL");
	bool addStudent(student *add);
	bool deleteStudent();
	void showAll();
	void showAllt();                                                     //�����üǵ�ɾ!!!
	void printTitle(int rank=0);//��rankΪ��,��ӡcurrent��Ӧ������
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
	int find(course *aim, bool print=0, int rank=0);//�����ҵ��ĸ���,����ҵ�һ��,current��Ϊ��
	int getRank();//����current��ָ�ڵ�����,ͷ����Ϊ1,��currentΪ�շ���0;
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
	bool findNode(int m, int n);//Ҫ��current
	bool showNode(int m, int n);
	bool isExist(int m, int n);//����current
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
	void quickSort(OLNode **P, int length);//���ɼ���������
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