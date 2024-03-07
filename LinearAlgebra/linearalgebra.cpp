#include "linearalgebra.h"

Matrix::Matrix(int rows, int columns)
{
    this->m_rows = rows;
    this->m_columns = columns;
    
    m_matrix.resize(m_rows);

    for (int i = 0; i < m_rows; i++)
    {
        m_matrix[i].resize(columns, 0);
    }
}
Matrix::Matrix(int rows, int columns, double initial)
{
    this->m_rows = rows;
    this->m_columns = columns;
    
    m_matrix.resize(rows);

    for (int i = 0; i < m_rows; i++)
    {
        m_matrix[i].resize(columns, initial);
    }
}
Matrix::Matrix(const Matrix& m)
{
    m_rows = m.m_rows;
    m_columns = m.m_columns;

    m_matrix = m.m_matrix;
}


void Matrix::printMatrix()
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j <= m_columns; j++)
        {
            if (j == m_columns)
                printf("|");
            else if (j != 0)
                printf(" %.1f", m_matrix[i][j]);
            else
                printf("|%.1f", m_matrix[i][j]);
        }

        printf("\n");
    }

    return;
}

void Matrix::setValues()
{
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_columns; j++)
            std::cin >> m_matrix[i][j];
}

void Matrix::setElementValue(int pos_i, int pos_j, double value)
{
    m_matrix[pos_i][pos_j] = value;
}

Matrix Matrix::operator+(const Matrix m)
{
    if (m_matrix.size() != m.m_matrix.size())
        throw std::invalid_argument("Não é possível somar matrizes de dimensões diferentes.");

    Matrix sum(m_rows, m_columns);

    for (int i = 0; i < m_matrix.size(); i++)
        for (int j = 0; j < m_matrix[0].size(); j++)
            sum.m_matrix[i][j] = m_matrix[i][j] + m.m_matrix[i][j];

    return sum;
}

Matrix Matrix::operator-(const Matrix m)
{
    if (m_matrix.size() != m.m_matrix.size() 
    || m_matrix[0].size() != m.m_matrix[0].size())
        throw std::invalid_argument("Não é possível subtrair matrizes de dimensões diferentes.");

    Matrix sum(m_rows, m_columns);

    for (int i = 0; i < m_matrix.size(); i++)
        for (int j = 0; j < m_matrix[0].size(); j++)
            sum.m_matrix[i][j] = m_matrix[i][j] - m.m_matrix[i][j];

    return sum;
}

void Matrix::operator*(const double n)
{
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_columns; j++)
            m_matrix[i][j] *= n;

    
}

Matrix Matrix::operator*(const Matrix m)
{
    if (m_columns != m.m_rows)
        throw("Não é possível realizar a multiplicação de matrizes, verifique as dimensões");

    Matrix mult(m_rows, m.m_columns);

    const int k = m_columns; 

    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m.m_columns; j++)
            for (int l = 0; l < k; l++)
                mult.m_matrix[i][j] += m_matrix[i][l] * m.m_matrix[l][j];

    return mult;
}

std::vector<double> Matrix::operator[](int pos)
{
    return m_matrix[pos];
}

void Matrix::operator=(Matrix other)
{
    m_rows = other.m_rows;
    m_columns = other.m_columns;

    m_matrix = other.m_matrix;
}

// End matrix methods

Vector::Vector(int size)
{
    v_vector = new double[size];    
    v_sz = size;
}

Vector::Vector(int size, double initial)
{
    v_vector = new double[size];
    v_sz = size;

    for (int i = 0; i < size; i++)
        v_vector[i] = initial;
}

double Vector::dotProduct(Vector& u, Vector& v)
{
    int v_sz = std::max(u.size(), v.size());
    double dotproduct = 0;

    for (int i = 0; i < v_sz; i++)
        dotproduct += u.v_vector[i % u.size()] * v.v_vector[i % v.size()];

    return dotproduct; 
}

void Vector::printVector()
{
    printf("<");

    if (v_sz) printf("%.1f", v_vector[0]);

    for (int i = 1; i < v_sz; i++)
        printf(", %.1f", v_vector[i]);

    printf(">");
    return;
}

void Vector::printVector(Vector v)
{
    printf("<");

    if (v.size()) printf("%.1f", v.v_vector[0]);

    for (int i = 1; i < v.size(); i++)
        printf(", %.1f", v.v_vector[i]);

    printf(">");
    printf("\n");
    return;
}

void Vector::operator=(Vector other)
{
    v_sz = other.v_sz;
    delete v_vector;
    v_vector = new double[v_sz];

    for (int i = 0; i < v_sz; i++)
        v_vector[i] = other.v_vector[i];

}

double Vector::operator[](int pos)
{
    return v_vector[pos];
}
double Vector::operator*(Vector other)
{
    return dotProduct(*this, other);
}

Vector Vector::operator*(double a)
{
    Vector scalarMultiplied(v_sz);
    for (int i = 0; i < v_sz; i++)
        scalarMultiplied.setValue(i, v_vector[i] * a);

    return scalarMultiplied;
}

Vector Vector::operator+(Vector other)
{
    if (size() != other.size())
        throw("Não é possível realizar a adição de dois vetores de tamanhos diferentes.");

    Vector d(size());
    for (int i = 0; i < size(); i++)
        d.v_vector[i] = v_vector[i] + other.v_vector[i];

    return d;
}

Vector Vector::operator-(Vector other)
{
    if (size() != other.size())
        throw("Não é possível realizar a adição de dois vetores de tamanhos diferentes.");

    Vector d(size());
    for (int i = 0; i < size(); i++)
        d.v_vector[i] = v_vector[i] - other.v_vector[i];

    return d;
}

void gaussianEliminate(Matrix& A, Vector& b)
{
    for (int i = 0; i < A.columns(); i++)
    {
        continue; // TODO
    }
}

int main()
{
    Vector v(3);

    for (int i = 1; i <= 3; i++)
        v.setValue(i-1, i);

    v = v * 2;
    v.printVector();
}