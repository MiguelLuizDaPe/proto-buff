
// #include "test/integers.cpp"

#include "test.hpp"

bool test_cu (){
	auto t = Test("Cuzao");

	Ex(t, 2 + 2 < 69);
	Ex(t, 2 + 2 == 4);

	return t.summary();
}

int main(){
	bool ok = true
		&& test_cu()
	;
	return int(!ok);
}
