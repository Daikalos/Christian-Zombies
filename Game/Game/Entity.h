#ifndef ENTITY_HEADER
#define ENTITY_HEADER

class Entity {
public:
	float GetHealthPoints() const;
	void SetHealthPoints(float someHealthPoints);

	float GetMaxHealth() const;

	float GetDamageValue() const;
	void SetDamageValue(float aDamageValue);

	virtual void Init();
	virtual void Update();
	virtual void Draw();

	virtual void Move();
	virtual void Attack();
protected:
	float myHealthPoints;
	float myMaxHealth;

	float myDamageValue;

	void SetMaxHealth(float aMaxHealthValue);
}

#endif
