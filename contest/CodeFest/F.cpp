#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

const int MAX_N = 210000;

vector<long long> fact(MAX_N + 1), invfact(MAX_N + 1);

long long modexp(long long base, long long exp, long long mod)
{
    long long result = 1 % mod;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void precomputeFactorials()
{
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[MAX_N] = modexp(fact[MAX_N], MOD - 2, MOD);
    for (int i = MAX_N; i >= 0; i--)
    {
        if (i > 0)
            invfact[i - 1] = (invfact[i] * i) % MOD;
    }
}

long long nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return ((fact[n] * invfact[r]) % MOD * invfact[n - r]) % MOD;
}

struct Sig
{
    int L;
    int cntL;
    int R;
    int cntR;
    bool operator==(const Sig &other) const
    {
        return L == other.L && cntL == other.cntL && R == other.R && cntR == other.cntR;
    }
};

struct SigHash
{
    std::size_t operator()(const Sig &s) const
    {
        size_t res = 17;
        res = res * 31 + std::hash<int>()(s.L);
        res = res * 31 + std::hash<int>()(s.cntL);
        res = res * 31 + std::hash<int>()(s.R);
        res = res * 31 + std::hash<int>()(s.cntR);
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precomputeFactorials();

    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<long long> d(N);
        for (int i = 0; i < N; i++)
        {
            cin >> d[i];
        }

        sort(d.begin(), d.end());

        vector<long long> prefix(N + 1, 0);
        for (int i = 0; i < N; i++)
        {
            prefix[i + 1] = prefix[i] + d[i];
        }

        int totalWindows = N - M + 1;
        vector<long long> fvals(totalWindows, 0);

        long long f0 = 0;
        for (int j = 0; j < M; j++)
        {
            int weight = 2 * j - (M - 1);
            f0 += weight * d[j];
        }
        fvals[0] = f0;

        for (int i = 0; i < totalWindows - 1; i++)
        {
            long long term = fvals[i] - 2 * (prefix[i + M] - prefix[i + 1]) + ((long long)(M - 1) * (d[i + M] + d[i]));
            fvals[i + 1] = term;
        }

        long long best = fvals[0];
        for (int i = 0; i < totalWindows; i++)
        {
            if (fvals[i] < best)
                best = fvals[i];
        }

        long long ansTravel = 2 * best;

        vector<int> group(N, 0);
        vector<int> groupStart, groupEnd, groupFreq;
        int currGroup = 0;
        groupStart.push_back(0);
        group[0] = 0;
        for (int i = 1; i < N; i++)
        {
            if (d[i] == d[i - 1])
            {
                group[i] = currGroup;
            }
            else
            {
                groupEnd.push_back(i - 1);
                groupFreq.push_back(i - groupStart[currGroup]);
                currGroup++;
                groupStart.push_back(i);
                group[i] = currGroup;
            }
        }
        groupEnd.push_back(N - 1);
        groupFreq.push_back(N - groupStart[currGroup]);

        unordered_map<Sig, long long, SigHash> sigMap;

        for (int i = 0; i < totalWindows; i++)
        {
            if (fvals[i] != best)
                continue;
            int L_idx = i, R_idx = i + M - 1;
            int Lgrp = group[L_idx], Rgrp = group[R_idx];
            Sig s;
            if (Lgrp == Rgrp)
            {
                s.L = Lgrp;
                s.cntL = M;
                s.R = Rgrp;
                s.cntR = M;
            }
            else
            {
                int countL = groupEnd[Lgrp] - L_idx + 1;
                int countR = R_idx - groupStart[Rgrp] + 1;
                s.L = Lgrp;
                s.cntL = countL;
                s.R = Rgrp;
                s.cntR = countR;
            }

            if (sigMap.find(s) == sigMap.end())
            {
                long long ways = 0;

                if (s.L == s.R)
                {

                    ways = nCr(groupFreq[s.L], M);
                }
                else
                {

                    ways = (nCr(groupFreq[s.L], s.cntL) * nCr(groupFreq[s.R], s.cntR)) % MOD;
                }
                sigMap[s] = ways;
            }
        }

        long long totalWays = 0;
        for (auto &entry : sigMap)
        {
            totalWays = (totalWays + entry.second) % MOD;
        }

        cout << ansTravel << " " << totalWays % MOD << "\n";
    }

    return 0;
}