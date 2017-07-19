#pragma once
class GameController
{
	struct Impl;
	unique_ptr<Impl> impl;
public:
	GameController();
	~GameController();

	void run();
};

