#include <iostream>
#include<time.h>
using namespace std;

#include "ArrayDSA.h"
#include "ArrayDSA_Functions.h"


//���������������ʹ��(��һ�����ԣ�ֻ����int�͵ģ����������չ����ͣ�
int Random(){
	return rand() % 100;//����0-100�������
}

int main()
{
	srand((int)time(NULL));

	int testSize = 10; //���������Ĺ�ģ
	ArrayDSA<int> c(testSize);  // ����һ����СΪtestSize������
	for (int f = 0; f < testSize; f++)
	{
		c.insertItem(Random()); //���������������ɵ������������
		//����Ҳ���Ըĳ������λ�ò���������������һЩ
	}

	cout << "The New Vector is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;

	//�ٲ���һ��Ԫ�أ��������ݺ�����λ�ò���
	c.insertItem(5, 111);

	cout << "Vector after Arbitrarily Insert is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;


	//����ȫ��������Ԫ��
	cout << "Rank of target " << 111 << " is:" << c.findRank(111) << endl;

	//�����������Ԫ��
	cout << "Rank of target " << 111 << " is:" << c.findRank(111,1,4) << endl;


	//����ɾ��Ԫ��
	c.deleteItem(5);
	cout << "Vector after single delete is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;

	//����ɾ������Ԫ��
	c.deleteItem(5, 8);
	cout << "Vector after range delete is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;


	//��������ȥ��
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

	
	//��������
	c.sort();
	cout << "Vector after sort is:" << endl;
	cout << "[";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << "]" << endl;
	
	system("PAUSE");

	return 0;
}

