/*** Don't change any text below */
// Important announcement on Significance of Academic Honor Policy
// The  Academic Honor Policy is an important aspect of keeping the integrity
// and quality of the computer science courses in general. Please don't share
// your project source with any other students on any occasion. I would like
// to let you know that, for the summer 2018 COP3014 course, we found several
// students violated the Academic Honor Policy by sharing their programming
// assignment source in an intentional and inadvertent manners. Please note that
// we will run MOSS" (plagiarism detection software tool) on future COP3014 student
// project submissions together with your summer 2018 project" submissions.
// In case your project source code happens to be >%75" similar to future student
// project source (which is statistically" almost impossible), your grade will
// be invalidated and your academic honor code violation will be reported to Dean's
// office. The following is the quick reference for Academic Honor Policy:"
// https://fda.fsu.edu/sites/g/files/upcbnu636/files/Media/Files/Academic%20Honor%20Policy/AHP%20Quick%20Reference%20Guide%20Nov%202017.pdf
//
/*
 * DON'T CHANGE FOLLOWING CODE
 */
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <string>

const float WIDTH     = 550.0;     // width of the window for display
const float HEIGHT    = 750.0;     // height of the window for display
const int   FONT_SIZE   =  25;     // character size
const float LEFT_X    = 100.0;     // Left X position for label
const float LOW_Y     = 700.0;     // LOW  Y position for label
const float HIGH_Y    =  50.0;     // HIGH Y position for label

using namespace std;

// Function prototypes - you need to implement
void readConfig(int &numGrades, int &maxInGrade, string &filename);
int  findNumInRange(string filename, int low, int high);
void initFrequency(string letters[], int freqLetters[],
                   int numGrades, string filename);
void setCurves(sf::RectangleShape bars[], sf::Text labels[], int freqLetters[],
               string letters[], sf::Font &font, int numGrades, int maxInGrades);

/* DON'T CHANGE THE ABOVE CODE */

int main() {

    int numGrades  = 5;   // number of different letter grades
    int maxInGrade = 20;  // maximum number of students in any letter grade
    string filename;      // name of input file containing scores

    // STEP 1:
    // IMPLEMENT readConfig that initializes (1) numGrades, (2) maxInGrade, and
    //                                       (3) filename
    //
    string letters[numGrades];   // each entry represents string representing the grade
    int freqLetters[numGrades];  // each entry records occurrence of grades corresponding
                                 // to the letter grade

    // STEP 2:
    // IMPLEMENT initFrequency that initializes letters[] and freqLetters[] by processing
    //                              input file (filename).
    // You need to replace the following for loop with a call to initFrequency
    //
    for (int i = 0; i < numGrades; i++) {
        letters[i] = 'A'+i;
        freqLetters[i] = 15+i;
    }

    //
    // DON'T CHANGE FOLLOWING CODE
    //
    sf::RenderWindow window(sf::VideoMode(600, 800), "COP3014 Grade Histogram");
    sf::Font font;
    font.loadFromFile("resources/arial.ttf");
    /* DON'T CHANGE ABOVE CODE */

    // You are free to change the following code. However, as it is, it should work
    sf::Text min, max;
    min.setFillColor(sf::Color::Yellow);
    min.setFont(font);
    min.setString("0");
    min.setCharacterSize(FONT_SIZE);
    max.setFillColor(sf::Color::Yellow);
    max.setFont(font);
    max.setString(to_string(maxInGrade));
    max.setCharacterSize(FONT_SIZE);
    min.setPosition(LEFT_X-FONT_SIZE*2, LOW_Y-FONT_SIZE);
    max.setPosition(LEFT_X-FONT_SIZE*2, HIGH_Y-FONT_SIZE/2);

    sf::RectangleShape bars[numGrades];
    sf::Text labels[numGrades];

    // STEP 3:
    // IMPLEMENT setTheCurves and replace the following initialization
    //                            code with a call to setTheCurves
    //
    float x_incr = (WIDTH - 100)/numGrades;
    float x_offset = LEFT_X+FONT_SIZE;
    float height_unit_pixels = (HEIGHT - (HIGH_Y + FONT_SIZE)) / maxInGrade;

    int count = 0;
    for (int i=0; i < numGrades; i++) {
        float height = freqLetters[i] > maxInGrade ? maxInGrade : freqLetters[i];
        bars[i].setSize(sf::Vector2f(x_incr-50, height*height_unit_pixels));
        bars[i].setPosition(x_offset+x_incr/2, LOW_Y);
        bars[i].rotate(180);
        labels[i].setFillColor(sf::Color::Yellow);
        labels[i].setFont(font);
        labels[i].setString(letters[i]);
        labels[i].setCharacterSize(FONT_SIZE);
        labels[i].setFillColor(sf::Color::Red);
        labels[i].setPosition(bars[i].getPosition().x-FONT_SIZE, LOW_Y+FONT_SIZE);
        x_offset += x_incr;
    }

    /* DON'T CHANGE THE FOLLOWING CODE */
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    window.clear();
                    window.draw(min);
                    window.draw(max);

                    for (int i = 0; i < numGrades; i++) {
                        window.draw(bars[i]);
                        window.draw(labels[i]);
                    }
                    window.display();
            }
        }
    }
    return 0;
}
