#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution















bool IsRefundFundSourceFreeze(int fund_source) {
  static const std::set<int> fund_source_freeze{1, 2, 4, 8 ,16};
  for(const auto &it : fund_source_freeze)
  {
      cout<<"it:"<<it<<endl;
      if(it & fund_source)
      {
          return true;
      }
  }
  return false;
}



int main()
{
    int kk = 32;
    if(IsRefundFundSourceFreeze(kk))
        cout<<"ddd"<<endl;

    return 0;
}
