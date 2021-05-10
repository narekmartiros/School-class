#include "Pupil.h"
#include <string>
#include <iostream>
#include <map>

int Pupil::id = 0;

Pupil::Pupil() : m_name{ "noname" }, m_lastName{ "nolastname" }, m_class{ 1 }, m_pupil_id{ ++id }
{

}

Pupil::Pupil(std::string& name, std::string& lastName) :m_name{ name }, m_lastName{ lastName }, m_class{ 1 }, m_pupil_id{ ++id }
{

}

Pupil::Pupil(Pupil& p): m_pupil_id{ ++id } {
	m_name = p.m_name;
	m_lastName = p.m_lastName;
	m_class = p.m_class;
	m_quarter = p.m_quarter;
}

void Pupil::set_name(const std::string& name) {
	m_name = name;
}

void Pupil::set_lastName(const std::string& lastName) {
	m_lastName = lastName;
}

const std::string& Pupil::get_name() const {
	return m_name;
}
const std::string& Pupil::get_lastName()const {
	return m_lastName;
}

void Pupil::set_class(const int& cl) {
	m_class = cl;
}

const int Pupil::get_class()const {
	return m_class;
}

void Pupil::set_quarter(const std::string& s, int gr) {
	m_quarter.emplace(s, gr);
}
	
const std::map<const std::string,int>& Pupil::get_quarter() const{
	return m_quarter;
}

void Pupil::display_quarter()const {
	for (auto& x : m_quarter) {
		std::cout << x.first << "\t" << x.second << std::endl;
	}
}

int Pupil::get_pupil_id()const {
	return m_pupil_id;
}

int Pupil::get_avg_quarter()const {
	int sum = 0;
	for (auto& x : m_quarter) {
		sum += x.second;
	}
	return sum / m_quarter.size();
}