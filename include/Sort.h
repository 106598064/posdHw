#include <list>
#include "Shapes.h"
#include "algorithm"

using namespace std;

bool Increasingcompactness(const Shape* a,const Shape* b){
    return a->area()/a->perimeter() < b->area()/b->perimeter();
};

bool IncreasingArea(const Shape* a,const Shape* b){
    return a->area() < b->area();
};

bool DecreasingArea(const Shape* a,const Shape* b){
    return a->area() > b->area();
};

bool IncreasingPerimeter(const Shape* a,const Shape* b){
    return a->perimeter() < b->perimeter();
};

bool DecreasingPerimeter(const Shape* a,const Shape* b){
    return a->perimeter() > b->perimeter();
};

class Sort {

  public :static void sortByIncreasingPerimeter(list<Shape *> * shapeList){
    shapeList->sort(IncreasingPerimeter);
  };

  public :static void sortByDecreasingPerimeter(list<Shape *> * shapeList){
      shapeList->sort(DecreasingPerimeter);
  };

  public :static void sortByIncreasingArea(list<Shape *> * shapeList){
    shapeList->sort(IncreasingArea);
  };

  public :static void sortByDecreasingArea(list<Shape *> * shapeList){
    shapeList->sort(DecreasingArea);
  };

  public :static void sortByIncreasingCompactness(list<Shape *> * shapeList){
    shapeList->sort(Increasingcompactness);
  };



};

/*void sortByIncreasingPerimeter(list<Shape *> * shapeList){
    sort(shapeList->begin(), shapeList->end(),[]( const Shape* first, const Shape* second){
        return first->perimeter() < second->perimeter();
    });
}

void sortByDecreasingPerimeter(list<Shape *> * shapeList){
    sort(shapeList->begin(), shapeList->end(),[]( const Shape* first, const Shape* second){
        return first->perimeter() > second->perimeter();
    });

}*/

/*void sortByIncreasingArea(list<Shape *> * shapeList){
    sort(shapeList.begin(), shapeList.end(),[]( const Shape* first, const Shape* second){
        return first->area() < second->area();
    });
}

void sortByDecreasingArea(list<Shape *> * shapeList){
    sort(shapeList.begin(), shapeList.end(),[]( const Shape* first, const Shape* second){
        return first->area() > second->area();
    });
}*/
