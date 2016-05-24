/* MANTAS */

#pragma once

#include <array>

class Matrix2D{
protected:
	std::array<std::array<int, 3>, 3> matrix;
public:
	Matrix2D();
	//Matrix2D();
	~Matrix2D();
};

