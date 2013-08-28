#ifndef _OBJECT_POINT_
#define _OBJECT_POINT_

enum ObjectPointerType { O_BLOCK, O_POINT };

class ObjectPointer {
public:
						ObjectPointer		();
	ObjectPointerType	type;
	void*				pointer;
private:
	bool				shit;
};


#endif