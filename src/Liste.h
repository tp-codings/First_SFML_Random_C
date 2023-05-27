#pragma once
class Liste
{
public:
	Liste();
	~Liste();

	void listenApplication();
	int push(int);
	int pop();
	int print();
	int previous();
	int next();
	int destroy();

private:
	struct elements {
		int var;
		elements* nxt;
	}* top, *anf, *akt;
};

