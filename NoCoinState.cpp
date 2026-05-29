#include <iostream>
#include "NoCoinState.h"
#include "CoffeeMachine.h"

using namespace std;

NoCoinState::NoCoinState(CoffeeMachine* machine) : machine(machine) {}

void NoCoinState::InsertCoin()
{
    cout << "Монета принята. Выберите напиток.\n";
    machine->SetState(machine->GetHasCoinState());
}

void NoCoinState::SelectDrink()
{
    cout << "Сначала бросьте монету\n";
}

void NoCoinState::Dispense()
{
    cout << "Нечего выдавать\n";
}
