

class cMouse
{
public:
	void Update(int,int);
	bool LeftClick(int,int,int,int);
	bool OneLeftClick(int,int,int,int);
	bool IsOver(int,int,int,int);

	void Drag(bool&,bool,bool,int&,int&,int&,int&);

	void GetMousePosition(int &posx, int &posy)
	{
		posx = mouse_x;
		posy = mouse_y;
	}

	bool HasMouseOneJustBeenReleased()
	{
		return mouse1released;
	}

	bool IsMouseTwoBeingHeld()
	{
		return mouse2pressed;
	}

	bool bDragged[3];
	int iDiffX[3];
	int iDiffY[3];

	int mouse_x, mouse_y;
private:
	bool mouse1pressed;
	bool mouse1released;
	bool mouse2pressed;
	bool mouse2released;
};

inline cMouse g_Mouse;
