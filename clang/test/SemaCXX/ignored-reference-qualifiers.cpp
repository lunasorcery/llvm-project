// RUN: %clang_cc1 %s -std=c++11 -Wignored-qualifiers -verify

const int scalar_c(); // expected-warning{{'const' type qualifier on return type has no effect}}
volatile int scalar_v(); // expected-warning{{'volatile' type qualifier on return type has no effect}}
const volatile int scalar_cv(); // expected-warning{{'const volatile' type qualifiers on return type have no effect}}

typedef int& IntRef;

const IntRef ref_c(); // expected-warning{{'const' qualifier on reference type 'IntRef' (aka 'int &') has no effect}}
volatile IntRef ref_v(); // expected-warning{{'volatile' qualifier on reference type 'IntRef' (aka 'int &') has no effect}}
const volatile IntRef ref_cv(); /* expected-warning{{'const' qualifier on reference type 'IntRef' (aka 'int &') has no effect}} \
                                expected-warning{{'volatile' qualifier on reference type 'IntRef' (aka 'int &') has no effect}} */

template<typename T>
class container {
	using value_type = T;
	using reference  = value_type&;
	reference get();
	const reference get() const; // expected-warning{{'const' qualifier on reference type 'container::reference' (aka 'T &') has no effect}}
};
