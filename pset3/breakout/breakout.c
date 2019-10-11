//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // keep playing until game over
    srand48((long int) time(NULL));
    double random = drand48();
    while(random < 0.5)
    {
        random = drand48();
    }
    double rate = 0.2;
    double velocityx = random * rate;
    double velocityy = velocityx;
    waitForClick();
    while (lives > 0 && bricks > 0)
    {
        // Game instructions
        move(ball, velocityx, velocityy);
        
        // paddle movement
        GEvent paddlemove = getNextEvent(MOUSE_EVENT);
        if (paddlemove != NULL)
        {
            if (getEventType(paddlemove) == MOUSE_MOVED)
            {
                double x = getX(paddlemove) - getWidth(paddle) / 2;
                if (x >= 340)
                {
                    x = 340;
                }
                else if (x <= 0)
                {
                    x = 0;
                }
                setLocation(paddle, x, 500);
            }
        }
        
        // detect balls collision with walls
        if (getX(ball) + 20 >= 400)
        {
            velocityx = -velocityx;
        }
        else if (getX(ball) <= 0)
        {
            velocityx = -velocityx;
        }
        
        if (getY(ball) + 20 >= 600)
        {
            lives = lives - 1;
            waitForClick();
            if (lives >= 1)
            {
                setLocation(ball, 190, 290);    
            }           
        }
        else if (getY(ball) <= 0)
        {
            velocityy = -velocityy;
        }
        
        // detect balls collision with paddle and bricks
        GObject object = detectCollision(window, ball);
        if (object != NULL)
        {
            if ((object == paddle) && (getY(ball) + 20 < 525))
            {
                if (velocityy >= 0)
                {
                    velocityy = -velocityy;
                }
            }
            if (strcmp(getType(object), "GRect") == 0 && object != paddle)
            {
                removeGWindow(window, object);
                bricks = bricks - 1;
                velocityy = -velocityy;
                points++;
            }
            updateScoreboard(window, label, points);            
        }
        

    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // brick grid
    int x = 1;
    int y = 61;
    string colour;
    for(int i = 1; i < 6; i++)
    {
        if (i == 1)
        {
            colour = "RED";
        }
        else if (i == 2)
        {
            colour = "ORANGE";
        }
        else if (i == 3)
        {
            colour = "YELLOW";
        }
        else if (i == 4)
        {
            colour = "GREEN";
        }
        else
        {
            colour = "CYAN";
        }
        
        x = 1;
        for(int j = 0; j < 11; j++)
        {
            GRect rect = newGRect(x, y, 35, 15);
            setFilled(rect, true);
            setColor(rect, colour);
            add(window, rect);
            x = x + 40;
        }
        y = y + 20;
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // ball
    GOval oval = newGOval(190, 290, 20, 20);
    setFilled(oval, true);
    setColor(oval, "BLACK");
    add(window, oval);
    return oval;
}

/**
 * Instantiates paddle in bottom-middle of window.
 
 */
GRect initPaddle(GWindow window)
{
    // paddle
    GRect rect = newGRect(165, 500, 70, 5);
    setFilled(rect, true);
    setColor(rect, "BLACK");
    add(window, rect);
    return rect;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // Scoreboard
    double x, y;
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-50");
    setColor(label, "GRAY");
    x = (getWidth(window) - getWidth(label)) / 2;
    y = (getHeight(window) - getFontAscent(label)) / 2;
    setLocation(label, x, y);
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
