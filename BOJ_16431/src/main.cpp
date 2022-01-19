#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int br, bc;
	cin >> br >> bc;

	int dr, dc;
	cin >> dr >> dc;

	int jr, jc;
	cin >> jr >> jc;

	// bessie
	auto bessie = int{ 0 };

	const auto& dBr = jr - br;
	const auto& dBc = jc - bc;
	const auto& diag = abs(dBr) < abs(dBc) ? abs(dBr) : abs(dBc);

	if (0 != dBr) {
		br += diag * dBr / abs(dBr);
	}

	if (0 != dBc) {
		bc += diag * dBc / abs(dBc);
	}

	bessie += diag;

	if (0 != (br - jr)) {
		bessie += abs(br - jr);
	}
	else if (0 != (bc - jc)) {
		bessie += abs(bc - jc);
	}

	// daisy
	const auto& daisy = abs(jr - dr) + abs(jc - dc);

	// answer
	if (bessie < daisy) {
		cout << "bessie";
	}
	else if (daisy < bessie) {
		cout << "daisy";
	}
	else {
		cout << "tie";
	}

	return 0;
}