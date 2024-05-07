#include <iostream>
#include<vector>
using namespace std;

class Place {
public:
	string country = " ";
	string region = " ";
	string city = " ";
	string street = " ";
	int house_number = 0;
	char korpus = ' ';
	short postal_code = 0;
};

class Date {
public:
	int day = 0;
	int month = 0;
	int year = 0;
};

class Subject {
public:
	string theme = " ";
	string course = " ";
};
class AttendanceInfo {
public:
	Subject* subject;
	Date date;
	bool is_late;
};

class Attendance {
public:
	vector<AttendanceInfo> info;
};
class Homework {
public:
	vector<int> homework_rates;
};

class Exam {
public:
	vector<int> exam_rates;
};

class TotalAverageRate {
public:
	double total_average_rate;
};

class Zachet {
public:
	vector<int> zachet_rates;
};

class Practice {
public:
	vector<int> practice_rates;
};

class Study {// учёба
public:
	Date start;
	Attendance* attendance = nullptr;
	Practice* practices = nullptr;
	Homework* homeworks = nullptr;
	Zachet* zachets = nullptr;
	Exam* exams = nullptr;
	Study() {
		attendance = new Attendance;
		practices = new Practice;
		homeworks = new Homework;
		zachets = new Zachet;
		exams = new Exam;		
	}	
};

class Student {
public:
	string name;
	string surname;
	string lastname;		
	Date birthday;
	Study* study = nullptr;
};

class StudentConsolePrinter {
public:
	void Print(Student& student) const {
		cout << student.name << " " << student.lastname << " " << student.surname << "\n";
		cout << student.birthday.day << '/' << student.birthday.month << '/' << student.birthday.year << "\n";
		cout << student.study->start.day << '/' << student.study->start.month << '/' << student.study->start.year << "\n";

		for(int i = 0; i < student.study->exams->exam_rates.size(); i++)
			cout << student.study->exams->exam_rates[i] << " ";

		for (int i = 0; i < student.study->homeworks->homework_rates.size(); i++)
			cout << student.study->homeworks->homework_rates[i] << " ";

		for (int i = 0; i < student.study->practices->practice_rates.size(); i++)
			cout << student.study->practices->practice_rates[i] << " ";

		for (int i = 0; i < student.study->zachets->zachet_rates.size(); i++)
			cout << student.study->zachets->zachet_rates[i] << " ";
		cout << "\n";
	}
};
class Teacher {
public:
	string name = "";
	string subject = " ";
	void Teach() {}
};
class Group {
public:
	string name = " ";
	string specialisation = " ";
	vector<Student> students;
	//string subject_name; // название предмета
	vector<Teacher> teachers;
	int kurs = 0;
};

class GroupConsolePrinter {
public:
	void Print(Group& group, StudentConsolePrinter& a) const {
		cout << group.name << "\n";
		cout << group.specialisation << "\n";
		cout << group.students.size() << "\n";
		for (int i = 0; i < group.teachers.size(); i++)
			cout << group.teachers[i].name << "\n";
		for (int i = 0; i < group.students.size(); i++)
			a.Print(group.students[i]);
		cout << "\n";
	}
};

int main() {
	Student student;
	student.birthday.day = 10;
	student.birthday.month = 10;
	student.birthday.year = 2000;
	student.name = "Student";
	student.study = new Study;
	student.study->start.day = 15;
	student.study->start.month = 3;
	student.study->start.year = 2015;
	//student.study->homeworks->homework_rates.push_back(5);
	StudentConsolePrinter a;
	//a.Print(student);
	Group group;
	group.name = "P26";
	group.specialisation = "Programming";
	group.students.push_back(student);
	group.students.push_back(student);
	GroupConsolePrinter b;
	b.Print(group, a);
}