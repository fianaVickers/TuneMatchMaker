//
// https://termspar.wordpress.com/2019/04/11/c-sfml-textbox-and-button-classes/
//
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
public:
    Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor) {
        button.setSize(buttonSize);
        button.setFillColor(bgColor);

        // Get these for later use:
        btnWidth = buttonSize.x;
        btnHeight = buttonSize.y;

        text.setString(btnText);
        text.setCharacterSize(charSize);
        text.setColor(textColor);
    }

    // Pass font by reference:
    void setFont(sf::Font &fonts) {
        text.setFont(fonts);
    }

    void setBackColor(sf::Color color) {
        button.setFillColor(color);
    }

    void setTextColor(sf::Color color) {
        text.setColor(color);
    }

    void setPosition(sf::Vector2f point) {
        button.setPosition(point);

        // Center text on button:
        float xPos = (point.x + btnWidth / 2) - (text.getLocalBounds().width / 2);
        float yPos = (point.y + btnHeight / 2.2) - (text.getLocalBounds().height / 2);
        text.setPosition(xPos, yPos);
    }

    void drawTo(sf::RenderWindow &window) {
        window.draw(button);
        window.draw(text);
    }

    // Check if the mouse is within the bounds of the button:
    bool isMouseOver(sf::RenderWindow &window) {
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        int btnPosX = button.getPosition().x;
        int btnPosY = button.getPosition().y;

        int btnxPosWidth = button.getPosition().x + btnWidth;
        int btnyPosHeight = button.getPosition().y + btnHeight;

        if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
            return true;
        }
        return false;
    }
private:
    sf::RectangleShape button;
    sf::Text text;

    int btnWidth;
    int btnHeight;
};
