#include "Pupil.h"
#include <vector>

class pclass{
    public:
    pclass();
    pclass(int size);
    ~pclass();
    void add_pupil();
    Pupil get_pupil(int id);
    Pupil*  operator[](int index);
    Pupil* operator[](int index) const;
    int pupil_count();

    private:
    std::vector<Pupil*> m_class;
    std::string m_class_name;


};