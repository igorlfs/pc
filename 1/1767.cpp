#include <bits/stdc++.h>

using namespace std;

constexpr int PESO = 50;

int main() {
    int num_casos;
    cin >> num_casos;
    for (int i = 0; i < num_casos; ++i) {
        int n;
        cin >> n;
        vector<pair<int, int>> pacotes(n);
        for (int j = 0; j < n; ++j) {
            cin >> pacotes[j].first >> pacotes[j].second;
        }
        vector<vector<int>> valores(n);
        for (int j = 0; j < n; ++j) {
            valores[j].resize(PESO + 1);
        }
        for (int j = pacotes[0].second; j < PESO + 1; ++j) {
            valores[0][j] = pacotes[0].first;
        }
        for (int j = 1; j < n; ++j) {
            int peso_atual = pacotes[j].second;
            for (int k = 1; k <= PESO; ++k) {
                int max_anterior = valores[j - 1][k];
                int max_atual = 0;
                if (peso_atual <= k) {
                    max_atual +=
                        pacotes[j].first + valores[j - 1][k - peso_atual];
                }
                valores[j][k] = max(max_anterior, max_atual);
            }
        }
        int brinquedos = 0;
        int peso = 0;
        for (int j = PESO; j >= 0; --j) {
            if (valores[n - 1][j] >= brinquedos) {
                brinquedos = valores[n - 1][j];
                peso = j;
            }
        }
        int perdendo_peso = peso;
        int não_usados = 0;
        for (int k = n - 1; k > 0; --k) {
            if (valores[k][perdendo_peso] != valores[k - 1][perdendo_peso]) {
                perdendo_peso -= pacotes[k].second;
            } else {
                não_usados++;
            }
        }
        if (valores[0][perdendo_peso] == 0) não_usados++;
        cout << brinquedos << " brinquedos" << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "sobra(m) " << não_usados << " pacote(s)" << endl << endl;
    }
    return 0;
}
