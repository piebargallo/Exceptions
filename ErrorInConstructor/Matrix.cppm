module;

#include <cstddef>

export module matrix;

import <iostream>;
import <new>;
import <exception>;

export template <typename T>
class Matrix
{
public:
	Matrix(size_t width, size_t height);
	virtual ~Matrix();
private:
	void cleanup();

	size_t m_width{ 0 };
	size_t m_height{ 0 };
	T** m_matrix{ nullptr };
};

