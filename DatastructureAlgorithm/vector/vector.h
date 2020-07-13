#pragma once
typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T>
class vector 
{
protected:
	Rank _size;int _capacity;T *_elem;//因为下面要用new的方式申请内存，所以是指针；
	void copyFrom(T const * A, Rank lo, Rank hi);//T const * A 
	void expand();
	void shrink();
	void bubbleSort(Rank lo, Rank hi);
	Rank Max(Rank lo, Rank hi);
	void SelectionSort(Rank lo, Rank hi);
	void merge(Rank lo, Rank hi);
	void mergeSort(Rank lo, Rank hi);
	void heapSort(Rank lo, Rank hi);
	void partition(Rank lo, Rank hi);
	void quickSort(Rank lo, Rank hi);
	void shellSort(Rank lo, Rank hi);
public:
//constructor;
	vector(T v, int s=0, int c=DEFAULT_CAPACITY)//default parameter must set end parameter list;
	{
		_elem = new T[c = DEFAULT_CAPACITY];
		for (_size = 0; _size < s; _size++)
		{
			_elem[_size] = v;
		}
	}
	vector(T const*A, Rank n) { copyFrom(A, 0, n); }//all copy
	vector(T const*A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }//part copy
	vector(vector<T> const &A, Rank lo, Rank hi) { copyFrom(A._elem, lo, hi); }
	vector(vector<T> const &A, Rank n) { copyFrom(A._elem, 0, n); }
	~vector() { delete[] _elem; }
//read only interface	
	Rank size() const { return _size; }
	bool empty() const { return !_szie; }
	Rank find(T const &e, Rank lo, Rank hi) const;//unorder vector search
	Rank find(T const &e) const { return find(e, 0, _size); }
	Rank search(T const&e, Rank lo, Rank hi) const;
	Rank search(T const &e) const
	{
		return (0 >= _size) ? -1; search(e, 0, _size);
	};//ordered vector search

//write and read interface
	T & operator[](Rank r);//reload the []
	const T & operator[](Rank r)const;
	T remove(Rank r);
	int remove(Rank lo, Rank hi);
	Rank insert(Rank r, T const&e);
	Rank insert(T const&e) { return insert(_size, e); }
	void sort(Rank lo, Rank hi);//对区间[lo,hi)排序
	void sort() { sort(0, _size); }
	void unsort(Rank lo, Rank hi);
	void unsort() { unsort(0, _size); }
	int deduplicate();//无序去重
	int uniquify();//有序去重
//traverse
	void traverse(void(*) (T&));//traverse by pointer
	template<typename VST> void traverse(VST&);//函数对象，可全局性修改
};
template <typename T>
Rank vector<T>::find(T const &e, Rank lo, Rank hi) const
{
	if (lo >= hi)
	{	
		return -1;
	}

}