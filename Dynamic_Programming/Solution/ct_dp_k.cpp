#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TileCount
{
    int large;  // 2x4
    int medium; // 2x2
    int small;  // 1x1
    int waste;  // uncovered area

    TileCount(int l = 0, int m = 0, int s = 0, int w = 0)
        : large(l), medium(m), small(s), waste(w) {}
};

TileCount getBestTileFit(int length, int width)
{
    // Create a 2D grid representing the room
    vector<vector<bool>> room(length, vector<bool>(width, false));
    TileCount result;

    // First try to fit 2x4 tiles
    for (int i = 0; i < length - 1; i += 2)
    {
        for (int j = 0; j < width - 3; j += 4)
        {
            bool canFit = true;
            // Check if we can fit a 2x4 tile here
            for (int x = 0; x < 2 && canFit; x++)
            {
                for (int y = 0; y < 4 && canFit; y++)
                {
                    if (i + x >= length || j + y >= width || room[i + x][j + y])
                    {
                        canFit = false;
                    }
                }
            }

            if (canFit)
            {
                // Place the 2x4 tile
                for (int x = 0; x < 2; x++)
                {
                    for (int y = 0; y < 4; y++)
                    {
                        room[i + x][j + y] = true;
                    }
                }
                result.large++;
            }
        }
    }

    // Try to fit 2x2 tiles in remaining space
    for (int i = 0; i < length - 1; i += 2)
    {
        for (int j = 0; j < width - 1; j += 2)
        {
            bool canFit = true;
            // Check if we can fit a 2x2 tile here
            for (int x = 0; x < 2 && canFit; x++)
            {
                for (int y = 0; y < 2 && canFit; y++)
                {
                    if (i + x >= length || j + y >= width || room[i + x][j + y])
                    {
                        canFit = false;
                    }
                }
            }

            if (canFit)
            {
                // Place the 2x2 tile
                for (int x = 0; x < 2; x++)
                {
                    for (int y = 0; y < 2; y++)
                    {
                        room[i + x][j + y] = true;
                    }
                }
                result.medium++;
            }
        }
    }

    // Fill remaining spaces with 1x1 tiles
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (!room[i][j])
            {
                room[i][j] = true;
                result.small++;
            }
        }
    }

    return result;
}

int main()
{
    int length = 7, width = 9;

    TileCount result = getBestTileFit(length, width);

    cout << "Room size: " << length << "x" << width << endl;
    cout << "Required tiles:" << endl;
    cout << "2x4 tiles: " << result.large << " pieces" << endl;
    cout << "2x2 tiles: " << result.medium << " pieces" << endl;
    cout << "1x1 tiles: " << result.small << " pieces" << endl;

    return 0;
}