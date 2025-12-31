#ifndef SED_HPP
# define SED_HPP
# include <string>

class Sed
{
	private:
		std::string	infile;
		std::string	outfile;
		std::string	s1;
		std::string	s2;
	public:
		Sed(const std::string& filename,
			const std::string& s1,
			const std::string& s2);
		bool	replace();
};

#endif
