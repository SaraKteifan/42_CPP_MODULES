#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <exception>
# include <ostream>

class Bureaucrat;  // forward declaration

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_to_sign;
		const int			grade_to_execute;
		static int			check_grade(const int grade);
	public:
		Form();
		Form(const std::string& name, const int grade_to_sign, const int grade_to_execute);
		Form(const Form& other);
		Form&	operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& bureaucrat);
		
		class	GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
