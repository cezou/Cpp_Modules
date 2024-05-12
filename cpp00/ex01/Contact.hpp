#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iomanip>
# include <iostream>
# include <sstream>
# include <algorithm>
# include <cctype>

class Contact
{
  public:
	void set(size_t field, std::string val);
	std::string get(size_t field);
	Contact();
	~Contact();

  private:
	std::string _first_name;
	std::string _last_name;
	std::string _nick_name;
	std::string _number;
	std::string _secret;
};

typedef enum field
{
	first_name,
	last_name,
	nick_name,
	number,
	secret
}	field;

#endif