//
// Created by amanda on 27/10/18.
//

#include "Carte.h"
#include "ObstacleTexture.h"
#include "LootTexture.h"
#include "DecorationTexture.h"
#include <math.h>


Carte::Carte(std::string filename) {
    std::string line;

    std::ifstream carteFile("carte.txt");

    largeur=960;
    hauteur=640;

    std::getline(carteFile,line);
    largeur=std::stoi(line);
    std::getline(carteFile,line);
    hauteur=std::stoi(line);




    int j=0;
    while (std::getline(carteFile,line,'\n')){
        //std::cout << line << std::endl;
        j++;
        for (int i = 0; i <line.size() ; ++i) {

                if (line[i] == '*') {
                    Obstacle obstacle;
                    obstacle.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    obstacle.setType("crystal.gif");
                    carte.push_back(new Obstacle(obstacle));
                    // 32*32
                }
                if (line[i] == '0') {
                    Obstacle obstacle;
                    obstacle.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    obstacle.setType("water.jpg");
                    carte.push_back(new Obstacle(obstacle));
                    // 32*320
                }
                if (line[i] == '1') {
                    Obstacle obstacle;
                    obstacle.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    obstacle.setType("water.png");
                    carte.push_back(new Obstacle(obstacle));
                    // 32*32
                }
                if (line[i] == '8') {
                    Obstacle obstacle;
                    obstacle.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    obstacle.setType("tree_blue.png");
                    carte.push_back(new Obstacle(obstacle));
                    //96*64
                }
                if (line[i] == '5') {
                    Obstacle obstacle;
                    obstacle.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    obstacle.setType("inn_house.png");
                    carte.push_back(new Obstacle(obstacle));
                } else if (line[i] == '+') {
                    Loot loot;
                    loot.setPosition(Position(i * 32, (j - 1) * 32));
                    loot.setType("bag.gif");
                    carte.push_back(new Loot(loot));

                } else if (line[i] == 'a') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_middle.jpeg");
                    carte.push_back(new Decoration(decoration));
                } else if (line[i] == 'b') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_up.jpg");
                    carte.push_back(new Decoration(decoration));
                } else if (line[i] == 'c') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_down.jpg");
                    carte.push_back(new Decoration(decoration));
                } else if (line[i] == 'd') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_left.jpg");
                    carte.push_back(new Decoration(decoration));
                } else if (line[i] == 'e') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_right.jpg");
                    carte.push_back(new Decoration(decoration));
                } else if (line[i] == 'f') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_bottom_right.jpg");
                    carte.push_back(new Decoration(decoration));
                } else if (line[i] == 'j') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_top_left.jpg");
                    carte.push_back(new Decoration(decoration));

                } else if (line[i] == 'l') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_top_right.jpg");
                    carte.push_back(new Decoration(decoration));
                } else if (line[i] == 'k') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_bottom_left.jpg");
                    carte.push_back(new Decoration(decoration));
                } else if (line[i] == 'm') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_end_left.jpg");
                    carte.push_back(new Decoration(decoration));
                } else if (line[i] == 'n') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_end_left_top.jpg");
                    carte.push_back(new Decoration(decoration));
                } else if (line[i] == 'o') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_end_right.jpg");
                    carte.push_back(new Decoration(decoration));
                } else if (line[i] == 'p') {
                    Decoration decoration;
                    decoration.setPosition(Position((i%600) * 32, ((j - 1)%600) * 32));
                    decoration.setType("tile_end_right_top.jpg");
                    carte.push_back(new Decoration(decoration));

                }

        }

//            else if (line[i]=='/'){
//                ElementTexture elementTexture;
//                elementTexture.getElement().setPosition(Position(i*32,(j-1)*32));
//                elementTexture.getElement().setType("tile_end_right_top.jpg");
//                elementTexture.setEHeight(32);
//                elementTexture.setEWidth(32);
//                carte.push_back(new ElementTexture (elementTexture));
//
//            }
//            std::cout << "CARTE SIZE "<<carte.size() << std::endl;
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



// THIS METHOD IS TO TEST A NEW FEATURE WHICH IS RENDERING CARTE BY LAYERS, THE LAST LAYERS CONTAIN ONLY OBSTACLE OBJECTS
Carte::Carte(std::string filename, int) {
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
        layers.push_back(std::vector<Element*>());
    }



    while (std::getline(carteFile,line,'\n')){


//        l++;
//        std::cout << l << std::endl;
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
                }

                layers.at(l).push_back(new Obstacle(obstacle));


            }

            // THIS IS FOR THE LOOT
            else if (line[i]=='+' || line[i]=='='){
                Loot loot;
                loot.setPosition(Position(i*32,j*32));

                switch (line[i]){
                    case '+':
                        loot.setType("bag.gif");
                        break;
                    case '=':
                        loot.setType("apple.png");
                        break;
                }

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
                    return 1;
                }
                else {

                    if (o= dynamic_cast<Obstacle*>( layers.at( layers.size()-1 ).at(pos-largeur)) ){
                        return 0;
                    }
                    else {
                        return 1;
                    }
                }

            }
        case SDLK_DOWN:

            if (pos +largeur < largeur*hauteur){
                if ( layers.at( layers.size()-1 ).at(pos+largeur)==nullptr ){
                    return 1;
                }
                else {

                    if (o= dynamic_cast<Obstacle*>( layers.at( layers.size()-1 ).at(pos+largeur)) ){
                        return 0;
                    }
                    else {
                        return 1;
                    }
                }
            }
        case SDLK_LEFT:
            if (pos -1> 0){
                if ( layers.at( layers.size()-1 ).at(pos-1)==nullptr ){
                    return 1;
                }
                else {

                    if (o= dynamic_cast<Obstacle*>( layers.at( layers.size()-1 ).at(pos-1)) ){
                        return 0;
                    }
                    else {
                        return 1;
                    }
                }
            }

        case SDLK_RIGHT:
            if (pos +1< largeur*hauteur){

                if ( layers.at( layers.size()-1 ).at(pos+1)==nullptr ){
                    return 1;
                }
                else {
                    if (o= dynamic_cast<Obstacle*>( layers.at( layers.size()-1 ).at(pos+1)) ){

                    }
                    else {
                        return 1;
                    }
                }
            }


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