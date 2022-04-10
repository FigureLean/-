// 多项式类.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Polynomial {

public:
	Polynomial()//默认构造函数 
	{
		size = 10;
		num = new int[size];
		for (int i = 0; i < size; i++)
		{
			num[i] = 0;
		}
	}
	


	Polynomial(int _size)//带参数的构造函数
	{
		size = _size;
		num = new int[size];
		for (int i = 0; i < size; i++)
		{
			num[i] = 0;
		}
	}

	

	Polynomial(int* m, int _size)
	{
		size = _size;
		num = new int[_size];
		for (int i = 0; i < size; i++)
		{
			num[i] = m[i];
		}
	}

	Polynomial(const Polynomial&p1copy) {
		size = p1copy.size;

		num = new int[size];
		for (int i = 0; i < size; i++) {
			num[i] = p1copy.num[i];
		}

	}
	~Polynomial(){
		delete   []num;
	}

	void setNum(int counter, int nums)
	{
		num[counter] = nums;
	}

	int getNum(int counter) {
		cout << num[counter];
		return num[counter];
	}

	void print() {

		for (int i = 0; i < size; i++)
		{
			if (num[i] != 0) {
				cout << "x" << num[i];
			}
		}

	}

	Polynomial& operator =(Polynomial& p1) {
		size = p1.size;
		for (int i = 0; i < size; i++) {
			num[i] = p1.num[i];
		}
	}

	friend Polynomial operator+(Polynomial&, Polynomial&);
	
	friend Polynomial operator-(Polynomial&, Polynomial&);

	friend Polynomial operator*(Polynomial&, Polynomial&);

	friend ostream& operator<<(ostream&, Polynomial&);

	Polynomial &operator+=(Polynomial&p1) {
		
		if (p1.size <= size) {
			for (int i = 0; i < p1.size; i++) {
				num[i] = num[i] + p1.num[i];
			}
			return *this;
		}

		else
		{
			for (int i = 0; i < size; i++) {
				num[i] = num[i] + p1.num[i];
			}
			return *this;
		}

	}

	Polynomial& operator-=(Polynomial& p1) {

		if (p1.size <= size) {
			for (int i = 0; i < p1.size; i++) {
				num[i] = num[i] - p1.num[i];
			}
			return *this;
		}

		else
		{
			for (int i = 0; i < size; i++) {
				num[i] = num[i] - p1.num[i];
			}
			return *this;
		}

	}

	Polynomial& operator*=(Polynomial& p1) {

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < p1.size; j++) {
				num[i + j] += p1.num[i] *num[j];
			}
		}

		return *this;

	}
	void Print()
	{

		cout << "多项式为: ";
		for (int i = 0; i < size; i++)
		{
			cout << num[i] << "X^" << i;
			if (i != size - 1)
				cout << "+";
		}
		cout << endl;
	}
private:
	int size;
	int* num;
};




Polynomial operator+(Polynomial&p1, Polynomial&p2) {
	if (p1.size < p2.size)
	{
		Polynomial p3(p2);
		for (int i = 0; i < p2.size; i++)
		{
			p3.num[i] = p1.num[i] + p2.num[i];
		}
		return p3;
	}
	else {
		Polynomial p3(p1);
		for (int i = 0; i < p1.size; i++)
		{
			p3.num[i] = p1.num[i] + p2.num[i];
		}
		return p3;
	}
	
}

Polynomial operator-(Polynomial&p1, Polynomial&p2) {
	if (p1.size <= p2.size)
	{
		Polynomial p3(p2);
		for (int i = 0; i < p2.size; i++)
		{
			p3.num[i] = p1.num[i] - p2.num[i];
		}
		return p3;
	}
	else {
		Polynomial p3(p1);
		for (int i = 0; i < p1.size; i++)
		{
			p3.num[i] = p1.num[i] - p2.num[i];
		}
		return p3;
	}
}

Polynomial operator*(Polynomial&p1, Polynomial&p2) {
	Polynomial p3(p1.size + p2.size);
	//p3.size = p1.size + p2.size;

	
	for (int i = 0; i < p1.size; i++) {
		for (int j = 0; j < p2.size; j++) {
			p3.num[i + j] += p1.num[i] * p2.num[j];
		}
	}

	return p3;
}

ostream& operator<<(ostream&output, Polynomial&p1) {

	int i;

	for (i = 0; i < p1.size; i++)
	{
		if (p1.num[i] != 0) {

			output << "x" << p1.num[i];
		}
		
	}
	return output;

}


int main()
{
	//Polynomial p1(3);
	//p1.setNum(1, 2);
	//Polynomial p2(5);
	//p2.setNum(3, 2);
	//Polynomial p3= p1 + p2;
	//p3 = p1 + p2;
	//p3.getNum(1);
	//p3.getNum(3);
	//cout << p3;
	//p3.print();

	int m[3] = { 1,3 };
	
	int n [3] = { 1,2 };

	Polynomial p1(m,3);

	Polynomial p2(n, 3);

	Polynomial p3;
	p1 += p2;
	
	//Polynomial p3 = p1 * p2;

	//p3.print();
	
	//cout << p1;
	p1.Print();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
