#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int A, B, now, next;
		cin >> A >> B;

		bool check[10000] = { false, };
		char how[10000] = { '\0', };
		int from[10000] = { 0, };

		queue<int> reg;
		reg.push(A);
		check[A] = true;

		while (!reg.empty()) {
			now = reg.front();
			reg.pop();

			next = (now * 2) % 10000;
			if (check[next] == false) {
				reg.push(next);
				check[next] = true;
				how[next] = 'D';
				from[next] = now;
			}

			if (now == 0) next = 9999;
			else next = now - 1;
			if (check[next] == false) {
				reg.push(next);
				check[next] = true;
				how[next] = 'S';
				from[next] = now;
			}

			next = (now % 1000) * 10 + (now / 1000);
			if (check[next] == false) {
				reg.push(next);
				check[next] = true;
				how[next] = 'L';
				from[next] = now;
			}

			next = (now % 10) * 1000 + (now / 10);
			if (check[next] == false) {
				reg.push(next);
				check[next] = true;
				how[next] = 'R';
				from[next] = now;
			}
		}
		string ans = "";
		while (A != B) {
			ans += how[B];
			B = from[B];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}