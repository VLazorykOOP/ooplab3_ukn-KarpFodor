#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include<cassert>
#include <array>
#include <math.h>
#if !defined(CODING_VS_CODE)
#include <clocale>
#endif


using namespace std;

class Rhombus {
private:
	double side;
	double diagonal_less = -1;
	double diagonal_greater = -1;
	unsigned int color;


public:
	void setColor(unsigned int color) {
		assert(color >= 0 && "Color must be greater or equal than 0");
		this->color = color;
	}

	void setSide(double side, unsigned int color)
	{
		assert((side > 0) && "side square must be a positive numbers");
		this->side = side;
	}

	void setDiagonals(double diagonal_greater, double diagonal_less)
	{
		assert((diagonal_greater == sqrt(4 * side * side - diagonal_less * diagonal_less)) && (diagonal_less == sqrt(4 * side * side - diagonal_less * diagonal_greater)) && "incorrect values");
		this->diagonal_greater = diagonal_greater;
		this->diagonal_less = diagonal_less;
	}

	unsigned int getColor() {
		return this->color;
	}

	double getSide()
	{
		return side;
	}


	Rhombus() : side(1.0), color(0) {
		cout << endl << "created Rhombus with side = 1.0 and color = 0" << endl;
	}

	Rhombus(double side, unsigned int color) {
		assert((side > 0) && "side Rhombus must be a positive numbers");
		assert(color >= 0 && "Color must be greater or equal than 0");
		this->side = side;
		this->color = color;
	}

	Rhombus(double side, double diagonal_greater, double diagonal_less, unsigned int color) {
		assert((side > 0) && "side Rhombus must be a positive numbers");
		assert(color >= 0 && "Color must be greater or equal than 0");
		this->side = side;
		this->color = color;
		this->diagonal_greater = diagonal_greater;
		this->diagonal_less = diagonal_less;
	}


	Rhombus(double side) :Rhombus(side, 0) {}

	double area() {
		if ((diagonal_greater == -1) && (diagonal_less == -1))
		{
			cout << "diagonals is not install" << endl;
			return 0;
		}
		else
		{
			return (0.5 * diagonal_greater * diagonal_less);
		}
	}

	double perimeter() {
		return side * 4;



	}


	void showInfo() {
		cout << "--------------------\n\tColor = " << this->color << "\n";
		cout << "\tSide: " << this->side
			<< "\n\tDiagonal_greater: " << this->diagonal_greater
			<< "\n\tDiagonal_less: " << this->diagonal_less
			<<
			"\n--------------------\n";
	}


};


int mainExample11() {

	cout << "TASK 1.6 class Rhombus\n";

	cout << endl << "Rhombus romb1(5, 6.5028784015, 4.8717451246, 6);\n";
	Rhombus romb1(5, 6.5028784015, 4.8717451246, 6);

	cout << "rhombus.area()      =  " << romb1.area() << "\n";

	cout << "rhombus.perimeter() = " << romb1.perimeter() << "\n";

	cout << "Used method : getSide():" << romb1.getSide() << endl;

	cout << "Used method : getColor():" << romb1.getColor() << endl;

	cout << "Used method : showInfoAboutSquare()\n";
	romb1.showInfo();

	cout << endl << "Rhombus rhombStandart;\n";
	Rhombus rhombStandart;

	cout << "rhombStandart.area() = " << rhombStandart.area() << "\n";

	cout << "rhombStandart.perimeter() = " << rhombStandart.perimeter() << "\n";

	cout << "Used method : getSide():" << rhombStandart.getSide() << endl;

	cout << "Used method : getColor():" << rhombStandart.getColor() << endl;

	cout << "Used method : showInfo()\n";
	rhombStandart.showInfo();
	return 1;
}

enum STATE {
	OK, ZERO_VECTOR, NEGATIVE_SIZE, BAD_INIT, BAD_DIV, OUT_OF_RANGE
};


class VECTOR {
private:
	float x, y, z;
	string state;

public:
	VECTOR() {
		x = 0;
		y = 0;
		z = 0;
	}
	VECTOR(float A) {
		x = A;
		y = A;
		z = A;
	}
	VECTOR(float* Mass) {
		if (Mass == nullptr) {
			state = "ERROR CODE[0001]";
			cout << state << endl;
		}
		else {
			x = Mass[0];
			y = Mass[1];
			z = Mass[2];
		}
	}
	VECTOR(const VECTOR& EX) {
		x = EX.x;
		y = EX.y;
		z = EX.z;
		state = EX.state;
	}


	void showAll() { cout << x << "   " << y << "   " << z << endl; }
	void SetRandom(float a = 10, float b = 3, float c = 7) {
		x = a;
		y = b;
		z = c;
	}
	float GetRandom() {
		int random;
		random = rand() % 100 + 1;

		if (random < 33)return x;
		else if (66 > random > 33) return y;
		else return z;

	}
	void Plus(const VECTOR& other) {
		x = x + other.x;
		y = y + other.y;
		z = z + other.z;
	}
	void Minus(const VECTOR& other) {
		x = x - other.x;
		y = y - other.y;
		z = z - other.z;
	}
	void VProduct(const VECTOR& other) {
		x = (y * other.z) - (z * other.y);
		y = (x * other.z) - (z * other.x);
		z = (x * other.y) - (y * other.x);
	}
	void Division_short(short int A) {
		float x1, y1, z1;
		if (A != 0) {
			x1 = x / A;
			y1 = y / A;
			z1 = z / A;
			x = x1;
			y = y1;
			z = z1;
		}
		else { state = "ERROR CODE [0002]"; }
		cout << state << endl;
	}
	bool Bilshe(const VECTOR& other) {
		if (x > other.x && y > other.y && z > other.z)return 1;
		else return 0;
	}
	bool Menshe(const VECTOR& other) {
		if (x < other.x && y < other.y && z < other.z)return 1;
		else return 0;
	}
	bool Rivno(const VECTOR& other) {
		if (x == other.x && y == other.y && z == other.z)return 1;
		else return 0;
	}


	VECTOR& operator = (const VECTOR& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		state = other.state;
		return *this;
	}
	~VECTOR() {
		cout << "Destruct...| State vector: " << state << this << endl;
	}
};


void mainExample22() {
	cout << "\nTASK 2.6:\n";
	cout << "float rvariabl; \n float* arrry = nullptr; \n float arr[]{ 4.5,23.5,63.2 };" << endl;

	float rvariabl;
	float* arrry = nullptr;
	float arr[]{ 4.5,23.5,63.2 };
	VECTOR vector(arr);
	cout << "VECTOR vector(arr);\n";
	cout << "vector.showAll();\n\n";
	vector.showAll();

	cout << "rvariabl = vector.GetRandom();\n";
	rvariabl = vector.GetRandom();
	cout << "rvariabl = " << rvariabl << endl;


	cout << "VECTOR vector2(vector), Killa;" << endl;
	VECTOR vector2(vector), Killa;

	cout << "vector2.showAll();" << endl;
	vector2.showAll();

	cout << "vector2.GetRandom(); = ";
	cout << vector2.GetRandom() << endl;

	cout << "Killa = vector2;" << endl;
	Killa = vector2;
	cout << "Killa.Plus(vector2); Killa.showAll();" << endl;
	Killa.Plus(vector2);
	Killa.showAll();

	cout << "vector2.SetRandom(); " << endl;
	vector2.SetRandom();

	cout << "Killa.VProduct(vector2); Killa.showAll();" << endl;
	Killa.VProduct(vector2);
	Killa.showAll();

	cout << "Killa.Minus(vector2); Killa.showAll();" << endl;
	Killa.Minus(vector2);
	Killa.showAll();
	short int t = 10;

	cout << "Killa.Division_short(10); \n Killa.showAll();" << endl;
	Killa.Division_short(t);
	Killa.showAll();

	cout << "if (vector2.Menshe(vector)) cout << 'yes' " << endl;;
	if (vector2.Menshe(vector)) cout << "yes" << endl;

}

class Matrix {
private:
	double** matrix = nullptr;
	int row;
	int col;

public:
	Matrix();
	Matrix(int size);
	Matrix(int row, int col, double value);
	Matrix(const Matrix& copy);
	Matrix& operator=(const Matrix& assign);
	Matrix operator+(const Matrix& addition);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator*(const int scalar);
	~Matrix() {
		cout << "DESTRUCT" << endl;
		for (int count = 0; count < row; ++count)
		{
			delete[] matrix[count];
		}
		delete[] matrix;
	}

	int getElementMatrix(int row, int col);

	bool isIndexIncludedMatrix(int row, int col);

	void setElementMatrix(int row, int col, double value);
	void showInfo();
};

Matrix::Matrix() : Matrix(3, 3, 0) {}
Matrix::Matrix(int size) : Matrix(size, size, 0) {
	assert(size >= 0 && "size must be > 0");
}

Matrix::Matrix(int row, int col, double value) {
	assert((row > 0 || col > 0) && "row, col must be > 0");

	this->row = row;
	this->col = col;
	matrix = new double* [row];
	for (int count = 0; count < row; ++count)
	{
		matrix[count] = new double[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = value;
		}
	}

}

Matrix::Matrix(const Matrix& copy)
{
	if (this == &copy) return;
	row = copy.row;
	col = copy.col;
	matrix = new double* [row];
	for (int count = 0; count < row; ++count)
	{
		matrix[count] = new double[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = copy.matrix[i][j];
		}
	}
}

Matrix& Matrix::operator=(const Matrix& assign) {
	if (row != assign.row || col != assign.col)
	{
		for (int count = 0; count < row; ++count)
		{
			delete[] matrix[count];
		}
		delete[] matrix;

		row = assign.row;
		col = assign.col;
		matrix = new double* [row];
		for (int count = 0; count < row; ++count)
		{
			matrix[count] = new double[col];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = assign.matrix[i][j];
			cout << this->matrix[i][j] << " ";
		}
	}

	return *this;
}

Matrix Matrix::operator+(const Matrix& addition) {
	if (row == addition.row && col == addition.col)
	{
		Matrix temp(row, col, 0);

		for (int i = 0; i < temp.row; i++)
		{
			for (int j = 0; j < temp.col; j++)
			{
				temp.matrix[i][j] = matrix[i][j] + addition.matrix[i][j];
			}
		}
		return temp;
	}
	else
	{
		cout << endl << "Matriñes have different sizes" << endl;
		cout << "will be returned zero matrix[1][1]" << endl;
		Matrix zeroMatrix(1);
		return zeroMatrix;
	}
}

Matrix Matrix::operator-(const Matrix& subtract) {
	if (row == subtract.row && col == subtract.col)
	{
		Matrix temp(row, col, 0);

		for (int i = 0; i < temp.row; i++)
		{
			for (int j = 0; j < temp.col; j++)
			{
				temp.matrix[i][j] = matrix[i][j] + subtract.matrix[i][j];
			}
		}
		return temp;

	}
	else
	{
		cout << endl << "Matriñes have different sizes" << endl;
		cout << "will be returned zero matrix[1][1]" << endl;
		Matrix zeroMatrix(1);
		return zeroMatrix;
	}
}

Matrix Matrix::operator*(const Matrix& multiply) {
	if (col == multiply.row)
	{
		Matrix temp(row, multiply.col, 0);

		for (int i = 0; i < temp.row; i++)
		{
			for (int j = 0; j < temp.col; j++)
			{
				for (int inner = 0; inner < col; inner++)
				{
					temp.matrix[i][j] += matrix[i][inner] * multiply.matrix[inner][j];
				}

			}
		}
		return temp;

	}
	else
	{
		cout << endl << "Matriñes cannot be multiply" << endl;
		cout << "will be returned zero matrix[1][1]" << endl;
		Matrix zeroMatrix(1);
		return zeroMatrix;
	}
}


Matrix Matrix::operator*(const int scalar) {
	Matrix temp(row, col, 0);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.matrix[i][j] += matrix[i][j] * scalar;
		}
	}
	return temp;
}

bool Matrix::isIndexIncludedMatrix(int row, int col) {
	if ((row >= 0) && (row < this->row) && (col >= 0) && (col < this->col))
	{
		return true;
	}
	else
	{
		cout << endl << "!ERROR: Array index is out of range\n";
		return false;
	}
}

void Matrix::setElementMatrix(int row, int col, double value = 0) {
	if (isIndexIncludedMatrix(row, col))
	{
		matrix[row][col] = value;
	}
}

int Matrix::getElementMatrix(int row, int col) {
	assert(isIndexIncludedMatrix(row, col));
	return matrix[row][col];
}



void Matrix::showInfo() {
	for (int i = 0; i < row; i++)
	{
		cout << endl;
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
	}
	cout << endl;
}


void mainExample33() {

	cout << "\tStart TASK 3.6\n";
	cout << endl << "Matrix standartMatrix; /// standartMatrix.showInfo();";
	Matrix standartMatrix;
	standartMatrix.showInfo();

	cout << endl << "Matrix matrix_one(2, 3, 13.21);\nmatrix_one.showInfo();";
	Matrix matrix_one(2, 3, 13.21);
	matrix_one.showInfo();

	cout << endl << "Matrix matrix_second(3, 2, 3.9);\nmatrix_second.showInfo();";
	Matrix matrix_second(3, 2, 3.9);
	matrix_second.showInfo();

	cout << endl << "Matrix multiply = matrix1 * matrix2;\multiply.showInfo();";
	Matrix multiply = matrix_one * matrix_second;
	multiply.showInfo();

	matrix_one.setElementMatrix(1, 0, 3);
	cout << endl << "matrix_one.setElementMatrix(1, 0, 3);\nmatrix_one.showInfo();";
	matrix_one.showInfo();

	cout << endl << "///matrix_one.getElementMatrix(1, 0) -> ";
	cout << matrix_one.getElementMatrix(1, 0) << endl;

	cout << endl << "Matrix multiplyScalar = matrix1 * 3;;\multiplyScalar.showInfo();";
	Matrix multiplyScalar = matrix_one * 3;
	multiplyScalar.showInfo();


	cout << endl << "Matrix assign =  matrix_one;\nassign1.showInfo(); ";
	Matrix assign = matrix_one;
	assign.showInfo();

	cout << endl << "Matrix addition = assign + matrix_one;\naddition.showInfo();";
	Matrix addition = assign + matrix_one;
	addition.showInfo();




}

////////////////////////////////////////////////
int main()
{
	std::cout << " Lab #3  !\n";

	mainExample11();
	std::cout << "///end task1///" << std::endl;

	mainExample22();
	std::cout << "///end task2///" << std::endl;

	mainExample33();
	std::cout << "///end task3///" << std::endl;
}