#pragma once


#include "iostream"
#include "ArrayDSA.h"

//普通构造函数
template <class T>  ArrayDSA<T>::ArrayDSA(){
	thisVector = new T[DEFAULT_LENGTH];//初始化成数组，所以可以使用数组的方法
	capacity = (int)DEFAULT_LENGTH;
	length = 0;
}

//自定义长度构造函数（后续可以和上面合并）
template <typename T>  ArrayDSA<T>::ArrayDSA(int cuslength){
	thisVector = new  T[cuslength]; //初始化成数组，所以可以使用数组的方法
	capacity = cuslength;
	length = 0;
}

//复制构造函数-从数组复制全部
template <class T>  ArrayDSA<T>::ArrayDSA(T *target, Rank TargetSize){
	copy(target, 0, TargetSize)
}

//复制构造函数-从数组复制一部分
template <class T>  ArrayDSA<T>::ArrayDSA(T *target, Rank lo, Rank hi){
	copy(target, lo, hi)
}

//复制构造函数-从向量复制全部
template <class T>  ArrayDSA<T>::ArrayDSA(ArrayDSA<T> &target){
	copy(target.thisVector, 0, target.size())
}

//复制构造函数-从向量复制一部分
template <class T>  ArrayDSA<T>::ArrayDSA(ArrayDSA<T> target, Rank lo, Rank hi){
	copy(target.thisVector, lo, hi)
}

//获取数组实际大小
template<class T> int ArrayDSA<T>::size(){
	return length;
}

//判空
template<class T> bool ArrayDSA<T>::isEmpty(){
	return length == 0;
}


template <class T> bool ArrayDSA<T>::isOrdered(){
	bool ordered = true; //默认有序
	for (int i = 1; i < length;i++){
		if (thisVector[i-1]>thisVector[i]){
			ordered = false;
			return ordered;
		}
	}
	return ordered;
}


//指定位置插入元素
template <class T> Rank ArrayDSA<T>::insertItem(Rank r, T ele){
	extend();//扩容

	for (int i = length - 1; i >= r; i--)
	{
		thisVector[i + 1] = thisVector[i];
	}

	thisVector[r] = ele;
	length++;
	return r;
}

//默认在末尾插入元素
template <class T> Rank ArrayDSA<T>::insertItem(T ele){
	return insertItem(length, ele);
}

//删除区间元素lo是闭区间，hi是开区间？
template <class T> int ArrayDSA<T>::deleteItem(Rank lo, Rank hi){
	//Rank point = hi + 1;

	while (lo < hi&&hi < length)
	{
		thisVector[lo++] = thisVector[hi++];
	}
	length = lo;
	return hi - lo + 1; //删除的元素个数
}

//删除单个元素
template <class T> int ArrayDSA<T>::deleteItem(Rank r){
	return deleteItem(r, r + 1);
}

//无序查找找元素位置区间
template <class T> Rank ArrayDSA<T>::findRank(T target, Rank lo, Rank hi){
	while (lo < hi)
	{
		if (target == thisVector[lo]){
			return lo;
		}
		lo++;
	}
	return -1;
}

//无序查找找元素位置整体
template <class T> Rank ArrayDSA<T>::findRank(T target){
	return findRank(target, 0, length);
}


//有序查找元素位置区间
template <class T> Rank ArrayDSA<T>::search(T target, Rank lo, Rank hi){
	//switch (rand() % 3) { //随机选取查找算法。可根据具体问题的特点灵活选取或扩充
	//case 1:  binarySearch(target,lo, hi); break; //二分查找
	//case 2:  fibSearch(target,lo, hi); break; //fibonacci 查找
	//case 3:  mergeSort(target,lo, hi); break; //插值查找
	//default:break;
	//}
	/*DSA*/ //selectionSort(lo, hi);
	return binarySearch(target, lo, hi);
}

//有序查找元素位置整体
template <class T> Rank ArrayDSA<T>::search(T target){
	return search(target, 0, length);
}

template <class T> Rank ArrayDSA<T>::binarySearch(T target, Rank lo, Rank hi){
	while (hi - lo > 1){
		Rank mi = (lo + hi) >> 1;
		if (target >= thisVector[mi]){
			lo = mi;
		}
		else{
			hi = mi;
		}
	}
	return lo;
}

//无序去重
template <class T> int ArrayDSA<T>::deduplicated(){
	int deleteNum = 0;
	for (Rank i = 0; i < length; i++){
		for (Rank j = i + 1; j < length; j++){
			if (thisVector[i] == thisVector[j]){
				deleteItem(j);
				deleteNum++;
			}
		}
	}
	return deleteNum;
}

// 有序去重
template <class T> int ArrayDSA<T>::uniquify(){
	if (isOrdered()){
		int j = 0;//不一样的元素个数

		for (int i = 0; i < length;){
			if (thisVector[i] == thisVector[i + 1]){
				i++;
			}
			else{
				j++;
				thisVector[j] = thisVector[i + 1];
				i++;
			}
		}
		int removeNum = length - j; //去除的元素个数
		length = j; //直接截取掉后面所有的元素
		return removeNum;
	}
	else{
		sort();
		return uniquify();
	}
}

//对某一段排序
template <class T> void ArrayDSA<T>::sort(Rank lo, Rank hi){
	//switch (rand() % 3) { //随机选取排序算法。可根据具体问题的特点灵活选取或扩充
	//case 1:  bubbleSort(lo, hi); break; //起泡排序
	//case 2:  selectionSort(lo, hi); break; //选择排序（习题）
	//case 3:  mergeSort(lo, hi); break; //归并排序
	//default:break;
	//   //case 4:  heapSort(lo, hi); break; //堆排序（稍后介绍）
	////default: quickSort(lo, hi); break; //快速排序（稍后介绍）
	//}
	selectionSort(lo, hi);
}

//对整体排序
template <class T> void ArrayDSA<T>::sort(){
	sort(0, length);
}


//起泡排序(最笨版?)
template <class T> void ArrayDSA<T>::bubbleSort(Rank lo, Rank hi){
	int realSortLength = length;
	while (lo < realSortLength){
		for (int i = hi; i >= lo; i--){
			if (thisVector[i] < thisVector[i - 1]){
				switchItem(i, i - 1);
			}
		}
		lo++;
	}

}

template <class T> void ArrayDSA<T>::switchItem(Rank a, Rank b){
	T c = thisVector[a];
	thisVector[a] = thisVector[b];
	thisVector[b] = c;
}


//归并排序
template <class T> void ArrayDSA<T>::mergeSort(Rank lo, Rank hi){
	int sortLength = hi - lo;
	if (sortLength < 2) return;
	Rank mi = hi + lo >> 1;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}

template <class T> void ArrayDSA<T>::merge(Rank lo, Rank mi, Rank hi){
	int lengthB = mi - lo;
	int lengthC = hi - mi;
	T *B = new T[lengthB];
	T *C = thisVector + mi;

	for (int i = 0; i < lengthB; i++){
		B[i] = thisVector[lo + i];
	}//备份出来[lo,mi] 防止后面放到末尾的时候被覆盖

	//原来for (int i = 0, j = 0, k = lo; (i < lengthB) || (j < lengthC);){
	//现在可以不考虑B用完的情况，B用完，直接退出即可
	for (int i = 0, j = 0, k = lo; i < lengthB;){
		//原来if (i < lengthB && (B[i] < C[j] || j >= lengthC)){
		//现在可以不考虑B用完的情况，B用完，直接退出即可
		if (B[i] <= C[j] || j >= lengthC){
			//B中元素比C中元素小，或者C中的元素已经用光了，
			//直接把B中当前元素拼在thisVector的末尾
			thisVector[k] = B[i];
			i++;
			k++;
		}
		//原来  if (j < lengthC && (B[i] > C[j] || i >= lengthB)){
		//现在可以不考虑B用完的情况，B用完，直接退出即可
		if (j < lengthC && B[i] > C[j]){
			//C中元素比B中元素小，或者B中的元素已经用光了，
			//直接把C中当前元素拼在thisVector的末尾
			//但这里，C本来就是thisVector的一部分，所以其实可以不用移动了
			thisVector[k] = C[j];
			j++;
			k++;
		}
	}

	delete[] B;
}


//选择排序
template <class T> void ArrayDSA<T>::selectionSort(Rank lo, Rank hi){
	hi--;
	while (hi > lo){
		Rank maxRank = lo;
		T maxCC = thisVector[lo];
		for (int i = lo+1; i <=  hi;i++){
			if (thisVector[i]>maxCC){
				maxCC = thisVector[i];
				maxRank = i;
			}
		}
		//T maxValue = thisVector[maxRank];
		T changeValue = thisVector[hi];
		thisVector[hi] = maxCC;
		thisVector[maxRank] = changeValue;

		for (int i = 0; i < length; i++)
		{
			cout << thisVector[i] << " ";
		}
		cout << endl;
		hi--;
	}
}


//从目标数组中复制一段
template <class T> void ArrayDSA<T>::copy(const T * const target, Rank lo, Rank hi){
	thisVector = new T[capacity = 2 * (hi - lo)];
	length = 0;
	for (int i = lo; i < hi; i++){
		thisVector[length++] = target[i];
	}
}

//遍历向量（使用函数指针，只读或局部性修改）
template <class T> void ArrayDSA<T>::traverse(void(*visit) (T&)) //借助函数指针机制
{
	for (int i = 0; i < length; i++) visit(thisVector[i]);
}

//遍历向量（使用函数对象，可全局性修改）
template <class T> template <typename VST> //元素类型、操作器
void ArrayDSA<T>::traverse(VST& visit) //借助函数对象机制
{
	for (int i = 0; i < length; i++) visit(thisVector[i]);
}


//重载[]运算符，可以像数组那样直接获取元素
template <class T>T ArrayDSA<T>::operator[](Rank r){
	return thisVector[r];
}

//template <class T> T ArrayDSA<T>::operator=(){
//
//}

//扩容
template<class T> void ArrayDSA<T>::extend(){
	if (length == capacity){

		T* oldV = thisVector;
		thisVector = new T[capacity <<= 1];
		for (int i = 0; i < length; i++)
		{
			thisVector[i] = oldV[i];
		}
		delete[] oldV;
	}
	else{ return; }
}