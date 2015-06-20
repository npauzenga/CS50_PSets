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

// brick dimensions
#define BRICK_WIDTH (WIDTH / COLS - 3)
#define BRICK_HEIGHT 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// Paddle dimensions and Y-position
#define PADDLE_HEIGHT 10
#define PADDLE_WIDTH 80
#define PADDLE_YPOS HEIGHT - PADDLE_HEIGHT

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);
void movePaddle(GEvent event, GRect paddle);

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
    
    // initial velocity of ball
    double xVelocity = drand48() + 1;
    double yVelocity = drand48() +1;
    
    waitForClick();

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
       GEvent mouseEvent = getNextEvent(MOUSE_EVENT);
       
       // move paddle according to mouse x-position
       movePaddle(mouseEvent, paddle);

       // move ball randomly along x and y
       move(ball, xVelocity, yVelocity);
       
       // check for collision and store the hit object
       GObject hitObject = detectCollision(window, ball);
       
       // if the paddle or brick is hit, reverse direction
       if (hitObject != NULL && strcmp(getType(hitObject), "GLabel") != 0)
       {
            yVelocity = -yVelocity;
            xVelocity = -xVelocity;
            
            // if the ball hits a brick, remove it and update points
            if (hitObject != paddle)
            {
                removeGWindow(window, hitObject);
                points++;
                updateScoreboard(window, label, points);
            } 
       }

       // if the ball hits the bottom, decrease lives and pause until click
       if (getHeight(ball) + getY(ball) >= getHeight(window))
       {
           lives--;
           waitForClick();
           setLocation(ball, WIDTH/2, HEIGHT/2);
       }
       // bounce ball off of all other edges
       else if (getY(ball) <= 0)
       {
           yVelocity = -yVelocity;
       }
       else if (getWidth(ball) + getX(ball) >= getWidth(window))
       {
        xVelocity = -xVelocity;
       }
       else if (getX(ball) <= 0)
       {
        xVelocity = -xVelocity;
       }
       pause(10);       
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
    string brickColor;

    // draw the rows first, then columns
        for (int i = 0; i < WIDTH; i+= WIDTH/COLS)
        {
            for (int j = 0; j < ROWS; j++)
            {
                // alternate brick color on odd/even rows
                if (j % 2 == 0)
                {
                    brickColor = "BLACK";
                }
                else
                {
                    brickColor = "ORANGE";
                }
                
                // draw bricks. setting the y position this way seems hacky
                
                GRect brick = newGRect(i, (j * 15), BRICK_WIDTH, BRICK_HEIGHT); 
                setFilled(brick, true);
                setColor(brick, brickColor);
                add(window, brick);
            }
        }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(WIDTH/2, HEIGHT/2, RADIUS * 2, RADIUS * 2);
    setFilled(ball, true);
    setColor(ball, "BLACK");
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    int paddleXpos = (WIDTH / 2) - (PADDLE_WIDTH / 2);
    
    GRect paddle = newGRect(paddleXpos, PADDLE_YPOS, PADDLE_WIDTH, PADDLE_HEIGHT);
    setFilled(paddle, true);
    setColor(paddle, "BLUE");
    add(window, paddle);
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel score = newGLabel("0");
    
    double x = (getWidth(window) - getWidth(score)) / 2;
    double y = (getHeight(window) - getHeight(score)) / 2;
    
    setFont(score, "sanSerif-18");
    setLocation(score, x, y);
    add(window, score);
    
    return score;
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

// move the paddle wth the mouse cursor
void movePaddle(GEvent event, GRect paddle)
{
     if (event != NULL)
           {
                if (getEventType(event) == MOUSE_MOVED)
                {
                    double x = getX(event) - getWidth(paddle) / 2;
                    setLocation(paddle, x, PADDLE_YPOS);
                }
           }
}


