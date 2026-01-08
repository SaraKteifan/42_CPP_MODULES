#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("UNKNOWN"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	*this = other;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string&	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::increment_grade()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrement_grade()
{	
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: grade is too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: grade is too low!");
}