#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> KeySet(map<int, float> test)
{
    vector<int> keys;
    for(map<int, float>::iterator it = test.begin(); it != test.end(); ++it){
        keys.push_back(it->first);
    }
    return keys;
}

class TradeFeeCal{
private:
    static map<int, int> quick_cal;
    map<int, int> charge_rule{
        {5, 30},
        {20, 15},
        {50, 10},
        {100, 9},
        {500, 8},

        {1000, 7},
        {2000, 6},
        {3000, 5},
        {4000, 4},
        {5000, 3},

        {6000, 2},
    };
    static vector<int> key_vector;
    static int min_fee;
public:
    int GetFeeByTradeCnt(int trade_cnt){
        int margin_idx = std::lower_bound(key_vector.begin(), key_vector.end(), trade_cnt) - key_vector.begin();
        //速算数
        int margin_val = key_vector[margin_idx - 1];
        //速算值
        int quicl_cal = quick_cal[margin_val];

        //下一档费率
        int fee_rate = min_fee;
        if (margin_idx != key_vector.size()){
            fee_rate = charge_rule[key_vector[margin_idx]];
        }
        int single_cal = fee_rate * (trade_cnt - margin_val);

        //结果
        int result = single_cal + quicl_cal;

        cout<<"margin_idx: "<<margin_idx<<endl;
        cout<<"margin_val: "<<margin_val<<endl;
        cout<<"quicl_cal: "<<quicl_cal<<endl;
        cout<<"fee_rate: "<<fee_rate<<endl;
        cout<<"single_cal: "<<single_cal<<endl;
        cout<<"result: "<<result<<endl;
        return result;
    }
};

vector<int> TradeFeeCal::key_vector{0, 5, 20, 50, 100, 1000, 2000, 3000, 4000, 5000, 6000};
int TradeFeeCal::min_fee = 1;
map<int, int> TradeFeeCal::quick_cal{
    {0, 0},
    {5, 150},
    {20, 15*15+150},
};

int main() {
    TradeFeeCal A;

    int result = A.GetFeeByTradeCnt(6);

    return 0;
}

// margin_idx: 1
// margin_val: 0
// quicl_cal: 0
// fee_rate: 30
// single_cal: 150
// result: 150

// margin_idx: 2
// margin_val: 5
// quicl_cal: 150
// fee_rate: 0
// single_cal: 0
// result: 150