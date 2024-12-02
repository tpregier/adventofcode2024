#include <bits/stdc++.h>

int main()
{

    int list1, list2, sum = 0;
    std::vector<int> list1Vec = {}, list2Vec = {};
    std::unordered_map<int, int> frequencyList;

    while (std::cin >> list1 >> list2)
    {
        list1Vec.push_back(list1);
        list2Vec.push_back(list2);
    }

    // sort(list1Vec.begin(), list1Vec.end());
    // sort(list2Vec.begin(), list2Vec.end());

    // loop through the list  and add them to the hashmap to get frequency
    for (int number : list2Vec)
    {
        frequencyList[number]++;
    }

    // loop through the list and take the number found at index and multiply it with the frequency of that number in the hasmap
    for (int number : list1Vec)
    {
        if (frequencyList.find(number) != frequencyList.end())
        {

            sum += number * frequencyList[number];
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
