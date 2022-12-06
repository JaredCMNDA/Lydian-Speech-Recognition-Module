/* Libraries */
#include "link.h"

using namespace std;

/* Global Variables */

const string spritesPath = "../assets/sprites/";

/* Functions */

// Note: All function definitions are in link.h
// AssetHandler.cpp and PositionFunctions.cpp are where many of the functions are written.

/* Main */
int btn = 1;

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lydian");

    std::map<std::string, sf::Sprite> assets = LoadSprites(window);
    cout << "Loaded " << assets.size() << " sprite(s) in main function. Printing." << endl;
    for(auto const& [key, val] : assets) {
        cout << "- - - - - " <<  key << endl;
    };
    cout << "Done printing." << endl;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close(); // Close window if user clicks the X
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close(); // Close window if user presses escape
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    if(event.mouseButton.x > 370 && event.mouseButton.x < 430){
                        if(event.mouseButton.y > 520 && event.mouseButton.y < 580){
                            cout << "button";
                            StartButton();
                        }
                    }
                } // Print mouse position if user clicks left mouse button
            }
        }
        // clear the window with black color
        window.clear(sf::Color(69, 90, 100));

        sf::Sprite mainimg = assets.at("XDZT.gif");
        CenterSprite(mainimg, window, 0, 0);
        sf::Sprite button = assets.at("buttons.png");
        button.setTextureRect(sf::IntRect(16, 0, 16, 16));
        button.setScale(4, 4);
        CenterSprite(button, window, 0, 250);



        sf::Text text;
        sf::Font font;
        font.loadFromFile("../assets/fonts/arial_narrow_7.ttf");
        text.setFont(font);
        text.setString("Lydian");
        text.setCharacterSize(96);
        text.setFillColor(sf::Color::White);
        CenterText(text, window, 0, +150);

        // end the current frame
        window.display();
    }

    return 0;
}
