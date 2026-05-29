#include "CoffeeMachine.h"
#include "State.h"
#include "NoCoinState.h"
#include "HasCoinState.h"
#include "DispensingState.h"

using namespace std;

CoffeeMachine::CoffeeMachine(int initialDrink) : drinkCount(initialDrink)
{
    noCoinState = make_shared<NoCoinState>(this);
    hasCoinState = make_shared<HasCoinState>(this);
    dispensingState = make_shared<DispensingState>(this);

    currentState = noCoinState;
}

void CoffeeMachine::SetState(shared_ptr<State> state)
{
    currentState = state;
}

void CoffeeMachine::InsertCoin()
{
    currentState->InsertCoin();
}

void CoffeeMachine::SelectDrink()
{
    currentState->SelectDrink();
}

void CoffeeMachine::Dispense()
{
    currentState->Dispense();
}

shared_ptr<State> CoffeeMachine::GetNoCoinState() const { return noCoinState; }
shared_ptr<State> CoffeeMachine::GetHasCoinState() const { return hasCoinState; }
shared_ptr<State> CoffeeMachine::GetDispensingState() const { return dispensingState; }

int CoffeeMachine::GetDrinkCount() { return drinkCount; }
void CoffeeMachine::SetDrinkCount(int count) { drinkCount = count; }
