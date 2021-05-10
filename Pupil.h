#include <string>
#include <map>


class Pupil {
public:
	Pupil();
	Pupil(std::string& name, std::string& lastName);
	Pupil(Pupil& p);
	void set_name(const std::string& name);
	void set_lastName(const std::string& lastName);
	const std::string& get_name() const;
	const std::string& get_lastName()const;
	void set_class(const int& cl);
	const int get_class()const;
	void set_quarter(const std::string& s, int gr);
	const std::map<const std::string,int>& get_quarter()const;
	void display_quarter()const;
	int get_avg_quarter()const;
	int get_pupil_id()const;

private:
	std::string m_name;
	std::string m_lastName;
	short m_class;
	const int m_pupil_id;
	static int id;
	std::map<const std::string, int> m_quarter;
};
