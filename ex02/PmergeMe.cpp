#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << "Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& source) : _vec(source._vec), _deq(source._deq)
{
    std::cout << "Copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& source)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &source)
	{
		_vec = source._vec;
        _deq = source._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	std::cout << "Destructor called" << std::endl;
}

void PmergeMe::parseArgs(int argc, char **argv)
{
    if (argc < 2)
        throw std::runtime_error("Error: aucun numéro fournis");
    
    _vec.clear();

    for (int i = 1; i < argc; i++) 
    {
        std::string string(argv[i]); //copie pour use les fonction empty size

        if (string.empty())
            throw std::runtime_error("Error: argument vide");

        for(size_t j = 0; j < string.size(); j++)
        {
            if(!std::isdigit(static_cast<unsigned char>(string[j])))
                throw std::runtime_error("Error: l'arg doit contenir que des chiffres");
        }

        errno = 0;
        long val = std::strtol(string.c_str(), NULL, 10); //

        if (errno == ERANGE || val > INT_MAX)
            throw std::runtime_error("Error: number depasse INT_MAX");
        
        if (val <= 0)
            throw std::runtime_error("Error: number doit etre positif");
        
        int nombre = static_cast<int>(val); 
        _vec.push_back(nombre);
    }
}

static  std::vector<int> getJacobsthalOrder(int n)
{
    std::vector<int> ordre;
    int precedent = 1;
    int actuel = 3;

    while (precedent < n)
    {
        int end;
        end = std::min(actuel, n);  //prendre la plus petite valeur entre les 2

        for (int i = end; i > precedent; i--)
            ordre.push_back(i);
        
        int next = actuel + 2 * precedent;
        precedent = actuel;
        actuel = next;
    }
    return ordre;
}

int main()
{
    std::vector<int> resultat = getJacobsthalOrder(7);

    for (size_t i = 0; i < resultat.size(); i++)
        std::cout << resultat[i] << " ";
    std::cout << std::endl;

    return 0;
}