#ifndef STATE_STACK_HPP
#define STATE_STACK_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <map>
#include <functional>
#include <utility>

#include "State.hpp"
#include "StateId.hpp"
#include "HomeState.hpp"


class StateStack {
public:
	explicit StateStack(sf::RenderWindow &window);
	void PushState(States::Id id);
	void PopState();
	void ClearStates();
	template <typename T>
	void RegisterState(States::Id stateId) {
		Factory[stateId] = [this] ()
		{       
			return State::StatePtr(new T(this, Window));
		};
	}
	State::StatePtr	CreateState(States::Id stateId);
	void Update(sf::Time& dt);
	void Draw();
	void HandleEvent(const sf::Event& event);
	bool IsEmpty() const; 
	void ApplyPendingChanges();
	enum Action {
		Push,
		Pop,
		Clear,
	};
private:
	struct PendingChange {
		explicit			PendingChange(Action action, States::Id stateId = States::Length);

		Action				action;
		States::Id			stateId;
	};
private:
	sf::RenderWindow		&Window;
	std::vector<State::StatePtr>	Stack;
	std::vector<PendingChange>	PendingList;
	std::map<States::Id, std::function<State::StatePtr()>>	Factory;
};

#endif /* STATE_STACK_HPP */
