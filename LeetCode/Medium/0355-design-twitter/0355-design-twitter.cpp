class Twitter {
private:
    // user 정보 = (user id, follower list, tweet id list)
    unordered_map<int, pair<vector<int>, vector<int>>> user_Info;
    // 모든 유저의 tweet을 저장하는 vector
    vector<int> total_tweets;
public:
    Twitter() {
    
    }
    
    void postTweet(int userId, int tweetId) {
        // 전체 tweet 저장하는 vector 앞부분에 tweetId 추가
        total_tweets.insert(total_tweets.begin(), tweetId);


        if (user_Info.find(userId) == user_Info.end()){
            // user가 없으면
            vector<int> followers;
            vector<int> tweets;
            tweets.push_back(tweetId);
            user_Info[userId] = make_pair(followers, tweets);

        }else{
            // user가 있으면
            // tweets 앞에 추가 10개까지
            if (user_Info[userId].second.size()==10) user_Info[userId].second.pop_back();
            user_Info[userId].second.insert(user_Info[userId].second.begin(), tweetId);
        }
    }
    
    vector<int> getNewsFeed(int userId) {

        // 최신 tweet에서 순서대로 보면서 본인, 본인이 following하는 사람들의 tweet인 거 10개 return
        vector<int> NewsFeed;

        for(auto tweetId: total_tweets){
            // NewsFeed가 10개 다 차면 break
            if(NewsFeed.size() == 10) break;

            // 내가 한 트윗이면 추가
            if (find(user_Info[userId].second.begin(), user_Info[userId].second.end(), tweetId) != user_Info[userId].second.end()){
                NewsFeed.push_back(tweetId);
            }

            // 내 팔로워가 한 트윗이면 추가
            for(auto follower: user_Info[userId].first){
                if (find(user_Info[follower].second.begin(), user_Info[follower].second.end(), tweetId) != user_Info[follower].second.end()){
                NewsFeed.push_back(tweetId);
                }
            }
        }

        return NewsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        // following list에 없으면 추가
        if (find(user_Info[followerId].first.begin(), user_Info[followerId].first.end(), followeeId) == user_Info[followerId].first.end()){
            user_Info[followerId].first.push_back(followeeId);
        }

    }
    
    void unfollow(int followerId, int followeeId) {
        // following list에 있으면 제거
        user_Info[followerId].first.erase(
            remove(
                user_Info[followerId].first.begin(),
                user_Info[followerId].first.end(),
                followeeId
            ),
            user_Info[followerId].first.end()
        );
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */