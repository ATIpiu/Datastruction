#pragma once
#pragma once
#include<string>
#include<iostream>
class Student
{
private:
	std::string name;
	int age;
	std::string sex;
	std::string Stu_num;
public:
	Student() {
		this->name = "No";
		this->age = -1;
		this->sex = "No";
		this->Stu_num = "00000000000";
	}
	Student(std::string name, int age, std::string sex, std::string Stu_num)
	{
		this->name = name; this->age = age; this->sex = sex; this->Stu_num = Stu_num;
	}
	void setImformation(std::string name, int age, std::string sex, std::string Stu_num)
	{
		this->name = name; this->age = age; this->sex = sex; this->Stu_num = Stu_num;
	}
	std::string getName() { return this->name; }
	std::string getStu_num() { return this->Stu_num; }
	std::string getSex() { return this->sex; }
	int getAge() { return this->age; }
	friend std::ostream& operator<<(std::ostream& out, Student stu)
	{
		std::cout << "name:";
		out << stu.name << std::endl;
		std::cout << "Age:";
		out << stu.age << std::endl;
		std::cout << "Sex:";
		out << stu.sex << std::endl;
		std::cout << "Student number:";
		out << stu.Stu_num << std::endl;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Student& stu)
	{
		std::cout << "Name:"; in >> stu.name;
		std::cout << "Age:"; in >> stu.age;
		std::cout << "Sex:"; in >> stu.sex;
		std::cout << "Student number:"; in >> stu.Stu_num;
		return in;
	}
	friend int operator==(Student a, Student b)
	{
		if (a.getStu_num() == b.getStu_num())
		{
			return 1;
		}
		return 0;
	}
};

