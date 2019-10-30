#include"ListNode.h"
#include<iostream>
#include<fstream>
using namespace std;
template<typename T>
class List;
template<typename T>
class ListNode
{
private:
	friend typename List<T>;
public:
	ListNode(T Data)
	{
		this->data = Data;
		this->next = NULL;
	}
	ListNode()
	{

	}
	T data;
	ListNode* next;
};
template<typename T>
class List
{
private:
	ListNode<T> *head;
	ListNode<T>* rear;
	static int count;
public:
	List()
	{
		head = new ListNode<T>();
		rear = head;
	}
	void preInsert(ListNode<T>* newNode)
	{
		newNode->next = head->next;
		head->next = newNode;
		rear = newNode;
	}
	void postInsert(ListNode<T>* newNode)
	{
		rear->next = newNode;
		rear = newNode;
	}
	bool insert(ListNode<T>* newNode,int x)
	{
		int i = 0;
		ListNode<T> *current = head;
		while (current->next)
		{
			current = current->next;
			if (i == x)
				break;
			i++;
		};
		if (i==x)
		{
			newNode->next = current->next;
			current->next = newNode;
			return true;
		}
		return false;
	}
	void Show();
	
	void Function()
	{
		this->getFromFile();
		for (;;)
		{
			int a;
			cout << "========================" << endl;
			cout << "Pleas Input your choice" << endl;
			cout << "========================" << endl;
			cout << "1.PreInsert" << endl;
			cout << "2.PostInsert" << endl;
			cout << "3.inset" << endl;
			cout << "4.ShowData" << endl;
			cout << "5.Find" << endl;
			cout << "6.Locate" << endl;
			cout << "7.change" << endl;
			cout << "0.Exit" << endl;
			cout << "==================" << endl;
			cin >> a;
			switch (a)
			{
			case 1: {
				cout << "please input the Data" << endl;
				T Data; cin >> Data;
				ListNode<T>* newNode =new ListNode<T>(Data);
				this->preInsert(newNode); break;
			}
			case 2: {
				cout << "please input the Data" << endl;
				T Data; cin >> Data;
				ListNode<T>* newNode = new ListNode<T>(Data);
				this->postInsert(newNode); break; 
			}
			case 3: {
				cout << "please input the Data" << endl;
				T Data; cin >> Data;
				ListNode<T>* newNode = new ListNode<T>(Data);
				cout << "please input the Locate" << endl;
				int locate; cin >> locate;
				if (this->insert(newNode,locate) == false)	cout << "Inset Wrong!!!!!!!" << endl;
				break;
			}
			case 4:this->Show(); break;
			case 5: {
				cout << "Please input the Locate" << endl;
				int locate; cin >> locate;
				cout << "the Date is:" << this->Find(locate) << endl;
				break;
			}
			case 6: {
				cout << "Please input the Data" << endl;
				T data; cin >> data;
				cout << "Locate:" << this->Locate(data) << endl; break;
			}
			case 7: {
				cout << "Please input where you want to change" << endl;
				int i; cin >> i;
				cout << "Please input how should you change" << endl;
				T data; cin >> data;
				this->change(i, data);
				break;
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
	int Locate(T Data)
	{
		ListNode<T>* current = this->head;
		int i = 1;
		while (current->next!=NULL)
		{
			current = current->next;
			if (current->data == Data)
			{
				break;
			}	
			i++;
		}
		return i;
	}
	T Find(int x)
	{
		int i = 1;
		ListNode<T>* current = this->head;
			while (current->next!=NULL)
			{
				current = current->next;
				if (i == x)
				{
					break;
				}
				i++;
			}
			return current->data;
	}
	void change(int x,T data)
	{
		int i = 1;
		ListNode<T>* current = this->head;
		while (current->next)
		{
			current = current->next;
			if (i == x)
			{
				current->data = data;
			}
			i++;
		}
	}
	void saveToFile()
	{
		ofstream out("List.txt");
		if (out.is_open()==false)
		{
			cout << "Open error" << endl;
			exit(1);
		}
		ListNode<T>* current = this->head; int i = 1;
		while (current->next != NULL)
		{
			current = current->next;
			i++;
		}
		i--;
		out << i << endl;
		current = this->head;
		while(current->next != NULL)
		{
			current = current->next;
			out << current->data << endl;
		}
	}
	void getFromFile()
	{
		ifstream in("List.txt");
		if (in.is_open() == false)
		{
			cout << "File open error" << endl;
			exit(1);
		}
		int a;
		in >> a;
		while (a>=1)
		{
			T data;
			in >> data;
			ListNode<T>* current = new ListNode<T>(data);
			this->postInsert(current);
			a--;
		}
	}
};
template<typename T>
inline void List<T>::Show()
{
	int i = 1;
	ListNode<T>* current = head;
	while (current->next != NULL)
	{
		current = current->next;
		
		cout << i++ << "data:" << current->data << endl;
	}
}
