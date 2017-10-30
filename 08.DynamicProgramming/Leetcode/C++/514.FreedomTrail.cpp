#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int findRotateSteps(string ring, string key) {
    int ans=INT_MAX, KS=key.size(), RS=ring.size();
    vector<vector<int>> mem(KS+1,vector<int>(RS,INT_MAX));
    mem[0][0]=0; // start state
    for(int i=1;i<=KS;i++) // Go through every char in key
        for(int j=0;j<RS;j++) // Go through every char in ring
            if(ring[j]==key[i-1]) // ring char matches key char
                for(int k=0;k<RS;k++) // look up previous result
                    if(mem[i-1][k]!=INT_MAX) { // find previous result
                        mem[i][j]=min(mem[i][j],mem[i-1][k]+min((k+RS-j)%RS,(j+RS-k)%RS)); // update current state
                        (i==KS)?ans=min(ans,mem[KS][j]):0; // if last row, update answer
                    }
    return ans+KS;
}
