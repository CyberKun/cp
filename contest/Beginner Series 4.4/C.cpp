#include <iostream>
#include <vector>

using namespace std;

vector<int> win(int size, vector<int> &numbers)
{
    int xor_sum = 0;
    vector<int> results;
    for (int i = 0; i < size; i++)
    {
        int value = numbers[i];
        int game_state;
        if (value == 1)
            game_state = 0;
        else
        {
            game_state = (value - 1) % 2;
        }
        xor_sum ^= game_state;

        if (xor_sum != 0)
            results.push_back(1);
        else
            results.push_back(2);
    }
    return results;
}

int main()
{
    int size;
    cin >> size;

    vector<int> numbers(size);

    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }

    vector<int> outcomes = win(size, numbers);

    for (int i = 0; i < size; i++)
    {
        cout << outcomes[i] << endl;
    }

    return 0;
}
