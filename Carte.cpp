//
// Created by amanda on 27/10/18.
//

#include "Carte.h"
#include "ObstacleTexture.h"
#include "LootTexture.h"
#include "DecorationTexture.h"
#include <math.h>



// THIS METHOD IS TO TEST A NEW FEATURE WHICH IS RENDERING CARTE BY LAYERS, THE LAST LAYERS CONTAIN ONLY OBSTACLE OBJECTS
Carte::Carte(std::string filename) {
    std::string line;

    std::ifstream carteFile("carte_1.txt");

    largeur=960;
    hauteur=640;

    std::getline(carteFile,line);
    largeur=std::stoi(line);
    std::getline(carteFile,line);
    hauteur=std::stoi(line);
    std::getline(carteFile,line);
    int layer=std::stoi(line);

    int l=0;
    int j=0;

    for (int k = 0; k < layer; ++k) {
        layers.emplace_back(std::vector<Element*>());
    }



    while (std::getline(carteFile,line,'\n')){


        for (int i = 0; i <largeur ; ++i) {

            if (line[i] == '*' || line[i]=='8' || line[i]=='5' || line[i]=='9') {

                Obstacle obstacle;

                obstacle.setPosition(Position(i * 32, j * 32));

                switch (line[i]){
                    case '*':
                        obstacle.setType("crystal.gif");
                        break;
                    case '8':
                        obstacle.setType("tree_blue.png");
                        break;
                    case '5':
                        obstacle.setType("inn_house.png");
                        break;
                    case '9':
                        obstacle.setType("invisible.png");
                        break;
                    default:break;
                }

                layers.at(l).push_back(new Obstacle(obstacle));


            }

                // THIS IS FOR THE LOOT
            else if (line[i]=='+' || line[i]=='=' || line[i]=='<' || line[i]=='>' || line[i]=='@' || line[i]=='#'){
                std::string type;


                switch (line[i]){
                    case '+':
                        type="bag";
                        break;
                    case '=':
                        type="apple";
                        break;
                    case '<':
                        type="greenCrystal";
                        break;
                    case '>':
                        type="blueCrystal";
                        break;
                    case '@':
                        type="heart";
                        break;
                    case '#':
                        type="scroll";
                        break;
                    default:break;
                }

                Loot loot(type);
                loot.setPosition(Position(i*32,j*32));
                layers.at(l).push_back(new Loot(loot));



            }

            else if (line[i]=='a' || line[i]=='b' || line[i]=='c' || line[i]=='d' || line[i]=='e'
                     || line[i]=='f' || line[i]=='h' || line[i]=='g' || line[i]=='i' || line[i]=='j'
                     || line[i]=='k' || line[i]=='l' || line[i]=='m' || line[i]=='n'){
                Decoration decoration;
                decoration.setPosition(Position(i*32,j*32));

                switch (line[i]){
                    case 'a':
                        decoration.setType("tile_middle.jpeg");
                        break;
                    case 'b':
                        decoration.setType("tile_up.jpg");
                        break;
                    case 'c':
                        decoration.setType("tile_down.jpg");
                        break;
                    case 'd':
                        decoration.setType("tile_left.jpg");
                        break;
                    case 'e':
                        decoration.setType("tile_right.jpg");
                        break;
                    case 'f':
                        decoration.setType("tile_top_left.jpg");
                        break;
                    case 'g':
                        decoration.setType("tile_bottom_right.jpg");
                        break;
                    case 'h':
                        decoration.setType("tile_bottom_left.jpg");
                        break;
                    case 'i':
                        decoration.setType("tile_top_right.jpg");
                        break;
                    case 'j':
                        decoration.setType("tile_end_left.jpg");
                        break;
                    case 'k':
                        decoration.setType("tile_end_left_top.jpg");
                        break;
                    case 'l':
                        decoration.setType("tile_end_right_top.jpg");
                        break;
                    case 'm':
                        decoration.setType("tile_end_right.jpg");
                        break;
                    case 'n':
                        decoration.setType("tile_n.jpg");
                        break;
                    default:break;
                }


                layers.at(l).push_back(new Decoration(decoration));
            }
            else {
                layers.at(l).push_back(nullptr);
            }
        }
        j++;
        if (j%hauteur==0){

            std::cout << " J LENGTH " << j<<std::endl;
            std::vector<Element*> vec;

            std::cout << layers.size() <<std::endl;

//            layers.push_back(vector);
            l++;

            j=0;
        }

    }


}



int Carte::getLargeur() const {
    return largeur;
}

void Carte::setLargeur(int largeur) {
    Carte::largeur = largeur;
}

int Carte::getHauteur() const {
    return hauteur;
}

void Carte::setHauteur(int hauteur) {
    Carte::hauteur = hauteur;
}

std::vector<Element*> &Carte::getCarte() {
    return carte;
}

void Carte::setCarte(const std::vector<Element> &carte) {
//    Carte::carte = carte;
}





const std::vector<std::vector<Element *>> &Carte::getLayers() const {
    return layers;
}

void Carte::setLayers(const std::vector<std::vector<Element *>> &layers) {
    Carte::layers = layers;
}


void Carte::addPlayerToMap(Player* player, int position) {
    if (!layers.empty()){

        layers.at(layers.size()-1).at(position)=player;
    }

}

bool Carte::allowedMovement(SDL_Keycode key,Position position) {

    int pos=  position.getY()/32*largeur+ position.getX()/32;
    Obstacle *o= nullptr;

    switch (key){
        case SDLK_UP:
            if (pos-largeur>0){


                if ( layers.at( layers.size()-1 ).at(pos-largeur)==nullptr ){
                    return true;
                }
                else {

                    if (o= dynamic_cast<Obstacle*>( layers.at( layers.size()-1 ).at(pos-largeur)) ){
                        return false;
                    }
                    else {
                        return true;
                    }
                }

            }
        case SDLK_DOWN:

            if (pos < largeur*hauteur-largeur-1){
                if ( layers.at( layers.size()-1 ).at(pos+largeur)==nullptr ){
                    return true;
                }
                else {

                    if (o= dynamic_cast<Obstacle*>( layers.at( layers.size()-1 ).at(pos+largeur)) ){
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }
        case SDLK_LEFT:
            if (pos -1> 0){
                if ( layers.at( layers.size()-1 ).at(pos-1)==nullptr ){
                    return true;
                }
                else {

                    if (o= dynamic_cast<Obstacle*>( layers.at( layers.size()-1 ).at(pos-1)) ){
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }

        case SDLK_RIGHT:
            if ( (pos +2) < largeur*hauteur){

                if ( layers.at( layers.size()-1 ).at(pos+1)==nullptr ){
                    return true;
                }
                else {
                    if (o= dynamic_cast<Obstacle*>( layers.at( layers.size()-1 ).at(pos+1)) ){
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }
            else return false;


        default:break;
    }

}


void Carte::updatePosition(Position position, int indexPlayer) {
    Player *p= nullptr;
    int currentIndex=0;

    int pos;
    for (int i = 0; i < layers.at( layers.size()-1 ).size(); ++i) {
        if (p= dynamic_cast<Player*>(layers.at( layers.size()-1 ).at(i)  )){

            if (currentIndex== indexPlayer){

                p->setPosition(position);
                layers.at( layers.size()-1 ).at(i)=p;

                break;
            }
            else {
                currentIndex++;
            }
        }

    }
}

void Carte::updateCurrentPlayer() {

    std::vector<int> liste;
    Player *p= nullptr;
    Element *player;
    for (int i = 0; i < layers.at( layers.size()-1 ).size(); ++i) {
        if (p= dynamic_cast<Player*>( layers.at( layers.size()-1 ).at(i) )){
            liste.push_back(i);

        }
    }
    for (int j = 0; j < liste.size(); ++j) {

        if (j==0){
            player= layers.at( layers.size()-1 ).at(liste.at(0)) ;

        }
        if (j+1== liste.size()){
            std::swap(
                    layers.at( layers.size()-1 ).at(liste.at(j)),
                    player
            );
        }
        else{
            std::swap(
                    layers.at( layers.size()-1 ).at(liste.at(j)),
                    layers.at( layers.size()-1 ).at(liste.at(j+1))
            );
        }

    }

    for (int i = 0; i < layers.at( layers.size()-1 ).size(); ++i) {
        if (p= dynamic_cast<Player*>( layers.at( layers.size()-1 ).at(i) )){
            std::cout << "********************************" <<std::endl;
            std::cout << "PLAYER NAME " << p->getType() <<std::endl;
            std::cout << "********************************" <<std::endl;

        }
    }
}