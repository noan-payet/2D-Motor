#pragma once

#include <vector>
#include <cstddef>

template <typename T>
class StateBase
{
public:
	virtual void Start(T* type) = 0;
	virtual void Update(T* type, float dt) = 0;
	virtual void End(T* type) = 0;

	virtual bool CanTransitionFrom(T* type, int currentState) { return true; };
};

template<typename T>
class Condition
{
	bool m_expectedValue = true;
public:
	Condition(bool expectedValue = true) { m_expectedValue = expectedValue; }

	bool InternalTest(T* type) { return Test(type) == m_expectedValue; }

	virtual bool Test(T* type) = 0;
};


template<typename T>
class Transition
{
	int m_targetState;
	std::vector<Condition<T>*> m_conditions;

public:
	Transition(int targetState)
	{
		m_targetState = targetState;
	}

	void AddCondition(Condition<T>* condition)
	{
		m_conditions.push_back(condition);
	}

	int TryTransition(T* type)
	{
		for (int i = 0; i < m_conditions.size(); ++i)
		{
			if (m_conditions[i]->InternalTest(type) == false)
				return -1;
		}

		return m_targetState;
	}
};

template<typename T>
class StateMachine {
private:

	int m_currentState = 0;
	std::vector<StateBase<T>*> m_states;
	std::vector<std::vector<Transition<T>*>> m_transitions;

public:
	bool DEBUG = true;

	void AddState(StateBase<T>* newState)
	{
		m_states.push_back(newState);

		m_transitions.resize(m_states.size());
	}

	void Update(T* type, float dt)
	{
		if (m_states.empty() || m_currentState >= m_states.size())
			return;

		m_states[m_currentState]->Update(type, dt);

		std::vector<Transition<T>*>& transitions = m_transitions[m_currentState];
		for (int i = 0; i < transitions.size(); ++i)
		{
			int nextState = transitions[i]->TryTransition(type);
			if (nextState == -1)
				continue;

			TransitionTo(type, nextState);
			break;
		}
	}

	void TransitionTo(T* type, std::size_t nextState)
	{
		_ASSERT(nextState >= 0);
		_ASSERT(nextState < m_states.size());

		m_states[m_currentState]->End(type);

		m_currentState = nextState;

		m_states[m_currentState]->Start(type);
	}

	void Initialize(T* type, std::size_t _newState)
	{
		if (_newState >= m_states.size())
			return;

		m_currentState = _newState;

		m_states[m_currentState]->Start(type);
	}

	Transition<T>* AddTransition(int fromState, int toState)
	{
		Transition<T>* transition = new Transition<T>(toState);
		m_transitions[fromState].push_back(transition);

		return transition;
	}

	int GetState() const
	{
		return m_currentState;
	}
};