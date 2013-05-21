/* Will Richard
 * Visibility.h
 */


#ifndef __Visibility_h
#define __Visibility_h

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>

#include "Points.h"
#include "Horizon.h"

#define DUMMY_SLOPE -1 * FLT_MAX //set a dummy slope which is the absolutely smallest value a float can have

/* recursivly computes the visibility of set a points.  The points should be ordered by distance, from closest to furthest away.
BASE CASE:  When there is only one point cosidered, it creates a new Horizon with dummy points surrounding the one point
RECURSION: Split the range of points (going from index "start" to index "end", not including end) into 2 by distance, and calculate the horizon for each half. It then checks to make sure that any points in the 2nd half that are occluded by the 1st horizon are marked as inivsible.  Finally, it merges the 2 halves together using Horizon_merge (see Horizon.h).
Also, pass an int*.  The int at that pointer will have the number of visible points.
The passed int, rightSide is 1 if visibility is working on the right-hand side of the grid (with x greater than viewpoint x), 0 if it is working on the left hand side of the grid (with x value less than viewpoint x)
Pass the level of recursion and viewpoint row, column as well, for horizon information purposes - they are not used, just printed.
*/
Horizon* visibility(int start, int end, Point** points, long* numVisible, int rightSide, short recursionLevel);

#endif
