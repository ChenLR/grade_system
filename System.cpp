#include <fstream>
#include <cstring>
#include <iomanip>
#include "class.h"
#include "head.h"
#define _Length 1000000
using namespace std;

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
		<<"请输入序号:";
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
		<<"请输入序号:";
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
		<<"请输入序号:";
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
		<<"请输入序号:";
	if(!inputInt(state,3)) return 1;
	switch(state) {
	case 0: return -1;
	case 1: {
		char name[_peopleNameLength];

		cout<<"---------------\n"
			<<"请输入新的姓名:";
		if(!inputString(name,_peopleNameLength)) return -1;
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
		if(!inputString(password,_passwordLength)) return -1;
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
		<<"请输入序号:";
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
		<<"请输入序号:";
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
	if(num == 1) {
		while(CourseMenu());
		return -1;
	}
	else if(num > 1) {
		C::find(&course("NULL",name), 1);
		cout<<setw(2)<<num + 1<<". 返回上一级\n"
			<<"---------------\n请输入序号:";
		if(!inputInt(state,num + 1)) return 1;
		if(!state || state == num + 1) {
			C::clearCurrent();
			return -1;
		}
		else {
			C::find(&course("NULL",name),0,state);
			while(CourseMenu());
			return 1;
		}
	}
	else {
		cout<<"---------------\n"
			<<"课程信息:\n"
			<<"---------------\n"
			<<"该用户无任何课程!\n";
		system("pause");
		return -1;
	}
}
int teacherOperation::CourseMenu() {
	int state;
	system("cls");
	cout.setf(ios_base::left);
	cout<<"---------------\n"
		<<setw(_courseNameLength+1)<<"课程"
		<<"教师\n";
	C::printTitle(C::getRank(),0);
	cout<<"\n---------------\n"
		<<setw(_peopleNameLength+1)<<"学生"
		<<setw(5)<<"成绩"<<"排名\n";
	G::refreshRank();
	G::showRow(C::getRank());
	cout<<"总人数:"<<C::getStudentNum();
	cout<<"\n---------------\n"
		<<"1. 录入或修改成绩\n"
		<<"2. 查看统计信息\n"
		<<"3. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,3)) return 1;
	switch(state) {
	case 1: {
		while(EditGrade());
		break;
			}
	case 2: {
		while(CourseDetail());
		break;
			}
	default: {
		C::clearCurrent();
		return _exit;
			}
	}
	return 1;
}
int teacherOperation::EditGrade() {
	int state;
	system("cls");
	cout<<"---------------\n"
		<<"修改或录入成绩\n"
		<<"---------------\n"
		<<setw(_courseNameLength+1)<<"课程"
		<<"教师\n";
	C::printTitle(C::getRank(),0);
	cout<<"\n---------------\n";
	showRowList(C::getRank());
	cout<<"---------------\n请选择学生序号:";
	if(!inputInt(state,C::getStudentNum())) return 1;
	if(state) {
		int grade;
		system("cls");
		moveInRow(state);
		cout<<"---------------\n"
			<<setw(_courseNameLength+1)<<"课程"
		    <<setw(_peopleNameLength+1)<<"教师"
			<<setw(_peopleNameLength+1)<<"学生"
			<<"成绩\n";
		showNode();
		cout<<"\n---------------\n"
			<<"请输入新的成绩:";
		if(inputGrade(grade)) {
			cout<<"确认修改成绩?(Y/n):";
			if(inputBool()) {
				G::setNode(grade);
				cout<<"修改成功!\n";
			}
			G::clearCurrent();
			cout<<"---------------\n"
				<<"1. 继续修改成绩\n"
				<<"2. 返回上一级\n"
				<<"---------------\n"
				<<"请输入序号:";
			if(!inputInt(state,2)) return 0;
			switch(state) {
			case 1: return 1;
			default: return 0;
			}
		}
		G::clearCurrent();
		return 0;
	}
	else return 0;
}
int teacherOperation::CourseDetail() {
	int state;
	system("cls");
	cout<<"---------------\n"
		<<setw(_courseNameLength+1)<<"课程"
		<<setw(_peopleNameLength+1)<<"教师"
		<<"学分\n";
	C::printTitle();
	cout<<"\n---------------\n"
		<<"最高分:"<<maxInRow()
		<<"\n最低分:"<<minInRow()
		<<"\n平均分:"<<setprecision(3)<<meanInRow()
		<<"\n---------------\n";
	system("pause");
	return 0;
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
		<<"请输入序号:";
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
		<<"请输入序号:";
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
		<<"1. 教师信息\n"
		<<"2. 学生信息\n"
		<<"3. 课程信息\n"
		<<"4. 成绩信息\n"
		<<"5. 修改个人信息\n"
		<<"6. 注销\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state, 6)) return 1;
	while(1) {
		switch(state) {
		case 0: return _exit;
		case 1: {
			state=EditTeacher();
			break;
				}
		case 2: {
			state=EditStudent();
			break;
				}
		case 3: {
			state=EditCourse();
			break;
				}
		case 4: {
			state=EditGrade(); 
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

int adminOperation::EditTeacher() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"教师信息\n"
		<<"---------------\n"
		<<"1. 查看教师信息\n"
		<<"2. 添加教师\n"
		<<"3. 修改教师信息\n"
		<<"4. 删除教师\n"
		<<"5. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,5)) return 1;
	while(1){
		switch(state) {
		case -1: return 1;
		case 1: {
			state = TeacherInfo();
			break;
				}
		case 2: {
			state = AddTeacher();
			break;
				}
		case 3: {
			state = SetTeacher();
			break;
				}
		case 4: {
			state = DeleteTeacher();
			break;
				}
		default: return -1;
		}
	}
	return 1;
}
int adminOperation::TeacherInfo() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"教师信息\n"
		<<"---------------\n";
	T::showAll();
	cout<<"---------------\n"
		<<"1. 查找教师\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(inputInt(state,2) && state == 1) {
		while(1) {
			state = FindTeacher();
			switch(state) {
			case 1: break;
			case 3: return 3;
			case 4: return 4;
			default: return 1;
			}
		}
	}
	else return -1;
}
int adminOperation::FindTeacher(bool flag) {
	int state,num;
	char name[_peopleNameLength];
	if(flag) {
		system("cls");
		cout<<"---------------\n"
			<<"查找教师\n"
			<<"---------------\n";
	}
	cout<<"请输入查找的姓名:";
	if(!inputString(name,_peopleNameLength)) return -1;
	cout<<"---------------\n";
	num = T::find(&teacher(name));
	if(num == 1 && !flag) {
		cout<<"---------------\n";
		return 0;//flag为0时,找到一个即退出
	}
	while(1){
		if(num == 1) {
			cout<<"---------------\n"
				<<"1. 修改教师信息\n"
				<<"2. 删除教师\n"
				<<"3. 返回上一级\n"
				<<"---------------\n"
				<<"请输入序号:";
			if(!inputInt(state,3)) return -1;
			switch(state) {
			case 1: return 3;
			case 2: return 4;
			default: {
				T::clearCurrent();
				return -1;
					 }
			}
		}
		if(num > 1) {
			cout<<"---------------\n"
				<<"1. 选择上述教师的序号\n"
				<<"2. 重新查找\n"
				<<"3. 返回上一级\n"
				<<"---------------\n"
				<<"请输入序号:";
			if(!inputInt(state,3)) return -1;
			switch(state) {
			case 1: {
				cout<<"请选择序号:";
				if(!inputInt(state,num)) return -1;
				num=T::find(&teacher(name),state);//唯一无返回值的路径
				if(!flag && num == 1) {
					cout<<"---------------\n";
					return 0;//flag为0时,找到一个即退出
				}
				break;
					}
			case 2: return 1;
			default: return -1;
			}
		}
		else {
			cout<<"---------------\n"
				<<"1. 重新查找\n"
				<<"2. 返回上一级\n"
				<<"---------------\n"
				<<"请输入序号:";
			if(!inputInt(state,2)) return -1;
			switch(state) {
			case 1: return 1;
			default: return -1;
			}
		}
	}
	return -1;
}
int adminOperation::AddTeacher() {
	system("cls");
	int state;
	char name[_peopleNameLength],password[_passwordLength];
	cout<<"---------------\n"
		<<"添加教师\n"
		<<"---------------\n"
		<<"教师姓名:";
	if(!inputString(name,_peopleNameLength)) return -1;
	if(T::isExists(&teacher(name),0)) {
		cout<<"用户名已存在!\n";
	}
	else {
		cout<<"密码:";
		if(!inputString(password,_passwordLength)) return -1;
		cout<<"确认添加教师?(Y/n):";
		if(inputBool()) {
			teacher *p;
			p = new teacher(name,password);
			if(T::addTeacher(p))
				cout<<"添加成功!\n";
			else cout<<"添加失败:\n";
		}
	}
	cout<<"---------------\n"
		<<"1. 继续添加教师\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,2)) return -1;
	switch(state) {
	case 1: return 2;
	default: return -1;
	}
	return -1;
}
int adminOperation::SetTeacher() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"修改教师信息\n"
		<<"---------------\n";
	if(!T::isCurrent()){
		while(1) {
			state = FindTeacher(0);			
			if(state == -1) return -1;//若查找函数返回上一级,则返回上一级
			else if(state == 0) break;//找到一个教师,退出循环
			system("cls");
			cout<<"---------------\n"
				<<"修改教师信息\n"
				<<"---------------\n";
		}
	}

	cout.setf(ios_base::left);
	cout<<"待修改的条目:\n"
		<<setw(_peopleNameLength+1)<<"姓名"
		<<setw(_passwordLength+1)<<"密码"<<endl;
	T::showCurrent();
	cout<<"\n---------------\n"
		<<"1. 修改姓名\n"
		<<"2. 修改密码\n"
		<<"3. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,3)) return -1;
	switch(state) {
	case 1: {
		char name[_peopleNameLength];
		cout<<"---------------\n"
			<<"请输入新的姓名:";
		if(!inputString(name,_peopleNameLength)) return -1;
		if(T::isExists(&teacher(name),0)) {
			cout<<"用户名已存在!"<<endl;
			_sleep(_delay);
			return 3;
		}
		setTeacher(name);
		cout<<"修改已成功!\n";
		break;
			}
	case 2: {
		char password[_passwordLength];
		cout<<"---------------\n"
			<<"请输入新的密码:";
		if(!inputString(password,_passwordLength)) return -1;
		setTeacher("NULL",password);
		cout<<"修改已成功!\n";
		break;
			}
	default: {
		T::clearCurrent();
		return -1;
			 }
	}

	cout<<"---------------\n"
		<<"1. 继续修改教师信息\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,2)) {
		T::clearCurrent();
		return -1;
	}
	switch(state) {
	case 1: return 3;
	default: {
		T::clearCurrent();
		return -1;
			 }
	}
	T::clearCurrent();
	return -1;
}
int adminOperation::DeleteTeacher() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"删除教师\n"
		<<"---------------\n";
	if(!T::isCurrent()){
		while(1) {
			state = FindTeacher(0);			
			if(state == -1) return -1;//若查找函数返回上一级,则返回上一级
			else if(state == 0) break;//找到一个教师,退出循环
			system("cls");
			cout<<"---------------\n"
				<<"删除教师\n"
				<<"---------------\n";
		}
	}
	cout.setf(ios_base::left);
	cout<<"待删除的条目:\n"
		<<setw(_peopleNameLength+1)<<"姓名"
		<<setw(_passwordLength+1)<<"密码"<<endl;
	T::showCurrent();
	cout<<"\n---------------\n"
		<<"该教师执教的课程,及其成绩信息将一并删除\n确认删除教师?(Y/n):";
	if(inputBool()){
		char name[_peopleNameLength];
		T::getName(name);
		G::deleteCourses(name);//删除教师对应的课程及成绩信息
		if(T::deleteTeacher())
			cout<<"删除成功!\n";
		else 
			cout<<"删除失败!\n";
	}
	cout<<"---------------\n"
		<<"1. 继续删除教师\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,2)) {
		T::clearCurrent();
		return -1;
	}
	switch(state) {
	case 1: return 4;
	default: {
		T::clearCurrent();
		return -1;
			 }
	}
	T::clearCurrent();
	return -1;
}

int adminOperation::EditStudent(){
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"学生信息\n"
		<<"---------------\n"
		<<"1. 查看学生信息\n"
		<<"2. 添加学生\n"
		<<"3. 修改学生信息\n"
		<<"4. 删除学生\n"
		<<"5. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,5)) return 2;
	while(1){
		switch(state) {
		case -1: return 2;
		case 1: {
			state = StudentInfo();
			break;
				}
		case 2: {
			state = AddStudent();
			break;
				}
		case 3: {
			state = SetStudent();
			break;
				}
		case 4: {
			state = DeleteStudent();
			break;
				}
		default: return -1;
		}
	}
	return 2;
}
int adminOperation::StudentInfo() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"学生信息\n"
		<<"---------------\n";
	S::showAll();
	cout<<"---------------\n"
		<<"1. 查找学生\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(inputInt(state,2) && state == 1) {
		while(1) {
			state = FindStudent();
			switch(state) {
			case 1: break;
			case 3: return 3;
			case 4: return 4;
			default: return 1;
			}
		}
	}
	else return -1;
}
int adminOperation::FindStudent(bool flag) {
	int state,num;
	char name[_peopleNameLength];
	if(flag) {
		system("cls");
		cout<<"---------------\n"
			<<"查找学生\n"
			<<"---------------\n";
	}
	cout<<"请输入查找的姓名:";
	if(!inputString(name,_peopleNameLength)) return -1;
	cout<<"---------------\n";
	num = S::find(&student(name));
	if(num == 1 && !flag) {
		cout<<"---------------\n";
		return 0;//flag为0时,找到一个即退出
	}
	while(1){
		if(num == 1) {
			cout<<"---------------\n"
				<<"1. 修改学生信息\n"
				<<"2. 删除学生\n"
				<<"3. 返回上一级\n"
				<<"---------------\n"
				<<"请输入序号:";
			if(!inputInt(state,3)) return -1;
			switch(state) {
			case 1: return 3;
			case 2: return 4;
			default: {
				S::clearCurrent();
				return -1;
					 }
			}
		}
		if(num > 1) {
			cout<<"---------------\n"
				<<"1. 选择上述学生的序号\n"
				<<"2. 重新查找\n"
				<<"3. 返回上一级\n"
				<<"---------------\n"
				<<"请输入序号:";
			if(!inputInt(state,3)) return -1;
			switch(state) {
			case 1: {
				cout<<"请选择序号:";
				if(!inputInt(state,num)) return -1;
				num=S::find(&student(name),state);//唯一无返回值的路径
				if(!flag && num == 1) {
					cout<<"---------------\n";
					return 0;//flag为0时,找到一个即退出
				}
				break;
					}
			case 2: return 1;
			default: return -1;
			}
		}
		else {
			cout<<"---------------\n"
				<<"1. 重新查找\n"
				<<"2. 返回上一级\n"
				<<"---------------\n"
				<<"请输入序号:";
			if(!inputInt(state,2)) return -1;
			switch(state) {
			case 1: return 1;
			default: return -1;
			}
		}
	}
	return -1;
}
int adminOperation::AddStudent() {
	system("cls");
	int state;
	char name[_peopleNameLength],password[_passwordLength];
	cout<<"---------------\n"
		<<"添加学生\n"
		<<"---------------\n"
		<<"学生姓名:";
	if(!inputString(name,_peopleNameLength)) return -1;
	if(S::isExists(&student(name),0)) {
		cout<<"用户名已存在!\n";
	}
	else {
		cout<<"密码:";
		if(!inputString(password,_passwordLength)) return -1;
		cout<<"确认添加学生?(Y/n):";
		if(inputBool()) {
			student *p;
			p = new student(name,password);
			if(S::addStudent(p))
				cout<<"添加成功!\n";
			else cout<<"添加失败:\n";
		}
	}
	cout<<"---------------\n"
		<<"1. 继续添加学生\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,2)) return -1;
	switch(state) {
	case 1: return 2;
	default: return -1;
	}
	return -1;
}
int adminOperation::SetStudent() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"修改学生信息\n"
		<<"---------------\n";
	if(!S::isCurrent()){
		while(1) {
			state = FindStudent(0);			
			if(state == -1) return -1;//若查找函数返回上一级,则返回上一级
			else if(state == 0) break;//找到一个学生,退出循环
			system("cls");
			cout<<"---------------\n"
				<<"修改学生信息\n"
				<<"---------------\n";
		}
	}

	cout.setf(ios_base::left);
	cout<<"待修改的条目:\n"
		<<setw(_peopleNameLength+1)<<"姓名"
		<<setw(_passwordLength+1)<<"密码"<<endl;
	S::showCurrent();
	cout<<"\n---------------\n"
		<<"1. 修改姓名\n"
		<<"2. 修改密码\n"
		<<"3. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,3)) return -1;
	switch(state) {
	case 1: {
		char name[_peopleNameLength];
		cout<<"---------------\n"
			<<"请输入新的姓名:";
		if(!inputString(name,_peopleNameLength)) return -1;
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
		if(!inputString(password,_passwordLength)) return -1;
		setStudent("NULL",password);
		cout<<"修改已成功!\n";
		break;
			}
	default: {
		S::clearCurrent();
		return -1;
			 }
	}

	cout<<"---------------\n"
		<<"1. 继续修改学生信息\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,2)) {
		S::clearCurrent();
		return -1;
	}
	switch(state) {
	case 1: return 3;
	default: {
		S::clearCurrent();
		return -1;
			 }
	}
	S::clearCurrent();
	return -1;
}
int adminOperation::DeleteStudent() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"删除学生\n"
		<<"---------------\n";
	if(!S::isCurrent()){
		while(1) {
			state = FindStudent(0);			
			if(state == -1) return -1;//若查找函数返回上一级,则返回上一级
			else if(state == 0) break;//找到一个学生,退出循环
			system("cls");
			cout<<"---------------\n"
				<<"删除学生\n"
				<<"---------------\n";
		}
	}
	cout.setf(ios_base::left);
	cout<<"待删除的条目:\n"
		<<setw(_peopleNameLength+1)<<"姓名"
		<<setw(_passwordLength+1)<<"密码"<<endl;
	S::showCurrent();
	cout<<"\n---------------\n"
		<<"该学生对应的成绩信息将一并删除\n确认删除学生?(Y/n):";
	if(inputBool()){
		G::deleteCol(S::getRank());//删除成绩信息
		if(S::deleteStudent())//删除学生信息
			cout<<"删除成功!\n";
		else 
			cout<<"删除失败!\n";
	}
	cout<<"---------------\n"
		<<"1. 继续删除学生\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,2)) {
		S::clearCurrent();
		return -1;
	}
	switch(state) {
	case 1: return 4;
	default: {
		S::clearCurrent();
		return -1;
			 }
	}
	S::clearCurrent();
	return -1;
}

int adminOperation::EditCourse(){
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"课程信息\n"
		<<"---------------\n"
		<<"1. 查看课程信息\n"
		<<"2. 添加课程\n"
		<<"3. 修改课程信息\n"
		<<"4. 删除课程\n"
		<<"5. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,5)) return 3;
	while(1){
		switch(state) {
		case -1: return 3;
		case 1: {
			state = CourseInfo();
			break;
				}
		case 2: {
			state = AddCourse();
			break;
				}
		case 3: {
			state = SetCourse();
			break;
				}
		case 4: {
			state = DeleteCourse();
			break;
				}
		default: return -1;
		}
	}
	return 3;
}
int adminOperation::CourseInfo() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"课程信息\n"
		<<"---------------\n";
	C::showAll();
	cout<<"---------------\n"
		<<"1. 查找课程\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(inputInt(state,2) && state == 1) {
		while(1) {
			state = FindCourse();
			switch(state) {
			case 1: break;
			case 3: return 3;
			case 4: return 4;
			default: return 1;
			}
		}
	}
	else return -1;
}
int adminOperation::FindCourse(bool flag) {
	char name[_courseNameLength],teacher[_peopleNameLength];
	int credit;
	int state,num = 0;
	bool isEmpty = courseBuff.isEmpty();

	if(flag) {
		system("cls");
		cout<<"---------------\n"
			<<"查找课程\n"
			<<"---------------\n";
	}

	if(isEmpty) {
		cout<<"添加查找信息:\n"
			<<"1. 课程名\n"
			<<"2. 教师\n"
			<<"3. 学分\n"
			<<"4. 返回上一级\n"
			<<"---------------\n"
			<<"请输入序号:";
		if(!inputInt(state,4)) return 1;
	}
	else {
		cout<<"目前的查找信息:\n";
		courseBuff.print();
		cout<<"---------------\n"
			<<"添加查找信息:\n"
			<<"1. 课程名\n"
			<<"2. 教师\n"
			<<"3. 学分\n"
			<<"4. 清空查找信息\n"
			<<"5. 返回上一级\n"
			<<"---------------\n"
			<<"请输入序号:";
		if(!inputInt(state,5)) return 1;
	}

	if(isEmpty && state == 4 || !isEmpty && state == 5 || state == 0) {//返回上一级
		courseBuff.clear();
		return -1;
	}

	if(state==1) {
		cout<<"---------------\n"
			<<"查找的课程名:";
		if(inputString(name,_courseNameLength))
			courseBuff.set(name);
		else return 1;
	}
	else if(state==2) {
		cout<<"---------------\n"
			<<"查找的教师:";
		if(inputString(teacher,_peopleNameLength))
			courseBuff.set("NULL",teacher);
		else return 1;
	}
	else if(state==3) {
		cout<<"---------------\n请输入查找的学分:";
		if(inputGrade(credit,_maxCredit))
			courseBuff.set("NULL","NULL",credit);
		else return 1;
	}
	else {
		courseBuff.clear();
		return 1;
	}

	num=C::find(&courseBuff,1);//查找课程,返回找到的个数

	if(num == 1 && !flag) {
		cout<<"---------------\n";
		return 0;//flag为0时,找到一个即退出
	}

	while(1){
		if(num == 1) {
			cout<<"---------------\n"
				<<"1. 修改课程信息\n"
				<<"2. 删除课程\n"
				<<"3. 返回上一级\n"
				<<"---------------\n"
				<<"请输入序号:";
			courseBuff.clear();
			if(!inputInt(state,3)) return -1;
			switch(state) {
			case 1: return 3;
			case 2: return 4;
			default: {
				C::clearCurrent();
				return -1;
					 }
			}
		}
		if(num > 1) {
			cout<<"---------------\n"
				<<"1. 选择上述课程的序号\n"
				<<"2. 添加或修改查找信息\n"
				<<"3. 返回上一级\n"
				<<"---------------\n"
				<<"请输入序号:";
			if(!inputInt(state,3)) {
				courseBuff.clear();
				return -1;
			}
			switch(state) {
			case 1: {
				cout<<"---------------\n"
					<<"请选择序号:";
				if(!inputInt(state,num)) return -1;
				num=C::find(&courseBuff,flag,state);//唯一无返回值的路径
				if(!flag && num == 1) {
					cout<<"---------------\n";
					return 0;//flag为0时,找到一个即退出
				}
				break;
					}
			case 2: return 1;
			default: {
				courseBuff.clear();
				return -1;
					 }
			}
		}
		else {
			cout<<"---------------\n"
				<<"1. 添加或修改查找信息\n"
				<<"2. 返回上一级\n"
				<<"---------------\n"
				<<"请输入序号:";
			if(!inputInt(state,2)) {
				courseBuff.clear();
				return -1;
			}
			switch(state) {
			case 1: return 1;
			default: {
				courseBuff.clear();
				return -1;
					 }
			}
		}
	}
}
int adminOperation::AddCourse() {
	system("cls");
	int state;
	char name[_courseNameLength],teacher[_peopleNameLength];
	int credit;
	cout<<"---------------\n"
		<<"添加课程\n"
		<<"---------------\n"
		<<"课程名:";
	if(!inputString(name,_courseNameLength)) return -1;
	cout<<"教师:";
	if(!inputString(teacher,_peopleNameLength)) return -1;
	if(C::isExists(&course(name,teacher))) {
		cout<<"该课程已存在!\n";
	}
	else if(!T::isExists(&class teacher(teacher),0)) {
		cout<<"该教师不存在,请先添加教师!\n";
	}
	else {
		cout<<"学分:";
		if(!inputGrade(credit,_maxCredit)) return -1;
		if(credit < 0) credit = 0;
		cout<<"确认添加课程?(Y/n):";
		if(inputBool()) {
			course *p;
			p = new course(name,teacher,credit);
			if(C::addCourse(p))
				cout<<"添加成功!\n";
			else cout<<"添加失败:\n";
		}
	}
	cout<<"---------------\n"
		<<"1. 继续添加课程\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,2)) return -1;
	switch(state) {
	case 1: return 2;
	default: return -1;
	}
	return -1;
}
int adminOperation::SetCourse() {
	system("cls");
	char name[_courseNameLength],teacher[_peopleNameLength];
	int credit;
	int state;
	cout<<"---------------\n"
		<<"修改课程信息\n"
		<<"---------------\n";
	if(!C::isCurrent()){
		while(1) {
			state = FindCourse(0);			
			if(state == -1) return -1;//若查找函数返回上一级,则返回上一级
			else if(state == 0) break;//找到一门课程,退出循环
			system("cls");
			cout<<"---------------\n"
				<<"修改课程信息\n"
				<<"---------------\n";
		}
	}

	cout.setf(ios_base::left);
	cout<<"待修改的条目:\n";
	C::showCurrent();
	cout<<"\n---------------\n"
		<<"1. 修改课程名\n"
		<<"2. 修改教师\n"
		<<"3. 修改学分\n"
		<<"4. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,4)) return -1;
	switch(state) {
	case 1: {
		cout<<"---------------\n"
			<<"请输入新的课程名:";
		if(!inputString(name,_courseNameLength)) return -1;
		C::getTeacher(teacher);
		if(C::isExists(&course(name,teacher))) {
			cout<<"该课程已存在!"<<endl;
			_sleep(_delay);
			return 3;
		}
		setCourse(name);
		cout<<"修改已成功!\n";
		break;
			}
	case 2: {
		cout<<"---------------\n"
			<<"请输入新的教师名:";
		if(!inputString(teacher,_peopleNameLength)) return -1;
		if(!T::isExists(&class teacher(teacher),0)) {
			cout<<"该教师不存在!请先添加教师\n";
		}
		C::getName(name);
		if(C::isExists(&course(name,teacher))) {
			cout<<"该课程已存在!"<<endl;
			_sleep(_delay);
			return 3;
		}
		setCourse("NULL",teacher);
		cout<<"修改已成功!\n";
		break;
			}
	case 3: {
		cout<<"---------------\n"
			<<"请输入新的学分:";
		if(!inputGrade(credit,_maxCredit)) return -1;
		if(credit < 0) credit = 0;
		setCourse("NULL","NULL",credit);
		cout<<"修改已成功!\n";
		break;
			}
	default: {
		C::clearCurrent();
		return -1;
			 }
	}
	cout<<"---------------\n"
		<<"1. 继续修改课程信息\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,2)) {
		C::clearCurrent();
		return -1;
	}
	switch(state) {
	case 1: return 3;
	default: {
		C::clearCurrent();
		return -1;
			 }
	}
	C::clearCurrent();
	return -1;
}
int adminOperation::DeleteCourse() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"删除课程\n"
		<<"---------------\n";
	if(!C::isCurrent()){
		while(1) {
			state = FindCourse(0);			
			if(state == -1) return -1;//若查找函数返回上一级,则返回上一级
			else if(state == 0) break;//找到一个课程,退出循环
			system("cls");
			cout<<"---------------\n"
				<<"删除课程\n"
				<<"---------------\n";
		}
	}
	cout.setf(ios_base::left);
	cout<<"待删除的条目:\n";
	C::showCurrent();
	cout<<"\n---------------\n"
		<<"该课程对应的成绩信息将一并删除\n确认删除课程?(Y/n):";
	if(inputBool()){
		G::deleteRow(C::getRank());//删除成绩信息
		if(C::deleteCourse())//删除课程信息
			cout<<"删除成功!\n";
		else 
			cout<<"删除失败!\n";
	}
	cout<<"---------------\n"
		<<"1. 继续删除课程\n"
		<<"2. 返回上一级\n"
		<<"---------------\n"
		<<"请输入序号:";
	if(!inputInt(state,2)) {
		C::clearCurrent();
		return -1;
	}
	switch(state) {
	case 1: return 4;
	default: {
		C::clearCurrent();
		return -1;
			 }
	}
	C::clearCurrent();
	return -1;
}

int adminOperation::EditGrade() {return 0;}
int adminOperation::FindGrade(bool flag) {
	return 0;
}
int adminOperation::AddGrade() {
	return 0;
}
int adminOperation::SetGrade() {
	return 0;
}
int adminOperation::DeleteGrade() {
	return 0;
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
		<<"请输入序号:";
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
		<<"请输入序号:";
	if(!inputInt(state,2)) return 1;
	switch(state) {
	case 1: return 5;
	case 2: return -1;
	}
}

//------------------------------System----------------------------------

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
		<<"请输入序号:";
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
	showColList(1);
}