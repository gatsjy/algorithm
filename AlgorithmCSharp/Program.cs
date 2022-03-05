using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        while (true)
        {
            string line = Console.ReadLine();
            if (line.Equals("end")) return;
            bool flag = true;

            int aeiouCnt = 0;
            int vowelCnt = 0;
            int consonantCnt = 0;
            char prev = '-';

            for (int i = 0; i < line.Length; i++)
            {
                if(i != 0)
                {
                    prev = line[i - 1];

                    // 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
                    if (prev == line[i])
                    {
                        if(!(line[i] == 'e' || line[i] == 'o'))
                        {
                            flag = false;
                            break;
                        }
                    }
                }

                if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u'){
                    aeiouCnt++;
                    vowelCnt++;
                    consonantCnt = 0;
                }
                else // 자음일때
                {
                    vowelCnt = 0;
                    consonantCnt++;
                }

                // 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안된다.
                if (consonantCnt == 3 || vowelCnt == 3)
                {
                    flag = false;
                    break;
                }
            }

            // 1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
            if(aeiouCnt == 0)
            {
                flag = false;
            }

            if (flag)
            {
                Console.WriteLine("<{0}> is acceptable.", line);
            }
            else
            {
                Console.WriteLine("<{0}> is not acceptable.", line);
            }
        }
    }
}