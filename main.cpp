#include <iostream>
#include <fstream>

int main()
{



int alloc[5][3];
int max[5][3];

int available[3] = {3,3,2};
int n = 5;
int m = 3;


std::ifstream input;
input.open("input.txt");
if(input.is_open())
{
        for(int j = 0; j < 5; ++j)
        {
            for(int k = 0; k < 3; ++k)
            {
                input >> alloc[j][k];
                
            }
        }

        for(int x = 0; x < 5; ++x)
        {
            for(int y = 0; y < 3; ++y)
            {
                input >> max[x][y];
            }
        }
}

int f[n], ans[n], index = 0;
for (int k = 0; k < n; ++k)
{
    f[k] = 0;
}

int need[n][m];
for (int i = 0; i < n; ++i)
{
    for(int j = 0; j < m; ++j)
        need[i][j] = max[i][j] - alloc[i][j];
}


for(int x = 0; x < 5; ++x)
{
    for(int y = 0; y < n; ++y)
    {
        if(f[y] == 0)
        {
            int flag = 0;

            for (int z = 0; z < m; ++z)
            {
                if(need[y][z] > available[z])
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                ans[index++] = y;
                for (int f = 0; f < m; ++f)
                {
                    available[f] += alloc[y][f];
                }
                f[y] = 1;
            }
        }
    }
}


std::cout << "This is the Safe sequence" << '\n';
for(int i = 0; i < n - 1; ++i)
{
    std::cout << " P" << ans[i] << "->";
}
std::cout << " P" <<ans[n - 1] << '\n';



//Testing Lines
/*
std::cout << alloc[0][1];
std::cout << alloc[1][1];
std::cout << alloc[2][1];
std::cout << alloc[3][1];
std::cout << alloc[4][1] << '\n';

std::cout << alloc[0][2];
std::cout << alloc[1][2];
std::cout << alloc[2][2];
std::cout << alloc[3][2];
std::cout << alloc[4][2] << '\n';

std::cout << max[0][0];
std::cout << max[1][0];
std::cout << max[2][0];
std::cout << max[3][0];
std::cout << max[4][0] << '\n';

std::cout << max[0][1];
std::cout << max[1][1];
std::cout << max[2][1];
std::cout << max[3][1];
std::cout << max[4][1];
*/

input.close();
}