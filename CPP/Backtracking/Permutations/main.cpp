#include <iostream>
#define MAXSIZE 10

using namespace std;

void init(int A[MAXSIZE], int k)
{
    A[k] = 0;
}

bool successor(int A[MAXSIZE], int k, int n)
{
    if (A[k] < n)
    {
        A[k]++;
        return true;
    }
    return false;
}

bool valid(int A[MAXSIZE], int k)
{
    for (int i = 1; i < k; i++)
    {
        if (A[i] == A[k])
        {
            return false;
        }
    }
    return true;
}

bool solution(int k, int n)
{
    return k == n; /// if we are on the last level
}

void print(int A[MAXSIZE], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << ' ';
    }
    cout << endl;
}

void bt(int A[MAXSIZE], int n)
{
    int k = 1;
    init(A, k);
    bool s = false, v = false;
    while (k > 0)
    {
        do
        {
            s = successor(A, k, n);
            if (s)
            {
                v = valid(A, k);
            }
        } while (s && !v);
        if (s)
        {
            if (solution(k, n))
            {
                print(A, n);
            }
            else
            {
                init(A, ++k);
            }
        }
        else
        {
            k--;
        }
    }
}

int main()
{
    int A[MAXSIZE];
    int n;
    cout << "n: ";
    cin >> n;
    bt(A, n);

    return 0;
}