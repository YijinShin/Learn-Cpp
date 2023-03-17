#pragma once
#include "CBullet.h"

class CBullet_Screw : public CBullet
{
private:

public:
	CBullet_Screw();
	virtual ~CBullet_Screw();

	virtual void	Initialize()	override;
	virtual	int		Update()		override;
	virtual int		Late_Update()	override;
};

