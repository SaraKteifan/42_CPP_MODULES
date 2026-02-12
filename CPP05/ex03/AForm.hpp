#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <exception>
# include <ostream>

class Bureaucrat;  // forward declaration

class AForm
{
	private:
		const std::string	name;
		const std::string	target;
		bool				is_signed;
		const int			grade_to_sign;
		const int			grade_to_execute;

		static int			check_grade(const int grade);

	public:
		AForm();
		AForm(const std::string& name, const std::string& target, const int grade_to_sign, const int grade_to_execute);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm();

		const std::string&	getName() const;
		const std::string&	getTarget() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& bureaucrat);
		void				execute(Bureaucrat const & executor) const;
		virtual void		executeAction() const = 0;
		
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
		class	FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class	GradeTooLowToExecuteException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
