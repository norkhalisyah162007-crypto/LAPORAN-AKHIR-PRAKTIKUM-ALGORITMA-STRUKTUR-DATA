#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> labels(N);
    map<char, int> idx;
    for (int i = 0; i < N; i++){
        cin >> labels[i];
        idx[labels[i]] = i;
    }
    vector<vector<int>> matrix(N, vector<int>(N, 0));

    int M;
    cin >> M;
    for (int i = 0; i < M; i++){
        char U, V;
        int W;
        cin >> U >> V >> W;
        matrix[idx[U]][idx[V]] = W;
    }
    
    cout << "Adjacency Matrix:" << endl;

    cout << " ";
    for (int i = 0; i < N; i++) {
        cout << " " << labels [i];
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << labels[i];
        for (int j = 0; j<N; j++){
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
