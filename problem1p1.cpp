#include <bits/stdc++.h>

int main()
{

    int list1, list2, sum = 0;
    std::vector<int> list1Vec = {}, list2Vec = {};

    // while loop  used since unknown number of inputs
    while (std::cin >> list1 >> list2)
    {
        list1Vec.push_back(list1);
        list2Vec.push_back(list2);
    }

    // sorted since we want to math the lowest values together from each list
    sort(list1Vec.begin(), list1Vec.end());
    sort(list2Vec.begin(), list2Vec.end());

    // add the absolute values together from the sorted pairs
    for (int i = 0; i < list1Vec.size(); i++)
    {
        sum += abs(list1Vec[i] - list2Vec[i]);
    }

    std::cout << sum << std::endl;

    return 0;
}
