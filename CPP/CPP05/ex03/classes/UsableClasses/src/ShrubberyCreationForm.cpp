#include "../header/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", target , 145, 137) {

}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {

	}
	return (*this);
}

void ShrubberyCreationForm::executeConcrete() const {
	std::ofstream file;
	std::string filename = this->getTarget() + "_shrubbery";
	file.open(filename.c_str());
	if (!file.is_open()) {
		throw std::ios_base::failure("Failed to open file: " + filename);
	}
	file << "       ###\n";
	file << "      #o###\n";
	file << "    #####o###\n";
	file << "   #o#\\#|#/###\n";
	file << "    ###\\|/#o#\n";
	file << "     # }|{  #\n";
	file << "       }|{\n";
	file << "\n";
	file << "       ###\n";
	file << "      #o###\n";
	file << "    #####o###\n";
	file << "   #o#\\#|#/###\n";
	file << "    ###\\|/#o#\n";
	file << "     # }|{  #\n";
	file << "       }|{\n";
	file.close();
}
