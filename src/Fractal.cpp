/* File Sierpinski.cpp
 * -------------------------------------------------------
 *
 * This program draws the Sierpinski triangle using the
 * Chaos game method.
 */

#include <iostream>
#include "gwindow.h"
#include "random.h"
#include "gbufferedimage.h"
#include "point.h"
using namespace std;

/* Function prototypes */
Point moveRandomly(Point point);
Point randomCorner();

/* Constants */
const int WIDTH = 600;
const int HEIGHT = 600;
const int OFFSET = 20;

/* Main function */
int main() {
    GWindow window(WIDTH, HEIGHT);
    GBufferedImage *image = new GBufferedImage(WIDTH, HEIGHT, 0xFFFFFF);
    window.add(image);

    Point newPoint(WIDTH - OFFSET, HEIGHT - OFFSET); // start point

    for (int i = 0; i <= 200000; i++){
        image->setRGB(newPoint.getX() - 1, newPoint.getY() - 1, 0x000000);
        newPoint = moveRandomly(newPoint);
    }

    return 0;
}

/* Function: moveRandomly
 * Usage: newPoint = moveRandomly(newPoint);
 * -------------------------------------------------------------------------
 *
 * This function return point in center between received point and randomly
 * selected corner of the triangle.
 *
 * @return Point between received point and randomly selected corner
 * of the triangle
 */
Point moveRandomly(Point point){
    Point corner = randomCorner();

    return Point((point.getX() + corner.getX()) / 2, (point.getY() + corner.getY()) / 2);
}

/* Function: randomCorner
 * Usage: Point corner = randomCorner();
 * ----------------------------------------------------------------------------
 *
 * This function randomly select one of the destination points of the triangle
 *
 * @return Point - one of three corners of the triangle
 */
Point randomCorner(){
    int cornerIndex = randomInteger(1, 3);

    /* Corners of the triangle*/
    if (cornerIndex == 1){
        return Point(WIDTH / 2, OFFSET);
    } else if(cornerIndex == 2){
        return Point(OFFSET, HEIGHT - OFFSET);
    } else {
        return Point(WIDTH - OFFSET, HEIGHT - OFFSET);
    }
}


