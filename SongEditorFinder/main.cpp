#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
using namespace std;

void updateWindow(sf::RenderWindow *window, bool showMenu, bool showRateScreen, sf::Sprite *background,
        sf::Sprite *searchBar, sf::Sprite *searchBtn, sf::Sprite *rateScreen, sf::Sprite *loveBtn,
                  sf::Sprite *hateBtn, sf::Sprite *exitBtn){

    window->clear(sf::Color::White);

    if(showMenu){
        //cout << "drawing menu.." << endl;
        window->draw(*background);
        searchBar->setPosition(((1955/2)-630),1185/2);
        auto position = searchBar->getPosition().y;
        searchBtn->setPosition((1955/2)-180,  (int)position + 350);
        window->draw(*searchBar);
        window->draw(*searchBtn);

    }else if(showRateScreen){
        window->draw(*rateScreen);
        loveBtn->setPosition(1515,window->getSize().y/2);
        hateBtn->setPosition(5,window->getSize().y/2);
        exitBtn->setPosition(1650,1100);
        window->draw(*loveBtn);
        window->draw(*hateBtn);
        window->draw(*exitBtn);


    }
}

int main() {

    /* program stage one Initialization */

    sf::RenderWindow window(sf::VideoMode(1955, 1185), "TuneMatchMaker.io");

    ////// //1 Load texture from file
    ///2 set that texture to a sprite

//need to put all sprites in unordered map for optimization
    sf::Sprite hateBtn(TextureManager::GetTexture("hateButn"));
    sf::Sprite loveBtn(TextureManager::GetTexture("lovebtn2"));
    sf::Sprite background(TextureManager::GetTexture("newBGMenu"));
    sf::Sprite searchBar(TextureManager::GetTexture("searchPNG"));
    sf::Sprite searchBtn(TextureManager::GetTexture("searchButton"));
    sf::Sprite rateScreen(TextureManager::GetTexture("like"));
    sf::Sprite exitBtn(TextureManager::GetTexture("exitBtn"));
    //input revealed tiles in a 2d vector
    ///////////generating random number//////////


    // cout << randomX << endl;
    //cout << randomY << endl;
    bool showRateScreen = false;
    bool showMainMenu = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            //if a button was pressed (any part of the mouse was pressed)
            if (event.type == sf::Event::MouseButtonPressed) {

                //and it it was the left mouse button...
                if (event.mouseButton.button == sf::Mouse::Left) {

                    //1. Get the mouse position
                    auto pos = sf::Mouse::getPosition(window);
                    cout << "mouses x:" << pos.x << " mouses y" << pos.y << endl;
                    if(searchBtn.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y))){
                        cout << "search btn clicked!" << endl;
                        showMainMenu = false;
                        showRateScreen = true;
                    }else if(exitBtn.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y))){
                        cout << "exit btn was clicked returning to main menu..." << endl;
                        showMainMenu = true;
                        showRateScreen = false;
                    }




                } else if (event.mouseButton.button == sf::Mouse::Right) {

                    auto pos = sf::Mouse::getPosition(window);
                    for(int i = 0; i < 25; i++){

                    }

//                    flagSprite.setPosition(pos.x, pos.y);
//                    window.draw(flagSprite);


                }
            }
        }

        //Program stage two update


        //Program stage 3: Draw
        //step1 clear the screen
        updateWindow(&window, showMainMenu,showRateScreen,  &background, &searchBar, &searchBtn, &rateScreen, &loveBtn, &hateBtn, &exitBtn);
        window.display();


    }

    ///===final program stage shut down ====///
    TextureManager::Clear();

    return 0;
}
