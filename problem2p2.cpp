#include <bits/stdc++.h>

bool validAfterRemoval(const std::vector<int> &numberList)
{

    for (size_t skipIndex = 0; skipIndex < numberList.size(); skipIndex++)
    {
        bool valid = true;
        int direction = 0;
        int prevIndex = -1;
        for (size_t i = 0; i < numberList.size(); i++)
        {
            if (i == skipIndex)
                continue;
            if (prevIndex != -1)
            {
                int diff = numberList[i] - numberList[prevIndex];
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
            prevIndex = i;
        }

        if (valid)
        {
            return true;
        }
    }

    return false;
}

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

        if (valid || validAfterRemoval(numberList))
        {
            numberOfSafeReports++;
        }
    }

    std::cout << numberOfSafeReports << std::endl;
    return 0;
}
