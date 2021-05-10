#include <string>
#include <iostream>
#include <map>
#include "pclass.h"
#include <fstream>
#include <bits/stdc++.h>

void display_pupil(const Pupil& pup);
void display_quarter(const pclass& cls);
void pupil_name(pclass& cls);
void set_grade_subject(pclass& cls);
int  display_menu();
void display_quarter_average(const pclass& cls);
void display_class(pclass& pclass);
void save_class_data(pclass& class1,std::fstream&);
void create_class_from_file(pclass& class1,std::fstream&);
void add_pupil(pclass& class1);

int main() {
	pclass new_class;
	pclass class_from_file;
	std::fstream class_data;
	std::fstream class_file;
	bool done = false;

	while (!done) {
		int selection = display_menu();

		switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			add_pupil(new_class);
			break;
		case 2:
			pupil_name(new_class);
			break;
		case 3:
			set_grade_subject(new_class);
			break;
		case 4:
			display_class(new_class);
			break;
		case 5:
			int i;
			std::cout<<"Pupil Id";
			std::cin>>i;
			display_pupil(*(new_class[i]));
			break;
		case 6:
			display_quarter(new_class);
			break;
		case 7:
			display_quarter_average(new_class);
			break;
		case 8:
			class_data.open("tt.txt");
			if(!class_file.is_open()){
  				std::cerr<<"Error8";
					}
			save_class_data(new_class,class_data);
			class_data.close();
			break;
		case 9:
			
			class_file.open("tt.txt");
			if(!class_file.is_open()){
  				std::cerr<<"Error9";
					}
			create_class_from_file(class_from_file, class_file);
			display_class(class_from_file);
			class_file.close();
			break;
		default:
			std::cerr << "Unknown command." << std::endl;
			break;
		}
	}
	display_class(class_from_file);
	return 0;
}

void display_pupil(const Pupil& pup) {
	
	std::cout <<"ID number: " << pup.get_pupil_id()<<std::endl;
	std::cout << pup.get_name() << " " << pup.get_lastName() << std::endl;
	pup.display_quarter();
	std::cout << "--------------------------" << std::endl;
}

void display_quarter(const pclass& cls) {
	int index;
	std::cout << "Pupils Id? " << std::endl;
	std::cin>>index;
	cls[index]->display_quarter();
}

void pupil_name(pclass& cls) {
	int index;
	std::string name;
	std::string	lastName;
	std::cout << "Pupils Id? " << std::endl;
	std::cin>>index;
	std::cout << "Set name? " << std::endl;
	std::cin >> name;
	std::cout << "Set last name? " << std::endl;
	std::cin >> lastName;
	cls[index]->set_name(name);
	cls[index]->set_lastName(lastName);
}

void add_pupil(pclass& class1){
	class1.add_pupil();
	std::cout<<"Pupil is added"<<std::endl;
}

void create_class_from_file(pclass& class1,std::fstream& class_file){
	std::string temp_s;
	std::vector<std::string>  temp;

	while(!class_file.eof()){
		std::string m;
		getline(class_file,temp_s);
		std::istringstream ss(temp_s);
		while(ss>>m){
			temp.push_back(m);
		}
		int counter=0;
		for(int i=0;i<temp.size();++i){
			if(temp[i]=="Id:"){
				class1.add_pupil();
				counter++;
			}
			if(temp[i]=="Name:"){
				class1[counter]->set_name(temp[i+1]);
			}
			if(temp[i]=="Last"){
				class1[counter]->set_name(temp[i+2]);
			}
			if(temp[i]=="Subject:"){
				std::string s=temp[i+3];
				int m=std::stoi(s);
				class1[counter]->set_quarter(temp[i+1],m);
			}
		}
		temp.clear();
	}
}

void save_class_data(pclass& class1, std::fstream& data){
	for(int i=0; i<class1.pupil_count(); ++i){
		data<<"       Id: "<<class1[i]->get_pupil_id()<<std::endl;
		data<<"     Name: "<<class1[i]->get_name()<<std::endl;
		data<<"Last Name: "<<class1[i]->get_lastName()<<std::endl;
		for(auto &x:class1[i]->get_quarter()){
			data<<"  Subject: "<<x.first<<" - "<<x.second<<" pts"<<std::endl;
			}
		data<<std::endl;
	}
}
void display_class(pclass& cls){
	if(cls.pupil_count()==0){
		std::cout<<"No pupil in the class"<<std::endl;
	}
	for(int i=0;i<cls.pupil_count();++i){
		display_pupil(*(cls[i]));
	}
}
int display_menu() {
	int selection;
	std::cout << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "1) Create pupil" << std::endl;
	std::cout << "2) Set pupil data" << std::endl;
	std::cout << "3) Set grades for subjects" << std::endl;
	std::cout << "4) Display class" << std::endl;
	std::cout << "5) Display pupil data" << std::endl;
	std::cout << "6) Display pupil grades for quarter" << std::endl;
	std::cout << "7) Display average for quarter" << std::endl;
	std::cout << "8) Save the class" << std::endl;
	std::cout << "9) Create a class from a file" << std::endl;
	std::cout << "0) Quit" << std::endl;
	std::cout << std::endl;
	std::cout << "---> ";
	std::cin >> selection;
	return selection;
	}

void set_grade_subject(pclass& cls) {
	int index;
	std::cout << "Pupils Id? " << std::endl;
	std::cin>>index;
	std::string sub;
	std::string s="st";
	int grade;
	
	while (s!="stop") {
		
		std::cout << "Subject name? " << std::endl;
		std::cin >> sub;
		std::cout << "Grade value( from 1 to 100)? " << std::endl;
		std::cin >> grade;
		if (grade > 0 && grade < 101) {
			cls[index]->set_quarter(sub, grade);
		}
		else
			std::cout << "Out of grade range" << std::endl;

		std::cout << "Type <stop> to finish or any key to continue. " << std::endl;
		std::cin >> s;
	}
}

void display_quarter_average(const pclass& cls) {
	int index;
	std::cout << "Pupils Id? " << std::endl;
	std::cin>>index;
	std::cout<<"The average quarter grade is: "<<cls[index]->get_avg_quarter() << std::endl;
}