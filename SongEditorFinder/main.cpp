#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "TextField.cpp"
#include "TextBox.cpp"
#include "Button.cpp"
#include "AdjListSong.h"
#include <unordered_map>
#include "ctime"
#include <chrono>
using namespace  std::chrono;
#include <iterator>
using namespace std;


vector<Song*> getSongList(string targetName){
    //read the tracks.csv files
    ifstream myData;
    string line1;
    myData.open("C:/Users/fiana/CLionProjects/testProject3/tracks.csv");
    getline(myData, line1);

    //ask for the name of the song to search
    string targetArtist;
    string targetAlbum;
    cout << targetName << endl;
    vector<Song*> songList;
    /*search Song*/
    while (myData.good())
    {
        string line;
        getline(myData, line);
        string id = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string name = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string album = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string albumId = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string artists= (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string artistId = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string year = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string release_date = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        if (name == targetName) {
            targetArtist = artists;
            targetAlbum = album;
            break;
        }
    }
    myData.close();
    ifstream myData2;
    string line2;
    myData2.open("C:/Users/fiana/CLionProjects/testProject3/tracks.csv");
    getline(myData2, line2);
    while (myData2.good())
    {
        string line;
        getline(myData2, line);
        string id = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string name = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string album = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string albumId = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string artists = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string artistId = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string year = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        string release_date = (line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1);
        if (artists == targetArtist)
        {
            Song* newSong = new Song(id, name, album, albumId, year, release_date);
            songList.push_back(newSong);
            //cout << ".." << endl;
        }
    }
    return songList;
}

unordered_map<int, Song*>getSongMap(const string& targetName, string whichList, string& time){

    vector<Song*> songList = getSongList(targetName);
    unordered_map<int, Song*> map;

    time = "";
    clock_t help;
    help = clock();

    if(whichList == "AdjMatrix"){
        auto* songGraph = new AdjMatrix(songList, targetName);
        cout<<"total: "<< songGraph->get_V()<<endl;
        map = songGraph->traverse();
    }else{
        auto* songGraph = new EdgeList(songList, targetName);
        cout<<"total: "<<songGraph->get_V()<<endl;
        map = songGraph->traverse();
    }

    help = clock() - help;
    time = to_string((float)help/CLOCKS_PER_SEC);
    return map;
}

void updateWindow(sf::RenderWindow *window, bool showMenu, bool showRateScreen, sf::Sprite *background,
                  sf::Sprite *searchBar, sf::Sprite *searchBtn, sf::Sprite *rateScreen, sf::Sprite *loveBtn,
                  sf::Sprite *hateBtn, sf::Sprite *exitBtn, Textbox *searchtxtBox, Button *search_Btn,
                  sf::Sprite *musicNote, Textbox *songInfoBox, Button *AdjListBtn, Button *EdgeBtn,
                  Textbox *searchTime, Textbox *musicLink) {

    window->clear(sf::Color::White);

    if (showMenu) {
        //cout << "drawing menu.." << endl;
        window->draw(*background);
        searchBar->setPosition(((1955 / 2) - 630), 1185 / 2);
        auto position = searchBar->getPosition().y;
        //searchBtn->setPosition((1955 / 2) - 180, (int) position + 350);
        window->draw(*searchBar);
        //window->draw(*searchBtn);
        searchtxtBox->drawTo(*window);
        search_Btn->drawTo(*window);
        AdjListBtn->drawTo(*window);
        EdgeBtn->drawTo(*window);

    } else if (showRateScreen) {
        musicNote->setPosition(680,100);
        window->draw(*rateScreen);
        window->draw(*musicNote);
        loveBtn->setPosition(1515, window->getSize().y / 2);
        hateBtn->setPosition(5, window->getSize().y / 2);
        exitBtn->setPosition(1650, 1100);
        window->draw(*loveBtn);
        window->draw(*hateBtn);
        window->draw(*exitBtn);
        songInfoBox->drawTo(*window);
        searchTime->drawTo(*window);
        musicLink->drawTo(*window);


    }
}
string getNextSong(vector<string> test, int currIndex){
    if(test.size() != 0){

        if(currIndex == test.size() - 1){
            cout << "reached end of vector" << endl;
            currIndex = 0;
            return test.at(currIndex);
        }

    }
}

int main() {

    /* program stage one Initialization */

    sf::RenderWindow window(sf::VideoMode(1955, 1185), "TuneMatchMaker.io");
    //added
    window.setKeyRepeatEnabled(true);

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/Arial.ttf"))
        std::cout << "Font not found!\n";

    Textbox searchTxtBox(40, sf::Color::White, true);
    searchTxtBox.setPosition({ 485, 630 });
    searchTxtBox.setLimit(true, 30);
    searchTxtBox.setFont(font);
    Button btn1("AdjMatrix vs. EdgeList", { 300, 100 }, 30, sf::Color::Blue, sf::Color::White);
    btn1.setFont(font);
    btn1.setPosition({ (1955 / 2) - 145, 972 });

    Textbox musicLink(30, sf::Color::White, true);
    musicLink.setPosition({ 530, 80 });
    musicLink.setLimit(true, 30);
    musicLink.setFont(font);
    musicLink.setText("Edit Music: https://music-editor.net/");


    Button AdjBFS("AdjMatrix BFS", { 300, 100 }, 30, sf::Color::Red, sf::Color::White);
    AdjBFS.setFont(font);
    AdjBFS.setPosition({ (1955 / 2) - 590, 972 });

    Button EdgeBFS("EdgeList BFS", { 300, 100 }, 30, sf::Color::Green, sf::Color::White);
    EdgeBFS.setFont(font);
    EdgeBFS.setPosition({ (1955 / 2) + 300, 972 });

    Textbox songInfoBox(50, sf::Color::Black, false);
    songInfoBox.setPosition({ 520, 700 });
    songInfoBox.setLimit(true, 30);
    songInfoBox.setFont(font);
    string songTitle = "Song : " ;
    string AlbumTitle = "\nAlbum : " ;
    string artistTitle = "\n\nArtist : ";
    string year = "\nYear: ";
    string releaseDate = "\nReleaseDate: ";
    string songID = "\nSong ID: ";

    //time/search text box
    Textbox searchTime(25, sf::Color::White, false);
    searchTime.setPosition({ 535, 490 });
    searchTime.setLimit(true, 30);
    searchTime.setFont(font);
    string searchType1 = "Search Type: ";
    string srchTime = "\nTime search took in seconds: ";


    //map stuff boys


    unordered_map<int, Song*> testMap;
    auto itr = testMap.begin();

    //stop added
    ////// //1 Load texture from file
    ///2 set that texture to a sprite

//need to put all sprites in unordered map for optimization
    sf::Sprite hateBtn(TextureManager::GetTexture("hateButn"));
    sf::Sprite loveBtn(TextureManager::GetTexture("lovebtn2"));
    sf::Sprite background(TextureManager::GetTexture("newBGMenu"));
    sf::Sprite searchBar(TextureManager::GetTexture("emptySearchbar"));
    sf::Sprite searchBtn(TextureManager::GetTexture("searchButton"));
    sf::Sprite rateScreen(TextureManager::GetTexture("like"));
    sf::Sprite exitBtn(TextureManager::GetTexture("exitBtn"));
    sf::Sprite musicNote(TextureManager::GetTexture("music3"));
    //input revealed tiles in a 2d vector
    ///////////generating random number//////////


    // cout << randomX << endl;
    //cout << randomY << endl;
    bool showRateScreen = false;
    bool showMainMenu = true;

    while (window.isOpen()) {
        sf::Event event;


        //added
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            searchTxtBox.setSelected(true);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            searchTxtBox.setSelected(false);
        }
        //stop added



        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            //added
            if(event.type == sf::Event::TextEntered){
                searchTxtBox.typedOn(event);
            }
            if(event.type == sf::Event::MouseMoved){
                if (btn1.isMouseOver(window)) {
                    btn1.setBackColor(sf::Color::Green);
                }
                else {
                    btn1.setBackColor(sf::Color::Blue);
                }
                break;
            }
            //stop added


            //if a button was pressed (any part of the mouse was pressed)
            if (event.type == sf::Event::MouseButtonPressed) {

                //added
                if(btn1.isMouseOver(window)){
                    testMap.clear();

                    showMainMenu = false;
                    showRateScreen = true;
                    unordered_map<int, Song*> tempMap;
                    unordered_map<int, Song*> tempMap2;


                    string time = " ";
                    tempMap = getSongMap(searchTxtBox.getText(), "EdgeList", time);
                    cout << "the search took EdgeList" << time << "seconds" << endl;

                    string time2 = " ";
                    tempMap2 = getSongMap(searchTxtBox.getText(), "AdjMatrix", time2);
                    cout << "the search took AdjMatrix" << time2 << "seconds" << endl;

                    if(time < time2){
                        testMap = tempMap;
                        itr = testMap.begin();
                        string justTest = songTitle + itr->second->get_name() + songID + itr->second->get_id() +
                                AlbumTitle + itr->second->get_album() +
                                releaseDate + itr->second->get_release_date() + year + itr->second->get_year();
                        songInfoBox.setTextBox(justTest);
                        searchTxtBox.clearText();
                        searchTime.setText(searchType1 + "EdjList WON!" + srchTime + time);
                    }else{
                        testMap = tempMap2;
                        itr = testMap.begin();
                        string justTest = songTitle + itr->second->get_name() + songID + itr->second->get_id() +
                                          AlbumTitle + itr->second->get_album() +
                                          releaseDate + itr->second->get_release_date() + year + itr->second->get_year();
                        songInfoBox.setTextBox(justTest);
                        searchTxtBox.clearText();
                        searchTime.setText(searchType1 + "AdjMatrix WON!" + srchTime + time2);

                    }


                }
                //stop added
                if(EdgeBFS.isMouseOver(window)){
                    testMap.clear();
                    showMainMenu = false;
                    showRateScreen = true;
                    string time = " ";
                    testMap = getSongMap(searchTxtBox.getText(), "EdgeList", time);
                    itr = testMap.begin();
                    string justTest = songTitle + itr->second->get_name() + songID + itr->second->get_id() +
                                      AlbumTitle + itr->second->get_album() +
                                      releaseDate + itr->second->get_release_date() + year + itr->second->get_year();
                    songInfoBox.setTextBox(justTest);
                    searchTxtBox.clearText();
                    cout << "the search took EdjList" << time << "seconds" << endl;
                    searchTime.setText(searchType1 + "EdjList" + srchTime + time);

                }

                if(AdjBFS.isMouseOver(window)){
                    testMap.clear();
                    showMainMenu = false;
                    showRateScreen = true;
                    string time = " ";
                    testMap = getSongMap(searchTxtBox.getText(), "AdjMatrix", time);
                    itr = testMap.begin();
                    string justTest = songTitle + itr->second->get_name() + songID + itr->second->get_id() +
                                      AlbumTitle + itr->second->get_album() +
                                      releaseDate + itr->second->get_release_date() + year + itr->second->get_year();
                    songInfoBox.setTextBox(justTest);
                    searchTxtBox.clearText();
                    cout << "the search took adjMatrix" << time << "seconds" << endl;
                    searchTime.setText(searchType1 + "AdjMatrix" + srchTime + time);
                }



                //and it it was the left mouse button...
                if (event.mouseButton.button == sf::Mouse::Left) {

                    //1. Get the mouse position
                    auto pos = sf::Mouse::getPosition(window);
                   // cout << "mouses x:" << pos.x << " mouses y" << pos.y << endl;
                    if (searchBtn.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y))) {
                        //cout << "search btn clicked!" << endl;
                        showMainMenu = false;
                        showRateScreen = true;
                        //cout << "cleared test map" << endl;
                        testMap.clear();
                        //cout << "test map size" << testMap.size() << endl;

                    } else if (exitBtn.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y))) {
                       // cout << "exit btn was clicked returning to main menu..." << endl;
                        showMainMenu = true;
                        showRateScreen = false;
                    } else if(hateBtn.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y))){
                        //cout << "hate btn clicked" << endl;
                        auto tempItr = itr;
                        tempItr++;
                        if(!testMap.empty()){

                            if(tempItr != testMap.end()){
                                auto copyItr = itr;
                                copyItr++;
                                testMap.erase(itr);
                                itr = copyItr;
                                cout << itr->second << endl;
                                string justTest = songTitle + itr->second->get_name() + songID + itr->second->get_id() +
                                                  AlbumTitle + itr->second->get_album() +
                                                  releaseDate + itr->second->get_release_date() + year + itr->second->get_year();
                                songInfoBox.setTextBox(justTest);
                            }else{
                                auto copyItr = itr;
                                copyItr = testMap.begin();
                                testMap.erase(itr);
                                itr = copyItr;
                                string justTest = songTitle + itr->second->get_name() + songID + itr->second->get_id() +
                                                  AlbumTitle + itr->second->get_album() +
                                                  releaseDate + itr->second->get_release_date() + year + itr->second->get_year();
                                songInfoBox.setTextBox(justTest);
                            }

                        }else{
                            cout << "no more songs left :(" << endl;
                        }

                    }else if(loveBtn.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y))){
                       auto tempItr = itr;
                       tempItr++;
                        //cout << "love btn clicked" << endl;

                        if(!testMap.empty()){

                            if(tempItr != testMap.end()){
                                itr++;
                                string justTest = songTitle + itr->second->get_name() + songID + itr->second->get_id() +
                                                  AlbumTitle + itr->second->get_album() +
                                                  releaseDate + itr->second->get_release_date() + year + itr->second->get_year();
                                songInfoBox.setTextBox(justTest);
                            }else{
                                itr = testMap.begin();
                                string justTest = songTitle + itr->second->get_name() + songID + itr->second->get_id() +
                                                  AlbumTitle + itr->second->get_album() +
                                                  releaseDate + itr->second->get_release_date() + year + itr->second->get_year();
                                songInfoBox.setTextBox(justTest);
                            }
                        }else{
                            cout << "no more songs left :(" << endl;
                        }

                    }


                } else if (event.mouseButton.button == sf::Mouse::Right) {

                    auto pos = sf::Mouse::getPosition(window);
                    for (int i = 0; i < 25; i++) {

                    }

//                    flagSprite.setPosition(pos.x, pos.y);
//                    window.draw(flagSprite);


                }
            }
        }

        //Program stage two update


        //Program stage 3: Draw
        //step1 clear the screen
        window.clear(sf::Color::White);
        updateWindow(&window, showMainMenu, showRateScreen, &background, &searchBar, &searchBtn, &rateScreen, &loveBtn,
                  &hateBtn, &exitBtn, &searchTxtBox, &btn1, &musicNote, &songInfoBox, &AdjBFS, &EdgeBFS, &searchTime,
                  &musicLink);
        //searchTxtBox.drawTo(window);
        //  btn1.drawTo(window);
          window.display();


    }

    ///===final program stage shut down ====///
    TextureManager::Clear();

    return 0;
}
