class Solution {
public:
  int numJewelsInStones(string J, string S) {
    size_t lenJ = J.size(), lenS = S.size();
    int cnt = 0;
    set<char> lut;
    for (size_t i = 0; i < lenJ; ++ i) {
      lut.insert(J[i]);
    }
    for (size_t i = 0; i < lenS; ++ i) {
      auto it = lut.find(S[i]);
      if (it != lut.end()) ++ cnt;
    }
    return cnt;
  }
};
