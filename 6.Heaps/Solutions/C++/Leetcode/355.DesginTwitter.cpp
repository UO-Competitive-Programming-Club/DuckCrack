#include "../Debug.h"
using namespace std;

/* edge cases: 
 *      you cannot follow yourself
 * */

class Twitter {
public:
    /** Initialize your data structure here. */
    struct Tweet {
        int tweet_id;
        int timestamp;

        Tweet(int tweet_id, int timestamp ) {
            this->tweet_id = tweet_id;
            this->timestamp = timestamp;
        }
    };

    struct User {
        int id;
        unordered_set<int> followers;
        unordered_set<int> followings;
        list<Tweet> tweets;

        User(int user_id) : id(user_id) { };

        void post(int tweet_id, int timestamp) {
            Tweet new_tweet(tweet_id, timestamp);
            tweets.push_front(new_tweet);
        }
    };

    unordered_map<int, User> userDB;
    int time;

    Twitter() {
        this->time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {

        if (userDB.find(userId) == userDB.end()) {
            User new_user(userId);
            userDB.insert({userId, new_user});
            //cout << "here" << endl;
        }

        User& user = userDB.at(userId);
        user.post(tweetId, time);
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        if (userDB.find(userId) == userDB.end()) {
            return result;
        }

        struct Entry {
            list<Tweet>::const_iterator iter;
            list<Tweet>::const_iterator end;

            bool operator<(const Entry& that) const {
                return this->iter->timestamp < that.iter->timestamp;
            }
        };

        priority_queue<Entry, vector<Entry>, less<Entry> > max_heap;
        User& user = userDB.at(userId);
        /* initalization */
                    
                    
        if (!user.tweets.empty()) {
            max_heap.emplace(Entry{ user.tweets.cbegin(), user.tweets.cend() });
        }
        
        for (auto iter = user.followings.cbegin(); iter != user.followings.cend(); ++iter) {
            int followee_id = *iter;
            User& followee = userDB.at(followee_id);
            
            if (!followee.tweets.empty()) {
                max_heap.emplace(Entry{ followee.tweets.cbegin(), followee.tweets.cend() });
            }
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
        
        if (userDB.find(followerId) == userDB.end()) {
            User new_user(followerId);
            userDB.insert({followerId, new_user});
        }
        
        if (userDB.find(followeeId) == userDB.end()) {
            User new_user(followeeId);
            userDB.insert({followeeId, new_user});
        }
        
        if (followerId != followeeId) {
            User& follower = userDB.at(followerId);
            User& followee = userDB.at(followeeId);
    
            follower.followings.insert(followeeId);
            followee.followers.insert(followerId);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        
        if (userDB.find(followerId) == userDB.end()) {
            User new_user(followerId);
            userDB.insert({followerId, new_user});
        }
        
        if (userDB.find(followeeId) == userDB.end()) {
            User new_user(followeeId);
            userDB.insert({followeeId, new_user});
        }
        
        if (followerId != followeeId) {
            User& follower = userDB.at(followerId);
            User& followee = userDB.at(followeeId);
    
            follower.followings.erase(followeeId);
            followee.followers.erase(followerId);
        }
    }
};


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
