#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        vector<int> res(puzzles.size(), 0);

        vector<int> wordshash(words.size(), 0);
        for (int i = 0; i < words.size(); ++i)
        {
            for (auto &&c : words[i])
            {
                wordshash[i] |= (1 << c - 'a');
            }
        }

        vector<int> num(7, 0);
        for (int i = 0; i < puzzles.size(); ++i)
        {
            for (auto &&c : puzzles[i])
            {
                num[i] |= (1 << c - 'a');
            }
        }

        vector<bool> midipossible(puzzles.size(), true);
        for (int i = 0; i < wordshash.size(); ++i)
        {
            //check某一个单词，是否是 每个puzzle的谜底
            for (int j = 0; j < puzzles.size(); ++j)
            {
                midipossible[j] = true;
                int first = puzzles[j][0] - 'a';
                if (!(wordshash[i] & (1 << first)))
                {
                    midipossible[j] = false;
                }
            }

            for (int k = 0; k < 26; ++k)
            {
                if ((wordshash[i] & (1 << k)) != 0) //word有k
                {
                    for (int j = 0; j < puzzles.size(); ++j)
                    {
                        if (midipossible[j] && !(num[j] & (1 << k))) //puzzle[j] 无 k
                        {
                            midipossible[j] = false;
                        }
                    }
                }
            }

            for (int j = 0; j < puzzles.size(); ++j)
            {
                res[j] += midipossible[j];
            }
        }
        return res;
    }
};

int main()
{
    Solution A;
    vector<string> words{"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
    vector<string> puzzles{"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
    //输出：[1,1,3,2,4,0]
    show(A.findNumOfValidWords(words, puzzles));

    return 0;
}
