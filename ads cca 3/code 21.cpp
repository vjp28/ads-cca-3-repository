#include <bits/stdc++.h>
using namespace std;

// Function to generate first q primes
vector<int> generatePrimes(int q) {
    vector<int> primes;
    int num = 2;
    while (primes.size() < q) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(num);
        num++;
    }
    return primes;
}

vector<int> waiter(vector<int> number, int q) {
    vector<int> primes = generatePrimes(q);
    vector<int> answer;
    vector<int> A = number;

    for (int i = 0; i < q; i++) {
        vector<int> nextA;
        vector<int> B;

        // Process stack A from top to bottom (reverse order)
        for (int j = A.size() - 1; j >= 0; j--) {
            if (A[j] % primes[i] == 0)
                B.push_back(A[j]);
            else
                nextA.push_back(A[j]);
        }

        // Add B elements (top to bottom) to answer
        for (int j = B.size() - 1; j >= 0; j--)
            answer.push_back(B[j]);

        A = nextA;
    }

    // Add remaining A elements (top to bottom)
    for (int j = A.size() - 1; j >= 0; j--)
        answer.push_back(A[j]);

    return answer;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> number(n);
    for (int i = 0; i < n; i++) cin >> number[i];

    vector<int> result = waiter(number, q);
    for (int val : result)
        cout << val << "\n";

    return 0;
}
