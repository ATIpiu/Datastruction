#pragma once
#pragma once
#include<string>
#include<list>
#include<iostream>
template<class T>
class Vertex {
	std::string name;
	std::list<Vertex*> connected_node;
	T data;
	Vertex(std::string name1, T data1)
	{
		this->name = name1;
		this->data = data1;
	}
};
template<class T>
class Edge {
	Vertex<T> fore_node;
	Vertex<T> aft_node;
	int weight;
	Edge(Vertex<T> fore_node1, Vertex<T> aft_node1, int weight1) {
		this->aft_node = aft_nod1;
		this->fore_node = fore_node1;
		this->weight = weight1;a
	}
};
template<class T>
class MyMap
{
private:
	int e_num;
	int v_num;
	std::list<Vertex<T>> vertexs;
	MyMap() {
		this->e_num = 0; this->v_num = 0;
	}
	void insert();
};
template<class T>
inline void MyMap<T>::insert()
{
	cout << "please input the name of the vertex" << endl;
	string name;
	cin >> name;
	cout << "please input the data of this vertex" << endl;
	T data;
	cin >> data;
	Vertex<T> vertex(name, data);
}

