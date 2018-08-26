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

//指定位置插入元素
template <class T> Rank ArrayDSA<T>::insertItem(Rank r, T ele){
	extend();//扩容

	for (int i = length-1; i >= r; i--)
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
	while(lo<hi)
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
	return findRank(target, 0, length - 1);
}

//无序去重
template <class T> int ArrayDSA<T>::deduplicated(){
	int deleteNum = 0;
	for (Rank i = 0; i < length;i++){
		for (Rank j = i+1; j < length;j++){
			if (thisVector[i]==thisVector[j]){
				  deleteItem(j);
				  deleteNum++;
			}
		}
	}
	return deleteNum;
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
	/*DSA*/ //selectionSort(lo, hi);
	bubbleSort(lo, hi);
}

//对整体排序
template <class T> void ArrayDSA<T>::sort(){
	sort(0, length - 1);
}

//从目标数组中复制一段
template <class T> void ArrayDSA<T>::copy(const T * const target, Rank lo, Rank hi){
	thisVector = new T[capacity = 2 * (hi - lo)];
	length = 0;
	for (int i = lo; i < hi; i++){
		thisVector[length++] = target[i];
	}
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





//重载[]运算符，可以像数组那样直接获取元素
template <class T>T ArrayDSA<T>::operator[](Rank r){
	return thisVector[r];
}

//template <class T> T ArrayDSA<T>::operator=(){
//
//}

template<class T> void ArrayDSA<T>::extend(){
	if (length == capacity){

		T* oldV = thisVector;
		thisVector = new T[capacity <<= 1];
		for (int i = 0; i < length; i++)
		{
			thisVector[i] = oldV[i];
		}
		delete [] oldV;
	}
	else{ return; }
}