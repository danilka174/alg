#include <iostream>
#include <cstdlib> // ��� system
#include <cmath>
using namespace std;

enum num_of_roots {
	zero_roots,
	one_root,
	two_roots
};

struct coefficients {
	double a;
	double b;
	double c;
};
struct answer {
	double x1;
	double x2;
	num_of_roots num;
};

void Interface(coefficients* coef) {
	std::cout << "������� ������������ a, b � c:" << endl;
	std::cout << "a: ";
	std::cin >> coef->a;
	std::cout << "b: ";
	std::cin >> coef->b;
	std::cout << "c: ";
	std::cin >> coef->c;
	return;
}

answer Equation(coefficients coef) {
	answer ans;
	double D = coef.b * coef.b - 4 * coef.a * coef.c;
	if (D >= 0) //���� ������������ ������ ��� ����� 0
	{
		ans.x1 = (-1 * coef.b + sqrt(D)) / (2 * coef.a);
		ans.x2 = (-1 * coef.b - sqrt(D)) / (2 * coef.a);
		if (ans.x1 == ans.x2) {
			ans.num = one_root;
		}
		else {
			ans.num = two_roots;
		}
	}
	else
	{
		ans.num = zero_roots;
	}
	return ans;
}

void PrintAnswers(answer ans) {
	if (ans.num == zero_roots) {
		cout << "������ ���." << endl;
	}
	if (ans.num == one_root) {
		cout << "������������ ������ ����� " << ans.x1 << endl;
	}
	else if (ans.num == two_roots) {
		cout << "������ ������ ����� " << ans.x1 << endl;
		cout << "������ ������ ����� " << ans.x2 << endl;
	}
}

int main()
{
	coefficients coef;
	answer ans;
	setlocale(LC_ALL, "Russian");
	Interface(&coef);
	ans = Equation(coef);
	PrintAnswers(ans);
    return 0;
}