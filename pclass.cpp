#include "pclass.h"

pclass::pclass(){};
pclass::pclass(int size){
  for(int i=0;i<size;++i){
    m_class.push_back(new Pupil);
  }
}

pclass::~pclass(){
  for(int i=0;i<m_class.size();++i){
    delete m_class[i];
  }
}

void pclass::add_pupil(){
   m_class.push_back(new Pupil);
  }

int pclass::pupil_count(){
  return m_class.size();
}

Pupil pclass::get_pupil(int x){
   return *m_class[x];
  }

Pupil*  pclass::operator[](int index){
    return m_class[index];
  }

 Pupil* pclass::operator[](int index)const{
    return m_class[index];
  }