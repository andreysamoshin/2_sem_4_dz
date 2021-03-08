#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <deque>
#include <list>
#include <set>
#include <random>



// First (Sequence 1 filling)
std::vector <int> seq1 = { 7, 2, 1, 9, 4, 6, 3, 5, 10, 8 };

// Second (Adding some elements)
std::copy(std::istream_iterator < int >(std::cin),
	std::istream_iterator < int >(),
	std::back_inserter(seq1));

std::cout << "1st after extra inputting:";
std::for_each(std::begin(seq1),
	std::end(seq1),
	[](auto x) {std::cout « x « ' '; });

std::cout << "\n\n";

// Third (Mixing)

std::random_device rd;
std::mt19937 g(rd());

std::shuffle(seq1.begin(), seq1.end(), g);

std::cout << "After mixing :\n";
std::for_each(std::begin(seq1),
	std::end(seq1),
	[](auto x) {std::cout « x « ' '; });

std::cout « "\n\n";

// Fourth (duplicates removing)
std::sort(std::begin(seq1), std::end(seq1));
seq1.erase(std::unique(std::begin(seq1), std::end(seq1)), std::end(seq1));

std::for_each(std::begin(seq1),
	std::end(seq1),
	[](auto x) {std::cout « x « ' '; });

std::cout << "\n\n";

// Fifth (amount of odd numbers)
auto amount_of_odds = std::count_if(std::begin(seq1), std::end(seq1), [](auto x) {return x % 2; });

std::cout << "Amount of odd numbers :\n" << amount_of_odds « std::endl;

// Sixth (find min and max)
auto [min, max] = std::minmax_element(std::begin(seq1), std::end(seq1));

std::cout << "min : " << *min << "\nmax : " << *max << std::endl;
std::cout << "\n\n";

std::transform(std::begin(seq1), std::end(seq1), std::begin(seq1),
	[](auto x) { return x * x; });

std::cout << "Squares :\n";
std::for_each(std::begin(seq1),
	std::end(seq1),
	[](auto x) {std::cout « x « ' '; });

std::cout << "\n\n";

// Ninth (Sequence 2 creating)
std::vector <int> seq2(seq1.size());

std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());;
std::uniform_int_distribution <> uid(0, 10);

std::generate(std::begin(seq2), std::end(seq2), [&dre, &uid]() {return uid(dre); });

std::cout << "2nd sequence:\n" « std::endl;

std::for_each(std::begin(seq2),
	std::end(seq2),
	[](auto x) {std::cout « x « ' '; });

std::cout << "\n\n";

// Tenth (sum(sqe2))

std::cout << "Sum of 2nd sequence:\n" « std::accumulate(std::begin(seq2), std::end(seq2),
	decltype(seq2)::value_type(0));
std::cout << "\n\n";
