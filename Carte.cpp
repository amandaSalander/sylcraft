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

    std::ifstream carteFile(filename);


    std::cout << carteFile.is_open() << std::endl;
    largeur=960;
    hauteur=640;

    std::getline(carteFile,line);
    largeur=std::stoi(line);
    std::getline(carteFile,line);
    hauteur=std::stoi(line);
    std::getline(carteFile,line);
    int layer=std::stoi(line);

    size_t l=0;
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
                        obstacle.setType("assets/obstacles/crystal.gif");
                        break;
                    case '8':
                        obstacle.setType("assets/obstacles/tree_blue.png");
                        break;
                    case '5':
                        obstacle.setType("assets/obstacles/inn_house.png");
                        break;
                    case '9':
                        obstacle.setType("assets/obstacles/invisible.png");
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

            l++;

            j=0;
        }

    }


}







const std::vector<std::vector<Element *>> &Carte::getLayers() const {
    return layers;
}



void Carte::addPlayerToMap(Player* player, int position) {
    if (!layers.empty()){

        layers.at(layers.size()-1).at((size_t)position)=player;
    }

}

bool Carte::allowedMovement(SDL_Keycode key,Position position) {

    int pos=  position.getY()/32*largeur+ position.getX()/32;
    Obstacle *o= nullptr;

    switch (key){
        case SDLK_UP:
            if (pos-largeur>0){


                if ( layers.at( layers.size()-1 ).at((size_t) pos-largeur)==nullptr ){
                    return true;
                }
                else {

                    if ( (o= dynamic_cast<Obstacle*>( layers.at( layers.size()-1 ).at(pos-largeur)) ) ){
                        return false;
                    }
                    else {
                        return true;
                    }
                }

            }
        case SDLK_DOWN:

            if (pos < largeur*hauteur-largeur-1){
                if ( layers.at( layers.size()-1 ).at((size_t)pos+largeur)==nullptr ){
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
                if ( layers.at( layers.size()-1 ).at((size_t)pos-1)==nullptr ){
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

                if ( layers.at( layers.size()-1 ).at((size_t)pos+1)==nullptr ){
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

    for (auto &i : layers.at(layers.size() - 1)) {
        if ((p= dynamic_cast<Player*>(i  ) )){

            if (currentIndex== indexPlayer){

                p->setPosition(position);
                i =p;

                break;
            }
            else {
                currentIndex++;
            }
        }

    }
}

Position const Carte::allowedPick(Position position) {
    int pos_min=  position.getY()/32*largeur+ position.getX()/32;
    int pos_max=  position.getY()/32*largeur+ (int) round(position.getX()/32.0);

    /** Get al the value surrouding the player **/
    std::vector<short> positions;
    positions.emplace_back(-31);
    positions.emplace_back(-30);
    positions.emplace_back(-29);
    positions.emplace_back(-1);
    positions.emplace_back(0);
    positions.emplace_back(1);
    positions.emplace_back(29);
    positions.emplace_back(30);
    positions.emplace_back(31);


    Position a(-1,-1);

    for (int i = 0; i <positions.size() ; ++i) {
        if (positions.at(i)<0){
            if (pos_min +positions.at(i) >0){
                if (auto *l = dynamic_cast<Loot*>( layers.at( layers.size()-1 ).at(pos_min+positions.at(i)) )){
                    a=l->getPosition();
                }
            }
            if (pos_max +positions.at(i) >0){
                if (auto *l = dynamic_cast<Loot*>( layers.at( layers.size()-1 ).at(pos_max+positions.at(i)) )){
                    a=l->getPosition();
                }
            }
        }
        else {
            if (pos_min +positions.at((size_t)i) <largeur*hauteur){
                if (auto *l = dynamic_cast<Loot*>( layers.at( layers.size()-1 ).at(pos_min+positions.at(i)) )){
                    a=l->getPosition();
                }
            }
            if (pos_max +positions.at((size_t)i) >0){
                if (auto *l = dynamic_cast<Loot*>( layers.at( layers.size()-1 ).at(pos_max+positions.at(i)) )){
                    a=l->getPosition();
                }
            }
        }
    }

    return a;
}

const Loot Carte::deleteLoot(const Position &position) {
    /** calculate the position of the Loot in the layer**/
    int pos=  position.getY()/32*largeur+ position.getX()/32;


    Element *e=layers[layers.size()-1][pos];e->setPosition(Position(-100,-100));

    return *dynamic_cast<Loot*>(e);

}


void Carte::updatePlayerStat(const Player &player, int indexPlayer) {
    Player *p= nullptr;
    int currentIndex=0;

    for (auto &i : layers.at(layers.size() - 1)) {
        if ((p= dynamic_cast<Player*>(i) )){

            if (currentIndex== indexPlayer){

                p->setClasse(player.getClasse());


                break;
            }
            else {
                currentIndex++;
            }
        }

    }
}