#ifndef _CPOINT_
#define _CPOINT_

enum CPointType { CONTROL_POINT, CONTROL_POINT_VISITED, FINISH };

class CPoint {
public:
				CPoint		( float32 x, float32 y, CPointType type_ );
	void		Render		();
	void		Update		();
	b2Body*		GetBody		();
	void		SetActive	();
	void		SetUnActive	();
private:
	b2Body*		body;
	CPointType	type;
	GLuint		texture;
};


#endif