#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Owner
{
	bool walkPet;
	double moneySpend;
	double timeSpend;
public:
	void ownerSet()
	{
		string option = "";
		cout << "Are you willing to walk your pet? : ";
		cin >> option;
		if (option == "Yes" || option == "yes")
			walkPet = 1;
		else
			walkPet = 0;
		cout << "How much money are you willing to spend a month on your pet? : ";
		cin >> moneySpend;
		cout << "How much time are you willing to spend with your pet every day? : ";
		cin >> timeSpend;
	}
	bool getWalkPet() const {
		return walkPet;
	}
	double getMoneySpend() const {
		return moneySpend;
	}
	double getTimeSpend() const {
		return timeSpend;
	}
};

class Pet
{
public:
	virtual bool accept(const Owner& owner) const = 0;
	virtual string name() const = 0;
	virtual ~Pet() {};
};

class Dog : public Pet
{
public:
	bool accept(const Owner& owner) const override
	{
		return owner.getWalkPet() && owner.getMoneySpend() >= 55 && owner.getTimeSpend() >= 1.5;
	}

	string name() const override
	{
		return "Dog";
	}
};

class Fish : public Pet
{
public:
	bool accept(const Owner& owner) const override
	{
		return owner.getMoneySpend() >= 15;
	}

	string name() const override
	{
		return "Fish";
	}
};

class Cat : public Pet
{
public:
	bool accept(const Owner& owner) const override
	{
		return owner.getMoneySpend() >= 30 && owner.getTimeSpend() >= 1;
	}

	string name() const override
	{
		return "Cat";
	}
};

class Petshop
{
	vector<Pet*> pets;
public:
	void addPet(Pet* pet)
	{
		pets.push_back(pet);
	}

	void check(const Owner& owner) const
	{
		cout << "List of suited pets:\n";
		for (const auto& pet : pets)
		{
			if (pet->accept(owner))
			{
				cout << pet->name() << " can be adopted\n";
			}
		}
	}
};

int main()
{
	Petshop petshop;
	Owner owner;
	owner.ownerSet();

	Dog dog;
	Fish fish;
	Cat cat;

	petshop.addPet(&dog);
	petshop.addPet(&fish);
	petshop.addPet(&cat);

	petshop.check(owner);
}
