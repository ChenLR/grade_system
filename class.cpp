#include <fstream>
#include <cstring>
#include <iomanip>
#include "class.h"
using namespace std;

people::people(char* name,char* password) {
	strcpy(this->name,name);
	strcpy(this->password,password);
}
people::people(people & people) {
	strcpy(this->name,people.name);
	strcpy(this->password,people.password);
}
void people::set(char* name,char* password) {
	if(name != "NULL") strcpy(this->name,name);
	if(password != "NULL") strcpy(this->password,password);
}
char* people::getPassword() {
	return password;
}
char* people::getName() {
	return name;
}

admin::admin(char* name,char* password) {
	strcpy(this->name,name);
	strcpy(this->password,password);
	next=NULL;
}
admin::admin(admin & admin):people(admin),next(admin.next) {};

adminList::adminList() {
	head=tail=current=NULL;
}
adminList::adminList(adminList & L):head(L.head),tail(L.tail),current(L.current) {};
adminList::~adminList() {
	admin *p,*q;
	p=head;
	while(p) {
		q=p->next;
		delete p;
		p=q;
	}
}
bool adminList::isExists(admin *aim, int flag) {
	admin *p;
	p=head;
	while(p) {
		if(!strcmp(p->name,aim->name)) {
			if(flag) current=p;
			p=NULL;
			return 1;
		}
		p=p->next;
	}
	p=NULL;
	return 0;
}
bool adminList::isCorrect(admin *aim) {
	if(isExists(aim))
		return !strcmp(aim->password,current->password);
	return 0;
}
void adminList::Import() {
	ifstream inf("Data\\adminInfo_in.txt");
	char name[_peopleNameLength],password[_passwordLength];
	admin *p;
	int Count=0;
	while(1) {
		inf>>name>>password;
		if(inf.fail()) break;
		p=new admin(name,password);
		if(addAdmin(p)) Count++;
	}
	inf.close();
	p=NULL;
	length=Count;
}
void adminList::Export() {
	ofstream outf("Data\\adminInfo_out.txt");
	admin *p;
	int Count=0;
	p=head;
	while(p) {
		outf<<*p<<endl;
		p=p->next;
		Count++;
	}
	outf.close();
	length=Count;
}
void adminList::setAdmin(char *name, char *password) {
	if(current) current->set(name,password);
}
bool adminList::addAdmin(admin *add) {
	admin *p;
	if(isExists(add)) return 0;
	p=new admin(*add);
	if(tail) {
		tail->next=p;
		tail=p;
		tail->next=NULL;
	}
	else {
		head=tail=p;
		p->next=NULL;
	}
	p=NULL;
	return 1;
}
bool adminList::deleteAdmin() {
	admin *p;
	if(head==NULL || current==NULL) return 0;
	if(head==current) {
		head=current->next;
		delete current;
		current=NULL;
		return 1;
	}
	else {
		p=head;
		while(p->next!=current) p=p->next;
		p->next=current->next;
		delete current;
		current=NULL;
		return 1;
	}
}
void adminList::showAll() {
	admin *p;
	cout<<"---------------\n";
	cout.setf(ios_base::left);
	cout<<setw(_peopleNameLength+1)<<"用户名"<<setw(_passwordLength+1)<<"密码"<<endl;
	p=head;
	while(p) {
		cout<<*p<<endl;
		p=p->next;
	}
	p=NULL;
}
void adminList::printTitle(int rank) {
	if(rank) {
		admin *p;
		p=head;
		for(int k=1;k<rank;p=p->next,k++);
		cout.setf(ios_base::left);
		cout<<setw(_peopleNameLength+1)<<p->name;
	}
	else if(current) {
		cout.setf(ios_base::left);
		cout<<setw(_peopleNameLength+1)<<current->name;
	}
}
void adminList::showCurrent() {
	if(current) cout<<*current;
}
void adminList::clearCurrent() {
	current=NULL;
}
bool adminList::isCurrent() {
	if(current) return 1;
	else return 0;
}

teacher::teacher(char* name,char* password) {
	strcpy(this->name,name);
	strcpy(this->password,password);
	next=NULL;
}
teacher::teacher(teacher & teacher):people(teacher),next(teacher.next) {};

teacherList::teacherList() {
	head=tail=current=NULL;
}
teacherList::teacherList(teacherList & L):head(L.head),tail(L.tail),current(L.current) {};
teacherList::~teacherList() {
	teacher *p,*q;
	p=head;
	while(p) {
		q=p->next;
		delete p;
		p=q;
	}
}
bool teacherList::isExists(teacher *aim, int flag) {
	teacher *p;
	p=head;
	while(p) {
		if(!strcmp(p->name,aim->name)) {
			if(flag) current=p;
			p=NULL;
			return 1;
		}
		p=p->next;
	}
	p=NULL;
	return 0;
}
bool teacherList::isCorrect(teacher *aim) {
	if(isExists(aim))
		return !strcmp(aim->password,current->password);
	return 0;
}
void teacherList::Import() {
	ifstream inf("Data\\teacherInfo_in.txt");
	char name[_peopleNameLength],password[_passwordLength];
	teacher *p;
	int Count=0;
	while(1) {
		inf>>name>>password;
		if(inf.fail()) break;
		p=new teacher(name,password);
		if(addTeacher(p)) Count++;
	}
	inf.close();
	p=NULL;
	length=Count;
}
void teacherList::Export() {
	ofstream outf("Data\\teacherInfo_out.txt");
	teacher *p;
	int Count=0;
	p=head;
	while(p) {
		outf<<*p<<endl;
		p=p->next;
		Count++;
	}
	outf.close();
	length=Count;
}
void teacherList::setTeacher(char *name, char *password) {
	if(current) current->set(name,password);
}
bool teacherList::addTeacher(teacher *add) {
	teacher *p;
	if(isExists(add)) return 0;
	p=new teacher(*add);
	if(tail) {
		tail->next=p;
		tail=p;
		tail->next=NULL;
	}
	else {
		head=tail=p;
		p->next=NULL;
	}
	p=NULL;
	return 1;
}
bool teacherList::deleteTeacher() {
	teacher *p;
	if(head==NULL || current==NULL) return 0;
	if(head==current) {
		head=current->next;
		delete current;
		current=NULL;
		return 1;
	}
	else {
		p=head;
		while(p->next!=current) p=p->next;
		p->next=current->next;
		delete current;
		current=NULL;
		return 1;
	}
}
void teacherList::showAll() {
	teacher *p;
	cout<<"---------------\n";
	cout.setf(ios_base::left);
	cout<<setw(_peopleNameLength+1)<<"用户名"<<setw(_passwordLength+1)<<"密码"<<endl;
	p=head;
	while(p) {
		cout<<*p<<endl;
		p=p->next;
	}
	p=NULL;
}
void teacherList::printTitle(int rank) {
	if(rank) {
		teacher *p;
		p=head;
		for(int k=1;k<rank;p=p->next,k++);
		cout.setf(ios_base::left);
		cout<<setw(_peopleNameLength+1)<<p->name;
	}
	else if(current) {
		cout.setf(ios_base::left);
		cout<<setw(_peopleNameLength+1)<<current->name;
	}
}
void teacherList::getName(char *buff) {
	strcpy(buff,current->name);
}

void teacherList::showCurrent() {
	if(current) cout<<*current;
}
void teacherList::clearCurrent() {
	current=NULL;
}
bool teacherList::isCurrent() {
	if(current) return 1;
	else return 0;
}

student::student(char* name,char* password) {
	strcpy(this->name,name);
	strcpy(this->password,password);
	next=NULL;
	GPA=-1;//-1代表暂无成绩
	totalCredit=0;
}
student::student(student & student):people(student),next(student.next),GPA(student.GPA),totalCredit(student.totalCredit) {};

studentList::studentList() {
	head=tail=current=NULL;
}
studentList::studentList(studentList & L):head(L.head),tail(L.tail),current(L.current) {};
studentList::~studentList() {
	student *p,*q;
	p=head;
	while(p) {
		q=p->next;
		delete p;
		p=q;
	}
}
void studentList::Import() {
	ifstream inf("Data\\studentInfo_in.txt");
	char name[_peopleNameLength],password[_passwordLength];
	student *p;
	int Count=0;
	while(1) {
		inf>>name>>password;
		if(inf.fail()) break;
		p=new student(name,password);
		if(addStudent(p)) Count++;
	}
	inf.close();
	p=NULL;
	length=Count;
}
void studentList::Export() {
	ofstream outf("Data\\studentInfo_out.txt");
	student *p;
	int Count=0;
	p=head;
	while(p) {
		outf<<*p<<endl;
		p=p->next;
		Count++;
	}
	outf.close();
	length=Count;
}
bool studentList::isExists(student *aim, int flag) {
	student *p;
	p=head;
	while(p) {
		if(!strcmp(p->name,aim->name)) {
			if(flag) current=p;
			p=NULL;
			return 1;
		}
		p=p->next;
	}
	p=NULL;
	return 0;
}
bool studentList::isCorrect(student *aim) {//用户名和密码是否正确
	if(isExists(aim))
		return !strcmp(aim->password,current->password);
	return 0;
}
int studentList::find(student *aim,int rank) {//返回找到的个数,如果找到一个,current不为空;rank不为零则输出第几条
	student *p;
	int count=0;//count记录找到的个数
	p=head;
	while(p) {
		if(!strcmp(p->name,aim->name)) {
			if(!count && !rank) cout<<"读者姓名:"<<endl;
			count++;
			current=p;
			if(!rank) cout<<setw(2)<<count<<". "<<*p<<endl;
			if(count==rank) {
				cout<<"---------------\n"<<setw(2)<<1<<". "<<*p<<endl;
				return 1;
			}
		}
		p=p->next;
	}
	if(count==1) return count;
	else if(count>1) {
		current=NULL;
		return count;
	}
	else {//若精确搜索无法找到则模糊搜索
		p=head;
		while(p) {
			if(strstr(p->name,aim->name)) {
				if(!count && !rank) cout<<"可能的读者姓名:"<<endl;
				count++;
				current=p;
				if(!rank) cout<<setw(2)<<count<<". "<<*p<<endl;
				if(count==rank) {
					cout<<"---------------\n"<<setw(2)<<1<<". "<<*p<<endl;
					return 1;
				}
			}
			p=p->next;
		}
		if(count==1) return count;
		else if(count>1) {
			current=NULL;
			return count;
		}
		else {
			cout<<"未找到符合条件的条目"<<endl;
			current=NULL;
			return 0;
		}
	}
}
int studentList::getRank() {
	student *p;
	if(current==NULL) return 0;
	int k=1;
	p=head;
	while(p!=current) {
		p=p->next;
		k++;
		if(p==NULL) break;
	}
	p=NULL;
	return k;
}
int studentList::getLength() {
	return length;
}
void studentList::setStudent(char *name, char *password) {
	if(current) current->set(name,password);
}
bool studentList::addStudent(student *add) {
	student *p;
	if(isExists(add)) return 0;
	p=new student(*add);
	if(tail) {
		tail->next=p;
		tail=p;
		tail->next=NULL;
	}
	else {
		head=tail=p;
		p->next=NULL;
	}
	p=NULL;
	return 1;
}
bool studentList::deleteStudent() {
	student *p;
	if(head==NULL || current==NULL) return 0;
	if(head==current) {
		head=current->next;
		delete current;
		current=NULL;
		return 1;
	}
	else {
		p=head;
		while(p->next!=current) p=p->next;
		p->next=current->next;
		delete current;
		current=NULL;
		return 1;
	}
}
void studentList::showAll() {
	student *p;
	cout<<"---------------\n";
	cout.setf(ios_base::left);
	cout<<setw(_peopleNameLength+1)<<"用户名"<<setw(_passwordLength+1)<<"密码"<<endl;
	p=head;
	while(p) {
		cout<<*p<<endl;
		p=p->next;
	}
	p=NULL;
}
void studentList::showAllt() {
	student *p;
	cout<<"---------------\n";
	cout.setf(ios_base::left);
	cout<<setw(_peopleNameLength+1)<<"用户名"<<setw(_passwordLength+1)<<"密码"<<endl;
	p=head;
	while(p) {
		cout<<*p<<setw(5)<<p->totalCredit<<p->GPA<<endl;
		p=p->next;
	}
	p=NULL;
}
void studentList::printTitle(int rank) {
	if(rank) {
		student *p;
		p=head;
		for(int k=1;k<rank;p=p->next,k++);
		cout.setf(ios_base::left);
		cout<<setw(_peopleNameLength+1)<<p->name;
	}
	else if(current) {
		cout.setf(ios_base::left);
		cout<<setw(_peopleNameLength+1)<<current->name;
	}
}
void studentList::showCurrent() {
	if(current) cout<<*current;
}
void studentList::showSTU(int rank) {
	if(rank) {
		student *p;
		p=head;
		for(int k=1;k<rank;k++,p=p->next);
		cout<<setw(7)<<p->totalCredit
			<<setw(7)<<setprecision(4)<<p->GPA;
	}
	else if(current) {
		cout<<setw(7)<<current->totalCredit
			<<setw(7)<<setprecision(4)<<current->GPA;
	}
}
void studentList::setSTU(int totalCredit, double GPA, int rank) {
	if(rank) {
		student *p;
		p=head;
		for(int k=1;k<rank;k++,p=p->next);
		p->GPA=GPA;
		p->totalCredit=totalCredit;
	}
	else if(current) {
		current->GPA=GPA;
		current->totalCredit=totalCredit;
	}
}
int studentList::rankInAll(int n) {
	int rank=1;
	student *p;
	if(n) {
		student *q;
		q=head;
		for(int k=1;k<n;k++,q=q->next);
		for(p=head;p;p=p->next) {
			if(p->GPA > q->GPA)
				rank++;
		}
	}
	else {
		for(p=head;p;p=p->next) {
			if(p->GPA > current->GPA)
				rank++;
		}
	}
	return rank;	
}
void studentList::clearCurrent() {
	current=NULL;
}
bool studentList::isCurrent() {
	if(current) return 1;
	else return 0;
}

course::course(char *name, char *teacher, int credit):credit(credit) {
	strcpy(this->name,name);
	strcpy(this->teacher,teacher);
	studentNum=0;
	next=NULL;
}
course::course(course &C):credit(C.credit),studentNum(C.studentNum) {
	strcpy(this->name,C.name);
	strcpy(this->teacher,C.teacher);
	next=C.next;
}
void course::set(char *name, char *teacher, int credit) {//0为不可能的值,用于判断是否赋值
	if(name!="NULL") strcpy(this->name,name);
	if(teacher!="NULL") strcpy(this->teacher,teacher);
	if(credit>0) this->credit=credit;
}
void course::clear() {
	strcpy(name,"NULL");
	strcpy(teacher,"NULL");
	credit=0;
}
void course::print() {//只打印非初值的量
	cout.setf(ios_base::left);
	if(strcmp(name,"NULL")) cout<<setw(8)<<"课程:"<<name<<endl;
	if(strcmp(teacher,"NULL")) cout<<setw(8)<<"教师:"<<teacher<<endl;
}
bool course::isEmpty() {
	return !strcmp(name,"NULL") && !strcmp(teacher,"NULL");
}

courseList::courseList() {
	head=tail=current=NULL;
}
courseList::courseList(courseList & L):head(L.head),tail(L.tail),current(L.current) {};
courseList::~courseList() {
	course *p,*q;
	p=head;
	while(p) {
		q=p->next;
		delete p;
		p=q;
	}
}
bool courseList::isExists(course *aim) {//不改变current指针
	course *p;
	p=head;
	if(!strcmp(aim->name,"NULL")) {
		while(p) {
			if(!strcmp(p->name,current->name) && !strcmp(p->teacher,aim->teacher)) {
				p=NULL;
				return 1;
			}
			p=p->next;
		}
		p=NULL;
		return 0;
	}
	if(!strcmp("NULL",aim->teacher)) {
		while(p) {
			if(!strcmp(p->name,aim->name) && !strcmp(p->teacher,current->teacher)) {
				p=NULL;
				return 1;
			}
			p=p->next;
		}
		p=NULL;
		return 0;
	}
	while(p) {
		if(!strcmp(p->name,aim->name) && !strcmp(p->teacher,aim->teacher)) {
			p=NULL;
			return 1;
		}
		p=p->next;
	}
	p=NULL;
	return 0;
}
int courseList::find(course *aim, bool print, int rank) {//返回找到的个数,如果找到一个,current不为空;rank不为零则输出第几条
	course *p;
	int count=0;//count记录找到的个数
	p=head;
	cout.setf(ios_base::left);
	while(p) {
		if((!strcmp(p->name,aim->name) || !strcmp(aim->name,"NULL")) &&
			(!strcmp(p->teacher,aim->teacher) || !strcmp(aim->teacher,"NULL"))) 
		{
			if(!count && !rank && print) cout<<"---------------\n课程信息:\n"
				<<"---------------\n    "<<setw(_courseNameLength+1)
				<<"课程名"<<setw(_peopleNameLength+1)<<"教师"<<"学分"<<endl;
			count++;
			current=p;
			if(!rank && print) cout<<setw(2)<<count<<". "<<*p<<endl;
			if(count==rank) {
				if(print) cout<<"---------------\n"<<setw(2)<<1<<". "<<*p<<endl;
				return 1;
			}
		}
		p=p->next;
	}
	if(count==1) return count;
	else if(count>1) {
		current=NULL;
		return count;
	}
	else {//若精确搜索无法找到则模糊搜索
		p=head;
		while(p) {
			if((strstr(p->name,aim->name) || !strcmp(aim->name,"NULL")) &&
			(strstr(p->teacher,aim->teacher) || !strcmp(aim->teacher,"NULL")))
			{
				if(!count && !rank && print) cout<<"---------------\n可能的课程信息:\n"
					<<"---------------\n    "<<setw(_courseNameLength+1)
				<<"课程名"<<setw(_peopleNameLength+1)<<"教师"<<"学分"<<endl;
				count++;
				current=p;
				if(!rank && print) cout<<setw(2)<<count<<". "<<*p<<endl;
				if(count==rank && print) {
					cout<<"---------------\n"<<setw(2)<<1<<". "<<*p<<endl;
					return 1;
				}
			}
			p=p->next;
		}
		if(count==1) return count;
		else if(count>1) {
			current=NULL;
			return count;
		}
		else {
			if(print)
				cout<<"未找到符合条件的条目"<<endl;
			current=NULL;
			return 0;
		}
	}
}
int courseList::getRank() {
	course *p;
	if(current==NULL) return 0;
	int k=1;
	p=head;
	while(p!=current) {
		p=p->next;
		k++;
		if(p==NULL) break;
	}
	p=NULL;
	return k;
}
int courseList::getLength() {
	return length;
}
int courseList::getCredit(int rank) {
	if(rank) {
		course *p;
		p=head;
		for(int k=1;k<rank;p=p->next,k++);
		return p->credit;
	}
	else
		return current->credit;
}
void courseList::setStudentNum(int n) {
	if(current) current->studentNum = n;
}
void courseList::printStudentNum() {
	if(current) cout<<current->studentNum;
}
void courseList::Import() {
	ifstream inf("Data\\courseInfo_in.txt");
	char name[_courseNameLength], teacher[_peopleNameLength];
	course *p;
	int credit;
	int Count=0;
	while(1) {
		inf>>name>>teacher>>credit;
		if(inf.fail()) break;
		p=new course(name, teacher, credit);
		if(addCourse(p)) Count++;
	}
	inf.close();
	p=NULL;
	length=Count;
}
void courseList::Export() {
	ofstream outf("Data\\courseInfo_out.txt");
	course *p;
	int Count=0;
	p=head;
	while(p) {
		outf<<*p<<endl;
		p=p->next;
		Count++;
	}
	outf.close();
	length=Count;
}
bool courseList::addCourse(course *add) {
	if(isExists(add)) return 0;
	course *p;
	p=new course(*add);
	if(tail) {
		tail->next=p;
		tail=p;
		tail->next=NULL;
	}
	else {
		head=tail=p;
		p->next=NULL;
	}
	p=NULL;
	return 1;
}
bool courseList::deleteCourse() {
	course *p;
	if(head==NULL || current==NULL) return 0;
	if(head==current) {
		head=current->next;
		delete current;
		current=NULL;
		return 1;
	}
	else {
		p=head;
		while(p->next!=current) p=p->next;
		p->next=current->next;
		delete current;
		current=NULL;
		return 1;
	}
}
void courseList::showAll() {
	course *p;
	cout.setf(ios_base::left);
	cout<<"---------------\n"<<setw(_courseNameLength+1)
				<<"课程名"<<setw(_peopleNameLength+1)<<"教师"<<"学分"<<endl;
	p=head;
	while(p) {
		cout<<*p<<endl;
		p=p->next;
	}
	p=NULL;
}
void courseList::printTitle(int rank) {
	if(rank) {
		course *p;
		p=head;
		for(int k=1;k<rank;p=p->next,k++);
		cout.setf(ios_base::left);
		cout<<setw(_courseNameLength+1)<<p->name<<setw(_peopleNameLength+1)<<p->teacher<<setw(5)<<p->credit;
	}
	else if(current) {
		cout.setf(ios_base::left);
		cout<<setw(_courseNameLength+1)<<current->name<<setw(_peopleNameLength+1)<<current->teacher<<setw(5)<<current->credit;
	}
}
void courseList::clearCurrent() {
	current=NULL;
}
bool courseList::isCurrent() {
	if(current) return 1;
	else return 0;
}

OLNode::OLNode(int row, int col, int grade):row(row),col(col),grade(grade) {
	rank=0;
	right=NULL;
	down=NULL;
}
OLNode::OLNode(OLNode &N):row(N.row),col(N.col),grade(N.grade),right(N.right),down(N.down) {};
void OLNode::print() {
	cout<<row<<col<<grade;
}

gradeList::gradeList(int r,int c):rowMax(r),colMax(c) {
	if(!(rowHead=new OLNode *[r]))
		exit(1);
	for(int k=0;k<r;k++)
		rowHead[k]=NULL;
	if(!(colHead=new OLNode *[c]))
		exit(1);
	for(int k=0;k<c;k++)
		colHead[k]=NULL;
}
gradeList::gradeList(gradeList &C):rowMax(C.rowMax),colMax(C.colMax),rowHead(C.rowHead),colHead(C.colHead) {};
gradeList::~gradeList() {
	OLNode *p;
	for(int k=0;k<rowMax;k++) {
		current=rowHead[k];
		while(current) {
			p=current->right;
			delete current;
			current=p;
		}
	}
	delete []colHead;
	delete []rowHead;
};
void gradeList::set(int r,int c) {
	rowMax=r,colMax=c;
	if(!(rowHead=new OLNode *[r]))
		exit(1);
	for(int k=0;k<r;k++)
		rowHead[k]=NULL;
	if(!(colHead=new OLNode *[c]))
		exit(1);
	for(int k=0;k<c;k++)
		colHead[k]=NULL;
}
void gradeList::Import() {
	ifstream inf("Data\\gradeInfo_in.txt");
	int m,n,grade;
	OLNode *p;
	while(1) {
		inf>>m>>n>>grade;
		if(inf.fail()) break;
		if(m<=rowMax && m>0 && 
			n<=colMax && n>0) {
				if(grade>=0 && grade<=100) p=new OLNode(m,n,grade);
				else p=new OLNode(m,n,-1);
				addNode(p);
		}
	}
	inf.close();
}
void gradeList::Export() {
	ofstream outf("Data\\gradeInfo_out.txt");
	int m;
	OLNode *p;
	for(m=0;m<rowMax;m++) {
		p=rowHead[m];
		while(p) {
			outf<<*p<<endl;
			p=p->right;
		}
	}	
	outf.close();
}
bool gradeList::findNode(int m, int n) {
	if(m>rowMax || m<=0 || n>colMax || n<=0) 
		return 0;
	OLNode *p;
	p=rowHead[m-1];
	while(p) {
		if(p->col==n) {
			current=p;
			return 1;
		}
		p=p->right;
	}
	return 0;
}//要改current
bool gradeList::showNode(int m, int n) {
	if(m>rowMax || m<=0 || n>colMax || n<=0) 
		return 0;
	OLNode *p;
	p=rowHead[m-1];
	while(p) {
		if(p->col==n) {
			cout<<p->grade;
			return 1;
		}
		p=p->right;
	}
	return 0;
}
bool gradeList::isExist(int m, int n) {
	if(m>rowMax || m<=0 || n>colMax || n<=0) 
		return 0;
	OLNode *p;
	p=rowHead[m-1];
	while(p) {
		if(p->col==n) {
			return 1;
		}
		p=p->right;
	}
	return 0;
}//不改current
bool gradeList::addNode(OLNode *Node) {
	if(isExist(Node->row,Node->col)) return 0;
	OLNode *p;
	//在行表中添加
	if(rowHead[Node->row-1]==NULL) {
		rowHead[Node->row-1]=Node;
		Node->right=NULL;
	}
	else if((p=rowHead[Node->row-1])->right==NULL) {
		if(Node->col < p->col) {
			rowHead[Node->row-1]=Node;
			Node->right=p;
		}
		else {
			Node->right=p->right;
			p->right=Node;
		}
	}
	else{
		for(p=rowHead[Node->row-1]; p->right && p->right->col < Node->col; p=p->right);//移动指针
		Node->right=p->right;
		p->right=Node;
	}
	//在列表中添加
	if(colHead[Node->col-1]==NULL) {
		colHead[Node->col-1]=Node;
		Node->down=NULL;
	}
	else if((p=colHead[Node->col-1])->down==NULL) {
		if(Node->row < p->row) {
			colHead[Node->col-1]=Node;
			Node->down=p;
		}
		else {
			Node->down=p->down;
			p->down=Node;
		}
	}
	else{
		for(p=colHead[Node->col-1]; p->down && p->down->row < Node->row; p=p->down);//移动指针
		Node->down=p->down;
		p->down=Node;
	}
	return 1;
}
bool gradeList::deleteNode() {
	if(!current) return 0;
	OLNode *p;
	//在行表中删除
	p=rowHead[current->row-1];
	if(p==current) rowHead[current->row-1]=current->right;
	else {
		for(p; p->right != current; p=p->right);//移动指针
		p->right=current->right;
	}
	//在列表中删除
	p=colHead[current->col-1];
	if(p==current) colHead[current->col-1]=current->down;
	else {
		for(p; p->down != current; p=p->down);//移动指针
		p->down=current->down;
	}
	delete current;
	current=NULL;
	return 1;
}
bool gradeList::addRow() {
	OLNode **p;
	if(!(p=new OLNode *[rowMax+1]())) return 0; //初始化时已将指针全部置0
	for(int k=0;k<rowMax;k++)
		p[k]=rowHead[k];
	rowMax++;
	delete []rowHead;
	rowHead=p;
	return 1;
}
bool gradeList::addCol() {
	OLNode **p;
	if(!(p=new OLNode *[colMax+1]())) return 0; //初始化时已将指针全部置0
	for(int k=0;k<colMax;k++)
		p[k]=colHead[k];
	colMax++;
	delete []colHead;
	colHead=p;
	return 1;
}
bool gradeList::deleteRow(int m) {
	if(m>rowMax || m<=0) return 0;
	OLNode *p;
	OLNode **q;
	current=rowHead[m-1];
	while(current) { //在列表中删除
		if((p=colHead[current->col-1])==current) {
			colHead[current->col-1]=current->down;
			current=current->right;
		}
		else {
			for(p=colHead[current->col-1]; p->down != current; p=p->down);
			p->down=current->down;
			current=current->right;
		}
	}
	current=rowHead[m-1];
	while(current) { //释放内存
		p=current->right;
		delete current;
		current=p;
	}
	if(!(q=new OLNode *[rowMax-1]())) return 0;
	for(int k=0;k<m-1;k++) q[k]=rowHead[k];
	for(int k=m-1;k<rowMax-1;k++) {
		q[k]=rowHead[k+1];
		p=q[k];
		while(p) {  //修改列角标
			p->row=k+1;
			p=p->right;
		}
	}
	rowMax--;
	delete []rowHead;
	rowHead=q;
	return 1;
}
bool gradeList::deleteCol(int n) {
	if(n>colMax || n<=0) return 0;
	OLNode *p;
	OLNode **q;
	current=colHead[n-1];
	while(current) { //在行表中删除
		if((p=rowHead[current->row-1])==current) {
			rowHead[current->row-1]=current->right;
			current=current->down;
		}
		else {
			for(p=rowHead[current->row-1]; p->right != current; p=p->right);
			p->right=current->right;
			current=current->down;
		}
	}
	current=colHead[n-1];
	while(current) { //释放内存
		p=current->down;
		delete current;
		current=p;
	}
	if(!(q=new OLNode *[colMax-1]())) return 0;
	for(int k=0;k<n-1;k++) q[k]=colHead[k];
	for(int k=n-1;k<colMax-1;k++) {
		q[k]=colHead[k+1];
		p=q[k];
		while(p) {  //修改列角标
			p->col=k+1;
			p=p->down;
		}
	}
	colMax--;
	delete []colHead;
	colHead=q;
	return 1;	
}
void gradeList::showAll() {
	cout.setf(ios_base::left);
	OLNode *p;
	int count=0;
	for(int k=0;k<rowMax;k++) {
		p=rowHead[k];
		count=1;
		if(!p) for(int k=0;k<colMax;k++) cout<<setw(3)<<"_";
		while(p) {
			for(int k=count;k < p->col;k++) cout<<setw(3)<<"_";
			cout<<setw(3)<<p->grade;
			count=p->col+1;
			if(!(p->right))
				for(int k=p->col;k<colMax;k++) cout<<setw(3)<<"_";
			p=p->right;
		}
		cout<<endl;
	}
	cout<<endl;
}
void gradeList::showAllt() {
	cout.setf(ios_base::left);
	OLNode *p;
	int count=0;
	for(int k=0;k<colMax;k++) {
		p=colHead[k];
		count=1;
		if(!p) for(int k=0;k<rowMax;k++) cout<<setw(3)<<"_";
		while(p) {
			for(int k=count;k < p->row;k++) cout<<setw(3)<<"_";
			cout<<setw(3)<<p->grade;
			count=p->row+1;
			if(!(p->down))
				for(int k=p->row;k<rowMax;k++) cout<<setw(3)<<"_";
			p=p->down;
		}
		cout<<endl;
	}
	cout<<endl;
}
void gradeList::showRow(int r) {
	int count = 0;
	if(r<=0 || r>rowMax) return;
	OLNode *p;
	p=rowHead[r-1];
	while(p) {
		studentList::printTitle(p->col);
		cout.setf(ios_base::left);
		if(p->grade>=0) {
			cout<<setw(5)<<p->grade
				<<setw(5)<<p->rank<<endl;
		}
		else {
			cout<<"*"<<endl;
		}
		count++;
		p=p->right;
	}
	setStudentNum(count);
}
void gradeList::showCol(int c) {
	if(c<=0 || c>colMax) return;
	OLNode *p;
	p=colHead[c-1];
	while(p) {
		courseList::printTitle(p->row);
		cout.setf(ios_base::left);
		if(p->grade>=0) {
			cout<<setw(5)<<p->grade
				<<setw(5)<<p->rank<<endl;
		}
		else {
			cout<<"*"<<endl;
		}
		p=p->down;
	}
}
void gradeList::refreshRank() {
	OLNode *p,*q;
	int length;
	int temp, count, k;
	//遍历各行头指针
	for(k=0, p=rowHead[k]; k<rowMax; k++, p=rowHead[k]) {
		if(p) {
			q=p;
			length=0;
			//第一次遍历该行,统计元素个数
			while(q) {
				length++;
				q=q->right;
			}
			q=p;
			OLNode **P;
			if(!(P=new OLNode *[length])) return;
			//第二次遍历该行,初始化指针数组
			for(int k=0; k<length; k++) {
				P[k]=q;
				q=q->right;
			}
			//按成绩降序排序
			quickSort(P,length);
			//记录名次,成绩相同者名次相同
			temp=P[0]->grade;
			count=0;
			for(int k=0; k < length; k++) {
				if(P[k]->grade < temp) {
					count=k;
					temp=P[k]->grade;
				}
				P[k]->rank=count+1;
			}
		}
	}
}
void gradeList::refreshStudent() {
	OLNode *p;
	int creditSum, gradeSum;
	int rank;
	for(rank=0;rank<colMax;rank++) {
		creditSum=0;
		gradeSum=0;
		p=colHead[rank];
		while(p) {
			if(p->grade >= 0) {
				creditSum+=getCredit(p->row);
				gradeSum+=p->grade*getCredit(p->row);
			}
			p=p->down;
		}
		if(creditSum) setSTU(creditSum,double(gradeSum)/double(creditSum),rank+1);
		else setSTU(creditSum,-1,rank+1);
	}
}

int gradeList::maxInRow() {
	OLNode *p;
	int max;
	p = rowHead[C::getRank()-1];
	if(!p) max = -1;
	else {
		max = p->grade;
		while(p) {
			if(p->grade > max) max = p->grade;
			p = p->right;
		}
	}
	return max;
}
int gradeList::minInRow() {
	OLNode *p;
	int min = 101;
	p = rowHead[C::getRank()-1];
	if(!p) min = -1;
	else {
		if (p->grade != -1) min = p->grade;
		while(p) {
			if(p->grade < min && p->grade != -1) min = p->grade;
			p = p->right;
		}
	}
	if(min == 101) min = -1;
	return min;
}
double gradeList::meanInRow() {
	int sum = 0,count = 0;
	OLNode *p;
	p = rowHead[C::getRank()-1];
	while(p) {
		if(p->grade != -1) {
			count++;
			sum += p->grade;
		}
		p = p->right;
	}
	if(count) return sum/double(count);
	else return -1;
}
void gradeList::quickSort(OLNode **P,int length) {
	if(length<=1) return;
	int refer;//参考值
	int temp=0,head=1, tail=length-1;
	OLNode *buff;
	refer=P[temp]->grade;
	while(1) {
		while(P[head]->grade>=refer && head<length-1) head++;//找更小值
		while(P[tail]->grade<=refer && tail>0) tail--;//找更大值
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


void gradeList::clearCurrent() {
	current=NULL;
}
bool gradeList::isCurrent() {
	if(current) return 1;
	else return 0;
}
