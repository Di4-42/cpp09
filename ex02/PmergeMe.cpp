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

template <typename T>
static void formerPaires(const T& ordre, const T& value, T& highers, T& partner)
{
    for(size_t i = 0; i + 1 < ordre.size(); i += 2)   //formation des paires
    {
        int higher = ordre[i];
        int lower = ordre[i + 1];

        if (value[higher] < value[lower])    //si highers contient le plus petit swap
            std::swap(higher, lower);

        highers.push_back(higher);
        partner[higher] = lower;
    }

}

template <typename T>
static T recupererPetits(const T& ordre, T& highers, T& partner)
{
    T attente;

    for(size_t i = 0; i < highers.size(); i++)
        attente.push_back(partner[highers[i]]);

    if (ordre.size() % 2 != 0)  //chopper les pas paires
        attente.push_back(ordre.back());
    
    return attente;
}

template <typename T>
static size_t chercherPosition(const T& chain, const T& value, int id, size_t right)
{
    size_t left = 0;
    size_t middle = 0;

    while (left < right)
    {
        middle = left + (right - left) / 2;

        if (value[chain[middle]] < value[id])
            left = middle + 1;
        
        else
            right = middle;
    }
    return left;
}