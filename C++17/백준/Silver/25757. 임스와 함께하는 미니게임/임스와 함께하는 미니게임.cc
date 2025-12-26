#include <iostream>
#include <queue>
using namespace std;

class human {
public:
	human() : name(NULL), left(NULL), right(NULL) {};
	human(string name) : name(name), left(NULL), right(NULL) {};
	static int get_num() { return num; };
	void connect(human* ptr);
	static int num;

private:
	string name;
	human* left;
	human* right;
};

int human::num = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, required_people;
	char Game;
	string name;
	human* root;
	cin >> N >> Game;
	switch (Game) {
	case 'Y':
		required_people = 1;
		break;
	case 'F':
		required_people = 2;
		break;
	case 'O':
		required_people = 3;
		break;
	default:
		required_people = 10;
	}
	cin >> name;
	root = new human(name);
	for (int i = 1; i < N; ++i) {
		cin >> name;
		human* temp_human = new human(name);
		root->connect(temp_human);
	}
	// cout << (root->get_num()) << '\n';
	cout << (root->get_num() / required_people);
	return 0;
}

void human::connect(human* ptr) {
	if (name < ptr->name) { // set to right
		if (right == NULL) {
			right = ptr;
			num++;
		}
		else {
			right->connect(ptr);
		}
	}
	else if (name > ptr->name) {
		if (left == NULL) {
			left = ptr;
			num++;
		}
		else left->connect(ptr);
	}
	else { delete ptr; }
}