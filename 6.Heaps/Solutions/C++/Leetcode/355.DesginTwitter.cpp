#include "../Debug.h"
using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    struct Tweet {
        int user_id; 
        int tweet_id;
        int timestamp;

        Tweet(int user_id, int tweet_id, int timestamp ) {
            this->user_id = user_id;
            this->tweet_id = tweet_id;
            this->timestamp = timestamp;
        }
    };

    struct User {
        int id;
        unordered_set<int> followers;
        unordered_set<int> following;
        unordered_map<int, Tweet> tweets;
        list<Tweet> lastest_tweets;

        User(int user_id) : id(user_id) { };

        void post(int tweet_id, int timestamp) {
            Tweet new_tweet(this->id, tweet_id, timestamp);
            if (tweets.find(tweet_id) != tweets.end()) {
                tweets.insert({tweet_id,  new_tweet});
            } else {
                // throw exception
            }

            if (lastest_tweets.size() >= 10) {
                lastest_tweets.pop_back();
            }

            lastest_tweets.push_front(new_tweet);
        }
    };


    unordered_map<int, User> userDB;
    int time;

    Twitter() {
        this->time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (userDB.find(userId) != userDB.end()) {
            User new_user(userId);
            userDB.insert({userId, new_user});
            new_user.post(tweetId, time);
        } else {
            User& user = userDB.at(userId);
            user.post(tweetId, time);
        }

        time++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the 
     * news feed must be posted by users who the user followed or by the user herself. 
     * Tweets must be ordered from most recent to least recent. */

    vector<int> getNewsFeed(int userId) {
        vector<int> result(10); 
        if (userDB.find(userId) == userDB.end()) {
            return result;
        }

        struct Entry {
            list<Tweet>::const_iterator iter;
            list<Tweet>::const_iterator end;

            bool operator>(const Entry& that) const {
                return this->iter->timestamp > that.iter->timestamp;
            }
        };

        priority_queue<Entry, vector<Entry>, greater<Entry> > max_heap;
        User& user = userDB.at(userId);

        /* initalization */
        for (auto iter = user.followers.cbegin(); iter != user.followers.cend(); ++iter) {
            int followee_id = *iter;
            User& followee = userDB.at(followee_id);
            max_heap.emplace(Entry{ followee.lastest_tweets.cbegin(), followee.lastest_tweets.cend() });
        }

        for (int i = 0; i < 10 && !max_heap.empty(); i++) {
            Entry entry = max_heap.top();
            max_heap.pop();
            result.emplace_back(entry.iter->tweet_id);

            if (next(entry.iter) != entry.end) {
                entry.iter = next(entry.iter);
                max_heap.emplace(entry);
            }
        }

        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (userDB.find(followerId) != userDB.end() && 
            userDB.find(followeeId) != userDB.end()) {

            User& follower = userDB.at(followerId);
            User& followee = userDB.at(followeeId);
            
            follower.following.insert(followeeId);
            followee.followers.insert(followerId);
        } 
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (userDB.find(followerId) != userDB.end() && 
            userDB.find(followeeId) != userDB.end()) {

            User& follower = userDB.at(followerId);
            User& followee = userDB.at(followeeId);
            
            follower.following.erase(followeeId);
            followee.followers.erase(followerId);
        } 
    }
};
