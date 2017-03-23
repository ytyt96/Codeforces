#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> vi;

class SegmentTree {   
private: vi st, A;   
  int n;
  int left (int p) { return p << 1; }  
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {   
    if (L == R)                      
      st[p] = 0;
    else {                         
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      long long p1 = st[left(p)], p2 = st[right(p)];
      st[p] = p1 + p2;
  } }

  long long rmq(int p, int L, int R, int i, int j) {               
    if (i >  R || j <  L) return -1;
    if (L >= i && R <= j) return st[p];            

    long long p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    long long p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);
    if (p1 == -1) return p2; 
    if (p2 == -1) return p1; 
    return p1 + p2;
}

  long long update_point(int p, int L, int R, int idx, int new_value) {
    int i = idx, j = idx;

    if (i > R || j < L)
      return st[p];

    if (L == i && R == j) {
      A[i] += new_value;
      return st[p] = A[i]; 
    }

    long long p1, p2;
    p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

    return st[p] = p1 + p2;
  }

public:
	SegmentTree(const vi &_A) {
		A = _A; n = (int)A.size();
		st.assign(4 * n, 0);
		//build(1, 0, n - 1);
	}
	long long rmq(int i, int j) {return rmq(1, 0, n - 1, i, j);}
	void update_point(int idx, int val) { update_point(1, 0, n - 1, idx, val);}
};

int main(){
    int n, k;
    cin >> n >> k;
    SegmentTree st(vector<long long>(n, 0));

    k = min(k, n - k);
    int pt = 0;
    long long sec = 1;
    for (int i = 0; i < n; i++) {
        sec++;


        if (pt + k - 1 < n) {
            sec += st.rmq(pt + 1, pt + k - 1);
            st.update_point(pt, 1);
            st.update_point((pt + k) % n, 1);
            pt = (pt + k) % n;
        }
        else {
            if (pt + 1 <= n - 1) 
                sec += st.rmq(pt + 1, n - 1);
            if (pt + k - 1 >= n)
                sec += st.rmq(0, pt + k - n - 1);
            st.update_point(pt, 1);
            st.update_point((pt + k) % n, 1);
            pt = (pt + k) % n;
        }
        if (i != 0)
            cout << " ";
        cout << sec;
    }
    cout << "\n";
    return 0;
}
