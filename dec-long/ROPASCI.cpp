#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
  ll N;
  cin >> N;
  map<pair<string, string>, int> rps;
  rps[make_pair("R", "P")] = 1;
  rps[make_pair("R", "S")] = 0;
  rps[make_pair("R", "R")] = 0;
  rps[make_pair("P", "P")] = 0;
  rps[make_pair("P", "S")] = 1;
  rps[make_pair("P", "R")] = 0;
  rps[make_pair("S", "P")] = 0;
  rps[make_pair("S", "S")] = 0;
  rps[make_pair("S", "R")] = 1;
  while (N--)
  {
    ll len;
    cin >> len;
    ll n = len;
    vector<string> moves;
    char c;
    map<int, string> results;
    scanf("%c", &c);

    while (n--)
    {
      scanf("%c", &c);
      string letter(1,c);
      moves.push_back(letter);
    }
    string result = moves[len - 1];
    results[len-1] = result;
    // traversing back of array leaving last element as result already known
    for (ll i = len - 2; i >= 0; i--)
    {
      // current player
      ll prevWinner = i;

      // traversing from current index to the last of array to calculate winner move
      for (ll j = i + 1; j < len; j++)
      {

        // computation and if last result store in map
        string winnerMove;
        ll winnerIndex;
        string prevWinnerMove = moves[prevWinner]; // for which we are calculating
        string currentPlayerMove = moves[j];       // competing with

        if (rps.find(make_pair(prevWinnerMove, currentPlayerMove))->second == 0)
        {
          // prev player wins
          if (j == len - 1)
          {
            result = prevWinnerMove + result;
            results[prevWinner] = prevWinnerMove;
          }
        }
        else
        {
          // prev player looses -> computation present
          result = results.find(j)->second + result;
          results[prevWinner] = results.find(j)->second;
          break;
        }
      }
    }
    cout << result << "\n";
  }

  return 0;
}
