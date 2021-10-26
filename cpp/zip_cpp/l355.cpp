#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution



class Twitter {
public:
    /** Initialize your data structure here. */
    int time;
    map<int, vector<pair<int, int>>> usertwitterlist;
    map<int, set<int>> userrelation;
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(usertwitterlist.find(userId) == usertwitterlist.end())
        {
            usertwitterlist[userId] = {};
        }
        pair<int, int> p(time++, tweetId);
        usertwitterlist[userId].push_back(p);
        if(usertwitterlist.size()>10)
        {
            usertwitterlist.erase(usertwitterlist.begin());
        }
        userrelation[userId].insert(userId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> news;
        for(auto u:userrelation)
        {
            if(usertwitterlist.find(u.first) != usertwitterlist.end())
            {
                news.insert(news.end(), usertwitterlist[u.first].begin(), usertwitterlist[u.first].end());
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> theq;
        vector<int>ret;
        while(ret.size()<10)
        {
            int v = theq.top().second;
            theq.pop();
            ret.push_back(v);
        }
        
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        userrelation[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        userrelation[followerId].erase(followeeId);
    }
};



int main()
{
    Twitter* obj = new Twitter();
    obj->postTweet(1,123);
    obj->postTweet(1,124);
    obj->postTweet(1,125);
    obj->postTweet(1,126);
    obj->postTweet(2,127);
    obj->postTweet(2,128);
    obj->postTweet(2,129);
    vector<int> param_2 = obj->getNewsFeed(2);
    show(param_2);
    obj->follow(1,2);
    vector<int> param_3 = obj->getNewsFeed(1);
    show(param_3);
    obj->unfollow(1,2);
    vector<int> param_4 = obj->getNewsFeed(1);
    show(param_4);
    return 0;
}
