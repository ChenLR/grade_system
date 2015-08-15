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
		<<"ѧ����½\n"
		<<"---------------\n"
		<<"�û���:";
	if(!inputString(name,_peopleNameLength)) return _exit;
	cout<<"����:";
	if(!inputString(password,_passwordLength)) return _exit;
	if(S::isCorrect(&student(name,password))) {
		while(Menu());
		S::clearCurrent();
	}
	else {
		cout<<"�û������������!\n";
		_sleep(_delay);
	}
	return _exit;
}
bool studentOperation::Menu() {
	system("cls");
	refreshRank();//���ɵ�������
	refreshStudent();//ͳ����ѧ�ֺ�GPA
	int state;
	cout<<"---------------\n"
		<<"����!";
	S::printTitle();
	cout<<"\n---------------\n"
		<<"1. �ɼ���ѯ\n"
		<<"2. ������ѯ\n"
		<<"3. �޸ĸ�����Ϣ\n"
		<<"4. ע��\n"
		<<"---------------\n"
		<<"�����빦�����:";
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
			cout<<"ȷ��ע��?(Y/n):";
			if(inputBool()) {
				cout<<"�û���ע��\n";
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
	cout<<"---------------\n�ɼ���\n"
		<<"ѧ��:";
	S::printTitle();
	cout<<"\n---------------\n"
		<<setw(_courseNameLength+1)<<"�γ�"
		<<setw(_peopleNameLength+1)<<"��ʦ"
		<<"ѧ�� �ɼ� ����"<<endl;
	G::showCol(S::getRank());   
	cout<<"---------------\n"
		<<"1. ������ѯ\n"
		<<"2. �޸ĸ�����Ϣ\n"
		<<"3. ע��\n"
	    <<"---------------\n"
		<<"�����빦�����:";
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
		<<"ѧ��:";
	S::printTitle();
	cout<<"\n---------------\n"
		<<"��ѧ�� �ɼ�   ����"<<endl;
	S::showSTU();
	cout<<rankInAll()<<endl;
	cout<<"---------------\n"
		<<"1. �ɼ���ѯ\n"
		<<"2. �޸ĸ�����Ϣ\n"
		<<"3. ע��\n"
		<<"---------------\n"
		<<"�����빦�����:";
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
		<<setw(_peopleNameLength+1)<<"����"
		<<setw(_passwordLength+1)<<"����"<<endl;
	S::showCurrent();
	cout<<"\n---------------\n"
		<<"1. �޸�����\n"
		<<"2. �޸�����\n"
		<<"3. ������һ��\n"
		<<"---------------\n"
		<<"�����빦�����:";
	if(!inputInt(state,3)) return 1;
	switch(state) {
	case 0: return _exit;
	case 1: {
		char name[_peopleNameLength];
		cout<<"---------------\n"
			<<"�������µ�����:";
		if(!inputString(name,_peopleNameLength)) return _exit;
		if(S::isExists(&student(name),0)) {
			cout<<"�û����Ѵ���!"<<endl;
			_sleep(_delay);
			return 3;
		}
		setStudent(name);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	case 2: {
		char password[_passwordLength];
		cout<<"---------------\n"
			<<"�������µ�����:";
		if(!inputString(password,_passwordLength)) return _exit;
		setStudent("NULL",password);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	case 3: return -1;
	}
	cout<<"---------------\n"
		<<"1. �ɼ���ѯ\n"
		<<"2. ������ѯ\n"
		<<"3. �����޸ĸ�����Ϣ\n"
		<<"4. ע��\n"
		<<"---------------\n"
		<<"�����빦�����:";
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
		<<"��ʦ��½\n"
		<<"---------------\n"
		<<"�û���:";
	if(!inputString(name,_peopleNameLength)) return _exit;
	cout<<"����:";
	if(!inputString(password,_passwordLength)) return _exit;
	if(T::isCorrect(&teacher(name,password))) {
		while(Menu());
		T::clearCurrent();
	}
	else {
		cout<<"�û������������!\n";
		_sleep(_delay);
	}
	return _exit;
}
bool teacherOperation::Menu() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"����!";
	T::printTitle();
	cout<<"\n---------------\n"
		<<"1. �鿴�γ�\n"
		<<"2. �޸ĸ�����Ϣ\n"
		<<"3. ע��\n"
		<<"---------------\n"
		<<"�����빦�����:";
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
			cout<<"ȷ��ע��?(Y/n):";
			if(inputBool()) {
				cout<<"�û���ע��\n";
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
		cout<<setw(2)<<num + 1<<". ������һ��\n"
			<<"---------------\n���������:";
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
		<<setw(_peopleNameLength+1)<<"����"
		<<setw(_passwordLength+1)<<"����"<<endl;
	T::showCurrent();
	cout<<"\n---------------\n"
		<<"1. �޸�����\n"
		<<"2. �޸�����\n"
		<<"3. ������һ��\n"
		<<"---------------\n"
		<<"�����빦�����:";
	if(!inputInt(state,3)) return 1;
	switch(state) {
	case 0: return _exit;
	case 1: {
		char name[_peopleNameLength];
		cout<<"---------------\n"
			<<"�������µ�����:";
		if(!inputString(name,_peopleNameLength)) return _exit;
		if(T::isExists(&teacher(name),0)) {
			cout<<"�û����Ѵ���!"<<endl;
			_sleep(_delay);
			return 2;
		}
		setTeacher(name);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	case 2: {
		char password[_passwordLength];
		cout<<"---------------\n"
			<<"�������µ�����:";
		if(!inputString(password,_passwordLength)) return _exit;
		setTeacher("NULL",password);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	case 3: return -1;
	}
	cout<<"---------------\n"
		<<"1. �����޸ĸ�����Ϣ\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"�����빦�����:";
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
		<<"����Ա��½\n"
		<<"---------------\n"
		<<"�û���:";
	if(!inputString(name,_peopleNameLength)) return _exit;
	cout<<"����:";
	if(!inputString(password,_passwordLength)) return _exit;
	if(A::isCorrect(&admin(name,password))) {
		while(Menu());
		A::clearCurrent();
	}
	else {
		cout<<"�û������������!\n";
		_sleep(_delay);
	}
	return _exit;
}
bool adminOperation::Menu() {
	system("cls");
	refreshRank();//���ɵ�������
	refreshStudent();//ͳ����ѧ�ֺ�GPA
	int state;
	cout<<"---------------\n"
		<<"����!";
	A::printTitle();
	cout<<"\n---------------\n"
		<<"1. ���Ľ�ʦ��Ϣ\n"
		<<"2. ����ѧ����Ϣ\n"
		<<"3. ���Ŀγ���Ϣ\n"
		<<"4. ���ĳɼ���Ϣ\n"
		<<"5. �޸ĸ�����Ϣ\n"
		<<"6. ע��\n"
		<<"---------------\n"
		<<"�����빦�����:";
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
			cout<<"ȷ��ע��?(Y/n):";
			if(inputBool()) {
				cout<<"�û���ע��\n";
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
		<<setw(_peopleNameLength+1)<<"����"
		<<setw(_passwordLength+1)<<"����"<<endl;
	A::showCurrent();
	cout<<"\n---------------\n"
		<<"1. �޸�����\n"
		<<"2. �޸�����\n"
		<<"3. ������һ��\n"
		<<"---------------\n"
		<<"�����빦�����:";
	if(!inputInt(state,3)) return 1;
	switch(state) {
	case 0: return _exit;
	case 1: {
		char name[_peopleNameLength];
		cout<<"---------------\n"
			<<"�������µ�����:";
		if(!inputString(name,_peopleNameLength)) return _exit;
		if(A::isExists(&admin(name),0)) {
			cout<<"�û����Ѵ���!"<<endl;
			_sleep(_delay);
			return 5;
		}
		setAdmin(name);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	case 2: {
		char password[_passwordLength];
		cout<<"---------------\n"
			<<"�������µ�����:";
		if(!inputString(password,_passwordLength)) return _exit;
		setAdmin("NULL",password);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	case 3: return -1;
	}
	cout<<"---------------\n"
		<<"1. �����޸ĸ�����Ϣ\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"�����빦�����:";
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
	void Init();//ϵͳ��ʼ��,Ψһ���ⲿ�ӿ�
private:
	bool MainMenu();//���˵����
	void TestMain();//���Խӿ�
	void Lists_import();//�������ļ���Ϣ���������
	void Lists_export();//������������Ϣ��������ļ�
	void About();

};

void System::Init() {
	Lists_import();
	cout<<"Import complete."<<endl;

	while(1) {//���Խӿ�
		cout<<"���Բ˵�:\n1.����or2.��������?\n"
			<<"��ѡ�����:";
		int state;
		while(!inputInt(state,2));
		if(state == 1) 
			TestMain();
		else break;
	}

	while(MainMenu());//1Ϊ����,0Ϊ�˳�

	Lists_export();
	cout<<"Export complete."<<endl;
}
bool System::MainMenu() {
	system("cls");
	int state;
	cout<<"=================\n"
		<<"�ɼ�����ϵͳ"<<endl;
	showTime();
	cout<<"\n---------------\n"
		<<"���˵���\n"
		<<"1. ����Ա��½\n"
		<<"2. ��ʦ��½\n"
		<<"3. ѧ����½\n"
		<<"4. ����\n"
		<<"5. �˳�\n"
		<<"---------------\n"
		<<"�����빦�����:";
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
			<<"ȷ���˳�?(Y/n):";
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
	G::set(C::getLength(),S::getLength());//���ݿγ�������ѧ�����������ɼ�����Ĵ�С
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
	cout<<"---------------\n������Ϣ:������ 2014011205\n"
		<<"���ʱ��:δ���!!!!!!\nAll rights reserved."<<endl;
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
	int refer;//�ο�ֵ
	int temp=0,head=1, tail=length-1;
	int *buff;
	refer=*P[temp];
	while(head<tail) {
		while(*P[head]>=refer && head<length-1) head++;//�Ҹ�Сֵ
		while(*P[tail]<=refer && tail>0) tail--;//�Ҹ���ֵ
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