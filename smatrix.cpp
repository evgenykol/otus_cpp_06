#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <assert.h>

using namespace std;
using index = pair<int, int>;

template<typename T, T default_val = -1>
class SparseMatrix
{
	map<index, T> data; 
	T dafault_value = default_val;

public:
	SparseMatrix() {}
	~SparseMatrix() {}

	using iterator = typename map<index, T>::iterator;
	using const_iterator = typename map<index, T>::const_iterator;

	iterator begin()
	{
		return data.begin();
	}

	iterator end()
	{
		return data.end();
	}


	void SetElement(int row, int col, T val)
	{
		data[index(row, col)] = val;
	}

	T GetElement(int row, int col)
	{
		auto p = data.find(index(row, col));
		return (p == data.end()) ? dafault_value : p->second;
	}

	size_t Size()
	{
		return data.size();
	}

	// operator int ()
	// {
	// 	cout << "operator *" << endl;
	// 	return
	// }
};

void test()
{
	const int msize = 9;
	SparseMatrix<int, 0> matrix;

	for(int i = 0; i <= msize; ++i)
	{
		matrix.SetElement(i, i, i);
		matrix.SetElement(i, msize-i, msize-i);
	}

	for(int i = 1; i < msize; ++i)
	{
		for(int j = 1; j < msize; ++j)
		{
			cout << matrix.GetElement(i, j) << " ";
		}
		cout << endl;
	}

	cout << matrix.Size() << endl;

	for (auto c : matrix)
	{
		auto cc = make_tuple(c.first.first, c.first.second, c.second);
		int x;
		int y;
		int v;
		tie(x, y, v) = cc;
		cout << x << "," << y << " = " << v << endl;
	}

}

int main(int argc, char const *argv[])
{
	SparseMatrix<int, -1> matrix;
	assert(matrix.Size() == 0);

	auto a = matrix.GetElement(0, 0);
	assert(a == -1);
	assert(matrix.Size() == 0);

	matrix.SetElement(100, 100, 314);
	assert(matrix.GetElement(100, 100) == 314);
	assert(matrix.Size() == 1);

	for (auto c : matrix)
	{
		auto cc = make_tuple(c.first.first, c.first.second, c.second);
		int x;
		int y;
		int v;
		tie(x, y, v) = cc;
		cout << x << y << v << endl;
	}

	// for (auto c = matrix.begin(); c != matrix.end(); ++c)
	// {
	// 	cout << c->second << endl;
	// }

	cout << endl << endl;
	test();
	return 0;
}
