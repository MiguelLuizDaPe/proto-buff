#ifndef _test_hpp_include_
#define _test_hpp_include_

#include <cstdio>

struct Test {
	int total = 0;
	int failed = 0;
	const char* title = "";

	void expect(bool cond){
		total += 1;
		if(!cond){
			failed += 1;
		}
	}

	void expect(bool cond, const char* msg, const char* file, int line){
		total += 1;
		if(!cond){
			failed += 1;
			std::printf("[%s:%d] Expect failed: %s\n", file, line, msg);
		}
	}

	bool summary() const {
		auto succ = failed == 0;
		std::printf("[%s] ", title);
		if(succ){
			std::printf("SUCCESS");
		}
		else {
			std::printf("FAILED");
		}

		std::printf(" ok in %d/%d\n", total - failed, total);
		return failed == 0;
	}

	Test(const char* title)
		: title{title} {}
};

#define Ex(t_, cond_) (t_).expect((cond_), #cond_, __FILE__, __LINE__)

#endif /* Include guard */
