class Solution {
    struct TrieNode {
        int children[26];
        int best; // index of best wordsContainer string passing through this node
        TrieNode() : best(-1) { fill(begin(children), end(children), -1); }
    };

    vector<TrieNode> trie;

    // Returns true if wordsContainer[a] is a better candidate than wordsContainer[b]
    bool isBetter(const vector<string>& wc, int a, int b) {
        if (b == -1) return true;
        if (wc[a].size() != wc[b].size()) return wc[a].size() < wc[b].size();
        return a < b;
    }

    void insert(const vector<string>& wc, int idx) {
        const string& w = wc[idx];
        int node = 0;
        // Update root
        if (isBetter(wc, idx, trie[node].best))
            trie[node].best = idx;
        // Insert reversed
        for (int i = w.size() - 1; i >= 0; --i) {
            int c = w[i] - 'a';
            if (trie[node].children[c] == -1) {
                trie[node].children[c] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].children[c];
            if (isBetter(wc, idx, trie[node].best))
                trie[node].best = idx;
        }
    }

    int query(const vector<string>& wc, const string& q) {
        int node = 0;
        for (int i = q.size() - 1; i >= 0; --i) {
            int c = q[i] - 'a';
            if (trie[node].children[c] == -1) break;
            node = trie[node].children[c];
        }
        return trie[node].best;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.emplace_back(); // root
        for (int i = 0; i < (int)wordsContainer.size(); ++i)
            insert(wordsContainer, i);

        vector<int> ans;
        for (const string& q : wordsQuery)
            ans.push_back(query(wordsContainer, q));
        return ans;
    }
};