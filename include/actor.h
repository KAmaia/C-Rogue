#ifndef actor_h
#define actor_h

class actor{
	public:
		void move(int);
		int getHealth();
		int getPOSX();
		int getPOSY();
	private:
		int posX;
		int posY;
		int health;
};
#endif	
