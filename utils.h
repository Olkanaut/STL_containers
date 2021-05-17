#pragma once

#include <iostream>
# include "list.h"

namespace ft
{
	struct true_type {};
	struct false_type {};

	template<typename T>
	struct is_int
	{
		// enum { value = 0 };
		typedef false_type type;
	};

	template<>
	struct is_int<int>
	{
		// enum { value = 1 };
		typedef true_type type;
	};


	struct str_type {};
	struct notstr_type {};

	template<typename T>
	struct is_string
	{
		// enum { value = 0 };
		typedef notstr_type type;
	};

	template<>
	struct is_string<std::string>
	{
		// enum { value = 1 };
		typedef str_type type;
	};


	struct int_type {};
	struct char_type {};
	struct string_type {};
	struct long_type {};
	struct undef_type {};

	template<typename T>
	struct what_type { typedef undef_type type; };

	template<>
	struct what_type<int> { typedef int_type type; };

	template<>
	struct what_type<char> { typedef char_type type; };

	template<>
	struct what_type<std::string> { typedef string_type type; };

	template<>
	struct what_type<long> { typedef long_type type; };


	std::string	to_string(size_t num, int base)
	{
		const char		*dict = "0123456789";

		if (num == 0)
			return (std::string("0"));
		std::string res;
		while (num)
		{
			res.insert(res.begin(), dict[num % base]);
			num /= base;
		}
		return (res);
	}
}
