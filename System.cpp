#include <fstream>
#include <cstring>
#include <iomanip>
#include "class.h"
#include "head.h"
#define _Length 1000000
using namespace std;

class studentOperation: virtual public G{
public:
	studentOperation() {};
	~studentOperation() {};
	bool Login();
private:
	bool Menu();
	int ShowGrade();
	int ShowRank();
	int EditStudent();
};
class teacherOperation: virtual public T, virtual public G{
public:
	teacherOperation() {};
	~teacherOperation() {};
	bool Login();
private:
	bool Menu();
	int ShowCourses();
	int CourseDetail();
	int EditTeacher();
};
class adminOperation: public A, virtual public T, virtual public G{
public:
	adminOperation() {};
	~adminOperation() {};
	bool Login();
private:
	bool Menu();
	int EditAdmin();
};

//--------------------------------function--------------------------------

bool studentOperation::Login() {
	S::clearCurrent();
	system("cls");
	char name[_peopleNameLength],password[_passwordLength];
	cout<<"---------------\n"
		<<"学生登陆\n"
		<<"---------------\n"
		<<"用户名:";
	if(!inputString(name,_peopleNameLength)) return _exit;
	cout<<"密码:";
	if(!inputString(password,_passwordLength)) return _exit;
	if(S::isCorrect(&student(name,password))) {
		while(Menu());
		S::clearCurrent();
	}
	else {
		cout<<"用户名或密码错误!\n";
		_sleep(_delay);
	}
	return _exit;
}
bool studentOperation::Menu() {
	system("cls");
	refreshRank();//生成单科排名
	refreshStudent();//统计总学分和GPA
	int state;
	cout<<"---------------\n"
		<<"您好!";
	S::printTitle();
	cout<<"\n---------------\n"
		<<"1. 成绩查询\n"
		<<"2. 排名查询\n"
		<<"3. 修改个人信息\n"
		<<"4. 注销\n"
		<<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state, 4)) return 1;
	while(1) {
		switch(state) {
		case 0: return _exit;
		case 1: {
			state=ShowGrade();
			break;
				}
		case 2: {
			state=ShowRank();
			break;
				}
		case 3: {
			state=EditStudent();
			break;
				}
		case 4: {
			cout<<"确认注销?(Y/n):";
			if(inputBool()) {
				cout<<"用户已注销\n";
				_sleep(_delay);
				return _exit;
			}
			else return 1;
				 }
		default: return 1;
		}
	}
}
int studentOperation::ShowGrade() {
	system("cls");
	int state;
	cout.setf(ios_base::left);
	cout<<"---------------\n成绩单\n"
		<<"学生:";
	S::printTitle();
	cout<<"\n---------------\n"
		<<setw(_courseNameLength+1)<<"课程"
		<<setw(_peopleNameLength+1)<<"教师"
		<<"学分 成绩 排名"<<endl;
	G::showCol(S::getRank());   
	cout<<"---------------\n"
		<<"1. 排名查询\n"
		<<"2. 修改个人信息\n"
		<<"3. 注销\n"
	    <<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state,3)) return 1;
	switch(state) {
	case 0: return _exit;
	case 1: return 2;
	case 2: return 3;
	case 3: return 4;
	}
}
int studentOperation::ShowRank() {
	system("cls");
	int state;
	cout.setf(ios_base::left);
	cout<<"---------------\n"
		<<"学生:";
	S::printTitle();
	cout<<"\n---------------\n"
		<<"总学分 成绩   排名"<<endl;
	S::showSTU();
	cout<<rankInAll()<<endl;
	cout<<"---------------\n"
		<<"1. 成绩查询\n"
		<<"2. 修改个人信息\n"
		<<"3. 注销\n"
		<<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state,3)) return 1;
	switch(state) {
	case 0: return _exit;
	case 1: return 1;
	case 2: return 3;
	case 3: return 4;
	}
}
int studentOperation::EditStudent() {
	system("cls");
	int state;
	cout.setf(ios_base::left);
	cout<<"---------------\n"
		<<setw(_peopleNameLength+1)<<"姓名"
		<<setw(_passwordLength+1)<<"密码"<<endl;
	S::showCurrent();
	cout<<"\n---------------\n"
		<<"1. 修改姓名\n"
		<<"2. 修改密码\n"
		<<"3. 返回上一级\n"
		<<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state,3)) return 1;
	switch(state) {
	case 0: return _exit;
	case 1: {
		char name[_peopleNameLength];
		cout<<"---------------\n"
			<<"请输入新的姓名:";
		if(!inputString(name,_peopleNameLength)) return _exit;
		if(S::isExists(&student(name),0)) {
			cout<<"用户名已存在!"<<endl;
			_sleep(_delay);
			return 3;
		}
		setStudent(name);
		cout<<"修改已成功!\n";
		break;
			}
	case 2: {
		char password[_passwordLength];
		cout<<"---------------\n"
			<<"请输入新的密码:";
		if(!inputString(password,_passwordLength)) return _exit;
		setStudent("NULL",password);
		cout<<"修改已成功!\n";
		break;
			}
	case 3: return -1;
	}
	cout<<"---------------\n"
		<<"1. 成绩查询\n"
		<<"2. 排名查询\n"
		<<"3. 继续修改个人信息\n"
		<<"4. 注销\n"
		<<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state,4)) return 1;
	switch(state) {
	case 0: return _exit;
	case 1: return 1;
	case 2: return 2;
	case 3: return 3;
	case 4: return 4;
	}
}


bool teacherOperation::Login() {
	T::clearCurrent();
	system("cls");
	char name[_peopleNameLength],password[_passwordLength];
	cout<<"---------------\n"
		<<"教师登陆\n"
		<<"---------------\n"
		<<"用户名:";
	if(!inputString(name,_peopleNameLength)) return _exit;
	cout<<"密码:";
	if(!inputString(password,_passwordLength)) return _exit;
	if(T::isCorrect(&teacher(name,password))) {
		while(Menu());
		T::clearCurrent();
	}
	else {
		cout<<"用户名或密码错误!\n";
		_sleep(_delay);
	}
	return _exit;
}
bool teacherOperation::Menu() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"您好!";
	T::printTitle();
	cout<<"\n---------------\n"
		<<"1. 查看课程\n"
		<<"2. 修改个人信息\n"
		<<"3. 注销\n"
		<<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state, 4)) return 1;
	while(1) {
		switch(state) {
		case 0: return _exit;
		case 1: {
			state=ShowCourses();
			break;
				}
		case 2: {
			state=EditTeacher();
			break;
				}
		case 3: {
			cout<<"确认注销?(Y/n):";
			if(inputBool()) {
				cout<<"用户已注销\n";
				_sleep(_delay);
				return _exit;
			}
			else return 1;
				 }
		default: return 1;
		}
	}
}

int teacherOperation::ShowCourses() {
	system("cls");
	int state,num;
	char name[_peopleNameLength];
	cout.setf(ios_base::left);
	T::getName(name);
	num = C::find(&course("NULL",name));
	if(num == 1 && C::isCurrent());
	else if(num > 1) {
		C::find(&course("NULL",name), 1);
		cout<<setw(2)<<num + 1<<". 返回上一级\n"
			<<"---------------\n请输入序号:";
		if(!inputInt(state,num + 1)) return 1;
		if(!state || state == num + 1) return -1;
		else {
			C::find(&course("NULL",name),0,state);
			if(C::isCurrent());
			else return -1;
		}
	}
	system("cls");

	G::refreshRank();
	G::showRow(C::getRank());
	system("pause");
	return -1;
}

int teacherOperation::EditTeacher() {
	system("cls");
	int state;
	cout.setf(ios_base::left);
	cout<<"---------------\n"
		<<setw(_peopleNameLength+1)<<"姓名"
		<<setw(_passwordLength+1)<<"密码"<<endl;
	T::showCurrent();
	cout<<"\n---------------\n"
		<<"1. 修改姓名\n"
		<<"2. 修改密码\n"
		<<"3. 返回上一级\n"
		<<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state,3)) return 1;
	switch(state) {
	case 0: return _exit;
	case 1: {
		char name[_peopleNameLength];
		cout<<"---------------\n"
			<<"请输入新的姓名:";
		if(!inputString(name,_peopleNameLength)) return _exit;
		if(T::isExists(&teacher(name),0)) {
			cout<<"用户名已存在!"<<endl;
			_sleep(_delay);
			return 2;
		}
		setTeacher(name);
		cout<<"修改已成功!\n";
		break;
			}
	case 2: {
		char password[_passwordLength];
		cout<<"---------------\n"
			<<"请输入新的密码:";
		if(!inputString(password,_passwordLength)) return _exit;
		setTeacher("NULL",password);
		cout<<"修改已成功!\n";
		break;
			}
	case 3: return -1;
	}
	cout<<"---------------\n"
		<<"1. 继续修改个人信息\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state,2)) return 1;
	switch(state) {
	case 1: return 2;
	case 2: return -1;
	}
}


bool adminOperation::Login() {
	A::clearCurrent();
	system("cls");
	char name[_peopleNameLength],password[_passwordLength];
	cout<<"---------------\n"
		<<"管理员登陆\n"
		<<"---------------\n"
		<<"用户名:";
	if(!inputString(name,_peopleNameLength)) return _exit;
	cout<<"密码:";
	if(!inputString(password,_passwordLength)) return _exit;
	if(A::isCorrect(&admin(name,password))) {
		while(Menu());
		A::clearCurrent();
	}
	else {
		cout<<"用户名或密码错误!\n";
		_sleep(_delay);
	}
	return _exit;
}
bool adminOperation::Menu() {
	system("cls");
	refreshRank();//生成单科排名
	refreshStudent();//统计总学分和GPA
	int state;
	cout<<"---------------\n"
		<<"您好!";
	A::printTitle();
	cout<<"\n---------------\n"
		<<"1. 更改教师信息\n"
		<<"2. 更改学生信息\n"
		<<"3. 更改课程信息\n"
		<<"4. 更改成绩信息\n"
		<<"5. 修改个人信息\n"
		<<"6. 注销\n"
		<<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state, 6)) return 1;
	while(1) {
		switch(state) {
		case 0: return _exit;
		case 1: {
			//state=ShowGrade();
			break;
				}
		case 2: {
			//state=ShowRank();
			break;
				}
		case 3: {
			//state=EditStudent();
			break;
				}
		case 5: {
			state=EditAdmin();
			break;
				}
		case 6: {
			cout<<"确认注销?(Y/n):";
			if(inputBool()) {
				cout<<"用户已注销\n";
				_sleep(_delay);
				return _exit;
			}
			else return 1;
				 }
		default: return 1;
		}
	}
}

int adminOperation::EditAdmin() {
	system("cls");
	int state;
	cout.setf(ios_base::left);
	cout<<"---------------\n"
		<<setw(_peopleNameLength+1)<<"姓名"
		<<setw(_passwordLength+1)<<"密码"<<endl;
	A::showCurrent();
	cout<<"\n---------------\n"
		<<"1. 修改姓名\n"
		<<"2. 修改密码\n"
		<<"3. 返回上一级\n"
		<<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state,3)) return 1;
	switch(state) {
	case 0: return _exit;
	case 1: {
		char name[_peopleNameLength];
		cout<<"---------------\n"
			<<"请输入新的姓名:";
		if(!inputString(name,_peopleNameLength)) return _exit;
		if(A::isExists(&admin(name),0)) {
			cout<<"用户名已存在!"<<endl;
			_sleep(_delay);
			return 5;
		}
		setAdmin(name);
		cout<<"修改已成功!\n";
		break;
			}
	case 2: {
		char password[_passwordLength];
		cout<<"---------------\n"
			<<"请输入新的密码:";
		if(!inputString(password,_passwordLength)) return _exit;
		setAdmin("NULL",password);
		cout<<"修改已成功!\n";
		break;
			}
	case 3: return -1;
	}
	cout<<"---------------\n"
		<<"1. 继续修改个人信息\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state,2)) return 1;
	switch(state) {
	case 1: return 5;
	case 2: return -1;
	}
}

//------------------------------System----------------------------------

class System: public adminOperation, public teacherOperation, public studentOperation{
public:
	System() {};
	~System() {};
	void Init();//系统初始化,唯一的外部接口
private:
	bool MainMenu();//主菜单入口
	void TestMain();//测试接口
	void Lists_import();//将所有文件信息导入各链表
	void Lists_export();//将所有链表信息输出到各文件
	void About();

};

void System::Init() {
	Lists_import();
	cout<<"Import complete."<<endl;

	while(1) {//测试接口
		cout<<"测试菜单:\n1.测试or2.正常启动?\n"
			<<"请选择序号:";
		int state;
		while(!inputInt(state,2));
		if(state == 1) 
			TestMain();
		else break;
	}

	while(MainMenu());//1为继续,0为退出

	Lists_export();
	cout<<"Export complete."<<endl;
}
bool System::MainMenu() {
	system("cls");
	int state;
	cout<<"=================\n"
		<<"成绩管理系统"<<endl;
	showTime();
	cout<<"\n---------------\n"
		<<"主菜单：\n"
		<<"1. 管理员登陆\n"
		<<"2. 教师登陆\n"
		<<"3. 学生登陆\n"
		<<"4. 关于\n"
		<<"5. 退出\n"
		<<"---------------\n"
		<<"请输入功能序号:";
	if(!inputInt(state,5)) return 1;
	switch(state) {
	case 0: return _exit;
	case 1: {
		while(adminOperation::Login());
		return 1;
			}
	case 2: {
		while(teacherOperation::Login());
		return 1;
			}
	case 3: {
		while(studentOperation::Login());
		return 1;
			}
	case 4: {
		About();
		return 1;
			}
	default: {
		cout<<"---------------\n"
			<<"确认退出?(Y/n):";
		if(inputBool()) return _exit;
		else return 1;
			 }
	}
}
void System::Lists_import() {
	A::Import();
	T::Import();
	S::Import();
	C::Import();
	G::set(C::getLength(),S::getLength());//根据课程数量、学生数量调整成绩矩阵的大小
	G::Import();
}
void System::Lists_export() {
	A::Export();
	T::Export();
	S::Export();
	C::Export();
	G::Export();
}
void System::About() {
	system("CLS");
	cout<<"---------------\n作者信息:陈立人 2014011205\n"
		<<"完成时间:未完成!!!!!!\nAll rights reserved."<<endl;
	system("pause");
}

void main(void)
{
	System GradeSystem;
	GradeSystem.Init();
}

//-----------------------------Test-----------------------------------
void quickSort(int **P,int length) {
	if(length<=1) return;
	int refer;//参考值
	int temp=0,head=1, tail=length-1;
	int *buff;
	refer=*P[temp];
	while(head<tail) {
		while(*P[head]>=refer && head<length-1) head++;//找更小值
		while(*P[tail]<=refer && tail>0) tail--;//找更大值
		if(head<tail) {
			buff=P[head];
			P[head]=P[tail];
			P[tail]=buff;
		}
		else break;
	}
	if(!tail) quickSort(&(P[1]),length-1);
	else {
		buff=P[tail];
		P[tail]=P[temp];
		P[temp]=buff;
		temp=tail;
		quickSort(P,temp);
		if(length-temp-1>1) quickSort(&(P[temp+1]),length-temp-1);
	}
}

void System::TestMain() {
	G::showAllt();
	G::refreshStudent();
	S::showAllt();
	for(int k=1;k<32;k++) {
		showSTU(k);
		cout<<rankInAll(k)<<endl;
	}
	cout.setf(ios_base::left);
	cout<<setw(7)<<setprecision(2)<<100<<"*\n";
	system("pause");
}