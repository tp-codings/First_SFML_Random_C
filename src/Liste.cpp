#include "Liste.h"
#include <iostream>
#include <string>

Liste::Liste()
{
	this->anf = nullptr;
	this->top = nullptr;
	this->akt = nullptr;
}

Liste::~Liste()
{
}

void Liste::listenApplication()
{
	char choice;
	int val;

	do {
		std::cout << "Gib Buchstabe ein Hejel [p = push; k = pop; b = previus; n = next; d = destroy;  x = abbruch]\n\n";
		print();
		std::cin >> choice;
		switch (choice)
		{
		case 'p': 
			std::cin >> val;
			if (push(val) != 1)
			{
				std::cout << "ERROR::DU KLEINE SCHLAMPE!!! \n";
				system("PAUSE");
			}
			break;
		case 'k':
			if (pop() != 1) 
			{
				std::cout<< "ERROR::NICHTS ZUM BUMSEN DA \n";
				system("PAUSE");
			}
			break;
		//case 's':
		//	if (print() != 1)
		//	{
		//		std::cout << "ERROR::WEILS EIN ERROR IST UND NICHTS ZUM LESEN DA\n";
		//		system("PAUSE");
		//	}
		//	break;
		case 'b':
			if (previous() != 1)
			{
				std::cout << "beim ersten ELement du Penner\n";
				system("PAUSE");
			}
			break;
		case 'n':
			if (next() != 1)
			{
				std::cout << "beim letzten ELement du Penner\n";
				system("PAUSE");
			}
			break;
		case 'd':
			if (destroy() != 1)
			{
				std::cout << "Jetzt wirds schlimm\n";
				system("PAUSE");
			}
			break;
		case 'x': break;
		default: 
			std::cout << "ERROR::ZU BLOED ZUM LESEN\n";
			system("PAUSE");
		}
		system("CLS");
	} while (choice != 'x');
	std::cout << "\nListenapplication beendet\n\n";
}

int Liste::push(int value)
{
	elements* neu = new elements;
	neu->nxt = anf;
	if (anf == nullptr)
	{
		top = neu;
		akt = top;
	}

	anf = neu;
	neu->var = value;
	return 1;
}

int Liste::pop()
{
	elements* zwPoint;
	zwPoint = anf;

	if (anf == nullptr)
	{
		return 0;
	}
	else if (anf->nxt == nullptr)
	{
		anf = nullptr;
		top = nullptr;
		akt = nullptr;
		//std::cout << "popped: " << zwPoint->var <<" (last one)" << "\n";
		delete zwPoint;
	}

	else 
	{
		if (akt == anf) akt = akt->nxt;
		anf = anf->nxt;
		//std::cout << "popped: " << zwPoint->var << "\n";
		delete zwPoint;
	}
	return 1;
}

int Liste::print()
{
	std::cout<<"\n";
	if (anf != nullptr)
	{
		elements* lauf;
		lauf = anf;
		while (lauf != top->nxt)
		{
			std::cout << lauf->var;
			if (lauf == akt) std::cout << "    <=";
			std::cout << std::endl;
			lauf = lauf->nxt;
		}
		std::cout << "\n";
		return 1;
	}
	return 0;
}

int Liste::previous()
{
	elements* lauf;
	if (anf != akt && akt != nullptr)
	{
		lauf = anf;
		while (lauf->nxt != akt) lauf = lauf->nxt;
		akt = lauf;
		return 1;
	}
	
}

int Liste::next()
{
	if (akt != top)
	{
		akt = akt->nxt;
		return 1;
	}
	return 0;
}

int Liste::destroy()
{
	elements* merker;
	elements* merkerNext;
	merker = akt;
	
	if (akt != nullptr)
	{
		if (anf->nxt == nullptr)
		{
			anf = nullptr;
			top = nullptr;
			akt = nullptr;
			//std::cout << "deleted: " << merker->var << " (last one)" << "\n";
			delete merker;
			return 1;
		}
		else if (akt == top)
		{
			previous();
			top = akt;
			top->nxt = nullptr;
			//std::cout << "deleted: " << merker->var << "\n";
			delete merker;
			return 1;
		}

		else if (akt == anf)
		{
			merkerNext = akt->nxt;
			next();
			anf = akt;
			anf->nxt = merkerNext->nxt;
			//std::cout << "deleted: " << merker->var << "\n";
			delete merker;
			return 1;
		}

		else
		{
			merkerNext = akt->nxt;
			previous();
			//std::cout << "deleted: " << merker->var << "\n";
			delete merker;
			akt->nxt = merkerNext;
			return 1;
		}
		return 0;
	}
}
