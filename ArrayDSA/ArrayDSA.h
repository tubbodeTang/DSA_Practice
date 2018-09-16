#pragma once

#define DEFAULT_LENGTH 5

typedef int Rank;
template <typename T> class ArrayDSA {
private:
	T * thisVector; //首地址指针

	int length; //向量实际长度

	int capacity; //向量容量

protected:
	void extend(); //扩容
	void copy();//复制
	void bubbleSort(Rank lo, Rank hi);
	void selectionSort(Rank lo, Rank hi);
	void mergeSort(Rank lo, Rank hi);
	void switchItem(Rank a, Rank b);
	void merge(Rank lo, Rank mi, Rank hi);

	Rank binarySearch(T target, Rank lo, Rank hi);
public:

	ArrayDSA(); // constructor
	ArrayDSA(int cuslength); // constructor


	//复制构造函数-从数组复制全部
	ArrayDSA(T *target, Rank TargetSize);

	//复制构造函数-从数组复制一部分
	ArrayDSA(T *target, Rank lo, Rank hi);
	//复制构造函数-从向量复制全部
	ArrayDSA(ArrayDSA<T> &target);

	//复制构造函数-从向量复制一部分
	ArrayDSA(ArrayDSA<T> target, Rank lo, Rank hi);

	~ArrayDSA(){
		delete[] thisVector;
	}; // destructor

	////只读访问接口

	int size();//vector规模

	bool isEmpty();//判断是否为空

	bool isOrdered(); //判断是否有序

	Rank findRank(T target , Rank lo,Rank hi ); //无序查找找元素位置区间
	Rank findRank(T target); //无序查找找元素位置整体

	Rank search(T target , Rank lo ,Rank hi); //有序向量查找区间
	Rank search(T target); // 有序向量查找整体

	////可写访问接口

	
	Rank insertItem(Rank r, T ele);//向指定位置插入元素
	Rank insertItem(T ele);//默认向末尾插入元素

	int deleteItem(Rank lo, Rank hi);//删除区间元素
	int deleteItem(Rank r);//删除单个元素

	//从目标数组中复制某一段元素
	void copy(const T * const target,Rank lo, Rank hi);

	//对某一段排序
	void sort(Rank lo, Rank hi);

	//对整体排序
	void sort();


	//置乱

	//有序去重
	int uniquify();

	//无序去重
	int deduplicated();

	//遍历  直接复制过来的，先看懂再说
	void traverse(void(*) (T&)); //遍历（使用函数指针，只读或局部性修改）
	template <typename VST> void traverse(VST&); //遍历（使用函数对象，可全局性修改）

	////运算符重载

	// [] 运算符
	T operator[](Rank r);
	// = 运算符
	//T operator=();

};