#pragma once
#include<iostream>
#include<fstream>
template<class T>
class Seqlist {
private:
	T* elements;
	int Maxsize;
	int length;
public:
	Seqlist(int maxsiaze = 100) {
		this->Maxsize = maxsiaze;
		length = 0;
		elements = new T[Maxsize];
	}
	~Seqlist() { delete []elements; }
	bool insert(T element,int location) {
		length++;
		if (location > length)
		{
			length--;
			return false;
		}
		int i;
		location--;
		for (i = 0; i < length; i++)
		{
			if (i == location)
			{
				for (int j = length-1; j >=i; j--)
				{
					elements[j +1] = elements[j];
				}
				elements[i] = element;
			}
		}
		return true;
	}
	int getLength(){	return length;}

	void Print()
	{
		for (int i = 0; i < length; i++)
		{
			std::cout << elements[i] << std::endl;
		}
	}
	void deleteByElement(T element)
	{
		for (int i = 0; i < length; i++)
		{
			if (elements[i] == element)
			{
				for (int j = i; j < length; j++)
				{
					elements[j] = elements[j + 1];
				}
			}
		}
		length--;
	}
	bool deleteByLocation(int location)
	{
		if (location > length)
		{
			return false;
		}
		location--; 
		for (int i = 0; i < length; i++)
		{
			if (i == location)
			{
				for (int j = i; j < length; j++)
				{
					elements[j] = elements[j + 1];
				}
			}
		}
		length--;
	}
	int locate(T element)
	{
		for (int i = 0; i < length; i++)
		{
			if (element == elements[i])
			{
				return i+1;
			}
		}
	}
	void Function()
	{
		using namespace std;
		this->getFromFile();
		for (;;)
		{
			int a;
			cout << "========================" << endl;
			cout << "Pleas Input your choice" << endl;
			cout << "========================" << endl;
			cout << "1.inset" << endl;
			cout << "2.ShowData" << endl;
			cout << "3.Find" << endl;
			cout << "4.Locate" << endl;
			cout << "5.Update" << endl;
			cout << "6.DeleteByLocation" << endl;
			cout << "7.DeleteByElement" << endl;
			cout << "0.Exit" << endl;
			cout << "==================" << endl;
			cin >> a;
			cout << "==================" << endl;
			switch (a)
			{
			case 1: {
				cout << "please input the Data" << endl;
				T Data; cin >> Data;
				cout << "please input the Locate" << endl;
				int locate; cin >> locate;
				if (this->insert(Data, locate) == false)	cout << "Inset Wrong!!!!!!!" << endl;
				break;
			}
			case 2:this->Print(); break;
			case 3: {
				cout << "Please input the Locate" << endl;
				int locate; cin >> locate;
				cout << "the Date is:" << this->findElement(locate) << endl;
				break;
			}
			case 4: {
				cout << "Please input the Data" << endl;
				T data; cin >> data;
				cout << "==============" << endl;
				cout << "Locate:" << this->locate(data) << endl; break;
			}
			case 5: {
				cout << "Please input where you want to change" << endl;
				int i; cin >> i;
				cout << "Please input how should you change" << endl;
				T data; cin >> data;
				this->update(data, i);
				break;
			}
			case 6: {
				cout << "Please input what you want to Delete" << endl;
				T data; cin >> data;
				this->deleteByElement(data);
			}
			case 7: {
				cout << "Please input where you want to Delete" << endl;
				int i; cin >> i;
				this->deleteByLocation(i);
			}
			default:
				break;
			}
			if (a == 0)
			{
				this->saveToFile();
				cout << "Thanks for using " << endl;
				break;
			}
		}
	}
	T findElement(int location)
	{
		if (location > length)
			{
			std::cout << "no such a elemnt" << std::endl;
			}
		location--;
			return elements[location];
	}
	void update(T element, int location)
	{
		location--;
		elements[location] = element;
	}
	void saveToFile()
	{
		std::ofstream out("Seqlist.txt");
		if (out.is_open() == false)
		{
			std::cout << "Open error" << std::endl;
			exit(1);
		}
		out << this->length << " ";
		for (int i = 0; i < length; i++)
		{
			out << elements[i] << " ";
		}
	}
	bool getFromFile()
	{
		std::ifstream in("Seqlist.txt");
		if (in.is_open() == false)
		{
			std::cout << "Open error" << std::endl;
			return 0;
		}
		in >> this->length;
		for (int i = 0; i < length; i++)
		{
			in >> elements[i];
		}
		return 1;
	}
};