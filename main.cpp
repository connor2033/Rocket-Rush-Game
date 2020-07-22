#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.hpp>
#include <math.h>
#include <vector>
#include <sstream>


using namespace std;
using namespace sf;


//function to give float variables string values
string NumberToString(float Number) {
    ostringstream converter;
    converter<< Number;
    return converter.str();
}


//function to give floats only 2 decimal places
float twodec (float num1){
    num1 = num1 * 100;
    num1 = round(num1);
    num1 = num1 / 100;
    return num1;
}



int main()
{
    RenderWindow window(VideoMode(800, 600), "Final Project");
    window.setFramerateLimit(60);


////////clocks and time
    srand(time(0));

    Clock c;
    Time t;

    Clock c1;
    Time t1;


////////////////////////////////////////////////Main texture creation
    Texture tex1;
    tex1.loadFromFile("Space.png");

    Texture tex2;
    tex2.loadFromFile("rocketsheet.png");

    Texture tex3;
    tex3.loadFromFile("rock.png");

    Texture menubg;
    menubg.loadFromFile("menubg.jpg");

    Texture tex4;
    tex4.loadFromFile("title.png");

    Texture tex5;
    tex5.loadFromFile("start.png");

    Texture tex6;
    tex6.loadFromFile("options.png");

    Texture tex7;
    tex7.loadFromFile("howtoplay.png");

    Texture tex8;
    tex8.loadFromFile("startbold.png");

    Texture tex9;
    tex9.loadFromFile("optionsbold.png");

    Texture tex10;
    tex10.loadFromFile("howtoplaybold.png");

    /////////////////////////option screen textures

    Texture tex11;
    tex11.loadFromFile("back.png");

    Texture tex12;
    tex12.loadFromFile("backbold.png");

    Texture tex13;
    tex13.loadFromFile("difeasy.png");

    Texture tex14;
    tex14.loadFromFile("difeasybold.png");

    Texture tex15;
    tex15.loadFromFile("difmed.png");

    Texture tex16;
    tex16.loadFromFile("difmedbold.png");

    Texture tex17;
    tex17.loadFromFile("difhard.png");

    Texture tex18;
    tex18.loadFromFile("difhardbold.png");

    Texture tex19;
    tex19.loadFromFile("redbutton.png");

    Texture tex20;
    tex20.loadFromFile("redbuttonbold.png");

    Texture tex21;
    tex21.loadFromFile("bluebutton.png");

    Texture tex22;
    tex22.loadFromFile("bluebuttonbold.png");

    Texture tex23;
    tex23.loadFromFile("greenbutton.png");

    Texture tex24;
    tex24.loadFromFile("greenbuttonbold.png");

    Texture tex25;
    tex25.loadFromFile("yellowbutton.png");

    Texture tex26;
    tex26.loadFromFile("yellowbuttonbold.png");

    Texture tex27;
    tex27.loadFromFile("LRMoff.png");

    Texture tex28;
    tex28.loadFromFile("LRMoffbold.png");

    Texture tex29;
    tex29.loadFromFile("LRMon.png");

    Texture tex30;
    tex30.loadFromFile("LRMonbold.png");

    Texture tex31;
    tex31.loadFromFile("fuel.png");

    Texture tex32;
    tex32.loadFromFile("restart.png");

    Texture tex33;
    tex33.loadFromFile("restartbold.png");

    Texture tex34;
    tex34.loadFromFile("howto.png");


/////////////////////////////////////////Main Sprite creation
    Sprite backbutton;
    backbutton.setTexture(tex11);
    backbutton.setPosition(0,0);

    Sprite howtoparagraph;
    howtoparagraph.setTexture(tex34);
    howtoparagraph.setPosition(0,0);

    Sprite lrmbutton;
    lrmbutton.setTexture(tex27);
    lrmbutton.setPosition(0,0);

    Sprite colourbutton;
    colourbutton.setTexture(tex19);
    colourbutton.setPosition(0,0);

    Sprite difficultybutton;
    difficultybutton.setTexture(tex13);
    difficultybutton.setPosition(0,0);

    Sprite fuelcan;
    fuelcan.setTexture(tex31);
    fuelcan.setPosition(1600, rand() % 550);

    Sprite restart;
    restart.setTexture(tex32);
    restart.setPosition(0,0);

    Sprite background1;
    background1.setTexture(tex1);
    background1.setPosition(0,0);

    Sprite background2;
    background2.setTexture(tex1);
    background2.setPosition(-1600,0);

    Sprite menubackground;
    menubackground.setTexture(menubg);
    menubackground.setScale(0.6, 0.6);
    menubackground.setPosition(0,0);

    Sprite startbutton;
    startbutton.setTexture(tex5);
    startbutton.setPosition(0,0);

    Sprite Title;
    Title.setTexture(tex4);
    Title.setPosition(0,0);

    Sprite optionsbutton;
    optionsbutton.setTexture(tex6);
    optionsbutton.setPosition(0,0);

    Sprite howtobutton;
    howtobutton.setTexture(tex7);
    howtobutton.setPosition(0,0);

    Sprite rocket;
    rocket.setTexture(tex2);
    rocket.setTextureRect(IntRect(1,23,303,122));
    rocket.setScale(0.5,0.5);
    rocket.setPosition(250,300);
    rocket.setRotation(17);

    ///////////////////////////////////////////////////////Audio Stuff

    SoundBuffer buffer;
    buffer.loadFromFile("click.wav");
    Sound click;
    click.setBuffer(buffer);

    SoundBuffer buffer2;
    buffer2.loadFromFile("fuel.wav");
    Sound fuel;
    fuel.setBuffer(buffer2);

    SoundBuffer buffer3;
    buffer3.loadFromFile("ded.wav");
    Sound gameover;
    gameover.setBuffer(buffer3);

    SoundBuffer buffer4;
    buffer4.loadFromFile("start.wav");
    Sound start;
    start.setBuffer(buffer4);


    /////////////////////////variable creation
    bool moveup = false;
    bool movedown = false;

    bool red = true;
    bool blue = false;
    bool green = false;
    bool yellow = false;

    bool startscreen = true;
    bool optionscreen = false;
    bool howtoscreen = false;

    bool easy = true;
    bool medium = false;
    bool hard = false;

    bool lrmon = false;
    bool lrmoff = true;

    bool endscreen = false;

    float difficulty;
    float distancekm = 0;

    float gas = 100;
    int colnum = 2;



    //asteroid vectors
    Sprite rock;
    vector<Sprite> As;
    vector<float> Rspeed;
    vector<int> Randtex;
    vector<int> randrota;


///////////////////////////Ingame rectanges
    RectangleShape r2;
    r2.setOrigin(0,0);
    r2.setFillColor(Color::Transparent);
    r2.setSize(Vector2f(45,22));
    r2.setOutlineColor(Color::Green);
    r2.setOutlineThickness(1);

    RectangleShape r3;
    r3.setOrigin(0,0);
    r3.setFillColor(Color::Transparent);
    r3.setSize(Vector2f(30,10));
    r3.setOutlineColor(Color::Green);
    r3.setOutlineThickness(1);

    RectangleShape fueltank;
    fueltank.setOrigin(0,0);
    fueltank.setFillColor(Color(56, 234, 112));
    fueltank.setPosition(10,10);
    fueltank.setSize(Vector2f(100,20));

    RectangleShape outline1;
    outline1.setOrigin(0,0);
    outline1.setOutlineColor(Color(66, 217, 244));
    outline1.setFillColor(Color(244, 66, 78));
    outline1.setOutlineThickness(3);
    outline1.setPosition(10, 10);
    outline1.setSize(Vector2f(100,20));

    RectangleShape drect;
    drect.setOrigin(0,0);
    drect.setOutlineColor(Color(66, 217, 244));
    drect.setFillColor(Color(56, 234, 112));
    drect.setOutlineThickness(3);
    drect.setPosition(710, 10);
    drect.setSize(Vector2f(80,25));


/////////////////////////Ingame texts and fonts
    Font font;
    font.loadFromFile("OCRAEXT.TTF");

    Text dist1 (NumberToString(distancekm), font);
    dist1.setPosition(714,7);
    dist1.setCharacterSize(24);
    dist1.setColor(Color(244, 66, 78));

    Text dist2 (NumberToString(distancekm), font);
    dist2.setPosition(478,330);
    dist2.setCharacterSize(38);
    dist2.setColor(Color(66, 217, 244));


/////////////////////////////////////////////////////Main While Loop
    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        t= c.getElapsedTime();
        t1= c1.getElapsedTime();


        //setting difficulties (higher # = easier)
        if (easy == true) difficulty = 0.7;
        if (medium == true) difficulty = 0.5;
        if (hard == true) difficulty = 0.3;


////////////////////////////////////////////////END SCREEN///////////////////////////////////////////////////

//resetting variables
if (endscreen == true){
    As.clear();
    fuelcan.setPosition(1600, rand() % 550);
    gas = 100;
    moveup = false;
    movedown = false;
    rocket.setPosition(250,300);
    dist2.setString(NumberToString(distancekm));
    distancekm = 0;
}


//endscreen loop
while (endscreen == true){

            Event event;
            while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        t1= c1.getElapsedTime();

        restart.setTexture(tex32);


        //restart button, sending to start screen
        if (Mouse::getPosition(window).x > 290 && Mouse::getPosition(window).x < 530){
            if (Mouse::getPosition(window).y > 440 && Mouse::getPosition(window).y < 480){
                restart.setTexture(tex33);
                if (Mouse::isButtonPressed(Mouse::Left) && optionscreen == false && howtoscreen == false && t1.asSeconds() > 0.2){
                    click.play();
                    endscreen = false;
                    startscreen = true;
                    c1.restart();
                }
            }
        }


        //temp getting mouse position on screen
        //cout<<Mouse::getPosition(window).x<<", "<<Mouse::getPosition(window).y<<endl;


      window.clear(Color::Black);
      window.draw(menubackground);
      window.draw(Title);
      window.draw(restart);
      window.draw(dist2);




      window.display();
}
///////////////////////////////////////////////////////////////start screen//////////////////////////////////////////////
        while (startscreen == true){

            Event event;
            while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        t1= c1.getElapsedTime();

        //temp getting mouse position on screen
        //cout<<Mouse::getPosition(window).x<<", "<<Mouse::getPosition(window).y<<endl;

        //reset mouse hover over button variables
        startbutton.setTexture(tex5);
        optionsbutton.setTexture(tex6);
        howtobutton.setTexture(tex7);
        backbutton.setTexture(tex11);
        if (easy == true) difficultybutton.setTexture(tex13);
        if (medium == true) difficultybutton.setTexture(tex15);
        if (hard == true) difficultybutton.setTexture(tex17);
        if (red == true) colourbutton.setTexture(tex19);
        if (blue == true) colourbutton.setTexture(tex21);
        if (green == true) colourbutton.setTexture(tex23);
        if (yellow == true) colourbutton.setTexture(tex25);
        if (lrmoff == true) lrmbutton.setTexture(tex27);
        if (lrmon == true) lrmbutton.setTexture(tex29);


        //start button
        if (Mouse::getPosition(window).x > 320 && Mouse::getPosition(window).x < 480){
            if (Mouse::getPosition(window).y > 255 && Mouse::getPosition(window).y < 295){
                startbutton.setTexture(tex8);
                if (Mouse::isButtonPressed(Mouse::Left) && optionscreen == false ){
                        start.play();
                        startscreen = false;
                }
            }
        }


        //how to button
        if (Mouse::getPosition(window).x > 215 && Mouse::getPosition(window).x < 592){
            if (Mouse::getPosition(window).y > 440 && Mouse::getPosition(window).y < 478){
                howtobutton.setTexture(tex10);
                if (Mouse::isButtonPressed(Mouse::Left) && optionscreen == false && endscreen == false  && t1.asSeconds() > 0.2){
                    click.play();
                    howtoscreen = true;
                    c1.restart();
                }
            }
        }


        //main colours
        //blue: rgb(66, 217, 244)
        //green: rgb(56, 234, 112)

        window.clear(Color::Black);
        window.draw(menubackground);
        window.draw(Title);


        //how to play screen
        if (howtoscreen == true){

            //back button
            if (Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 83){
            if (Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y < 33){
                backbutton.setTexture(tex12);
                if (Mouse::isButtonPressed(Mouse::Left)){
                    click.play();
                    howtoscreen = false;
                }
            }
            }


            window.draw(Title);
            window.draw(backbutton);
            window.draw(howtoparagraph);
        }


        //options screen
        if (optionscreen == true){

            //back button
            if (Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 83){
            if (Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y){
                backbutton.setTexture(tex12);
                if (Mouse::isButtonPressed(Mouse::Left)){
                    click.play();
                    optionscreen = false;
                }
            }
        }


            //difficulty selector
            if (Mouse::getPosition(window).x > 136 && Mouse::getPosition(window).x < 683){
            if (Mouse::getPosition(window).y > 254 && Mouse::getPosition(window).y < 294){
                if (easy == true) difficultybutton.setTexture(tex14);
                if (medium == true) difficultybutton.setTexture(tex16);
                if (hard == true) difficultybutton.setTexture(tex18);
                if (Mouse::isButtonPressed(Mouse::Left) && optionscreen == true  && t1.asSeconds() > 0.2){
                    click.play();
                    if (easy == true){
                    c1.restart();
                    easy = false;
                    medium = true;
                    hard = false;
                    }
                    else if (medium == true){
                    c1.restart();
                    easy = false;
                    medium = false;
                    hard = true;
                    }
                    else if (hard == true){
                    c1.restart();
                    easy = true;
                    medium = false;
                    hard = false;
                    }

                }
            }
        }


            //colour selector
            if (Mouse::getPosition(window).x > 220 && Mouse::getPosition(window).x < 600){
            if (Mouse::getPosition(window).y > 344 && Mouse::getPosition(window).y < 382){
                if (red == true) colourbutton.setTexture(tex20);
                if (blue == true) colourbutton.setTexture(tex22);
                if (green == true) colourbutton.setTexture(tex24);
                if (yellow == true) colourbutton.setTexture(tex26);
                if (Mouse::isButtonPressed(Mouse::Left) && optionscreen == true && t1.asSeconds() > 0.2){
                    click.play();
                    if (red == true){
                    c1.restart();
                    red = false;
                    blue = true;
                    green = false;
                    yellow = false;
                    }
                    else if (blue == true){
                    c1.restart();
                    red = false;
                    blue = false;
                    green = true;
                    yellow = false;
                    }
                    else if (green == true){
                    c1.restart();
                    red = false;
                    blue = false;
                    green = false;
                    yellow = true;
                    }
                    else if (yellow == true){
                    c1.restart();
                    red = true;
                    blue = false;
                    green = false;
                    yellow = false;
                    }
                }
            }
        }

                    //changing values of colnum variable for textureRect
                    if (red == true) colnum = 2;
                    if (blue == true) colnum = 606;
                    if (green == true) colnum = 1214;
                    if (yellow == true) colnum = 1820;


            //left/right motion button
            if (Mouse::getPosition(window).x > 40 && Mouse::getPosition(window).x < 775){
            if (Mouse::getPosition(window).y > 445 && Mouse::getPosition(window).y < 485){
                if (lrmoff == true) lrmbutton.setTexture(tex28);
                if (lrmon == true) lrmbutton.setTexture(tex30);
                if (Mouse::isButtonPressed(Mouse::Left) && optionscreen == true && t1.asSeconds() > 0.2){
                    click.play();
                    if (lrmoff == true) {
                        c1.restart();
                        lrmoff = false;
                        lrmon = true;
                    }
                    else if (lrmon == true) {
                        c1.restart();
                        lrmoff = true;
                        lrmon = false;
                    }
                }
            }
        }


                window.draw(backbutton);
                window.draw(difficultybutton);
                window.draw(colourbutton);
                window.draw(lrmbutton);
        }

        //options button
        if (Mouse::getPosition(window).x > 285 && Mouse::getPosition(window).x < 518){
            if (Mouse::getPosition(window).y > 346 && Mouse::getPosition(window).y < 385){
                optionsbutton.setTexture(tex9);
                if (Mouse::isButtonPressed(Mouse::Left) && optionscreen == false && t1.asSeconds() > 0.2){
                    click.play();
                    optionscreen = true;
                    c1.restart();
                }
            }
        }


        if (optionscreen == false && howtoscreen == false){
        window.draw(startbutton);
        window.draw(optionsbutton);
        window.draw(howtobutton);
        }

        window.display();

        }


///////////////^^^^^End of start screen^^^^^


        //creating and destroting asteroids
        if (t.asSeconds() > difficulty && endscreen == false) {
            c.restart();
            As.push_back(Sprite());
            As.back().setTexture(tex3);
            Randtex.push_back(rand() % 4 + 1);
            if (Randtex.back() == 1) As.back().setTextureRect(IntRect(0,0,128,128));
            else if (Randtex.back() == 2) As.back().setTextureRect(IntRect(128,0,128,128));
            else if (Randtex.back() == 3) As.back().setTextureRect(IntRect(0,128,128,128));
            else As.back().setTextureRect(IntRect(128,128,128,128));
            As.back().setScale(0.5,0.5);
            Rspeed.push_back(rand() % 6 +3);
            randrota.push_back(rand() % 3 + -1);
            As.back().setPosition(900,rand() % 472 + 60);
        }

        for (int i=0; i<As.size(); i++){
            As[i].setOrigin(64,64);
            As[i].move(-Rspeed[i],0);
            As[i].rotate(randrota[i]);
            //cout<<randrota[i]<<endl;
        }



        for (int i=0; i<As.size(); i++){
            if (As[i].getPosition().x < -70){
                As.erase(As.begin()+i);
                Rspeed.erase(Rspeed.begin()+i);
                randrota.erase(randrota.begin()+i);
            }
        }


        //rocket animation
        rocket.setTextureRect(IntRect(abs(int(background1.getPosition().x/10)%2)*303+colnum,23,302,122));


        //up and down movement
        if(Keyboard::isKeyPressed(Keyboard::Up)){
            moveup = true;
            movedown = false;
        }

        if(Keyboard::isKeyPressed(Keyboard::Down)){
            moveup = false;
            movedown = true;
        }

        if (moveup == true){
            rocket.move(0,-3);
        }

         if (movedown == true){
            rocket.move(0,3);
        }


//////////Left Right Motion///////////
    if (lrmon == true){
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            rocket.move(2,0);
        }

        if(Keyboard::isKeyPressed(Keyboard::Left)){
            rocket.move(-2,0);
        }
    }

        if (rocket.getPosition().x <= -23) rocket.move(2,0);
        if (rocket.getPosition().x >= 670) rocket.move(-2,0);



        //paralax background movement
        background1.move(-1,0);
        background2.move(-1,0);

        if (background1.getPosition().x <= -1600){
            background1.setPosition(1599,0);
        }

        if (background2.getPosition().x <= -1600){
        background2.setPosition(1599,0);
        }

        //rocket teleporting from top/bottom of screen
        if (rocket.getPosition().y > 600){
            rocket.setPosition(rocket.getPosition().x,-60);
        }

        if (rocket.getPosition().y < -60){
            rocket.setPosition(rocket.getPosition().x,600);
        }



        //Rocket/asteroid hit detection
        for (int i=0; i<As.size(); i++){
            if (As[i].getGlobalBounds().intersects(r3.getGlobalBounds())){
                    gameover.play();
                    endscreen = true;
            }
            if (As[i].getGlobalBounds().intersects(r2.getGlobalBounds())){
                    gameover.play();
                    endscreen = true;
            }

        }

        //hitbox positions
        r2.setPosition(rocket.getPosition().x + 30,rocket.getPosition().y + 35);
        r3.setPosition(rocket.getPosition().x + 77,rocket.getPosition().y + 41);


        //fuelcan position and gas reset
        fuelcan.move(-3, 0);
        if (fuelcan.getGlobalBounds().intersects(r3.getGlobalBounds())){
            fuelcan.setPosition(1600,  rand() % 550);
            gas = 100;
            fuel.play();
        }
        if (fuelcan.getGlobalBounds().intersects(r2.getGlobalBounds())){
            fuelcan.setPosition(1600,  rand() % 550);
            gas = 100;
            fuel.play();
        }

        if (fuelcan.getPosition().x <= -60) fuelcan.setPosition(1600,  rand() % 550);


        //gas draining
        gas = gas - 0.1;
        fueltank.setSize(Vector2f(gas,20));

        if (gas <= 0){
            gameover.play();
            endscreen = true;
        }

        //distance
        distancekm = distancekm + 0.01;
        distancekm = twodec(distancekm);
        dist1.setString(NumberToString(distancekm));



        window.clear(Color::White);
        window.draw(background1);
        window.draw(background2);
        window.draw(fuelcan);
        window.draw(rocket);

        for (int i=0; i<As.size(); i++){
            window.draw(As[i]);
        }

        window.draw(outline1);
        window.draw(fueltank);
        window.draw(drect);
        window.draw(dist1);

        //drawing hitboxes:
        //window.draw(r2);
        //window.draw(r3);

        window.display();
    }

    return 0;
}
