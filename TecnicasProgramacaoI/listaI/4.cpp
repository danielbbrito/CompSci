#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

class Ponto
{   
    public:

        int x;
        int y;

        Ponto(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
};

class Poligono
{
    private:
        vector<Ponto> pontos;

    public:
        double dist(Ponto p1, Ponto p2)
        {
            return sqrt(pow(p2.x - p1.x, 2) - pow(p2.y - p1.y, 2));
        }

        double calculaPerimetro()
        {
            double perimetro = 0;

            for (size_t i = 0; i < pontos.size(); i++)
            {
                perimetro += dist(pontos[i], pontos[i + 1]) % pontos.size();
            }
        }
};