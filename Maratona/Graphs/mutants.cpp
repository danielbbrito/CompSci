#include <bits/stdc++.h>
using namespace std;

int lastRow;
int lastCol;
bool lost[51][51];

class Robot
{
    public:
        int startRow;
        int startCol;
        int startDir;
        string instructions;
        map<char, int> directions {
            {'N', 1},
            {'E', 2},
            {'S', 3},
            {'W', 4}
        };
        int moveBot()
        {
            if (startDir == 1)
            {
                if (startRow + 1 > lastRow)
                    return -1;
                startRow++;
            }
            
            else if (startDir == 2)
            {
                if (startCol + 1 > lastCol)
                    return -1;
                startCol++;
            }

            else if (startDir == 3)
            {
                if (startRow - 1 < 0)
                    return -1;
                startRow--;
            }

            else if (startDir == 4)
            {
                if (startCol - 1 < 0)
                    return -1;
                startCol--;
            }

            return 1;
        }

        void changeDirection(char m)
        {
            if (m == 'R')
                startDir = (startDir + 1) % 4;
            
            else
                startDir = (startDir - 1) % 4;

            if (startDir <= 0)
                startDir += 4;
        }


};

int main()
{
    map<int, char> directionsR {
            {1,'N'},
            {2,'E'},
            {3,'S'},
            {4,'W'}
        };
    cin >> lastCol >> lastRow;

    Robot robot;
    char dir;
    memset(lost, false, sizeof(lost));
    while (cin >> robot.startCol >> robot.startRow >> dir)
    {
        robot.startDir = robot.directions[dir];
        cin.ignore();
        getline(cin, robot.instructions);
        int status = 1;
        for (int i = 0; i < robot.instructions.length(); i++)
        {
            if (robot.instructions[i] == 'F')
                status = robot.moveBot();
            else
                robot.changeDirection(robot.instructions[i]);

            if (status == -1 && !lost[robot.startCol][robot.startRow])
                break;
        }

        cout << robot.startCol << ' ' << robot.startRow << ' ' << directionsR[robot.startDir];

        if (status == -1)
        {
            cout << " LOST";
            lost[robot.startCol][robot.startRow] = true;
        }

        cout << endl;
    }

    return 0;
}