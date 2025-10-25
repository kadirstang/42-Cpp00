#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact();

		void		setFirstName(const std::string& _firstName);
		void		setLastName(const std::string& _lastName);
		void		setNickname(const std::string& _nickname);
		void		setPhoneNumber(const std::string& _phoneNumber);
		void		setDarkestSecret(const std::string& _darkestSecret);

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};

#endif
