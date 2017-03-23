#include <bits/stdc++.h>

using namespace std;

class DisjointSets{
public:
	void addelements(int num){
		while (num--)
			s.push_back(-1);
	}
	int find(int elem) {
		return s[elem] < 0 ? elem : s[elem] = find(s[elem]); 
	}

	void setunion(int a, int b) {
		int root1 = find(a), root2 = find(b);
		int newSize = s[root1] + s[root2];
		if (s[root1] <= s[root2]){
			s[root2] = root1;
			s[root1] = newSize;
		}
		else{
			s[root1] = root2;
			s[root2] = newSize;
		}
	}

private:
    std::vector<int> s;
};

int main(){
    int n;
    scanf("%d", &n);
    DisjointSets ds;
    ds.addelements(n);

    int answer = n;
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        if (ds.find(i) != ds.find(d - 1)) {
            answer--;
            ds.setunion(i, d - 1);
        }
    }
    printf("%d\n", answer);
    return 0;
}
