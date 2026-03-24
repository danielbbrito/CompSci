#include <bits/stdc++.h>

using namespace std;

#define MATRIX vector<vector<double>>
#define VECTOR vector<double>
#define INDEX  vector<int>

pair<pair<MATRIX, MATRIX>, vector<int>> lu_decomp_pivoting(MATRIX A)
{
    int m = A.size();
    MATRIX L(m, VECTOR(m, 0));
    vector<int> pivots;
    for (int i = 0; i < m; i++)
        pivots.push_back(i);

    for (int i = 0; i < m; i++)
        L[i][i] = 1;

    for (int i = 0; i < m - 1; i++)
    {
        // Antes da eliminação Gaussiana vamos verificar a troca de linhas
        int p = i;
        double Amax = abs(A[i][i]);

        for (int j = i + 1; j < m; j++)
        {
            if (abs(A[j][i]) > Amax)
            {
                Amax = abs(A[j][i]);
                p = j;
            }

        }

        if (p != i)
        {
            // Realizamos a troca de linhas
            swap(A[i], A[p]);
            swap(pivots[i], pivots[p]);
        }
        
        if (abs(A[i][i]) > 1e-14)
        {
            double r = 1 / A[i][i];
            for (int j = i + 1; j < m; j++)
            {
                double multiplier = A[j][i] * r;
                L[j][i] = multiplier;
                A[j][i] = 0;

                for (int k = i + 1; k < m; k++)
                    A[j][k] -= multiplier * A[i][k]; 
            }
        }
    }

    return {{L, A}, pivots};
}

VECTOR solveLU(MATRIX L, MATRIX U, VECTOR b, vector<int> p)
{
    VECTOR x(U.size(), 0);
    VECTOR c(b.size(), 0);
    // Trocar linhas em b se necessário
    c[0] = b[p[0]];

    for (int i = 1; i < L.size(); i++)
    {
        double soma = 0.0;

        for (int j = 0; j < i; j++)
            soma += L[i][j] * c[j];

        c[i] = b[p[i]] - soma;
    }

    int m = U.size();

    if (abs(U[m - 1][m - 1]) < 1e-12)
    {

        if (abs(c[m - 1]) < 1e-12)
        {
            printf("Atencao, existem infinitas solucoes\n");
            x[m - 1] = 0;
        }
        else
            return VECTOR{};
    }

    else
        x[m - 1] = c[m - 1] / U[m - 1][m - 1];

    for (int i = m - 2; i >= 0; i--)
    {
        double soma = 0;

        for (int j = i + 1; j < m; j ++)
            soma += U[i][j] * x[j];
        
        if (abs(U[i][i]) < 1e-12)
            return VECTOR{};

        x[i] = (c[i] - soma) / U[i][i];
    }

    return x;
}

VECTOR solve(MATRIX A, VECTOR b)
{
    pair<pair<MATRIX, MATRIX>, vector<int>> LU = lu_decomp_pivoting(A);
    return solveLU(LU.first.first, LU.first.second, b, LU.second);
}
MATRIX tranpose(MATRIX A)
{
    MATRIX At = A;
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A[0].size(); j++)
            At[i][j] = A[i][j];

    return At;
}

double dot(VECTOR a, VECTOR b)
{
    if (a.size() != b.size())
        throw invalid_argument("");

    double ans = 0;

    for (int i = 0; i < a.size(); i++)
        ans += a[i] * b[i];

    return ans;
}

MATRIX transpose(const MATRIX& M)
{
    int rows = M.size();
    int cols = M[0].size();

    MATRIX T(cols, VECTOR(rows));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            T[j][i] = M[i][j];

    return T;
}

class Simplex {
    private:
        MATRIX A;
        VECTOR x;
        MATRIX B;
        MATRIX N;
        VECTOR b;
        INDEX Ib;
        INDEX In;
        int m;
        int n;

        VECTOR get_column(const MATRIX& A, int j)
        {
            int m = A.size();
            VECTOR col(m);

            for (int i = 0; i < m; i++)
                col[i] = A[i][j];

            return col;
        }

        VECTOR phase_one()
        {
            // Inicializamos e populamos a matriz aumentada [A|I] e o vetor de variáveis de decisão xa
            MATRIX AI(m, VECTOR(n + m, 0.0));
            VECTOR xa(n + m, 0.0);
            VECTOR c(n + m, 0.0);
            VECTOR cB(m);
            VECTOR y, xB;
            VECTOR s(n + m, 0.0);

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    AI[i][j] = A[i][j];
                }
            }

            for (int i = 0; i < m; i++)
                AI[i][n + i] = 1;


            for (int i = 0; i < m; i++)
                xa[n + i] = b[i];

            for (int i = 0; i < m; i++)
                Ib[i] = n + i;
            
            In.resize(n);
            for (int j = 0; j < n; j++)
                In[j] = j;

            for (int i = n; i < n + m; i++)
                c[i] = 1;

            for (int i = 0; i < m; i++)
                cB[i] = c[Ib[i]];
            
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    B[i][j] = AI[i][Ib[j]];
                }
            }


            while (true)
            {
                y = solve(transpose(B), cB);

                bool stop = true;
                // Calculamos o vetor custo reduzido s e verificamos se temos uma solução ótima
                for (int i = 0; i < m; i++)
                {
                    s[Ib[i]] = 0;
                }

                int entering = -1;

                for (int i = 0; i < In.size(); i++)
                {
                    s[In[i]] = c[In[i]] - dot(y, get_column(AI, In[i]));

                    if (s[In[i]] < 0)
                    {
                        entering = In[i];
                        stop = false;
                        break;
                    }
                    
                }

                if (stop)
                    break;

                // Calculamos o vetor direcao

                VECTOR direction = solve(B, get_column(AI, entering));

                xB = solve(B, b);

                double theta = 1e18;
                int leaving_index = -1;

                for (int i = 0; i < m; i++)
                {
                    if (direction[i] > 1e-12)
                    {
                        double ratio = xB[i] / direction[i];

                        if (ratio < theta)
                        {
                            theta = ratio;
                            leaving_index = i;
                        }
                    }
                }

                if (leaving_index == -1)
                {
                    throw runtime_error("Erro: problema ilimitado na fase I");
                }

                int leaving = Ib[leaving_index];

                // Atualiza solução básica
                for (int i = 0; i < m; i++)
                {
                    xB[i] = xB[i] - theta * direction[i];
                }
                xB[leaving_index] = theta;

                // Atualiza base
                Ib[leaving_index] = entering;

                for (int i = 0; i < In.size(); i++)
                {
                    if (In[i] == entering)
                    {
                        In[i] = leaving;
                        break;
                    }
                }

                // Atualiza B
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        B[i][j] = AI[i][Ib[j]];
                    }
                }

                // Atualiza cB
                for (int i = 0; i < m; i++)
                    cB[i] = c[Ib[i]];


            }

            // Verificamos a viabilidade
            xB = solve(B, b);

            double value = 0.0;
            for (int i = 0; i < m; i++)
                value += cB[i] * xB[i];

            if (value > 1e-8)
            {
                throw runtime_error("Problema inviável");
            }

            INDEX K;

            for (int i = 0; i < m; i++)
            {
                if (Ib[i] >= n)
                    K.push_back(Ib[i]);
            }

            INDEX newIn;

            for (int i = 0; i < In.size(); i++)
            {
                int var = In[i];

                if (var < n)
                {
                    newIn.push_back(var);
                }
                else
                {
                    bool inK = false;

                    for (int j = 0; j < K.size(); j++)
                    {
                        if (K[j] == var)
                        {
                            inK = true;
                            break;
                        }
                    }

                    if (inK)
                        newIn.push_back(var);
                }
            }

            In = newIn;

            int p = In.size();
            MATRIX D(m, VECTOR(p, 0.0));

            for (int j = 0; j < p; j++)
            {
                VECTOR col = get_column(AI, In[j]);
                VECTOR sol = solve(B, col);

                for (int i = 0; i < m; i++)
                    D[i][j] = sol[i];
            }

            for (int i = 0; i < m; i++)
            {
                if (Ib[i] >= n)
                {
                    // 🔥 RECONSTRUIR B antes de usar
                    for (int r = 0; r < m; r++)
                    {
                        for (int c = 0; c < m; c++)
                        {
                            B[r][c] = AI[r][Ib[c]];
                        }
                    }

                    // 🔥 RECALCULAR D com base atual
                    int p = In.size();
                    MATRIX D(m, VECTOR(p, 0.0));

                    for (int j = 0; j < p; j++)
                    {
                        VECTOR col = get_column(AI, In[j]);
                        VECTOR sol = solve(B, col);

                        for (int r = 0; r < m; r++)
                            D[r][j] = sol[r];
                    }

                    int found_j = -1;

                    for (int j = 0; j < In.size(); j++)
                    {
                        if (abs(D[i][j]) > 1e-8)
                        {
                            found_j = j;
                            break;
                        }
                    }

                    if (found_j == -1)
                    {
                        continue;
                    }

                    int ib = In[found_j];
                    int inb = Ib[i];

                    // atualizar base
                    Ib[i] = ib;

                    // 🔥 atualizar In corretamente
                    INDEX newIn2;

                    for (int k = 0; k < In.size(); k++)
                    {
                        if (In[k] != ib)
                            newIn2.push_back(In[k]);
                    }

                    newIn2.push_back(inb);

                    In = newIn2;
                }
            }


            In.clear();

            for (int j = 0; j < n; j++)
            {
                bool is_basic = false;

                for (int i = 0; i < m; i++)
                {
                    if (Ib[i] == j)
                    {
                        is_basic = true;
                        break;
                    }
                }

                if (!is_basic)
                    In.push_back(j);
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    B[i][j] = A[i][Ib[j]];
                }
            }

            xB = solve(B, b);
            return xB;
        }

    public:
        Simplex(MATRIX A, VECTOR b) {
            if (!A.size() || !b.size())
                throw invalid_argument("");
            this->A = A;
            this->b = b;
            this->m = A.size();
            this->n = A[0].size();
            x.resize(n, 0.0);
            B.resize(m, vector<double>(m, 0.0));
            N.resize(m, vector<double>(n, 0.0));
            Ib.resize(m, 0);
            In.resize(n, 0);
        }

        VECTOR solveSimplex()
        {
            return phase_one();
        }

        
        
};

int main()
{
    MATRIX A = {
        {1, 1, 1, 0, 1, 0},
        {1, 0, 0, 1, 0, 1}
    };

    VECTOR b = {2, 1};  
    int m = 2;          
    int n = 4;     

    try
    {
        Simplex s(A, b);
        VECTOR xB = s.solveSimplex(); // chama phase_one

        cout << "Fase I concluida com sucesso (problema viavel) com xB = [";
        cout << xB[0];
        for (int i = 1; i < xB.size(); i++)
        {
            cout << ", " << xB[i];
        }
        cout << "]" << endl;
    }
    catch (exception& e)
    {
        cout << "Erro: " << e.what() << endl;
    }

    return 0;

}