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
		<<"���������:";
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
		<<"���������:";
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
		<<"���������:";
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
		<<"���������:";
	if(!inputInt(state,3)) return 1;
	switch(state) {
	case 0: return -1;
	case 1: {
		char name[_peopleNameLength];

		cout<<"---------------\n"
			<<"�������µ�����:";
		if(!inputString(name,_peopleNameLength)) return -1;
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
		if(!inputString(password,_passwordLength)) return -1;
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
		<<"���������:";
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
		<<"���������:";
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
	if(num == 1) {
		while(CourseMenu());
		return -1;
	}
	else if(num > 1) {
		C::find(&course("NULL",name), 1);
		cout<<setw(2)<<num + 1<<". ������һ��\n"
			<<"---------------\n���������:";
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
			<<"�γ���Ϣ:\n"
			<<"---------------\n"
			<<"���û����κογ�!\n";
		system("pause");
		return -1;
	}
}
int teacherOperation::CourseMenu() {
	int state;
	system("cls");
	cout.setf(ios_base::left);
	cout<<"---------------\n"
		<<setw(_courseNameLength+1)<<"�γ�"
		<<"��ʦ\n";
	C::printTitle(C::getRank(),0);
	cout<<"\n---------------\n"
		<<setw(_peopleNameLength+1)<<"ѧ��"
		<<setw(5)<<"�ɼ�"<<"����\n";
	G::refreshRank();
	G::showRow(C::getRank());
	cout<<"������:"<<C::getStudentNum();
	cout<<"\n---------------\n"
		<<"1. ¼����޸ĳɼ�\n"
		<<"2. �鿴ͳ����Ϣ\n"
		<<"3. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"�޸Ļ�¼��ɼ�\n"
		<<"---------------\n"
		<<setw(_courseNameLength+1)<<"�γ�"
		<<"��ʦ\n";
	C::printTitle(C::getRank(),0);
	cout<<"\n---------------\n";
	showRowList(C::getRank());
	cout<<"---------------\n��ѡ��ѧ�����:";
	if(!inputInt(state,C::getStudentNum())) return 1;
	if(state) {
		int grade;
		system("cls");
		moveInRow(state);
		cout<<"---------------\n"
			<<setw(_courseNameLength+1)<<"�γ�"
		    <<setw(_peopleNameLength+1)<<"��ʦ"
			<<setw(_peopleNameLength+1)<<"ѧ��"
			<<"�ɼ�\n";
		showNode();
		cout<<"\n---------------\n"
			<<"�������µĳɼ�:";
		if(inputGrade(grade)) {
			cout<<"ȷ���޸ĳɼ�?(Y/n):";
			if(inputBool()) {
				G::setNode(grade);
				cout<<"�޸ĳɹ�!\n";
			}
			G::clearCurrent();
			cout<<"---------------\n"
				<<"1. �����޸ĳɼ�\n"
				<<"2. ������һ��\n"
				<<"---------------\n"
				<<"���������:";
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
		<<setw(_courseNameLength+1)<<"�γ�"
		<<setw(_peopleNameLength+1)<<"��ʦ"
		<<"ѧ��\n";
	C::printTitle();
	cout<<"\n---------------\n"
		<<"��߷�:"<<maxInRow()
		<<"\n��ͷ�:"<<minInRow()
		<<"\nƽ����:"<<setprecision(3)<<meanInRow()
		<<"\n---------------\n";
	system("pause");
	return 0;
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
		<<"���������:";
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
		<<"���������:";
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
		<<"1. ��ʦ��Ϣ\n"
		<<"2. ѧ����Ϣ\n"
		<<"3. �γ���Ϣ\n"
		<<"4. �ɼ���Ϣ\n"
		<<"5. �޸ĸ�����Ϣ\n"
		<<"6. ע��\n"
		<<"---------------\n"
		<<"���������:";
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

int adminOperation::EditTeacher() {
	system("cls");
	int state;
	cout<<"---------------\n"
		<<"��ʦ��Ϣ\n"
		<<"---------------\n"
		<<"1. �鿴��ʦ��Ϣ\n"
		<<"2. ��ӽ�ʦ\n"
		<<"3. �޸Ľ�ʦ��Ϣ\n"
		<<"4. ɾ����ʦ\n"
		<<"5. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"��ʦ��Ϣ\n"
		<<"---------------\n";
	T::showAll();
	cout<<"---------------\n"
		<<"1. ���ҽ�ʦ\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
			<<"���ҽ�ʦ\n"
			<<"---------------\n";
	}
	cout<<"��������ҵ�����:";
	if(!inputString(name,_peopleNameLength)) return -1;
	cout<<"---------------\n";
	num = T::find(&teacher(name));
	if(num == 1 && !flag) {
		cout<<"---------------\n";
		return 0;//flagΪ0ʱ,�ҵ�һ�����˳�
	}
	while(1){
		if(num == 1) {
			cout<<"---------------\n"
				<<"1. �޸Ľ�ʦ��Ϣ\n"
				<<"2. ɾ����ʦ\n"
				<<"3. ������һ��\n"
				<<"---------------\n"
				<<"���������:";
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
				<<"1. ѡ��������ʦ�����\n"
				<<"2. ���²���\n"
				<<"3. ������һ��\n"
				<<"---------------\n"
				<<"���������:";
			if(!inputInt(state,3)) return -1;
			switch(state) {
			case 1: {
				cout<<"��ѡ�����:";
				if(!inputInt(state,num)) return -1;
				num=T::find(&teacher(name),state);//Ψһ�޷���ֵ��·��
				if(!flag && num == 1) {
					cout<<"---------------\n";
					return 0;//flagΪ0ʱ,�ҵ�һ�����˳�
				}
				break;
					}
			case 2: return 1;
			default: return -1;
			}
		}
		else {
			cout<<"---------------\n"
				<<"1. ���²���\n"
				<<"2. ������һ��\n"
				<<"---------------\n"
				<<"���������:";
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
		<<"��ӽ�ʦ\n"
		<<"---------------\n"
		<<"��ʦ����:";
	if(!inputString(name,_peopleNameLength)) return -1;
	if(T::isExists(&teacher(name),0)) {
		cout<<"�û����Ѵ���!\n";
	}
	else {
		cout<<"����:";
		if(!inputString(password,_passwordLength)) return -1;
		cout<<"ȷ����ӽ�ʦ?(Y/n):";
		if(inputBool()) {
			teacher *p;
			p = new teacher(name,password);
			if(T::addTeacher(p))
				cout<<"��ӳɹ�!\n";
			else cout<<"���ʧ��:\n";
		}
	}
	cout<<"---------------\n"
		<<"1. ������ӽ�ʦ\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"�޸Ľ�ʦ��Ϣ\n"
		<<"---------------\n";
	if(!T::isCurrent()){
		while(1) {
			state = FindTeacher(0);			
			if(state == -1) return -1;//�����Һ���������һ��,�򷵻���һ��
			else if(state == 0) break;//�ҵ�һ����ʦ,�˳�ѭ��
			system("cls");
			cout<<"---------------\n"
				<<"�޸Ľ�ʦ��Ϣ\n"
				<<"---------------\n";
		}
	}

	cout.setf(ios_base::left);
	cout<<"���޸ĵ���Ŀ:\n"
		<<setw(_peopleNameLength+1)<<"����"
		<<setw(_passwordLength+1)<<"����"<<endl;
	T::showCurrent();
	cout<<"\n---------------\n"
		<<"1. �޸�����\n"
		<<"2. �޸�����\n"
		<<"3. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
	if(!inputInt(state,3)) return -1;
	switch(state) {
	case 1: {
		char name[_peopleNameLength];
		cout<<"---------------\n"
			<<"�������µ�����:";
		if(!inputString(name,_peopleNameLength)) return -1;
		if(T::isExists(&teacher(name),0)) {
			cout<<"�û����Ѵ���!"<<endl;
			_sleep(_delay);
			return 3;
		}
		setTeacher(name);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	case 2: {
		char password[_passwordLength];
		cout<<"---------------\n"
			<<"�������µ�����:";
		if(!inputString(password,_passwordLength)) return -1;
		setTeacher("NULL",password);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	default: {
		T::clearCurrent();
		return -1;
			 }
	}

	cout<<"---------------\n"
		<<"1. �����޸Ľ�ʦ��Ϣ\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"ɾ����ʦ\n"
		<<"---------------\n";
	if(!T::isCurrent()){
		while(1) {
			state = FindTeacher(0);			
			if(state == -1) return -1;//�����Һ���������һ��,�򷵻���һ��
			else if(state == 0) break;//�ҵ�һ����ʦ,�˳�ѭ��
			system("cls");
			cout<<"---------------\n"
				<<"ɾ����ʦ\n"
				<<"---------------\n";
		}
	}
	cout.setf(ios_base::left);
	cout<<"��ɾ������Ŀ:\n"
		<<setw(_peopleNameLength+1)<<"����"
		<<setw(_passwordLength+1)<<"����"<<endl;
	T::showCurrent();
	cout<<"\n---------------\n"
		<<"�ý�ʦִ�̵Ŀγ�,����ɼ���Ϣ��һ��ɾ��\nȷ��ɾ����ʦ?(Y/n):";
	if(inputBool()){
		char name[_peopleNameLength];
		T::getName(name);
		G::deleteCourses(name);//ɾ����ʦ��Ӧ�Ŀγ̼��ɼ���Ϣ
		if(T::deleteTeacher())
			cout<<"ɾ���ɹ�!\n";
		else 
			cout<<"ɾ��ʧ��!\n";
	}
	cout<<"---------------\n"
		<<"1. ����ɾ����ʦ\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"ѧ����Ϣ\n"
		<<"---------------\n"
		<<"1. �鿴ѧ����Ϣ\n"
		<<"2. ���ѧ��\n"
		<<"3. �޸�ѧ����Ϣ\n"
		<<"4. ɾ��ѧ��\n"
		<<"5. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"ѧ����Ϣ\n"
		<<"---------------\n";
	S::showAll();
	cout<<"---------------\n"
		<<"1. ����ѧ��\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
			<<"����ѧ��\n"
			<<"---------------\n";
	}
	cout<<"��������ҵ�����:";
	if(!inputString(name,_peopleNameLength)) return -1;
	cout<<"---------------\n";
	num = S::find(&student(name));
	if(num == 1 && !flag) {
		cout<<"---------------\n";
		return 0;//flagΪ0ʱ,�ҵ�һ�����˳�
	}
	while(1){
		if(num == 1) {
			cout<<"---------------\n"
				<<"1. �޸�ѧ����Ϣ\n"
				<<"2. ɾ��ѧ��\n"
				<<"3. ������һ��\n"
				<<"---------------\n"
				<<"���������:";
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
				<<"1. ѡ������ѧ�������\n"
				<<"2. ���²���\n"
				<<"3. ������һ��\n"
				<<"---------------\n"
				<<"���������:";
			if(!inputInt(state,3)) return -1;
			switch(state) {
			case 1: {
				cout<<"��ѡ�����:";
				if(!inputInt(state,num)) return -1;
				num=S::find(&student(name),state);//Ψһ�޷���ֵ��·��
				if(!flag && num == 1) {
					cout<<"---------------\n";
					return 0;//flagΪ0ʱ,�ҵ�һ�����˳�
				}
				break;
					}
			case 2: return 1;
			default: return -1;
			}
		}
		else {
			cout<<"---------------\n"
				<<"1. ���²���\n"
				<<"2. ������һ��\n"
				<<"---------------\n"
				<<"���������:";
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
		<<"���ѧ��\n"
		<<"---------------\n"
		<<"ѧ������:";
	if(!inputString(name,_peopleNameLength)) return -1;
	if(S::isExists(&student(name),0)) {
		cout<<"�û����Ѵ���!\n";
	}
	else {
		cout<<"����:";
		if(!inputString(password,_passwordLength)) return -1;
		cout<<"ȷ�����ѧ��?(Y/n):";
		if(inputBool()) {
			student *p;
			p = new student(name,password);
			if(S::addStudent(p))
				cout<<"��ӳɹ�!\n";
			else cout<<"���ʧ��:\n";
		}
	}
	cout<<"---------------\n"
		<<"1. �������ѧ��\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"�޸�ѧ����Ϣ\n"
		<<"---------------\n";
	if(!S::isCurrent()){
		while(1) {
			state = FindStudent(0);			
			if(state == -1) return -1;//�����Һ���������һ��,�򷵻���һ��
			else if(state == 0) break;//�ҵ�һ��ѧ��,�˳�ѭ��
			system("cls");
			cout<<"---------------\n"
				<<"�޸�ѧ����Ϣ\n"
				<<"---------------\n";
		}
	}

	cout.setf(ios_base::left);
	cout<<"���޸ĵ���Ŀ:\n"
		<<setw(_peopleNameLength+1)<<"����"
		<<setw(_passwordLength+1)<<"����"<<endl;
	S::showCurrent();
	cout<<"\n---------------\n"
		<<"1. �޸�����\n"
		<<"2. �޸�����\n"
		<<"3. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
	if(!inputInt(state,3)) return -1;
	switch(state) {
	case 1: {
		char name[_peopleNameLength];
		cout<<"---------------\n"
			<<"�������µ�����:";
		if(!inputString(name,_peopleNameLength)) return -1;
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
		if(!inputString(password,_passwordLength)) return -1;
		setStudent("NULL",password);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	default: {
		S::clearCurrent();
		return -1;
			 }
	}

	cout<<"---------------\n"
		<<"1. �����޸�ѧ����Ϣ\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"ɾ��ѧ��\n"
		<<"---------------\n";
	if(!S::isCurrent()){
		while(1) {
			state = FindStudent(0);			
			if(state == -1) return -1;//�����Һ���������һ��,�򷵻���һ��
			else if(state == 0) break;//�ҵ�һ��ѧ��,�˳�ѭ��
			system("cls");
			cout<<"---------------\n"
				<<"ɾ��ѧ��\n"
				<<"---------------\n";
		}
	}
	cout.setf(ios_base::left);
	cout<<"��ɾ������Ŀ:\n"
		<<setw(_peopleNameLength+1)<<"����"
		<<setw(_passwordLength+1)<<"����"<<endl;
	S::showCurrent();
	cout<<"\n---------------\n"
		<<"��ѧ����Ӧ�ĳɼ���Ϣ��һ��ɾ��\nȷ��ɾ��ѧ��?(Y/n):";
	if(inputBool()){
		G::deleteCol(S::getRank());//ɾ���ɼ���Ϣ
		if(S::deleteStudent())//ɾ��ѧ����Ϣ
			cout<<"ɾ���ɹ�!\n";
		else 
			cout<<"ɾ��ʧ��!\n";
	}
	cout<<"---------------\n"
		<<"1. ����ɾ��ѧ��\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"�γ���Ϣ\n"
		<<"---------------\n"
		<<"1. �鿴�γ���Ϣ\n"
		<<"2. ��ӿγ�\n"
		<<"3. �޸Ŀγ���Ϣ\n"
		<<"4. ɾ���γ�\n"
		<<"5. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"�γ���Ϣ\n"
		<<"---------------\n";
	C::showAll();
	cout<<"---------------\n"
		<<"1. ���ҿγ�\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
			<<"���ҿγ�\n"
			<<"---------------\n";
	}

	if(isEmpty) {
		cout<<"��Ӳ�����Ϣ:\n"
			<<"1. �γ���\n"
			<<"2. ��ʦ\n"
			<<"3. ѧ��\n"
			<<"4. ������һ��\n"
			<<"---------------\n"
			<<"���������:";
		if(!inputInt(state,4)) return 1;
	}
	else {
		cout<<"Ŀǰ�Ĳ�����Ϣ:\n";
		courseBuff.print();
		cout<<"---------------\n"
			<<"��Ӳ�����Ϣ:\n"
			<<"1. �γ���\n"
			<<"2. ��ʦ\n"
			<<"3. ѧ��\n"
			<<"4. ��ղ�����Ϣ\n"
			<<"5. ������һ��\n"
			<<"---------------\n"
			<<"���������:";
		if(!inputInt(state,5)) return 1;
	}

	if(isEmpty && state == 4 || !isEmpty && state == 5 || state == 0) {//������һ��
		courseBuff.clear();
		return -1;
	}

	if(state==1) {
		cout<<"---------------\n"
			<<"���ҵĿγ���:";
		if(inputString(name,_courseNameLength))
			courseBuff.set(name);
		else return 1;
	}
	else if(state==2) {
		cout<<"---------------\n"
			<<"���ҵĽ�ʦ:";
		if(inputString(teacher,_peopleNameLength))
			courseBuff.set("NULL",teacher);
		else return 1;
	}
	else if(state==3) {
		cout<<"---------------\n��������ҵ�ѧ��:";
		if(inputGrade(credit,_maxCredit))
			courseBuff.set("NULL","NULL",credit);
		else return 1;
	}
	else {
		courseBuff.clear();
		return 1;
	}

	num=C::find(&courseBuff,1);//���ҿγ�,�����ҵ��ĸ���

	if(num == 1 && !flag) {
		cout<<"---------------\n";
		return 0;//flagΪ0ʱ,�ҵ�һ�����˳�
	}

	while(1){
		if(num == 1) {
			cout<<"---------------\n"
				<<"1. �޸Ŀγ���Ϣ\n"
				<<"2. ɾ���γ�\n"
				<<"3. ������һ��\n"
				<<"---------------\n"
				<<"���������:";
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
				<<"1. ѡ�������γ̵����\n"
				<<"2. ��ӻ��޸Ĳ�����Ϣ\n"
				<<"3. ������һ��\n"
				<<"---------------\n"
				<<"���������:";
			if(!inputInt(state,3)) {
				courseBuff.clear();
				return -1;
			}
			switch(state) {
			case 1: {
				cout<<"---------------\n"
					<<"��ѡ�����:";
				if(!inputInt(state,num)) return -1;
				num=C::find(&courseBuff,flag,state);//Ψһ�޷���ֵ��·��
				if(!flag && num == 1) {
					cout<<"---------------\n";
					return 0;//flagΪ0ʱ,�ҵ�һ�����˳�
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
				<<"1. ��ӻ��޸Ĳ�����Ϣ\n"
				<<"2. ������һ��\n"
				<<"---------------\n"
				<<"���������:";
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
		<<"��ӿγ�\n"
		<<"---------------\n"
		<<"�γ���:";
	if(!inputString(name,_courseNameLength)) return -1;
	cout<<"��ʦ:";
	if(!inputString(teacher,_peopleNameLength)) return -1;
	if(C::isExists(&course(name,teacher))) {
		cout<<"�ÿγ��Ѵ���!\n";
	}
	else if(!T::isExists(&class teacher(teacher),0)) {
		cout<<"�ý�ʦ������,������ӽ�ʦ!\n";
	}
	else {
		cout<<"ѧ��:";
		if(!inputGrade(credit,_maxCredit)) return -1;
		if(credit < 0) credit = 0;
		cout<<"ȷ����ӿγ�?(Y/n):";
		if(inputBool()) {
			course *p;
			p = new course(name,teacher,credit);
			if(C::addCourse(p))
				cout<<"��ӳɹ�!\n";
			else cout<<"���ʧ��:\n";
		}
	}
	cout<<"---------------\n"
		<<"1. ������ӿγ�\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"�޸Ŀγ���Ϣ\n"
		<<"---------------\n";
	if(!C::isCurrent()){
		while(1) {
			state = FindCourse(0);			
			if(state == -1) return -1;//�����Һ���������һ��,�򷵻���һ��
			else if(state == 0) break;//�ҵ�һ�ſγ�,�˳�ѭ��
			system("cls");
			cout<<"---------------\n"
				<<"�޸Ŀγ���Ϣ\n"
				<<"---------------\n";
		}
	}

	cout.setf(ios_base::left);
	cout<<"���޸ĵ���Ŀ:\n";
	C::showCurrent();
	cout<<"\n---------------\n"
		<<"1. �޸Ŀγ���\n"
		<<"2. �޸Ľ�ʦ\n"
		<<"3. �޸�ѧ��\n"
		<<"4. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
	if(!inputInt(state,4)) return -1;
	switch(state) {
	case 1: {
		cout<<"---------------\n"
			<<"�������µĿγ���:";
		if(!inputString(name,_courseNameLength)) return -1;
		C::getTeacher(teacher);
		if(C::isExists(&course(name,teacher))) {
			cout<<"�ÿγ��Ѵ���!"<<endl;
			_sleep(_delay);
			return 3;
		}
		setCourse(name);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	case 2: {
		cout<<"---------------\n"
			<<"�������µĽ�ʦ��:";
		if(!inputString(teacher,_peopleNameLength)) return -1;
		if(!T::isExists(&class teacher(teacher),0)) {
			cout<<"�ý�ʦ������!������ӽ�ʦ\n";
		}
		C::getName(name);
		if(C::isExists(&course(name,teacher))) {
			cout<<"�ÿγ��Ѵ���!"<<endl;
			_sleep(_delay);
			return 3;
		}
		setCourse("NULL",teacher);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	case 3: {
		cout<<"---------------\n"
			<<"�������µ�ѧ��:";
		if(!inputGrade(credit,_maxCredit)) return -1;
		if(credit < 0) credit = 0;
		setCourse("NULL","NULL",credit);
		cout<<"�޸��ѳɹ�!\n";
		break;
			}
	default: {
		C::clearCurrent();
		return -1;
			 }
	}
	cout<<"---------------\n"
		<<"1. �����޸Ŀγ���Ϣ\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"ɾ���γ�\n"
		<<"---------------\n";
	if(!C::isCurrent()){
		while(1) {
			state = FindCourse(0);			
			if(state == -1) return -1;//�����Һ���������һ��,�򷵻���һ��
			else if(state == 0) break;//�ҵ�һ���γ�,�˳�ѭ��
			system("cls");
			cout<<"---------------\n"
				<<"ɾ���γ�\n"
				<<"---------------\n";
		}
	}
	cout.setf(ios_base::left);
	cout<<"��ɾ������Ŀ:\n";
	C::showCurrent();
	cout<<"\n---------------\n"
		<<"�ÿγ̶�Ӧ�ĳɼ���Ϣ��һ��ɾ��\nȷ��ɾ���γ�?(Y/n):";
	if(inputBool()){
		G::deleteRow(C::getRank());//ɾ���ɼ���Ϣ
		if(C::deleteCourse())//ɾ���γ���Ϣ
			cout<<"ɾ���ɹ�!\n";
		else 
			cout<<"ɾ��ʧ��!\n";
	}
	cout<<"---------------\n"
		<<"1. ����ɾ���γ�\n"
		<<"2. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<setw(_peopleNameLength+1)<<"����"
		<<setw(_passwordLength+1)<<"����"<<endl;
	A::showCurrent();
	cout<<"\n---------------\n"
		<<"1. �޸�����\n"
		<<"2. �޸�����\n"
		<<"3. ������һ��\n"
		<<"---------------\n"
		<<"���������:";
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
		<<"���������:";
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
		<<"���������:";
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
	showColList(1);
}