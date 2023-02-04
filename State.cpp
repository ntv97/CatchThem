#include "State.hpp"
#include "StateStack.hpp"

State::State(StateStack* stack,  sf::RenderWindow &window) : Stack(stack), Window(window) {
	
}

void State::RequestStackPush(States::Id id) {
	Stack->PushState(id);
}

void State::RequestStackPop() {
	Stack->PopState();
}

void State::RequestStateClear() {
	Stack->ClearStates();
}

State::~State() {}
