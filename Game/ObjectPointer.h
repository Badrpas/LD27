#ifndef _OBJECT_POINT_
#define _OBJECT_POINT_

enum ObjectPointerType { O_BLOCK, O_POINT };

struct ObjectPointer {
	void * pointer;
	ObjectPointerType type;
	ObjectPointer() ;
};


#endif