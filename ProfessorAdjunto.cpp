#include "ProfessorAdjunto.hpp"

using namespace ufpr;
unsigned int ProfessorAdjunto::getSalario() const{
	return Professor::getSalario()*1.1;
}
