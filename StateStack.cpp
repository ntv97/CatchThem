#include "StateStack.hpp"
#include "HomeState.hpp"
#include "GameOverState.hpp"

StateStack::StateStack(sf::RenderWindow &window) : Window(window), Stack(), Factory() {
}

void StateStack::PushState(States::Id id) {
	PendingList.push_back(PendingChange(Push, id));
}

void StateStack::PopState() {
	PendingList.push_back(PendingChange(Pop));
}

void StateStack::ClearStates() {
	PendingList.push_back(PendingChange(Clear));
}

/*template <typename T>
void StateStack::RegisterState(States::Id stateId) {
	Factory[stateId] = [this] ()
	{
		return State::StatePtr(new T(*this, Window));
	};
}*/

State::StatePtr StateStack::CreateState(States::Id stateId) {
	auto state = Factory.find(stateId);
        if (state == Factory.end()) return NULL;
        return std::move(state->second());
}

void StateStack::Update(sf::Time& dt) {
	for (auto& state : Stack)
		if(!state->Update(dt)) break;
	ApplyPendingChanges();
}

void StateStack::Draw() {
	for(auto& state : Stack)
		state->Draw();

}

void StateStack::HandleEvent(const sf::Event& event) {
	for (auto &state : Stack) {
		if (state->HandleEvent(event))
			break;
	}

}

bool StateStack::IsEmpty() const {
	return Stack.size() == 0;
}

void StateStack::ApplyPendingChanges() {
	for (auto& change : PendingList) {
		if (change.action == Push) {
			Stack.push_back(CreateState(change.stateId));
		} else if (change.action == Pop) {
			Stack.pop_back();
		} else if (change.action == Clear) {
			Stack.clear();
		}
	}
	PendingList.clear();
}

StateStack::PendingChange::PendingChange(Action action, States::Id stateId)
: action(action), stateId(stateId) {
}
