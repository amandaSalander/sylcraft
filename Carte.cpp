//
// Created by amanda on 27/10/18.
//

#include "Carte.h"
#include "ObstacleTexture.h"
#include "LootTexture.h"
#include "DecorationTexture.h"
#include "HarmingObjects.h"
#include "NPC.h"
#include "Ennemy.h"
#include "Boss.h"
#include <math.h>



Carte::Carte(std::string filename) {
    std::string line;
    std::ifstream carteFile(filename);
    
    std::cout << carteFile.is_open() << std::endl;
    largeur=960;
    hauteur=640;

    killedAllEnnemy=false;
    killedBoss=false;

    std::getline(carteFile,line);
    largeur=std::stoi(line);
    std::getline(carteFile,line);
    hauteur=std::stoi(line);
    std::getline(carteFile,line);
    int layer=std::stoi(line);
    itemsInMap= new std::vector<Item*>();
    size_t l=0;
    int j=0;

    npcs = new std::vector<NPC*>();

    layers =new std::vector<std::vector<Element*>>();
    for (int k = 0; k < layer; ++k) {
        layers->emplace_back(std::vector<Element*>());
    }


    while (std::getline(carteFile,line,'\n')){


        for (int i = 0; i <largeur ; ++i) {

            if (line[i] == '*' || line[i]=='8' || line[i]=='5' || line[i]=='9' || line[i]=='7' || line[i]=='w'
            || line[i]=='1'|| line[i]=='z' || line[i]=='x' || line[i]=='2' || line[i]=='6' || line[i]=='3'
            || line[i]=='%' || line[i]=='`' || line[i]=='&' || line[i]=='.') {

                Obstacle obstacle;

                obstacle.setPosition(Position(i * 32, j * 32));

                switch (line[i]){
                    case '*':
                        obstacle.setType("assets/obstacles/crystal.gif");
                        break;
                    case '1':
                        obstacle.setType("assets/obstacles/house_1.png");
                        break;
                    case '2':
                        obstacle.setType("assets/obstacles/house_2.png");
                        break;
                    case '3':
                        obstacle.setType("assets/obstacles/house_3.png");
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
                    case '7':
                        obstacle.setType("assets/obstacles/tree_pink.png");
                        break;
                    case '6':
                        obstacle.setType("assets/obstacles/tree_weird.png");
                        break;
                    case 'w':
                        obstacle.setType("assets/obstacles/water.png");
                        break;
                    case 'z':
                        obstacle.setType("assets/obstacles/work_1.png");
                        break;
                    case 'x':
                        obstacle.setType("assets/obstacles/work_2.png");
                        break;
                    case '%':
                        obstacle.setType("assets/obstacles/block_1.png");
                        break;
                    case '`':
                        obstacle.setType("assets/obstacles/status_1.png");
                        break;
                    case '&':
                        obstacle.setType("assets/obstacles/status_2.png");
                        break;
                    case '.':
                        obstacle.setType("assets/obstacles/status_3.png");
                        break;
                    default:break;
                }

                layers->at(l).push_back(new Obstacle(obstacle));


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
                layers->at(l).push_back(new Loot(loot));



            }
            else if(line[i]=='A'){
                Boss boss("boss_1");
                boss.setPosition(Position(i*32,j*32));
                layers->at(l).push_back(new Boss(boss));
            }

            else if (line[i]=='a' || line[i]=='b' || line[i]=='c' || line[i]=='d' || line[i]=='e'
                     || line[i]=='f' || line[i]=='h' || line[i]=='g' || line[i]=='i' || line[i]=='j'
                     || line[i]=='k' || line[i]=='l' || line[i]=='m' || line[i]=='n' || line[i]=='$'
                     || line[i]=='~' || line[i]==':'){
                Decoration decoration;
                decoration.setPosition(Position(i*32,j*32));

                switch (line[i]){
                    case 'a':
                        decoration.setType("assets/tiles/tile_middle.jpeg");
                        break;
                    case 'b':
                        decoration.setType("assets/tiles/tile_up.jpg");
                        break;
                    case 'c':
                        decoration.setType("assets/tiles/tile_down.jpg");
                        break;
                    case 'd':
                        decoration.setType("assets/tiles/tile_left.jpg");
                        break;
                    case 'e':
                        decoration.setType("assets/tiles/tile_right.jpg");
                        break;
                    case 'f':
                        decoration.setType("assets/tiles/tile_top_left.jpg");
                        break;
                    case 'g':
                        decoration.setType("assets/tiles/tile_bottom_right.jpg");
                        break;
                    case 'h':
                        decoration.setType("assets/tiles/tile_bottom_left.jpg");
                        break;
                    case 'i':
                        decoration.setType("assets/tiles/tile_top_right.jpg");
                        break;
                    case 'j':
                        decoration.setType("assets/tiles/tile_end_left.jpg");
                        break;
                    case 'k':
                        decoration.setType("assets/tiles/tile_end_left_top.jpg");
                        break;
                    case 'l':
                        decoration.setType("assets/tiles/tile_end_right_top.jpg");
                        break;
                    case 'm':
                        decoration.setType("assets/tiles/tile_end_right.jpg");
                        break;
                    case 'n':
                        decoration.setType("assets/tiles/tile_n.jpg");
                        break;
                    case '$':
                        decoration.setType("assets/tiles/flower_1.png");
                        break;
                    case '~':
                        decoration.setType("assets/tiles/flower_2.png");
                        break;
                    case ':':
                        decoration.setType("assets/tiles/flower_3.png");
                        break;
                    default:break;
                }


                layers->at(l).push_back(new Decoration(decoration));
            }
            else if(line[i]=='F'){
                HarmingObjects harmingObjects("fire");
                harmingObjects.setPosition(Position(i*32,j*32));
                layers->at(l).emplace_back(new HarmingObjects(harmingObjects));
            }
            else if(line[i]=='O' || line[i]=='P' || line[i]=='M' || line[i]=='L' || line[i]=='Z'
            || line[i]=='W' || line[i]=='Y'){
                NPC npc("oldMan");

                switch (line[i]){
                    case 'O':
                        npc=NPC("oldMan");
                        break;
                    case 'P':
                        npc= NPC("priest");
                        break;
                    case 'M':
                        npc=NPC("mysteriousLady");
                        break;
                    case 'L':
                        npc=NPC("little_girl");
                        break;
                    case 'Z':
                        npc=NPC("little_boy");
                        break;
                    case 'W':
                        npc=NPC("worker_man");
                        break;
                    case 'Y':
                        npc=NPC("worker_woman");
                        break;
                    default:
                        break;
                }



                npc.setPosition(Position(i*32,j*32));

                layers->at(l).emplace_back(new NPC(npc));
                npcs->emplace_back( dynamic_cast<NPC*>(
                        layers->at(l).at( layers->at(l).size()-1 ) )
                        );


            }
            else if (line[i]=='B' || line[i]=='C'){
                Ennemy *ennemy= nullptr;
                switch (line[i]){
                    case 'B':
                        ennemy= new Ennemy("basic_ennemy");
                        break;
                    case 'C':
                        ennemy= new Ennemy("medium_ennemy");
                    default:
                        break;
                }

                ennemy->setPosition(Position(i*32,j*32));
                layers->at(l).emplace_back(ennemy);

            }
            else if (line[i]=='X' || line[i]=='S' || line[i]=='D' || line[i]=='(' || line[i]==')'
                || line[i]=='_' || line[i]=='^'
            ){
                Item *it = nullptr;
                switch (line[i]){
                    case 'X':
                        it= new Item("book");
                        break;
                    case 'S':
                        it= new Item("scroll");
                        break;
                    case 'D':
                        it= new Item("diamant");
                        break;
                    case '(':
                        it= new Item("candy_1");
                        break;
                    case ')':
                        it= new Item("candy_2");
                        break;
                    case '_':
                        it= new Item("candy_3");
                        break;
                    case '^':
                        it= new Item("candy_4");
                        break;
                    default:
                        break;
                }
                it->setPosition(Position(i*32,j*32));
                layers->at(l).emplace_back(it);
                itemsInMap->emplace_back(it);
                std::cout << it->getName() << std::endl;
            }
            else {
                    layers->at(l).push_back(nullptr);
            }
        }
        j++;
        if (j%hauteur==0){

            std::vector<Element*> vec;
            std::cout << layers->size() <<std::endl;
            l++;
            j=0;
        }

    }

    carteFile.close();


}


std::vector<std::vector<Element *>>* Carte::getLayers() const {
    return layers;
}

void Carte::addPlayerToMap(Player* player, int position) {
    if (!layers->empty()){

        layers->at(layers->size()-1).at((size_t)position)=player;
    }

}

bool Carte::allowedMovement(SDL_Keycode key,Position position) {

    int pos=  position.getY()/32*largeur+ position.getX()/32;
    Obstacle *o= nullptr;

    switch (key){
        case SDLK_UP:
            if (pos-largeur>0){


                if ( layers->at( layers->size()-1 ).at((size_t) pos-largeur)==nullptr ){
                    return true;
                }
                else {

                    if ( (o= dynamic_cast<Obstacle*>( layers->at( layers->size()-1 ).at(pos-largeur)) ) ){
                        return false;
                    }
                    else {
                        return true;
                    }
                }

            }
        case SDLK_DOWN:

            if (pos < largeur*hauteur-largeur-1){
                if ( layers->at( layers->size()-1 ).at((size_t)pos+largeur)==nullptr ){
                    return true;
                }
                else {

                    if (o= dynamic_cast<Obstacle*>( layers->at( layers->size()-1 ).at(pos+largeur)) ){
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }
        case SDLK_LEFT:
            if (pos -1> 0){
                if ( layers->at( layers->size()-1 ).at((size_t)pos-1)==nullptr ){
                    return true;
                }
                else {

                    if (o= dynamic_cast<Obstacle*>( layers->at( layers->size()-1 ).at(pos-1)) ){
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }

        case SDLK_RIGHT:
            if ( (pos +2) < largeur*hauteur){

                if ( layers->at( layers->size()-1 ).at((size_t)pos+1)==nullptr ){
                    return true;
                }
                else {
                    if (o= dynamic_cast<Obstacle*>( layers->at( layers->size()-1 ).at(pos+1)) ){
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

    for (auto &i : layers->at(layers->size() - 1)) {
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
                if (auto *l = dynamic_cast<Loot*>( layers->at( layers->size()-1 ).at(pos_min+positions.at(i)) )){
                    a=l->getPosition();
                }
            }
            if (pos_max +positions.at(i) >0){
                if (auto *l = dynamic_cast<Loot*>( layers->at( layers->size()-1 ).at(pos_max+positions.at(i)) )){
                    a=l->getPosition();
                }
            }
        }
        else {
            if (pos_min +positions.at((size_t)i) <largeur*hauteur){
                if (auto *l = dynamic_cast<Loot*>( layers->at( layers->size()-1 ).at(pos_min+positions.at(i)) )){
                    a=l->getPosition();
                }
            }
            if (pos_max +positions.at((size_t)i) >0){
                if (auto *l = dynamic_cast<Loot*>( layers->at( layers->size()-1 ).at(pos_max+positions.at(i)) )){
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


    Element *e=layers->at(layers->size()-1)[pos];
    layers->at(layers->size()-1)[pos]= nullptr;

    return *dynamic_cast<Loot*>(e);

}


void Carte::updatePlayerStat(const Player &player, int indexPlayer) {
    Player *p= nullptr;
    int currentIndex=0;

    for (auto &i : layers->at(layers->size() - 1)) {
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

bool Carte::addLootToMap(Loot *loot) {
    int pos=  loot->getPosition().getY()/32*largeur+ loot->getPosition().getX()/32;

    if (layers->at( layers->size()-1 )[pos]== nullptr){

        layers->at(layers->size()-1 )[pos]=loot;
        return  true;
    }
    else {
        return false;
    }
}

bool Carte::addObstacleToMap(Obstacle *obstacle) {
    int pos=  obstacle->getPosition().getY()/32*largeur+ obstacle->getPosition().getX()/32;

    if (layers->at( layers->size()-1 )[pos]== nullptr){

        layers->at(layers->size()-1 )[pos]=obstacle;
        return  true;
    }
    else {
        return false;
    }
}

Position const Carte::isHarming(const Position &position,float &timestep,float &start) {
    int pos=  position.getY()/32*largeur+ position.getX()/32;


    if (auto *h = dynamic_cast<HarmingObjects*>(layers->back().at(pos))){


            if (start==0){
                start=0.3;
                return h->getPosition();
            }
            else if ( timestep-start >0.3 ){
                start=0.3;
                timestep=0;

                return  h->getPosition();

            }
            else {

                return Position(-1,-1);
            }




//        else return Position(-1,-1);

    }
    else return Position(-1,-1);

}

Position const Carte::allowedTalkToNPC(Position position) {
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
                if (auto *l = dynamic_cast<NPC*>( layers->at( layers->size()-1 ).at(pos_min+positions.at(i)) )){
                    a=l->getPosition();
                }
            }
            if (pos_max +positions.at(i) >0){
                if (auto *l = dynamic_cast<NPC*>( layers->at( layers->size()-1 ).at(pos_max+positions.at(i)) )){
                    a=l->getPosition();
                }
            }
        }
        else {
            if (pos_min +positions.at((size_t)i) <largeur*hauteur){
                if (auto *l = dynamic_cast<NPC*>( layers->at( layers->size()-1 ).at(pos_min+positions.at(i)) )){
                    a=l->getPosition();
                }
            }
            if (pos_max +positions.at((size_t)i) >0){
                if (auto *l = dynamic_cast<NPC*>( layers->at( layers->size()-1 ).at(pos_max+positions.at(i)) )){
                    a=l->getPosition();
                }
            }
        }
    }

    return a;
}

bool Carte::playerIsAllowedToAttack(const Position &position, const int &margin) {

    int pos=position.getX()/32+position.getY()*30/32;
    auto allPositionToCheck= new std::vector<int>() ;

    for (int i = 0; i < margin/32 ; ++i) {
        for (int j = 0; j <3 ; ++j) {
            allPositionToCheck->emplace_back((29+j)*-1);
            allPositionToCheck->emplace_back(29+j);
            if (j==3-(2+1)){
                allPositionToCheck->emplace_back(0);
                allPositionToCheck->emplace_back(-1);
                allPositionToCheck->emplace_back(1);
            }
        }
    }
    std::sort(allPositionToCheck->begin(),allPositionToCheck->end());

//    for (int k = 0; k <allPositionToCheck->size() ; ++k) {
//        std::cout << allPositionToCheck->at(k) <<std::endl;
//    }
    bool a=false;
    for (int l = 0; l < allPositionToCheck->size() ; ++l) {
        if (allPositionToCheck->at(l)<0){
            if (allPositionToCheck->at(l)+pos>0){
                if (auto *e = dynamic_cast<Ennemy*>(
                        layers->back().at(
                                (allPositionToCheck->at(l) + pos)
                                ) ) ){

                    a=true;

                }
            }
        }
        else {
            if (allPositionToCheck->at(l)+pos<largeur*hauteur){
                if (auto *e = dynamic_cast<Ennemy*>(
                        layers->back().at(
                                (allPositionToCheck->at(l) + pos)
                        ) ) ){

                    a=true;

                }
            }
        }
    }
    return a;

}

item_t* Carte::allowedToPickItem(const Position &position,const int &margin) {
    unsigned  short a=0;
    item_t *t= nullptr;
    double distance;
    for (unsigned  long i = 0; i < itemsInMap->size(); ++i) {


        distance=sqrt(
                pow (position.getX()- itemsInMap->at(i)->getPosition().getX(), 2)+
                pow (position.getY()- itemsInMap->at(i)->getPosition().getY(), 2)
                );
        /** TODO : fix bug that allow player to pick item that is not visible**/
        if (distance<margin ){
                t= new item_t();
                t->npc_id=itemsInMap->at(i)->getNpc_id();
                t->quest_id=itemsInMap->at(i)->getQuest_id();
                t->item_id=itemsInMap->at(i)->getItem_id();
                itemsInMap->at(i)->setFound(true);
        }
    }
    return t;

}

std::string* Carte::pickItem(const Position &position, const int &margin) {

    std::string *returnVal= nullptr;
    if ( auto b=allowedToPickItem(position,margin) ){
        for (auto &a: *npcs){
            if (a->getNpc_id()==b->npc_id){
                std::cout <<"NPC name "<< a->getName() <<std::endl;
                if (a->getQuests()){
                    for( auto &c : *a->getQuests()){
                        if (c->getId()==b->quest_id){
                            std::cout <<"QUEST IS "<< c->getId() <<std::endl;
                            for( auto &i : *c->getItems()){
                                if (i->getItem_id()==b->item_id){
                                    std::cout <<"ITEM IS " << i->getName() << std::endl;
                                    returnVal= new std::string(i->getName());
                                    c->setQuest_state(QUEST_COMPLETED);
                                    break;
                                }
                            }
                        }

                    }
                }
            }


        }
    }

    return returnVal;
}

bool Carte::addHarmingObjectToMap(HarmingObjects *harmingObject) {
    int pos=  harmingObject->getPosition().getY()/32*largeur+ harmingObject->getPosition().getX()/32;

    if (layers->at( layers->size()-1 )[pos]== nullptr){

        layers->at(layers->size()-1 )[pos]=harmingObject;
        return  true;
    }
    else {
        return false;
    }
}

bool Carte::deleteHarmingObjectMap(const Position &position) {
    int pos=  position.getY()/32*largeur+ position.getX()/32;


    Element *e=layers->at(layers->size()-1)[pos];
    layers->at(layers->size()-1)[pos]= nullptr;

//    return *dynamic_cast<Loot*>(e);
}


bool Carte::isKilledAllEnnemy() const {
    return killedAllEnnemy;
}

void Carte::setKilledAllEnnemy(bool killedAllEnnemy) {
    Carte::killedAllEnnemy = killedAllEnnemy;
}

bool Carte::isKilledBoss() const {
    return killedBoss;
}

void Carte::setKilledBoss(bool killedBoss) {
    Carte::killedBoss = killedBoss;
}
