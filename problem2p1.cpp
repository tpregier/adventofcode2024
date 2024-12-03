#include <bits/stdc++.h>

int main()
{
    std::string inputNumbers;
    int numberOfSafeReports = 0;

    while (std::getline(std::cin, inputNumbers))
    {
        std::istringstream iss(inputNumbers);
        std::vector<int> numberList;
        int number;

        while (iss >> number)
        {
            numberList.push_back(number);
        }

        if (numberList.size() < 2)
        {
            continue;
        }

        bool valid = true;
        int direction = 0;

        for (size_t i = 0; i + 1 < numberList.size(); ++i)
        {
            int diff = numberList[i + 1] - numberList[i];

            if (std::abs(diff) > 3 || std::abs(diff) < 1)
            {
                valid = false;
                break;
            }

            if (diff > 0)
            {
                if (direction == -1)
                {
                    valid = false;
                    break;
                }
                direction = 1;
            }
            else if (diff < 0)
            {
                if (direction == 1)
                {
                    valid = false;
                    break;
                }
                direction = -1;
            }
        }

        if (valid)
        {
            numberOfSafeReports++;
        }
    }

    std::cout << numberOfSafeReports << std::endl;
    return 0;
}
