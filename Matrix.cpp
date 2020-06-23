#include <iostream>


class Matrix {
	int **m_Mx;
	int m_row;
	int m_col;

public:
	Matrix() 
	{
		m_Mx = nullptr;
		m_row = 0;
		m_col = 0;
	}

	Matrix(int m, int n) : m_row(m), m_col(n)
	{

		m_Mx = new int*[m_row];

		for (int i = 0; i < m_row; i++)
		{
			m_Mx[i] = new int[m_col];
		}

		for(int i=0; i<m_row; i++)
			for (int j = 0; j < m_col; j++)
			{
				m_Mx[i][j] = 0;
			}
	}

	~Matrix()
	{
		for (int i = 0; i < m_col; i++)
		{
		delete	m_Mx[i];
		}

		m_row = 0;
		m_col = 0;

		delete[] m_Mx;

		m_Mx = nullptr;
	}

	int* operator[](int index) const
	{
		if (index < m_row)
		{
			return m_Mx[index];
		}
		else
		{
			std::cerr << "\nRange out\n";
			return 0;
		}
	}

	void print() const
	{
		if (m_row == 0)
		{
			std::cout << "\nThis matrix is empty\n";
			return;
		}
		std::cout << std::endl;
		for (int i = 0; i < m_row; i++)
		{
			for (int j = 0; j < m_col; j++)
			{
				std::cout << m_Mx[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	const int getRow() const	{ return m_row; }

	const int getCol() const { return m_col; }

	Matrix(const Matrix& M)
	{
		m_row = M.m_row;
		m_col = M.m_col;
		m_Mx = new int* [m_row];

		for (int i = 0; i < m_row; i++)
		{
			m_Mx[i] = new int[m_col];
		}

		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
			{
				m_Mx[i][j] = M.m_Mx[i][j];
			}
	}

	Matrix(Matrix&& M)
	{
		m_row = M.m_row;
		m_col = M.m_col;
		m_Mx = M.m_Mx;

		M.m_row = 0;
		M.m_col = 0;
		M.m_Mx = nullptr;
	}

	Matrix& operator=(const Matrix& M)
	{
		if (this != &M)
		{
			
			for (int i = 0; i < m_col; i++)
			{
				delete	m_Mx[i];	//чистка
			}
			delete[] m_Mx;

			m_row = M.m_row;
			m_col = M.m_col;
			m_Mx = new int* [m_row];

			for (int i = 0; i < m_row; i++)
			{
				m_Mx[i] = new int[m_col];
			}

			for (int i = 0; i < m_row; i++)
				for (int j = 0; j < m_col; j++)
				{
					m_Mx[i][j] = M.m_Mx[i][j];
				}
		}
		return *this;
	}

	Matrix& operator=(Matrix&& M)
	{
		m_row = M.m_row;
		m_col = M.m_col;
		m_Mx = M.m_Mx;

		M.m_row = 0;
		M.m_col = 0;
		M.m_Mx = nullptr;

		return *this;
	}
};

int main()
{
	{
		Matrix M(3, 3);

		for (int i = 0; i < M.getRow(); i++)
		{
			for (int j = 0; j < M.getCol(); j++)
			{
				if (i == j) { M[i][j] = 1; }
			}
		}

		Matrix A(std::move(M));
		M.print();
		A.print();
	}


}