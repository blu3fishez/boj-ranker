#include <cstdio>
#include <queue>

using namespace std;

int main () {

    int N, M, a, b, i, temp;
    queue<int> q;
    vector<int> v[32001];

    scanf("%d %d", &N, &M);
    int indegree[N+1];

    for (i = 0; i < N+1; i++) indegree[i] = 0;


    for (i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        indegree[b]++;
        v[a].push_back(b);
    }

    for (i = 1; i <= N; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        temp = q.front();
        q.pop();

        printf("%d ", temp);

        for (i = 0; i < v[temp].size(); i++) {
            indegree[v[temp][i]]--;
            if (!indegree[v[temp][i]]) q.push(v[temp][i]);
        }
    }

    printf("\n");

    return 0;
}