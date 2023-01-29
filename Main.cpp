#include <iostream>
#include <vector>
class A {
public:
	virtual ~A() {}//�� ���� � ����
	virtual void foo(std::vector<int>& vec) = 0;
};
class B : public A {
public:
	void foo(std::vector<int>& vec) override {// ���� ������ ��������� �� ������ ����� �������� ������ ������ ������� �.�. ������� �����
		//��������� ���� ������ � ���������� � ���� ���������� ������ vec.erase() ����� ����������� �� � ����� �������� � ��� ������ 
		std::cout << "foo function" << std::endl;
		vec.erase(vec.begin());
	}
	
};
int main() {
	A* b = new B();
	std::vector<int> v = { 1,2,3 };
	b->foo(v);//�������� ��� �������� 2,3 ������ ��� � ������� ���� ��������� ������� erase(������ ������� - begin)
	delete b;//������ � ����
}
