#include "Sed.hpp"
#include <iostream>
#include <fstream>

Sed::Sed(const std::string& filename,
	const std::string& s1,
	const std::string& s2)
	: infile(filename),
	outfile(filename + ".replace"),
	s1(s1),
	s2(s2)
{}

bool	Sed::replace()
{
	if (this->s1.empty())
	{
		std::cerr << "s1 cannot be empty." << std::endl;
		return (false);
	}

	std::ifstream in_file(this->infile.c_str());
	if (!in_file.is_open())
	{
		std::cerr << "Cannot open the file " << this->infile << std::endl;
		return (false);
	}
	std::ofstream out_file(this->outfile.c_str());
	if (!out_file.is_open())
	{
		std::cerr << "Cannot create the output file " << this->outfile << std::endl;
		in_file.close();
		return (false);
	}

	std::string	in_line;
	while (std::getline(in_file, in_line))
	{
		size_t n = 0;
		while (true)
		{
			size_t pos = in_line.find(this->s1, n);
			if (pos == std::string::npos)
				break;
			out_file << in_line.substr(n, pos - n);
			out_file << this->s2;
			n = pos + this->s1.length();
		}
		out_file << in_line.substr(n) << '\n';
	}
	in_file.close();
	out_file.close();
	return (true);
}
