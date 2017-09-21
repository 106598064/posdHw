#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"
#include <vector>
#include <list>

TEST (Sort, sortByIncreasingPerimeter) {
	Circle c (0,0,10);
	Rectangle r (0,0,4,3);
	vertex v1,v2,v3;
	v1.x=0;
	v1.y=0;
	v2.x=3;
	v2.y=0;
	v3.x=0;
	v3.y=4;
	Triangle t (v1,v2,v3);
	list<Shape* >shape;
	shape.push_back(&r);
	shape.push_back(&c);
	shape.push_back(&t);
	Sort :: sortByIncreasingPerimeter(&shape);
	list <Shape *>::iterator i = shape.begin ();
	ASSERT_EQ("t", (*i)->getShapeName());
	//cout<<(*i)->perimeter()<<endl;
	ASSERT_EQ("r", (*++i)->getShapeName());
	//cout<<(*i)->perimeter()<<endl;
	ASSERT_EQ("c", (*++i)->getShapeName());
	//cout<<(*i)->perimeter()<<endl;
}

TEST (Sort, sortByDecreasingPerimeter) {
	  Circle c (0,0,10);
    Rectangle r (0,0,4,3);
		vertex v1,v2,v3;
		v1.x=0;
		v1.y=0;
		v2.x=3;
		v2.y=0;
		v3.x=0;
		v3.y=4;
    Triangle t (v1,v2,v3);
    list<Shape* >shape;
    shape.push_back(&r);
    shape.push_back(&c);
    shape.push_back(&t);
	  Sort :: sortByDecreasingPerimeter(&shape);
		list <Shape *>::iterator i = shape.begin ();
    ASSERT_EQ("c", (*i)->getShapeName());
		//cout<<(*i)->perimeter()<<endl;
		ASSERT_EQ("r", (*++i)->getShapeName());
		//cout<<(*i)->perimeter()<<endl;
		ASSERT_EQ("t", (*++i)->getShapeName());
		//cout<<(*i)->perimeter()<<endl;
		//cout<<(*i)->perimeter()<<endl;


}

TEST (Sort, sortByIncreasingArea) {
	Circle c (0,0,10);
	Rectangle r (0,0,4,3);
	vertex v1,v2,v3;
	v1.x=0;
	v1.y=0;
	v2.x=3;
	v2.y=0;
	v3.x=0;
	v3.y=4;
	Triangle t (v1,v2,v3);
	list<Shape* >shape;
	shape.push_back(&r);
	shape.push_back(&c);
	shape.push_back(&t);
	Sort :: sortByIncreasingArea(&shape);
	list <Shape *>::iterator i = shape.begin ();
	ASSERT_EQ("t", (*i)->getShapeName());
	//cout<<(*i)->area()<<endl;
	ASSERT_EQ("r", (*++i)->getShapeName());
	//cout<<(*i)->area()<<endl;
	ASSERT_EQ("c", (*++i)->getShapeName());
	//cout<<(*i)->area()<<endl;
}

TEST (Sort, sortByDecreasingArea) {
	Circle c (0,0,10);
	Rectangle r (0,0,4,3);
	vertex v1,v2,v3;
	v1.x=0;
	v1.y=0;
	v2.x=3;
	v2.y=0;
	v3.x=0;
	v3.y=4;
	Triangle t (v1,v2,v3);
	list<Shape* >shape;
	shape.push_back(&r);
	shape.push_back(&c);
	shape.push_back(&t);
	Sort :: sortByDecreasingArea(&shape);
	list <Shape *>::iterator i = shape.begin ();
	ASSERT_EQ("c", (*i)->getShapeName());
	//cout<<(*i)->area()<<endl;
	ASSERT_EQ("r", (*++i)->getShapeName());
	//cout<<(*i)->area()<<endl;
	ASSERT_EQ("t", (*++i)->getShapeName());
	//cout<<(*i)->area()<<endl;
}

TEST (Sort, sortByIncreasingCompactness) {
	Circle c (0,0,10);
	Rectangle r (0,0,4,3);
	vertex v1,v2,v3;
	v1.x=0;
	v1.y=0;
	v2.x=3;
	v2.y=0;
	v3.x=0;
	v3.y=4;
	Triangle t (v1,v2,v3);
	list<Shape* >shape;
	shape.push_back(&r);
	shape.push_back(&c);
	shape.push_back(&t);
	Sort :: sortByIncreasingCompactness(&shape);
	list <Shape *>::iterator i = shape.begin ();
	ASSERT_EQ("t", (*i)->getShapeName());
	//cout<<(*i)->area()<<endl;
	ASSERT_EQ("r", (*++i)->getShapeName());
	//cout<<(*i)->area()<<endl;
	ASSERT_EQ("c", (*++i)->getShapeName());
	//cout<<(*i)->area()<<endl;
}

#endif
