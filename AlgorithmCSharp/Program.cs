using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int[] solution(int[] numbers)
    {
        int[] answer = new int[] { };
        SortedSet<int> tmp = new SortedSet<int>();
        for (int i = 0; i < numbers.Length; i++)
        {
            for (int j = i; j < numbers.Length; j++)
            {
                if (i == j) continue;
                tmp.Add(numbers[i] + numbers[j]);
            }
        }
        var tmpList = answer.ToList();
        foreach (int i in tmp)
        {
            tmpList.Add(i);
        }
        answer = tmpList.ToArray();
        return answer;
    }
}
​