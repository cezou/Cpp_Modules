#include "Contact.hpp"

void Contact::set(size_t field, std::string val)
{
	if (field == first_name)
		this->_first_name = val;
	if (field == last_name)
		this->_last_name = val;
	if (field == nick_name)
		this->_nick_name = val;
	if (field == number)
		this->_number = val;
	if (field == secret)
		this->_secret = val;
}
std::string Contact::get(size_t field)
{
	if (field == first_name)
		return (this->_first_name);
	if (field == last_name)
		return (this->_last_name);
	if (field == nick_name)
		return (this->_nick_name);
	if (field == number)
		return (this->_number);
	if (field == secret)
		return (this->_secret);
	return ("False field");
}
Contact::Contact()
{
}
Contact::~Contact()
{
}