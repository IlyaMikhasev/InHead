#include <iostream>
#include <vector>
class A {
public:
	virtual ~A() {}//не было в коде
	virtual void foo(std::vector<int>& vec) = 0;
};
class B : public A {
public:
	void foo(std::vector<int>& vec) override {// если убрать амперсант то обьект будет меняться только внутри функции т.к. функция будет
		//создавать свой вектор и копировать в него переданный тоесть vec.erase() будет происходить не с нашим вектором а его копией 
		std::cout << "foo function" << std::endl;
		vec.erase(vec.begin());
	}
	
};
int main() {
	A* b = new B();
	std::vector<int> v = { 1,2,3 };
	b->foo(v);//остается два элемента 2,3 потому что в функции один удаляется методом erase(первый элемент - begin)
	delete b;//небыло в коде
}
