#include "persons.h"
#include <string> 

Person::Person(){
    name_ = "UNKNOWN";
    birth_year_ = -1;
}

Person::Person(std::string name, int birth_year){
    name_ = name;
    birth_year_ = birth_year;
}

Cyclist::Cyclist(){
    team_ = "UNKNOWN";
    cyclist_id_ = "UNKNOWN";
}

Cyclist::Cyclist(std::string name, int birth_year, std::string team, std::string cyclist_id)
    :Person(name, birth_year){

        team_ = team;
        cyclist_id_ = cyclist_id;
}

Director::Director(){
    team_ = "UNKNOWN";
    uci_license_id_ = "UNKNOWN";
    director_since_ = -1;
}

Director::Director(std::string name, int birth_year, std::string team, std::string uci_license_id, int director_since)
    :Person(name, birth_year){
        team_ = team;
        uci_license_id_ = uci_license_id;
        director_since_ = director_since;
}

Journalist::Journalist(){
    media_ = "UNKNOWN";
}

Journalist::Journalist(std::string name, int birth_year, std::string media)
    :Person(name, birth_year){

        media_ = media;
    }

bool Journalist::SetMedia(std::string media){
    if(media == ""){
        media_ = "UNKNOWN";
        return false;
    } else {
        media_ = media;
        return true;
    }
}

std::string PrintComment(IRole* role){
    return role->GetRole() + role->GetComment();
}

bool Cyclist::SetComment(std::string self_report){
    if(self_report == ""){
        return false;
    } else {
        self_report_ = self_report;
        return true;
    }
}

std::string Cyclist::GetComment(){
    return "COMENTARIO CICLISTA\n" + self_report_ + "\n";
}

std::string Cyclist::GetRole(){
    return GetName() + "," + std::to_string(GetBirthYear()) + "," + team_ + "," + cyclist_id_ + "\n";
}

bool Director::SetComment(std::string team_report){
    if(team_report == ""){
        return false;
    } else {
        team_report_ = team_report;
        return true;
    }
}

std::string Director::GetComment(){
    return "COMENTARIO DIRECTOR\n" + team_report_ + "\n";
}

std::string Director::GetRole(){
    return GetName() + "," + std::to_string(GetBirthYear()) + "," + team_ + "," + uci_license_id_ + "," + std::to_string(director_since_) + "\n";
}

bool Journalist::SetComment(std::string id, std::string comments){
    if(id == "" || comments == ""){
        return false;
    } else {
        comments_[id] = comments;
        return true;
    }
}

std::string Journalist::GetComment(){
    std::string result = "COMENTARIO JOURNALIST\n";

    for(const auto& pair : comments_){
        result = result + pair.first + "," + pair.second + "\n";
    }

    return result;
}

std::string Journalist::GetRole(){
    return GetName() + "," + std::to_string(GetBirthYear()) + "," + media_ + "\n"; 
}