//
// Created by amanda on 27/10/18.
//

#include "Carte.h"
#include "ObstacleTexture.h"
#include "LootTexture.h"
#include "DecorationTexture.h"


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
            std::cout << line[i] << " " <<std::endl;

            if (line[i]=='*'){
                ObstacleTexture obstacleTexture;
                obstacleTexture.getObstacle().setPosition(Position(i*32,(j-1)*32));
                obstacleTexture.getObstacle().setType("crystal.gif");
                obstacleTexture.setOWidth(32);
                obstacleTexture.setOHeight(32);


                carte.push_back(new ObstacleTexture(obstacleTexture));
            }
            if (line[i]=='0'){
                ObstacleTexture obstacleTexture;
                obstacleTexture.getObstacle().setPosition(Position(i*32,(j-1)*32));
                obstacleTexture.getObstacle().setType("water.jpg");
                obstacleTexture.setOHeight(32);
                obstacleTexture.setOWidth(32);

                carte.push_back(new ObstacleTexture(obstacleTexture));
            }
            if (line[i]=='1'){
                ObstacleTexture obstacleTexture;
                obstacleTexture.getObstacle().setPosition(Position(i*32,(j-1)*32));
                obstacleTexture.getObstacle().setType("water.png");
                obstacleTexture.setOHeight(32);
                obstacleTexture.setOWidth(32);

                carte.push_back(new ObstacleTexture(obstacleTexture));
            }
            if (line[i]=='8'){
                ObstacleTexture obstacleTexture;
                obstacleTexture.getObstacle().setPosition(Position(i*32,(j-1)*32));
                obstacleTexture.getObstacle().setType("tree_blue.png");
                obstacleTexture.setOHeight(96);
                obstacleTexture.setOWidth(64);

                carte.push_back(new ObstacleTexture(obstacleTexture));
            }
            if (line[i]=='5'){
                ObstacleTexture obstacleTexture;
                obstacleTexture.getObstacle().setPosition(Position(i*32,(j-1)*32));
                obstacleTexture.getObstacle().setType("inn_house.png");
                obstacleTexture.setOHeight(96);
                obstacleTexture.setOWidth(128);

                carte.push_back(new ObstacleTexture(obstacleTexture));
            }

            else if ( line[i]=='+'){
                LootTexture lootTexture;
                lootTexture.getLoot().setPosition(Position(i*32,(j-1)*32));
                carte.push_back(new LootTexture (lootTexture));

            }

            else if (line[i]=='a'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_middle.jpeg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='b'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_up.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='c'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_down.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='d'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_left.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='e'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_right.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='f'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_bottom_right.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='j'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_top_left.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='l'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_top_right.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='k'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_bottom_left.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='m'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_end_left.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='n'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_end_left_top.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='o'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_end_right.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            else if (line[i]=='p'){
                DecorationTexture decorationTexture;
                decorationTexture.getDecoration().setPosition(Position(i*32,(j-1)*32));
                decorationTexture.getDecoration().setType("tile_end_right_top.jpg");
                decorationTexture.setDHeight(32);
                decorationTexture.setDWidth(32);
                carte.push_back(new DecorationTexture (decorationTexture));

            }
            std::cout << "CARTE SIZE "<<carte.size() << std::endl;
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

std::vector<ElementTexture*> &Carte::getCarte() {
    return carte;
}

void Carte::setCarte(const std::vector<ElementTexture> &carte) {
//    Carte::carte = carte;
}
