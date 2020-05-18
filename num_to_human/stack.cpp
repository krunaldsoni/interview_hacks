#include <iostream>
#include <stack>

using namespace std;


string decimal_place_to_string(uint64_t rem)
{
	switch (rem)
	{
	case 10: return "ten";
	case 11: return "eleven";
	case 12: return "tweleve";
	case 13: return "thirteen";
	case 14: return "fourteen";
	case 15: return "fifteen";
	case 16: return "sixteen";
	case 17: return "seventeen";
	case 18: return "eighteen";
	case 19: return "nineteen";
	case 20: return "twenty";
	case 30: return "thirty";
	case 40: return "fourty";
	case 50: return "fifty";
	case 60: return "sixty";
	case 70: return "seventy";
	case 80: return "Eighty";
	case 90: return "ninty";
	default: return "";
	}
}

string digit_to_string(uint64_t rem)
{
	switch (rem)
	{
	case 1: return "one";
	case 2: return "two";
	case 3: return "three";
	case 4: return "four";
	case 5: return "five";
	case 6: return "six";
	case 7: return "seven";
	case 8: return "Eight";
	case 9: return "nine";
	case 0: return "zero";
	default: return "";
	}
}
string l_to_string(uint64_t lvl)
{
	switch (lvl) {
	case 1000:
		return "thousand";
	case 1000000:
		return "million";
	case 1000000000:
		return "billion";
	case 1000000000000:
		return "trillion";
	default:
		return "";
	}
}
string three_digit_num_to_string(uint64_t num)
{
	string s = "";
	if (num >= 100) {
		s.append(digit_to_string(num/100));
		s.append(" hundred ");
	}
	num = num % 100;
	if (num >= 20 || num < 10) {
		   s.append(decimal_place_to_string((num / 10) * 10));
		   s.append(" ");
		   s.append(digit_to_string(num % 10));
		   s.append(" ");
	} else if (num >= 10) {
		   s.append(decimal_place_to_string(num));
		   s.append(" ");
	}

	return s;
}

void print_num_to_string(uint64_t num)
{
	uint64_t rem = 0, lvl = 1;
	stack<int64_t> r, l;

	while(num)
	{
		rem = num % 1000;
		num = num / 1000;
		r.push(rem);
		l.push(lvl);
		lvl = lvl * 1000;
	}

	if (r.empty())
	{
		return;
	}
	else
	{
		while (!r.empty())
		{
			cout << three_digit_num_to_string(r.top()) << l_to_string(l.top()) <<" ";
			r.pop();
			l.pop();
		}
	}
}

int main()
{
	cout << "hello" << endl;
	cout << "12345678 = ";
	print_num_to_string(12345678);
	cout << endl;
	cout << "12345 = ";
    print_num_to_string(12345);
    cout << endl;
	cout << "123456 = ";
    print_num_to_string(123456);
    cout << endl;
	cout << "\n";
	return 0;
}
