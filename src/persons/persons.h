#ifndef PERSONS_H
#define PERSONS_H

#include <string>
#include <vector>
#include <map>
class IRole{

    public: 
            virtual std::string GetRole() = 0;
            virtual std::string GetComment() = 0;

};

std::string PrintComment(IRole* role);
class Person{

    private:
            std::string name_;
            int birth_year_;

    public:
            Person();
            Person(std::string name, int birth_year);
            
            std::string GetName()const {return name_;}
            int GetBirthYear()const {return birth_year_;}

            void SetName(std::string name){name_ = name;};
            void SetBirthYear(int birth_year){birth_year_ = birth_year;};

};

class Cyclist:public Person, public IRole{

    private:
            std::string team_;
            std::string cyclist_id_;
            std::string self_report_;

    public:
            Cyclist();
            Cyclist(std::string name, int birth_year, std::string team, std::string cyclist_id);

            std::string GetTeam()const {return team_;}
            std::string GetCyclistId()const {return cyclist_id_;}

            void SetTeam(std::string team){team_ = team;};
            void SetCyclistId(std::string cyclist_id){cyclist_id_ = cyclist_id;};

            bool SetComment(std::string self_report);
            std::string GetRole() override;
            std::string GetComment() override;

};

class Director:public Person, public IRole{

    private:
            std::string team_;
            std::string uci_license_id_;
            int director_since_;
            std::string team_report_;
    
    public:
            Director();
            Director(std::string name, int birth_year, std::string team, std::string uci_license_id, int director_since); ///////

            std::string GetTeam()const {return team_;}
            std::string GetUciLicenseId()const {return uci_license_id_;}
            int GetDirectorSince()const {return director_since_;}

            void SetTeam(std::string team){team_ = team;};
            void SetUciLicenseId(std::string uci_license_id){uci_license_id_ = uci_license_id;};
            void SetDirectorSince(int director_since){director_since_ = director_since;};

            bool SetComment(std::string team_report);
            std::string GetRole() override;
            std::string GetComment() override;

};

class Journalist:public Person, public IRole{

    private:
            std::string media_;
            std::map<std::string, std::string> comments_;

    public:
            Journalist();
            Journalist(std::string name, int birth_year, std::string media);

            std::string GetMedia()const {return media_;}

            bool SetMedia(std::string media);

            bool SetComment(std::string id, std::string comments);
            std::string GetRole() override;
            std::string GetComment() override;

};

#endif