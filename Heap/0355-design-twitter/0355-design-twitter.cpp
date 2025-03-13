/*
355. Design Twitter

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <tuple>
using namespace std;

class Twitter {
private:
    int timestamp;  // global time to order tweets
    // Map from userId to the set of users they follow.
    unordered_map<int, unordered_set<int>> followMap;
    // Map from userId to list of tweets. Each tweet is represented as (timestamp, tweetId).
    unordered_map<int, vector<pair<int, int>>> tweets;
    
public:
    /** Initialize your data structure here. */
    Twitter() : timestamp(0) {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. 
        Each item in the news feed must be posted by users who the user followed or by the user herself.
        Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        
        // Custom tuple: (timestamp, tweetId, userId, index in user's tweet list)
        typedef tuple<int, int, int, int> TweetInfo;
        // Comparator for max-heap based on timestamp.
        auto cmp = [](const TweetInfo &a, const TweetInfo &b) {
            return get<0>(a) < get<0>(b);
        };
        priority_queue<TweetInfo, vector<TweetInfo>, decltype(cmp)> pq(cmp);
        
        // Gather users: the user themselves plus all users they follow.
        unordered_set<int> users;
        users.insert(userId);
        if (followMap.count(userId)) {
            for (int followee : followMap[userId]) {
                users.insert(followee);
            }
        }
        
        // For each user, push their most recent tweet onto the heap.
        for (int u : users) {
            if (tweets.count(u) && !tweets[u].empty()) {
                int idx = tweets[u].size() - 1;
                auto [time, tweetId] = tweets[u][idx];
                pq.push({time, tweetId, u, idx});
            }
        }
        
        // Retrieve up to 10 most recent tweets.
        while (!pq.empty() && result.size() < 10) {
            auto [time, tweetId, u, idx] = pq.top();
            pq.pop();
            result.push_back(tweetId);
            // If there is an older tweet from the same user, push it to the heap.
            if (idx > 0) {
                auto [prevTime, prevTweetId] = tweets[u][idx - 1];
                pq.push({prevTime, prevTweetId, u, idx - 1});
            }
        }
        
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;  // A user cannot follow themselves.
        followMap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followMap.count(followerId))
            followMap[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;
    
    // User 1 posts a tweet.
    twitter.postTweet(1, 5); 
    vector<int> feed = twitter.getNewsFeed(1);
    cout << "User 1's news feed: ";
    for (int tweet : feed) {
        cout << tweet << " ";
    }
    cout << endl;
    
    // User 1 follows user 2.
    twitter.follow(1, 2);
    // User 2 posts a tweet.
    twitter.postTweet(2, 6);
    feed = twitter.getNewsFeed(1);
    cout << "User 1's news feed after following user 2: ";
    for (int tweet : feed) {
        cout << tweet << " ";
    }
    cout << endl;
    
    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);
    feed = twitter.getNewsFeed(1);
    cout << "User 1's news feed after unfollowing user 2: ";
    for (int tweet : feed) {
        cout << tweet << " ";
    }
    cout << endl;
    
    return 0;
}
