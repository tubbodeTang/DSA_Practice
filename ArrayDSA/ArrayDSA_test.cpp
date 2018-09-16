#include <iostream>
#include<time.h>
using namespace std;

#include "ArrayDSA.h"
#include "ArrayDSA_Functions.h"


//生成随机数供数组使用(第一个测试，只测试int型的，后面可以扩展多个型）
int Random(){
	return rand() % 100;//返回0-100的随机数
}

template<class T> struct Increase{
	virtual void operator()(T &e){
		e++;
	}
};

template<class T> void increase(ArrayDSA<T> & arrayDSA){
	arrayDSA.traverse(Increase<T>());
}

int main()
{
	srand((int)time(NULL));

	int testSize = 10; //测试向量的规模
	ArrayDSA<int> c(testSize);  // 创建一个大小为testSize的向量
	for (int f = 0; f < testSize; f++)
	{
		c.insertItem(Random()); //给该向量插入生成的随机测试数，
		//后面也可以改成向随机位置插入随机数，更随机一些
	}

	cout << "The New Vector is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;

	//再插入一个元素，测试扩容和任意位置插入
	c.insertItem(5, 111);

	cout << "Vector after Arbitrarily Insert is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;


	//测试全向量查找元素
	cout << "Rank of target " << 111 << " is:" << c.findRank(111) << endl;

	//测试区间查找元素
	cout << "Rank of target " << 111 << " is:" << c.findRank(111,1,4) << endl;


	//测试删除元素
	c.deleteItem(5);
	cout << "Vector after single delete is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;

	//测试删除区间元素
	c.deleteItem(5, 8);
	cout << "Vector after range delete is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;


	//测试无序去重
	c.insertItem(5, 111);
	c.insertItem(7, 111);
	cout << "Vector before duplicated is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;

	c.deduplicated();
	cout << "Vector after duplicated is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;

	
	//测试排序
	c.sort();
	cout << "Vector after sort is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;




	//测试有序去重
	c.insertItem(5, 111);
	c.insertItem(7, 111);
	cout << "Vector before uniquify is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;


	//排序
	c.sort();
	cout << "Vector after sort is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;


	//顺便测试一下有序查找(应该返回同值中最大的秩)
	cout << "Rank of target " << 111 << " is:" << c.search(111) << endl;



	c.uniquify();
	cout << "Vector after uniquify is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;



	//测试遍历
	increase(c);
	cout << "Vector after double traverse is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;
	
	system("PAUSE");

	return 0;
}

