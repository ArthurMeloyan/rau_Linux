#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Incorrect ammount of arguments is provided\n";
        return 1;
        std::cout << std::endl;
    }
    const int N = std::atoi(argv[1]);

    if (N <= 0)
    {
        std::cout << "Numbers cannot be non-positive";
        return 1;
    }

    int arr[N];

    for (int i = 0; i < N; ++i)
    {
        std::cin >> arr[i];
    }

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N - 1 - i; ++j)
        {
            if(arr[j] < arr[j+1])
            {
                int tmp = arr[j]; //tmp = 1
                arr[j] = arr[j+1]; // 1 -> 2
                arr[j+1] = tmp; // 2 -> 1
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        std::cout << arr[i] << " ";
    }

}