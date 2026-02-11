#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : name("UNKNOWN"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
}

Form::Form(const std::string& name, const int grade_to_sign, const int grade_to_execute) 
: name(name), is_signed(false), grade_to_sign(check_grade(grade_to_sign)), grade_to_execute(check_grade(grade_to_execute))
{
}

Form::Form(const Form& other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	*this = other;
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
		this->is_signed = other.is_signed;
	return (*this);
}

Form::~Form()
{
}

const std::string&	Form::getName() const
{
	return (this->name);
}

bool	Form::getIsSigned() const
{
	return (this->is_signed);
}

int	Form::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int	Form::getGradeToExecute() const
{
	return (this->grade_to_execute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->is_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName();
	os << ", signed: " << (form.getIsSigned()? "true" : "false");
	os << ", grade to sign: " << form.getGradeToSign();
	os << ", grade to execute: " << form.getGradeToExecute() << ".";
	return (os);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

int	Form::check_grade(const int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return(grade);
}
