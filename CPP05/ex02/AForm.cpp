#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : name("UNKNOWN"), target("UNKNOWN"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
}

AForm::AForm(const std::string& name, const std::string& target, const int grade_to_sign, const int grade_to_execute) 
: name(name), target(target), is_signed(false), 
	grade_to_sign(check_grade(grade_to_sign)), grade_to_execute(check_grade(grade_to_execute))
{
}

AForm::AForm(const AForm& other) : name(other.name), target(other.target),
	grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	*this = other;
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->is_signed = other.is_signed;
	return (*this);
}

AForm::~AForm()
{
}

const std::string&	AForm::getName() const
{
	return (this->name);
}

const std::string&	AForm::getTarget() const
{
	return (this->target);
}

bool	AForm::getIsSigned() const
{
	return (this->is_signed);
}

int	AForm::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int	AForm::getGradeToExecute() const
{
	return (this->grade_to_execute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->is_signed = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!this->is_signed)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->grade_to_execute)
		throw GradeTooLowException();
	else
		this->executeAction();
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName();
	os << ", signed: " << (form.getIsSigned()? "true" : "false");
	os << ", grade to sign: " << form.getGradeToSign();
	os << ", grade to execute: " << form.getGradeToExecute() << ".";
	return (os);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("form is not signed!");
}

int	AForm::check_grade(const int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return(grade);
}
