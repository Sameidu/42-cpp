#include "ShrubberyCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm() : AForm("ShruberryCreationForm", 145, 137), _target("none") {}

ShruberryCreationForm::~ShruberryCreationForm() {}

ShruberryCreationForm::ShruberryCreationForm(std::string target) : AForm("ShruberryCreationForm", 145, 137), _target(target) {}

ShruberryCreationForm::ShruberryCreationForm(ShruberryCreationForm const &other) : AForm(other) {
	if (this == &other)
		return;
	*this = other;
}

ShruberryCreationForm &ShruberryCreationForm::operator=(const ShruberryCreationForm &other) {
	if (other.getGradeToSign() < 1 || other.getGradeToExec() < 1)
		throw AForm::GradeTooHighException();
	else if (other.getGradeToSign() > 150 || other.getGradeToExec() > 150)
		throw AForm::GradeTooLowException();
	_target = other._target;
	return *this;
}

void ShruberryCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	std::ofstream file;
	
	std::string target = _target + "_shrubbery";
	const char *newFile = target.c_str();
	file.open(newFile);
	file << "            .        +          .      .          .\n"
		 << "     .            _        .                    .\n"
		 << "  ,              /;-._,-.____        ,-----.__\n"
		 << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
		 << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
		 << "                      ,    `./  \\:. `.   )==-'  .\n"
		 << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
		 << ".           \\/:/`-' , ,'-\\ '` ` `   ): , /_  -o\n"
		 << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
		 << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
		 << "   `.   (    \\: \\,-._` ` + \'\\, ,\"   _,--._,---\":.__/\n"
		 << "              \\:  `  X` _| _,\\/'   .-'\n"
		 << ".               \":._:`\\____  /:'  /      .           .\n"
		 << "                    \\::.  :\\/:'  /              +\n"
		 << "   .                 `.:.  /:'  }      .\n"
		 << "           .           ):_(:;   \\           .\n"
		 << "                      /:. _/ ,  |\n"
		 << "                   . (|::.     ,`                  .\n"
		 << "     .                |::.    {\\\n"
		 << "                      |::.\\  \\ `.\n"
		 << "                      |:::(\\    |\n"
		 << "              O       |:::/{ }  |                  (o\n"
		 << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
		 << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"
		 << "~~~   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~\n"
		 << "  ~         ~         ~   ~      ~       ~\n";
	file.close();
}