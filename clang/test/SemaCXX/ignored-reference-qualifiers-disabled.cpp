// RUN: %clang_cc1 %s -std=c++11 -Wignored-qualifiers -Wno-ignored-reference-qualifiers -verify

const int scalar_c(); // expected-warning{{'const' type qualifier on return type has no effect}}
volatile int scalar_v(); // expected-warning{{'volatile' type qualifier on return type has no effect}}
const volatile int scalar_cv(); // expected-warning{{'const volatile' type qualifiers on return type have no effect}}

// no warnings expected below here, as we've disabled ignored-reference-qualifiers.
typedef int& IntRef;

const IntRef ref_c();
volatile IntRef ref_v();
const volatile IntRef ref_cv();

template<typename T>
class container {
	using value_type = T;
	using reference  = value_type&;
	reference get();
	const reference get() const;
};
