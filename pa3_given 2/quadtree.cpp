/**
 * @file quadtree.cpp
 * Quadtree class implementation.
 */

#include <cstddef>
#include <cstdlib>
#include <iostream>

using namespace std;

#include "quadtree.h"

// Quadtree
//   - parameters: none
//   - constructor for the Quadtree class; makes an empty tree
Quadtree::Quadtree()
{
    root = NULL;

}

// Quadtree
//   - parameters: PNG const & source - reference to a const PNG
//                    object, from which the Quadtree will be built
//                 int resolution - resolution of the portion of source
//                    from which this tree will be built
//   - constructor for the Quadtree class; creates a Quadtree representing
//        the resolution by resolution block in the upper-left corner of
//        source
Quadtree::Quadtree(PNG const& source, int setresolution)
{
    buildTree(source, setresolution);
}

// Quadtree
//   - parameters: Quadtree const & other - reference to a const Quadtree
//                    object, which the current Quadtree will be a copy of
//   - copy constructor for the Quadtree class
Quadtree::Quadtree(Quadtree const& other)
{
    if (other.root == NULL){
        root = NULL;
        return;
    }
    root = copy(other.root);
}

Quadtree::QuadtreeNode* Quadtree::copy(QuadtreeNode* someroot){

    if (someroot == NULL){
        return NULL;
    }
    auto * temp = new QuadtreeNode(someroot);
    temp->nwChild = copy(someroot->nwChild);
    temp->neChild = copy(someroot->neChild);
    temp->swChild = copy(someroot->swChild);
    temp->seChild = copy(someroot->seChild);
    return temp;

}

// ~Quadtree
//   - parameters: none
//   - destructor for the Quadtree class
Quadtree::~Quadtree()
{
    clearTree(root);
}

void Quadtree:: clearTree(QuadtreeNode *& node){

    if (node == NULL){
        return;
    }
    clearTree(node->nwChild);
    clearTree(node->neChild);
    clearTree(node->swChild);
    clearTree(node->seChild);
    delete node;
    node = NULL;

}


// operator=
//   - parameters: Quadtree const & other - reference to a const Quadtree
//                    object, which the current Quadtree will be a copy of
//   - return value: a const reference to the current Quadtree
//   - assignment operator for the Quadtree class
Quadtree const& Quadtree::operator=(Quadtree const& other)
{
    if (root == other.root){
        return *this;
    }
    clearTree(root);
    root = copy(other.root);
    return *this;
}

// buildTree (public interface)
//   - parameters: PNG const & source - reference to a const PNG
//                    object, from which the Quadtree will be built
//                 int resolution - resolution of the portion of source
//                    from which this tree will be built
//   - transforms the current Quadtree into a Quadtree representing
//        the resolution by resolution block in the upper-left corner of
//        source
void Quadtree::buildTree(PNG const& source, int setresolution)
{
    root = new QuadtreeNode(0, 0, setresolution);

    buildHelp(source, setresolution, root);
}

void Quadtree::buildHelp(PNG const &source, int resolution, QuadtreeNode *subtree) {

    if ( resolution == 1){
        subtree->element = *(source(subtree->x, subtree->y));
        return;
    }

    subtree->nwChild = new QuadtreeNode(subtree->x, subtree->y, resolution/2);
    subtree->neChild = new QuadtreeNode(subtree->x + resolution/ 2, subtree->y, resolution/2);
    subtree->swChild = new QuadtreeNode(subtree->x, subtree->y + resolution/2 , resolution/2);
    subtree->seChild = new QuadtreeNode(subtree->x + resolution/2, subtree->y + resolution/2, resolution/2);

    buildHelp(source, resolution/2, subtree->nwChild);
    buildHelp(source, resolution/2, subtree->neChild);
    buildHelp(source, resolution/2, subtree->swChild);
    buildHelp(source, resolution/2, subtree->seChild);


    subtree->element.red = (subtree->nwChild->element.red + subtree->neChild->element.red + subtree->swChild->element.red + subtree->seChild->element.red)/4;
    subtree->element.green = (subtree->nwChild->element.green + subtree->neChild->element.green + subtree->swChild->element.green + subtree->seChild->element.green)/4;
    subtree->element.blue = (subtree->nwChild->element.blue + subtree->neChild->element.blue + subtree->swChild->element.blue + subtree->seChild->element.blue)/4;
}

// getPixel (public interface)
//   - parameters: int x, int y - coordinates of the pixel to be retrieved
//   - return value: an RGBAPixel representing the desired pixel of the
//        underlying bitmap
//   - retrieves and returns the pixel at coordinates (x, y) in the
//        underlying bitmap
RGBAPixel Quadtree::getPixel(int x, int y) const
{
    return getPixHelp(x, y, root);
}

RGBAPixel Quadtree::getPixHelp(int x, int y, QuadtreeNode *subtree) const {

    if ((subtree->x == x && subtree->y == y && subtree->res == 1) || (subtree->nwChild == NULL)) {
        return subtree->element;
    }

    if (inRange(x,y, subtree->nwChild)){
        return getPixHelp(x, y, subtree->nwChild);

    } else if (inRange(x, y, subtree->neChild)){
        return getPixHelp(x, y, subtree->neChild);

    } else if (inRange(x, y, subtree->swChild)){
        return getPixHelp(x, y, subtree->swChild);

    } else if (inRange(x, y, subtree->seChild)){
        return getPixHelp(x, y, subtree->seChild);
    }

    return subtree->element;
}

bool Quadtree::inRange(int x, int y, QuadtreeNode *subtree) const {

    int xRange = subtree->x + subtree->res;
    int yRange = subtree->y + subtree->res;

    return ((x >= subtree->x && x < xRange) && ( y >= subtree->y && y < yRange));

}


// decompress (public interface)
//   - parameters: none
//   - return value: a PNG object representing this quadtree's underlying
//        bitmap
//   - constructs and returns this quadtree's underlying bitmap
PNG Quadtree::decompress() const
{

    if ( root == NULL)
        return *(new PNG());

    int resolution = root->res;
    PNG temp(resolution, resolution);
    for ( int i =0; i < resolution; i++){
        for(int j = 0; j< resolution; j++){
            *(temp(i, j)) = getPixel(i, j);
        }
    }
    return temp;
}

// clockwiseRotate (public interface)
//   - parameters: none
//   - transforms this quadtree into a quadtree representing the same
//        bitmap, rotated 90 degrees clockwise
void Quadtree::clockwiseRotate()
{

}
void Quadtree::rotateClockWise(QuadtreeNode *subtree) {

    if (subtree->nwChild == NULL)
        return;

    QuadtreeNode* temp = subtree->nwChild;
    subtree->nwChild = subtree->swChild;
    subtree->swChild = subtree->seChild;
    subtree->seChild = subtree->neChild;
    subtree->neChild = temp;

    subtree->nwChild->x = subtree->x;
    subtree->nwChild->y = subtree->y;

    subtree->neChild->x = subtree->x +subtree->res/2;
    subtree->neChild->y = subtree->y;

    subtree->swChild->x = subtree->x;
    subtree->swChild->y = subtree->y + subtree->res/2;

    subtree->seChild->x = subtree->x + subtree->res/2;
    subtree->seChild->y = subtree->y + subtree->res/2;

    rotateClockWise(subtree->nwChild);
    rotateClockWise(subtree->neChild);
    rotateClockWise(subtree->swChild);
    rotateClockWise(subtree->seChild);
}

// prune (public interface)
//   - parameters: int tolerance - an integer representing the maximum
//                    "distance" which we will permit between a node's color
//                    (i.e. the average of its descendant leaves' colors)
//                    and the color of each of that node's descendant leaves
//   - for each node in the quadtree, if the "distance" between the average
//        of that node's descendant leaves' colors and the color of each of
//        that node's descendant leaves is at most tolerance, this function
//        deletes the subtrees beneath that node; we will let the node's
//        color "stand in for" the colors of all (deleted) leaves beneath it
void Quadtree::prune(int tolerance)
{
    prune(tolerance, root);
}

void Quadtree::prune(int tolerance, QuadtreeNode* subtree){

    if (subtree->nwChild == NULL)
        return;

    if (checkT(subtree, subtree, tolerance)){

        clearTree(subtree->nwChild);
        clearTree(subtree->neChild);
        clearTree(subtree->swChild);
        clearTree(subtree->seChild);
        return;
    }

    prune(tolerance, subtree->nwChild);
    prune(tolerance, subtree->neChild);
    prune(tolerance, subtree->swChild);
    prune(tolerance, subtree->seChild);
}

bool Quadtree::checkT(QuadtreeNode *subtree, QuadtreeNode *avgRoot, int avg) const {

    if (subtree->nwChild == NULL){
        return (difference(subtree, avgRoot) <= avg);
    }
    return (checkT(subtree->nwChild, avgRoot, avg) &&
                checkT(subtree->neChild, avgRoot, avg) &&
                checkT(subtree->swChild, avgRoot, avg) &&
                checkT(subtree->seChild, avgRoot, avg));
}

int Quadtree::difference(QuadtreeNode *a, QuadtreeNode *b) const {

    return (a->element.red - b->element.red ) * (a->element.red - b->element.red) + (a->element.green - b->element.green) + (a->element.blue - b->element.blue) * (a->element.blue - b->element.blue);
}

// pruneSize (public interface)
//   - parameters: int tolerance - an integer representing the maximum
//                    "distance" which we will permit between a node's color
//                    (i.e. the average of its descendant leaves' colors)
//                    and the color of each of that node's descendant leaves
//   - returns the number of leaves which this quadtree would contain if it
//        was pruned using the given tolerance; does not actually modify the
//        tree
int Quadtree::pruneSize(int tolerance) const
{
    return pruneSize(tolerance, root);
}

int Quadtree::pruneSize(int tolerance, QuadtreeNode* subtree) const
{
    if (subtree->nwChild == NULL)
        return 1;
    if (checkT(subtree, subtree, tolerance))
        return 1;

    return pruneSize(tolerance, subtree->nwChild) + pruneSize(tolerance, subtree->neChild) + pruneSize(tolerance, subtree->swChild) + pruneSize(tolerance, subtree->seChild);

}



// idealPrune (public interface)
//   - parameters: int numLeaves - an integer representing the number of
//                    leaves we wish the quadtree to have, after pruning
//   - returns the minimum tolerance such that pruning with that tolerance
//        would yield a tree with at most numLeaves leaves
int Quadtree::idealPrune(int numLeaves) const
{
    return idealPrune(numLeaves,255*255*3,255*255*3);
}

int Quadtree::idealPrune(int numLeaves, int n, int interval) const {

    if (pruneSize(n) == numLeaves){
        while (pruneSize(n) == numLeaves)
            n--;
        return n+1;
    }

    if(pruneSize(n) < numLeaves){
        return idealPrune(numLeaves, n-interval/2, interval/2);
    }
    else {
        return idealPrune(numLeaves, n+interval/2, interval/2);
    }
}

// QuadtreeNode
//   - parameters: none
//   - constructor for the QuadtreeNode class; creates an empty
//        QuadtreeNode, with all child pointers NULL
//Quadtree::QuadtreeNode::QuadtreeNode()
//{
//    neChild = seChild = nwChild = swChild = NULL;
//}
//
//// QuadtreeNode
////   - parameters: RGBAPixel const & elem - reference to a const
////        RGBAPixel which we want to store in this node
////   - constructor for the QuadtreeNode class; creates a QuadtreeNode
////        with element elem and all child pointers NULL
//Quadtree::QuadtreeNode::QuadtreeNode(RGBAPixel const& elem)
//{
//    element = elem;
//    neChild = seChild = nwChild = swChild = NULL;
//}
//
