#include "windows.h"
#include<cstdio>
#include<iostream>
#include<unordered_map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//vector<TreeNode*> generateTrees(int n) {
//    vector<int>nums, usednums;
//    vector<TreeNode*> ansTrees;
//    for (int i = 1; i <= n; i++) {
//        nums.push_back(i);
//    }
//    for (int n : nums) {
//        usednums.clear();
//        usednums.push_back(n);
//        ansTrees.push_back( buildTree(NULL, nums, usednums));
//    }
//    return ansTrees;
//}
//
//bool checkExist(int n, vector<int>& usednums) {
//    for (int num : usednums) {
//        if (n == num)
//            return true;
//    }
//    return false;
//}
//
//TreeNode* buildTree(TreeNode* root, vector<int>& nums, vector<int>& usednums) {
//
//
//    for (int n : nums) {
//        if (!checkExist(n,usednums)) {
//            if()
//        }
//    }
//    return root;
//}
//
//#define MAX 11111111
//
//struct Tri {
//    vector<int> edge1;
//    vector<int> edge2;
//    vector<int> edge3;
//    int degree;
//};
//vector<Tri> triangles;
//
//unordered_map<int, int> tNodes;
//void inputNode(vector<int>& e) {
//    for (int n : e) {
//        if (tNodes.find(n) == tNodes.end()) {
//            tNodes.insert({n,1});
//        }
//    }
//}
//
//int calDegree(vector<vector<int>>& edges) {
//    int cnt = 0;
//    for (vector<int> edge : edges) {
//        bool tf1 = false, tf2 = false;
//        if (tNodes.find(edge[0]) != tNodes.end())
//            tf1 = true;
//        if (tNodes.find(edge[1]) != tNodes.end())
//            tf2 = true;
//        if (tf1 != tf2) {
//            cnt++;
//        }
//    }
//    return cnt;
//}
//
//int checkIfTrio(vector<vector<int>>& edges, vector<int>& e1, vector<int>& e2, vector<int>& e3) {
//    for (Tri t : triangles) {
//        if (e1 == t.edge1 && e2 == t.edge2 && e3 == t.edge3)
//            return t.degree;
//    }
//    if (e1 == e2 || e1 == e3 || e3 == e2)
//        return -1;
//
//    tNodes.clear();
//    inputNode(e1);
//    inputNode(e2);
//    inputNode(e3);
//    if (tNodes.size() == 3) {
//        Tri tempT;
//        tempT.edge1 = e1;
//        tempT.edge2 = e2;
//        tempT.edge3 = e3;
//        tempT.degree = calDegree(edges);
//        triangles.push_back(tempT);
//        return tempT.degree;
//    }
//    return -1;
//}
//
//int minTrioDegree(int n, vector<vector<int>>& edges) {
//    int cnt = 0, mincnt = MAX, tricnt=0;
//    for (int i = 0; i < edges.size(); i++) {
//        for (int j = i + 1; j < edges.size(); j++) {
//            for (int k = j + 1; k < edges.size(); k++) {
//                cnt = checkIfTrio(edges, edges[i], edges[j], edges[k]);
//                if (cnt > -1) {
//                    tricnt = 1;
//                    if (mincnt > cnt)
//                        mincnt = cnt;
//                }
//            }
//        }
//    }
//    if (!tricnt)
//        return -1;
//    return mincnt;
//}

int longestValidParentheses(string s) {
    stack<int>stk;
    int ans=0;
    stk.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        }
        else {
            if (stk.size() != 1) {
                stk.pop();
                ans = max(ans, i - stk.top());
            }
            else
                stk.top() = i;
        }
    }
    return ans;
}

int main()
{
    //vector<vector<int>> edges = { {1, 2},{1, 3},{3, 2},{4, 1},{5, 2},{3, 6} };
    ////{{1, 3}, {4, 1}, {4, 3}, {2, 5}, {5, 6}, {6, 7}, {7, 5}, {2, 6}};
    //    //{{1, 2}, {4, 3}, {3, 1}, {4, 2}, {2, 3}};
    //vector<int> nums = { 6,5,4,8};
    //long long n = 19;
    //string s = ")()())";
    //string p = ".*";
    ////int target = 1;
    ////string s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    ////vector<string> sentences = { "alice and bob love leetcode", "i think so too", "this is great thanks very much" };
    //int x = longestValidParentheses(s);
    enum {N=3};
    int a[N] = { 1,2,3 };

    cout << a;/**/
}
