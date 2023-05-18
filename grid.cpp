#include "grid.h"

Grid::Grid() : QGridLayout()
{

}
Grid::~Grid(){
    for(int i = 0 ; i < 10; i++){
        for(int j = 0; j < 10; j++){
            delete itemAtPosition(i, j)->widget();
        }
    }
}
/*
void Grid::setGame(Game *g){
    game = g;
}
*/

void Grid::checkCompleteness(){

}
