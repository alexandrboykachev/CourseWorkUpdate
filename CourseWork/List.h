#pragma once
#include<iostream>

using namespace std;

template<class T>
class List
{
private:
	class Node {
	public:
		Node(T data = T(), Node* Next = nullptr) {
			this->data = data;
			this->Next = Next;
		}
		Node* Next;
		T data;
	};
public:
	void push_back(T obj) { // ���������� � ����� ������ bc
		if (head != nullptr) {
			this->tail->Next = new Node(obj);
			tail = tail->Next;
		}
		else {
			this->head = new Node(obj);
			this->tail = this->head;
		}
		Size++;
	}
	void push_front(T obj) { // ���������� � ������ ������ bc
		if (head != nullptr) {
			Node* current = new Node;
			current->data = obj;
			current->Next = this->head;
			this->head = current;
		}
		else {
			this->head = new Node(obj);
			tail = head;
		}
		this->Size++;
	}
	void pop_back() { // �������� ���������� �������� bc
		if (head != nullptr) {
			Node* current = head;
			while (current->Next != tail)//�� ���� ���� �������������
				current = current->Next;
			delete tail;
			tail = current;
			tail->Next = nullptr;
			Size--;
		}
		else throw out_of_range("out_of_range");
	}
	void pop_front() { // �������� ������� �������� bc-+
		if (head != nullptr) {
			Node* current = head;
			head = head->Next;
			delete current;
			Size--;
		}
		else throw out_of_range("out_of_range");
	}
	void insert(T obj, size_t k) {// ���������� �������� �� ������� (������� ����� ���������, ������� ��� ����� �������� �� ����� �������) bc
		if (k >= 0 && this->Size > k) {
			if (this->head != nullptr) {
				if (k == 0)
					this->push_front(obj);
				else
					if (k == this->Size - 1)
						this->push_back(obj);
					else
					{
						Node* current = new Node;//��� ���������� ��������
						Node* current1 = head;//��� ������ ����� ��������
						for (int i = 0; i < k - 1; i++) {
							current1 = current1->Next;
						}
						current->data = obj;
						current->Next = current1->Next;//������������� �� ���� �������
						current1->Next = current;
						Size++;
					}
			}
		}
		else {
			throw out_of_range("out_of_range");
		}
	}
	T at(size_t k) {// ��������� �������� �� ������� bc
		if (this->head != nullptr && k >= 0 && k <= this->Size - 1) {
			if (k == 0)
				return this->head->data;
			else
				if (k == this->Size - 1)
					return this->tail->data;
				else
				{
					Node* current = head;
					for (size_t i = 0; i < k; i++) {
						current = current->Next;
					}
					return current->data;
				}
		}
		else {
			throw out_of_range("out_of_range");
		}
	}
	void remove(int k) { // �������� �������� �� ������� bc
		if (head != nullptr && k >= 0 && k <= Size - 1) {
			if (k == 0) this->pop_front();
			else
				if (k == this->Size - 1) this->pop_back();
				else
					if (k != 0) {
						Node* current = head;
						for (int i = 0; i < k - 1; i++) {//��������� �� �����������
							current = current->Next;
						}

						Node* current1 = current->Next;
						current->Next = current->Next->Next;
						delete current1;
						Size--;
					}
		}
		else {
			throw out_of_range("out_of_range");
		}
	}
	size_t get_size() { // ��������� ������� ������ bc
		return Size;
	}
	void print_to_console() { // ����� ��������� ������ � ������� ����� �����������, �� ������������ at bc
		if (this->head != nullptr) {
			Node* current = head;
			for (int i = 0; i < Size; i++) {
				cout << current->data << ' ';
				current = current->Next;
			}
		}
	}
	void clear() { // �������� ���� ��������� ������
		if (head != nullptr) {
			Node* current = head;
			while (head != nullptr) {
				current = current->Next;
				delete head;
				head = current;
			}
			Size = 0;
		}
	}
	void set(size_t k, T obj)  // ������ �������� �� ������� �� ������������ ������� 
	{
		if (this->head != nullptr && this->get_size() >= k && k >= 0) {
			Node* current = head;
			for (int i = 0; i < k; i++) {
				current = current->Next;
			}
			current->data = obj;
		}
		else {
			throw out_of_range("out_of_range");
		}
	}
	bool isEmpty() { // �������� �� ������� ������ bc
		return (bool)(head);
	}
	void reverse() { // ������ ������� ��������� � ������
		int Counter = Size;
		Node* HeadCur = nullptr;
		Node* TailCur = nullptr;
		for (int j = 0; j < Size; j++) {
			if (HeadCur != nullptr) {
				if (head != nullptr && head->Next == nullptr) {
					TailCur->Next = head;
					TailCur = head;
					head = nullptr;
				}
				else {
					Node * cur = head;
					for (int i = 0; i < Counter - 2; i++)
						cur = cur->Next;
					TailCur->Next = cur->Next;
					TailCur = cur->Next;
					cur->Next = nullptr;
					tail = cur;
					Counter--;
				}
			}
			else {
				HeadCur = tail;
				TailCur = tail;
				Node* cur = head;
				for (int i = 0; i < Size - 2; i++)
					cur = cur->Next;
				tail = cur;
				tail->Next = nullptr;
				Counter--;
			}
		}
		head = HeadCur;
		tail = TailCur;
	}
public:
	List(Node* head = nullptr, Node* tail = nullptr, int Size = 0) :head(head), tail(tail), Size(Size) {}
	~List() {
		if (head != nullptr) {
			this->clear();
		}
	};
private:
	Node* head;
	Node* tail;
	int Size;
};
